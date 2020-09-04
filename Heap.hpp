
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

template <class T>
void Heap<T>::removeMin(){
    swap(0, _getLastIdx());
    _heapifyDn(0);
}

template<class T>
void Heap<T>::buildHeap(){
    int idx = _getLastIdx();
    while (idx >= 0){
        _heapifyDn(idx);
        idx--;
    }

}


template<class T>
void Heap<T>::_heapifyDn(int i){
    std::cout << "[heapifyDn] node " << i << std::endl; 
    int idxL, idxR, idxMinChild;
    while(!_isLeaf(i)){
        idxL = _getLeftChildIdx(i);
        idxR = _getRightChildIdx(i);
        // since this is not leaf, there is at least a left child
        // if no right child
        if (idxR == -1)  {
            idxMinChild = idxL;
        }
        else if (container_[idxL]< container_[idxR]) { idxMinChild = idxL;}
        else { idxMinChild = idxR;}
        
        if (container_[i] > container_[idxMinChild]) {
            _swap(idxMinChild, i);
            i = idxMinChild;
        }else{
            return; //break ??
        }
        
    }
}

template <typename T>
bool Heap<T>::_isLeaf(const int i){
    if (_getLeftChildIdx(i) == -1 && _getRightChildIdx(i) == -1){
        return 1;
    } else {
        return 0;
    }
}

template <typename T>  // or template <class T> ???????
int Heap<T>::_getLeftChildIdx(const int idx){
    //(idx+1)*2-1 = idx*2 +1
    int childIdx = idx*2+1;
    if (childIdx <= _getLastIdx()){
        return childIdx;
    }
    else { 
        return -1;
    }
}

template <typename T>
int Heap<T>::_getRightChildIdx(const int idx){
    int childIdx = idx*2 + 2;
    if (childIdx <= _getLastIdx()){
        return childIdx;
    }
    else { 
        return -1;
    }
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
        os << item << " " ;
    }
    return os;
}
/*
template <typename T>
std::ostream& operator<<(std::ostream& os, const Heap<T>& myHeap){
    myHeap.print(os);
    return os;
}*/


