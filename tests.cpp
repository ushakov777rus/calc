#include <gtest/gtest.h>

#include "tests_operations.cpp" 
#include "tests_types.cpp" 
#include "tests_calculator.cpp" 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}