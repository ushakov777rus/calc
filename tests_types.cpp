#include "types.h"

// Проверка конструктора
TEST(Number, TestCtor)
{    
    ASSERT_EQ(Number(1.23456), 1.23);
}

// Проверка функции fromstr
TEST(Number, TestNullString)
{    
    ASSERT_EQ(Number::fromstr(nullptr, nullptr),0.0);    
}

TEST(Number, TestEmptyString)
{    
    ASSERT_EQ(Number::fromstr("", nullptr),0.0);    
}

TEST(Number, TestIncorrectSymbol)
{    
    ASSERT_EQ(Number::fromstr("x", nullptr),0.0);    
}

TEST(Number, TestInteger)
{   
    ASSERT_EQ(Number::fromstr("123", nullptr),123.0);
}

TEST(Number, TestDoubleWithPoint)
{   
    ASSERT_EQ(Number::fromstr("123.12", nullptr),123.12);
}

TEST(Number, TestDoubleWithComma)
{   
    ASSERT_EQ(Number::fromstr("123,12", nullptr),123.12);
}

TEST(Number, TestOutputPtr)
{   
    char * out = nullptr;
    ASSERT_EQ(Number::fromstr("123,12sda", &out),123.12);
    ASSERT_EQ(std::string(out),"sda");
}

TEST(Number, TestTwoSeparators)
{   
    char * out = nullptr;
    ASSERT_EQ(Number::fromstr("123,12.345", &out),123.12);
    ASSERT_EQ(std::string(out),".345");
}

TEST(Number, TestSymbolCountAfterSeparator)
{    
    try
    {
        ASSERT_EQ(Number::fromstr("123.123", nullptr),123.12);
        FAIL() << "Expected std::logic_error";
    }
    catch(std::logic_error const & err)
    {
        EXPECT_EQ(err.what(),std::string("В числах можно указывать только 2 знака после разделителя"));
    }
    catch(...)
    {
        FAIL() << "Expected std::logic_error";
    }
}

