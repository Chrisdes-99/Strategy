#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"


#include "add.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"
/*
#include "Mock_div.hpp"
#include "Mock_mult.hpp"
#include "Mock_op.hpp"
#include "Mock_rand.hpp"
*/


//------------------Op------------------
TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(2.34);
    EXPECT_EQ(test->evaluate(), 2.34);
    EXPECT_EQ(test->stringify(), "2.340000");
}
TEST(OpTest, OpEvaluateZero) {
    Op* test = new Op(0);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "0.000000");
}
TEST(OpTest, OpEvaluateNeg) {
    Op* test = new Op(-2.34);
    EXPECT_EQ(test->evaluate(), -2.34);
    EXPECT_EQ(test->stringify(), "-2.340000");
}

//------------------Rand------------------
TEST(RandTest, RandEvaluateNonZero) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 100);
}

//------------------Mult------------------
TEST(MultTest, MultEvaluationNonZero) {
    Op* a = new Op(4.321);
    Op* b = new Op(2.231);

    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->evaluate(), 9.640151);
    EXPECT_EQ(test->stringify(), "4.321000 * 2.231000");
}
TEST(MultTest, MultEvaluationZero) {
    Op* a = new Op(2.313);
    Op* b = new Op(0.00);

    Mult* test = new Mult(a,b);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "2.313000 * 0.000000");
}
TEST(MultTest, MultEvaluationNeg) {
    Op* a = new Op(5.45);
    Op* b = new Op(-2.343);

    Mult* test = new Mult(a,b);
    EXPECT_NEAR(test->evaluate(), -12.76935, 0.0001);
    EXPECT_EQ(test->stringify(), "5.450000 * -2.343000");
}
TEST(MultTest, MultEvaluationAdd) {
    Op* a = new Op(3.25);
    Op* b = new Op(4.222);
    Op* c = new Op(2.22222);
    
    Add* child = new Add(a,b);
    Mult* test = new Mult(child,c);
    EXPECT_NEAR(test->evaluate(), 16.60442784, 0.000001);
    EXPECT_EQ(test->stringify(), "7.472000 * 2.222220");
}
//------------------Div------------------
TEST(DivTest, DivEvaluationNonZero) {
    Op* a = new Op(6.321);
    Op* b = new Op(2.345);

    Div* test = new Div(a,b);
    EXPECT_NEAR(test->evaluate(), 2.69552238806, 0.000001);
    EXPECT_EQ(test->stringify(), "6.321000 / 2.345000");
}
TEST(DivTest, DivEvaluationUndefined) {
    Op* a = new Op(4.3222);
    Op* b = new Op(0);

    Div* test = new Div(a,b);
    EXPECT_THROW(test->evaluate(), runtime_error);
    EXPECT_EQ(test->stringify(), "4.322200 / 0.000000");
}
TEST(DivTest, DivEvaluationNeg) {
    Op* a = new Op(8.545);
    Op* b = new Op(-2.43);

    Div* test = new Div(a,b);
    EXPECT_NEAR(test->evaluate(), -3.51646090535, 0.000001);
    EXPECT_EQ(test->stringify(), "8.545000 / -2.430000");
}
TEST(DivTest, DivEvaluationZero) {
    Op* a = new Op(0);
    Op* b = new Op(2.43);

    Div* test = new Div(a,b);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ(test->stringify(), "0.000000 / 2.430000");
}
TEST(DivTest, DivEvaluationPow) {
    Op* a = new Op(2.30);
    Op* b = new Op(4.233);
    Op* c = new Op(2.895);

    Pow* child = new Pow(a,b);
    Div* test = new Div(child,c);
    EXPECT_NEAR(test->evaluate(), 11.736682, 0.000001);
    EXPECT_EQ(test->stringify(), "33.977696 / 2.895000");
}
//------------------ADD------------------
TEST(AddTest, AddEvaluateNonZero) {
    Op* a = new Op(2.466);
    Op* b = new Op(3.98722);
    
    Add* test = new Add(a,b);
    EXPECT_EQ(test->evaluate(), 6.45322);
    EXPECT_EQ("2.466000 + 3.987220", test->stringify());
}
TEST(AddTest, AddEvaluateZero) {
    Op* a = new Op(0.00000);
    Op* b = new Op(0.00);

    Add* test = new Add(a,b);
    EXPECT_EQ(test->evaluate(), 0);
    EXPECT_EQ("0.000000 + 0.000000", test->stringify());
}
TEST(AddTest, AddEvaluateNeg) {
    Op* a = new Op(5.244);
    Op* b = new Op(-20.2);

    Add* test = new Add(a,b);
    EXPECT_EQ(test->evaluate(), -14.956);
    EXPECT_EQ("5.244000 + -20.200000", test->stringify());
}

TEST(AddTest, AddEvaluateOpSub) {
    Op* a = new Op(22.67);
    Op* b = new Op(19.233);
    Op* c = new Op(2.44);

    Sub* child = new Sub(a,b);
    Add* test = new Add(child,c);
    EXPECT_NEAR(test->evaluate(), 5.877, 0.000001);
    EXPECT_EQ("3.437000 + 2.440000", test->stringify());
}


//------------------POW------------------
TEST(PowTest, PowEvaluateNonZero) {
    Op* a = new Op(2.14);
    Op* b = new Op(3.5222);
    Pow* test = new Pow(a, b);
    EXPECT_NEAR(test->evaluate(), 14.58086847543, 0.000001);
    EXPECT_EQ("2.140000 ** 3.522200", test->stringify());
}
TEST(PowTest, PowEvaluateNeg) {
    Op* a = new Op(2);
    Op* b = new Op(-2);

    Pow* test = new Pow(a,b);
    EXPECT_EQ(test->evaluate(), 0.25);
    EXPECT_EQ("2.000000 ** -2.000000", test->stringify());
}
TEST(PowTest, PowEvaluateZero) {
    Op* a = new Op(3);
    Op* b = new Op(0);

    Pow* test = new Pow(a,b);
    EXPECT_EQ(test->evaluate(), 1);
    EXPECT_EQ("3.000000 ** 0.000000", test->stringify());
}
TEST(PowTest, PowEvaluateMult) {
    Op* a = new Op(6.533);
    Op* b = new Op(2.3433);
    Op* c = new Op(3.543);

    Mult* child = new Mult(a,b);
    Pow* test = new Pow(child,c);
    EXPECT_NEAR(test->evaluate(), 15784.992, 0.001);
    EXPECT_EQ(test->stringify(), "15.308779 ** 3.543000");
}
//------------------SUB------------------
TEST(SubTest, SubEvaluateNonZero) {
    Op* a = new Op(4.323);
    Op* b = new Op(2.4433);
    Sub* test = new Sub(a, b);
    EXPECT_NEAR(test->evaluate(), 1.8797, 0.000001);
    EXPECT_EQ("4.323000 - 2.443300", test->stringify());
}
TEST(SubTest, SubEvaluateNeg) {
    Op* a = new Op(2.99822);
    Op* b = new Op(4.239384);

    Sub* test = new Sub(a,b);
    EXPECT_NEAR(test->evaluate(),-1.241164, 0.000001);
    EXPECT_EQ("2.998220 - 4.239384", test->stringify());
}
TEST(SubTest, SubEvaluateZero) {
    Op* a = new Op(4);
    Op* b = new Op(4);

    Sub* test = new Sub(a,b);
    EXPECT_EQ(test->evaluate(),0);
    EXPECT_EQ("4.000000 - 4.000000", test->stringify());
}
TEST(SubTest, SubEvaluateDiv) {
    Op* a = new Op(10.3);
    Op* b = new Op(5.243);
    Op* c = new Op(1.95);

    Div* child = new Div(a,b);
    Sub* test = new Sub(child, c);
    EXPECT_NEAR(test->evaluate(), 0.014524, 0.000001); 
    EXPECT_EQ(test->stringify(), "1.964524 - 1.950000");
}

#endif __OP_TEST_HPP__
