#include "calculator.h"

// Проверка парсера
TEST(Calculator, TestEmptyExpression)
{    
    Operations operations;
	Calculator calc;
    std::string expr("");
    std::string error("");

    ASSERT_FALSE(calc.parse(expr, operations, error));    
}

TEST(Calculator, TestMissedLeftBracket)
{    
    Operations operations;
	Calculator calc;
    std::string expr("1+)+5");
    std::string error("");

    ASSERT_FALSE(calc.parse(expr, operations, error));    
}

TEST(Calculator, TestMissedRightBracket)
{    
    Operations operations;
	Calculator calc;
    std::string expr("1+(+5");
    std::string error("");

    ASSERT_FALSE(calc.parse(expr, operations, error));    
}

// Выражения из задания
TEST(Calculator, TestCorrectExpression1)
{    
    Operations operations;
	Calculator calc;
    std::string expr("-1 + 5 - 3");
    std::string error("");

    ASSERT_TRUE(calc.parse(expr, operations, error)); 
    ASSERT_EQ(calc.calc(operations), 1);    
}

TEST(Calculator, TestCorrectExpression2)
{    
    Operations operations;
	Calculator calc;
    std::string expr("-10 + (8 * 2.5) - (3 / 1,5)");
    std::string error("");

    ASSERT_TRUE(calc.parse(expr, operations, error));    
    ASSERT_EQ(calc.calc(operations), 8);    
}


TEST(Calculator, TestCorrectExpression3)
{    
    Operations operations;
	Calculator calc;
    std::string expr("1 + ( 2 * ( 2.5 + 2.5 + (3 - 2))) - (3 / 1.5)");
    std::string error("");

    ASSERT_TRUE(calc.parse(expr, operations, error));    
    ASSERT_EQ(calc.calc(operations), 11);    
}

TEST(Calculator, TestIncorrectExpression)
{    
    Operations operations;
	Calculator calc;
    std::string expr("1.1 + 2.1 + abc");
    std::string error("");

    ASSERT_FALSE(calc.parse(expr, operations, error));    
    ASSERT_EQ(error, "Некорректный ввод, строка содержит недопустимое выражение: abc");    
}

