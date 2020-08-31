
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

    private: 
        // Naming convention of private members
        // variables use _ after their name
        // functions use _ befor their name
        int capacity_;
        std::vector<T> container_;


}; // notice the ; after class definition 
#include "Heap.hpp"
#endif