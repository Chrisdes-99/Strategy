#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"

class Sub : public Base {
    private:
        Base* left = nullptr;
        Base* right = nullptr;

    public:
        Sub(Base* left_child, Base* right_child) {this->left = left_child; this->right = right_child; }
        virtual double evaluate() { return left->evaluate() - right->evaluate(); }
        virtual std::string stringify() { return std::to_string(left->evaluate()) + " - " + std::to_string(right->evaluate()); }
};

#endif //__SUB_HPP__
