#ifndef __LISTCONTAINER_HPP__
#define __LISTCONTAINER_HPP__

#include <list>
#include "container.hpp"
using namespace std;

class ListContainer : public Container {
 private:
    list<Base*> l_container;

 public:
    /* Constructors */

    void add_element(Base* element);
    void print();
    void sort();

    void swap(int i, int j);
    Base* at(int i);
    int size();
};

#endif //__LISTCONTAINER_HPP__
