#include "types.h"

#include <math.h>

// Конструктор преобразования типове
// Обрезает передаваемый double до двух знаков
Number::Number(double value)
{		
    double precision = pow(10, PRECISION);
    _value = floor(value * precision + 0.5) / precision;
}

// Получение числа из строки
// Здесь же и проверка на ввод двух знаков после запятой
Number Number::fromstr(const char *str, char **endptr)
{
    double result = 0.0;
    int decimals = 0;
    bool hasResult = false;

    char symbol;

    if(!str)
        return result;

    for (; '\0' != (symbol = *str); ++str) 
    {
        // Цифра?
        if ((symbol >= '0') && (symbol <= '9'))
        {
            int digit = symbol - '0';
            
            // Не было разделителя, сдвиг результата и прибавляем цифру
            if (decimals == 0)
            {
                result = (10 * result) + digit;
                hasResult = true;
            }
            // Был разделитель
            else
            {
				if (!hasResult)
					break;

                // Не много ли цифр после запятой?
                if (decimals > pow(10, PRECISION))
                    throw logic_error("В числах можно указывать только 2 знака после разделителя");

                // Прибавляем к результату копейки
                result += (double)digit / decimals;
                decimals *= 10;
            }
            continue;
        }

        // Разделитель?
        if (symbol == '.' || symbol == ',')
        {
            // Уже второй раз
            if (decimals != 0)
                break;

            decimals = 10;
            continue;
        }
        
        break;
    }

    if (endptr) *endptr = const_cast<char*>(str);

    return Number(result);
}
