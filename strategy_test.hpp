#ifndef __STRATEGYTEST_HPP__
#define __STRATEGYTEST_HPP__

#include <iostream>
#include "gtest/gtest.h"

#include "container.hpp"
#include "ListContainer.hpp"

#include "./Lab-04-Composite/add.hpp"
#include "./Lab-04-Composite/pow.hpp"
#include "./Lab-04-Composite/sub.hpp"
#include "./Lab-04-Composite/op.hpp"
#include "./Lab-04-Composite/rand.hpp"
#include "./Lab-04-Composite/mult.hpp"
#include "./Lab-04-Composite/div.hpp"

TEST(ListTest, AddTest) {
    Op* seven = new Op(7);
    ListContainer* test_container = new ListContainer();

    test_container->add_element(seven);

    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
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
