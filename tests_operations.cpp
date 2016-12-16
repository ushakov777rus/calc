#include "operations.h"

// Проверяем что зарегистрированы все заявленные операции
TEST(Operations, TestSumRegistered)
{
    Operations op;
    ASSERT_TRUE(op.isRegistered('+'));
}

TEST(Operations, TestSubRegistered)
{
    Operations op;
    ASSERT_TRUE(op.isRegistered('-'));
}

TEST(Operations, TestMulRegistered)
{
    Operations op;
    ASSERT_TRUE(op.isRegistered('*'));
}

TEST(Operations, TestDivRegistered)
{
    Operations op;
    ASSERT_TRUE(op.isRegistered('/'));
}

// Проверяем  случай когда операция не зарегистрирована
TEST(Operations, TestPowNotRegistered)
{
    Operations op;
    ASSERT_FALSE(op.isRegistered('^'));
}

// Проверяем что все операции выполняются
TEST(Operations, TestSumOperationExecuting)
{
    Operations op;
    ASSERT_EQ(op.execute('+', 1.2, 3), 4.2);
}

TEST(Operations, TestSubOperationExecuting)
{
    Operations op;
    ASSERT_EQ(op.execute('-', 2.35, 1), 1.35);
}

TEST(Operations, TestMulOperationExecuting)
{
    Operations op;
    ASSERT_EQ(op.execute('*', 4.5, 2), 9);
}

TEST(Operations, TestDivOperationExecuting)
{
    Operations op;
    ASSERT_EQ(op.execute('/', 4, 2), 2);
}

// Проверим что деление на ноль корректно обрабатывается
TEST(Operations, TestDivOperationByZero)
{
    Operations op;    
    try
    {
        ASSERT_EQ(op.execute('/', 4, 0), 2);
        FAIL() << "Expected std::logic_error";
    }
    catch(std::logic_error const & err)
    {
        EXPECT_EQ(err.what(),std::string("Division by ZERO!!!"));
    }
    catch(...)
    {
        FAIL() << "Expected std::logic_error";
    }
}
