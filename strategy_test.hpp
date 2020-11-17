#ifndef __STRATEGYTEST_HPP__
#define __STRATEGYTEST_HPP__

#include <iostream>
#include "gtest/gtest.h"

#include "container.hpp"
#include "sort.hpp"
#include "ListContainer.hpp"
#include "BubbleSort.hpp"

#include "./Lab-04-Composite/add.hpp"
#include "./Lab-04-Composite/pow.hpp"
#include "./Lab-04-Composite/sub.hpp"
#include "./Lab-04-Composite/op.hpp"
#include "./Lab-04-Composite/rand.hpp"
#include "./Lab-04-Composite/mult.hpp"
#include "./Lab-04-Composite/div.hpp"

//=====SelectionSort+VectorContainer=====

//=====SelectionSort+ListContainer=====

//=====BubbleSort+VectorContainer=====

//=====BubbleSort+ListContainer=====
TEST(SortTestSet, BubbleSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    ListContainer* container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);

}

//=====VectorContainer=====

//=====ListContainer=====
TEST(ListTest, AddTest) {
    Op* seven = new Op(7);
    Op* nine = new Op(9);
    Add* TreeA = new Add(seven, nine);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(nine);
    test_container->add_element(TreeA);

    ASSERT_EQ(test_container->size(), 3);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 9);
    EXPECT_EQ(test_container->at(2)->evaluate(), 16);
}

TEST(ListTest, SwapTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);

    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    test_container->swap(0, 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 8);
}

TEST(ListTest, PrintTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    ListContainer* test = new ListContainer();

    test->add_element(seven);
    test->add_element(eight);

    ASSERT_EQ(test->size(), 2);
    cout << "Expected: " << "7.000000 " << "8.000000" << endl;
    cout << "PrintTest: ";
    test->print();
    cout << endl;
    //testing::internal::CaptureStdout();
    //std::cout << test->print();
    //std::string output = testing::internal::GetCapturedStdout();
}

TEST(ListTest, atTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);

    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container->at(1)->evaluate(), 8);
}

TEST(ListTest, sizeTest) {
    Op* seven = new Op(7);
    Op* eight = new Op(8);
    Op* nine = new Op(9);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);
    test_container->add_element(eight);
    test_container->add_element(nine);

    ASSERT_EQ(test_container->size(), 3);
}







#endif //_STRATEGYTEST_HPP__
