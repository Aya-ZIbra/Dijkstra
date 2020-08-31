
#include <iostream>  // cout
#include "Heap.h"

// constructor implementation
template <class T>
Heap<T>::Heap(){
    std::cout<< "Heap data structure created" << std::endl;
}

template <class T>
Heap<T>::Heap(std::vector<T>& items){
    // Initialize the vector conatainer
    container_ = items;

}

/** 3 steps for template function
1- add template <class T>
2- put <T> after class name to indicate the T version of the class 
3- put T to replace intended variable type everywhere
*/
template <class T>
T Heap<T>::extractMin(){
    return container_[1];
}


