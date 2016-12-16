#pragma once

#include <map>
#include <functional>

using namespace std;

/*
    Класс, описывающий поддерживаемые операции
*/
class Operations
{
private:
    // Операции с даумя числами
	map<char, function<double (double, double)>> _operations = 
	{
		{ '*', [](double a, double b) {return a * b; } },
		{ '/', [](double a, double b) {if (b == 0)throw logic_error("Division by ZERO!!!"); return a / b; } },
		{ '+', [](double a, double b) {return a + b; } },
		{ '-', [](double a, double b) {return a - b; } },
	};

    // Операции с одним числом, на тот случай если выражение начинается с + или -
	map<char, function<double(double)>> _uoperations =
	{
		{ '+', [](double a) {return a; } },
		{ '-', [](double a) {return -1 * a; } },
	};

    // Приоритет операций
	map<char, unsigned char> _priority =
	{
		{ '*', 2 },
		{ '/', 2 },
		{ '+', 1 },
		{ '-', 1 },
	};

public:
    // Поддерживается ли операция
	bool isRegistered(char op)
	{
		return _operations.count(op) > 0;
	}

    // Возвращает приоритет операции
	unsigned char priority(const char& op)
	{
		if(isRegistered(op))
			return _priority[op];
		
		throw logic_error("Неизвестная команда");
	}

    // Выполнение бинарной операции
	double execute(const char& op, const double& a, const double& b)
	{
		if (isRegistered(op))
			return _operations[op](a, b);

		throw logic_error("Неизвестная команда");
	}

    // Выполнение унарной операции
	double execute(const char& op, const double& a)
	{
		if (isRegistered(op))
			return _uoperations[op](a);

		throw logic_error("Неизвестная команда");
	}
};
