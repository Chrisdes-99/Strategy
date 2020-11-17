#include "BubbleSort.hpp"

void BubbleSort::sort(Container* container) {
   auto i(0);
   auto j(0);
   for (; i < container->size()-1; i++) {
        for (; j < (container->size()-i-1); j++) {
            container->swap(j, j+1);
            //if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()) {
            //    container->swap(j, j+1);
            //}
        }

   }
    

};
