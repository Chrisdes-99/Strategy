#ifndef __POW_HPP__
#define __POW_HPP__

#include <cmath>
#include "base.hpp"
#include "op.hpp"

class Pow : public Base {
    private:
        Base* left = nullptr;
        Base* right = nullptr;

    public:
        Pow(Base* left_child, Base* right_child) {this->left = left_child; this->right = right_child; }
        virtual double evaluate() { return pow(left->evaluate(), right->evaluate()); }
        virtual std::string stringify() { return std::to_string(left->evaluate()) + " ** " + std::to_string(right->evaluate()); }
};

#endif //__POW_HPP__
