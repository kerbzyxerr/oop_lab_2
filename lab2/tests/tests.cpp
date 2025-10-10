#include <gtest/gtest.h>
#include "five.h"

TEST(FiveTest, DefaultConstructor) {
    Five num;
    EXPECT_EQ(num.getSize(), 1);
    EXPECT_EQ(num.getDigit(0), 0);
}

TEST(FiveTest, SizeConstructor) {
    Five num(3, 2);
    EXPECT_EQ(num.getSize(), 3);
    EXPECT_EQ(num.toString(), "222");
}

TEST(FiveTest, InitializerListConstructor) {
    Five num{1, 2, 3};
    EXPECT_EQ(num.toString(), "123");
}

TEST(FiveTest, StringConstructor) {
    Five num("123");
    EXPECT_EQ(num.toString(), "123");
}

TEST(FiveTest, InvalidDigitInSizeConstructor) {
    EXPECT_THROW(Five(2, 5), std::invalid_argument);
}

TEST(FiveTest, InvalidDigitInInitializerList) {
    EXPECT_THROW(Five({1, 5, 3}), std::invalid_argument);
}

TEST(FiveTest, InvalidDigitInString) {
    EXPECT_THROW(Five("167"), std::invalid_argument);
}

TEST(FiveTest, CopyConstructor) {
    Five num1("123");
    Five num2(num1);
    EXPECT_TRUE(num1.equals(num2));
}

TEST(FiveTest, MoveConstructor) {
    Five num1("123");
    Five num2(std::move(num1));
    EXPECT_EQ(num2.toString(), "123");
    EXPECT_EQ(num1.getSize(), 1);
    EXPECT_EQ(num1.getDigit(0), 0);
}

TEST(FiveTest, AddOperation) {
    Five num1("12");
    Five num2("23");
    Five result = num1.add(num2);
    EXPECT_EQ(result.toString(), "40");
}

TEST(FiveTest, SubtractOperation) {
    Five num1("32");
    Five num2("14");
    Five result = num1.subtract(num2);
    EXPECT_EQ(result.toString(), "13");
}

TEST(FiveTest, ComparisonOperations) {
    Five num1("12");
    Five num2("23");
    
    EXPECT_TRUE(num1.lessThan(num2));
    EXPECT_TRUE(num2.greaterThan(num1));
    EXPECT_TRUE(num1.equals(num1));
}

TEST(FiveTest, LeadingZerosRemoval) {
    Five num1("000123");
    EXPECT_EQ(num1.toString(), "123");
    
    Five num2("0000");
    EXPECT_EQ(num2.toString(), "0");
}

TEST(FiveTest, OutOfRangeException) {
    Five num("123");
    EXPECT_THROW(num.getDigit(5), std::out_of_range);
}

TEST(FiveTest, SubtractLargerNumber) {
    Five num1("12");
    Five num2("123");
    EXPECT_THROW(num1.subtract(num2), std::invalid_argument);
}