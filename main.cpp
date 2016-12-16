#include <iostream>

#include "calculator.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");

	Operations operations;
	Calculator calc;

	std::string expr;

	while (!std::cin.eof())
	{
		cout << "Введите выражение:" << endl;

		std::getline(std::cin, expr);

		if (expr.length() > 0)
		{
			try
			{
				string error;
				if (calc.parse(expr, operations, error))
                    cout << "Результат: " << (double)calc.calc(operations) << endl << endl;
				else
					if(!error.empty())
					cout << error << endl << endl;
			}
			catch (const std::exception&e)
			{
				cout << "Ошибка: " << e.what() << endl << endl;
			}
		}
	}

	return 0;
}
