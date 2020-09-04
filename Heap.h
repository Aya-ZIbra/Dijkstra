
/**
 * A simple Heap class.
 * 
 * @author
 *   Aya Zaki Ibrahim <aya.zaki.2012@gmail.com>
 */

/* supported operation
- extractMin
- removeMin
- insert(key)
- delete(key)
- decreaseKey(key)
*/
#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename T>
class Heap{  // no brackets after class name
    public:
        // if no constructor is present, we have an automatic default constructor
        // automatic default constructor initializes all member variables to their default values.

        Heap(); // custom default constructor: default = takes no arguments / custom = overrides default
        Heap(std::vector<T>& items); // custom non-default constructor
        T extractMin();
        void removeMin();
        void buildHeap();
        void insert(T);
        std::ostream& print(std::ostream&);

    private: 
        // Naming convention of private members
        // variables use _ after their name
        // functions use _ befor their name
        int capacity_;
        std::vector<T> container_;

        int _getLastIdx();
        void _heapifyUp(int);
        void _heapifyDn(int);
        void _swap(int, int);
        bool _isLeaf(const int);
        int _getLeftChildIdx(const int idx);
        int _getRightChildIdx(const int idx);

        static int _getParentIdx(const int idx){
            /* 1 : 2, 3
            2: 4, 5
            3: 6, 7
            parent = idx/2

            zero indexed : (idx+1)/2 -1 = (idx-1)/2
            */
            return (idx-1)/2;
            }


}; // notice the ; after class definition 

//template <typename T>
//std::ostream& operator<<(std::ostream&, const Heap<T>&);

// for template class, declarations are not enough. 
// Function implementations need to be included 
// the implementations will be compiled within the client cpp file. No compilation is done to the hpp files.

#include "Heap.hpp"
#endif