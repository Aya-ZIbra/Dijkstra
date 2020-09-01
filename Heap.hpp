
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
    std::cout<< "address of container_ = " << &container_ << std::endl;
    std::cout<< "address of items = " << &items << std::endl;
}

/** 3 steps for template function
1- add template <class T>
2- put <T> after class name to indicate the T version of the class 
3- put T to replace intended variable type everywhere
*/
template <class T>
T Heap<T>::extractMin(){
    return container_[0];
}

template<class T>
void Heap<T>::insert(T item){
    // add item to end of vector
    container_.push_back(item);
    std::cout << "Item added" << std::endl;
    // heapify up
    int idx = _getLastIdx();
    _heapifyUp(idx);
}

template <typename T>
void Heap<T>::_heapifyUp(int idx){
    int idxParent = _getParentIdx(idx);
    while (idx > 0  && container_[idx] < container_[idxParent]){
        _swap (idx, idxParent);
        idx = idxParent;
        idxParent = _getParentIdx(idx);
    }
}


template <typename T>
void Heap<T>::_swap(int idx, int idxParent){
    T temp = container_[idx];
    container_[idx] = container_[idxParent]; 
    container_[idxParent] = temp;

    // map [container_[idx]] = idx
}

template <typename T>
int Heap<T>::_getLastIdx(){
    return container_.size()-1;
}

template <typename T>
std::ostream& Heap<T>::print(std::ostream& os){
    for(T item: container_){
        os << item << ", " ;
    }
    return os;
}
/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const Heap<T>& myHeap){
    myHeap.print(os);
    return os;
}*/


