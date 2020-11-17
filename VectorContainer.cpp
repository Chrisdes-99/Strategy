#include "VectorContainer.hpp"
#include <vector>
#include "./Lab-04-Composite/op.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

void VectorContainer::add_element(Base *element){
     container.push_back(element);
}

void VectorContainer::print(){
     for(auto x: container){
        cout<<x->stringify()<<" "<<endl;
     }
}

void VectorContainer::sort(){
     if(sort_function != nullptr){
     this->sort_function->sort(this);
     }
     else {
     throw runtime_error("Sort function is empty");
      }
}

void VectorContainer::swap(int i,int j){
     auto temp = container.at(i);
     
     container.at(i) = j;
     container.at(j) = temp;
}

Base* VectorContainer::at(int i){
      return container.at(i);
}

int VectorContainer::size(){
    return container.size();
}

