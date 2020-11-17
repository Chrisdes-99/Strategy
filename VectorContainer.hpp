#include <vector>
#include "container.hpp"
#include "sort.hpp"

using namespace std;
class VectorContainer:public Container {
    private:
    vector<Base*>container;

    public:

     void add_element(Base* element);
     void print();
     void sort();
     void swap(int i, int j);
     Base* at(int i);
     int size();
 };

