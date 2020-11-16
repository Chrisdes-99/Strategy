#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>
#include "op.hpp"
#include <stdexcept>
using namespace std;

class Div : public Base {
    private:
        Base* left = nullptr;
        Base* right = nullptr;
    public:
        Div(Base* left_child, Base* right_child) {this->left = left_child; this->right = right_child; }
        virtual double evaluate() { if (right->evaluate() == 0) { throw runtime_error("Math error: Attempted to divide by zero"); } else {return left->evaluate() / right->evaluate(); }}
        virtual string stringify() { return to_string(left->evaluate()) + " / " + to_string(right->evaluate()); }
};

#endif //__DIV_HPP__
