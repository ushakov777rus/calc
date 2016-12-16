#pragma once

#include <stdexcept>

using namespace std;

/*
	Класс, описывающий наш double.

	Основное тут преобразование из double с обрезанием лишних знаков ну и преобразование в double
	Так же здесь статическая функция получения числа из строки (аналог strtod)

    Реализовал только самое необходимое
*/
class Number
{
public:
	// Количество знаков после запятой
	static const int PRECISION = 2;

private:
	// Значение
	double _value;

public:
	// Конструктор преобразования типов
	Number(double value);

	// Получение Number из строки
	static Number fromstr(const char *str, char **endptr );
public:
	// Этого не может быть 
	inline operator char()
	{
		throw logic_error("Это число, а не операция!");
	}

	// Преобразование обратно в double
	inline operator double()
	{
		return _value;
	}

    // Оператор сравнения
    inline bool operator==(const double value) const
    {
        return _value == value;
    }
};
