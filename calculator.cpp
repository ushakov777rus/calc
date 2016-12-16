#include "calculator.h"

#include <iostream>
#include <locale>

Number Calculator::calc(Operations& operations)
{
    // локальный стек для хранения значений
    stack<double> values;

    while (_rpn.size())
    {
        auto last = *_rpn.cbegin();
        
        if (last->isOperator())
        {
            if (values.empty())
                throw logic_error("Невозможно вычислить выражение, возможно оно не корректно");

            double ans;
            
            double r = values.top();values.pop();				

            // Если переменная одна, это может быть если выражение начинается с + или - и число
            // то выполняем операцию с ней
            if (values.empty())				
                ans = operations.execute(last->operation(), r);				
            // Иначе обычная операция
            else
            {
                double l = values.top();values.pop();

                ans = operations.execute(last->operation(), l, r);
            }
            
            values.push(ans);
        }
        else			
            values.push(last->value());
        
        _rpn.pop_front();
    }
    
    // Нагло??? Или написать свой Double?
    return values.top();
}

// Разбор выражения и преобразование его к RPN нотации
// 3+4*2.6/(1-5)*2
bool Calculator::parse(string& expression, Operations& operations, string& error)
{		
    if(expression.empty())
        return false;

    stack<char> operators;

    _rpn.erase(_rpn.begin(), _rpn.end());

    string errToken;
    locale loc;
    const char * ptr = expression.c_str();

    while(ptr && *ptr)
    {
        if (' ' == *ptr)
        {
            ++ptr;
            continue;
        }
        else if ('(' == *ptr)
            operators.push(*ptr);
        else if (')' == *ptr)
        {          
            while (!operators.empty() && !('(' == operators.top()))
            {
                _rpn.push_back(shared_ptr<IToken>(new Token< char >(operators.top(), true)));
                operators.pop();
            }

            // Не нашли открывающей скобки
            if(operators.empty())
            {
                error = "Несоответствие скобок";
                return false;
            }               

            operators.pop();
        }
        else if (isdigit(*ptr, loc))
        {
            char * next_ptr = 0;
            Number val = Number::fromstr(ptr, &next_ptr);
            
            _rpn.push_back(shared_ptr<IToken>(new Token< Number >(val, false)));
            ptr = next_ptr - 1;
        }
        else if (operations.isRegistered(*ptr))
        {
            while (!operators.empty()
                && operations.isRegistered(operators.top())
                && operations.priority(*ptr) <= operations.priority(operators.top()))
            {
                _rpn.push_back(shared_ptr<IToken>(new Token< char >(operators.top(), true)));
                operators.pop();
            }
            operators.push(*ptr);
        }
        else			
            errToken += *ptr;

        ++ptr;
    }

    if (!errToken.empty())    
    {
        error = "Некорректный ввод, строка содержит недопустимое выражение: " + errToken;
        return false;
    }
    
    while (!operators.empty())
    {			
        if(operators.top() == '(' || operators.top() == ')')
        {
            error = "Несоответствие скобок";
            return false;
        }

        _rpn.push_back(shared_ptr<IToken>(new Token< char >(operators.top(),true)));
        operators.pop();
    }

    return true;
}
