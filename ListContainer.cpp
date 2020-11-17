#include "ListContainer.hpp"
#include <list>
#include "./Lab-04-Composite/op.hpp"
#include <iostream>

using namespace std;
/*constructors*/

/*functions*/

void ListContainer::add_element(Base* element) {
    //l_container is our list
    l_container.push_back(element);
}

void ListContainer::print() {
 for (auto i: l_container) {
     cout << i->stringify() << " ";
 }

}

void ListContainer::sort() {
    int i = 0;
}

void ListContainer::swap(int i, int j) {
    //auto it1 = next(l_container.begin(), i);
    //auto it2 = next(l_container.begin(), j);
  
    list<Base*>::iterator it1 = l_container.begin();
    advance(it1, i);
    list<Base*>::iterator it2 = l_container.begin();
    advance(it2, j);
    
    iter_swap(it1, it2);

}

Base* ListContainer::at(int i) {
    auto it = next(l_container.begin(), i);
    return (*it);
}

int ListContainer::size() {
    return l_container.size();
}



