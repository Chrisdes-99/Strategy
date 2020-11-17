#include "SelectionSort.hpp"

void SelectionSort::sort(Container* container){
     auto i(0);
     auto j(0);
     for(i = 0;i<container->size()-1;i++){
         for(j =0;j<(container->size()-i+1);j++ ){
             if(container->at(j)->evaluate() < container->at(j+1)->evaluate()){
             container->swap(j,j+1);
       
             }
          }
     }
};

