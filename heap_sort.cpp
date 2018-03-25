#include <iostream>
#include <cstdlib>
#include <string>
#include <MaxHeap.h>


Heap::Heap(const int size){
    heap_size = size;
    S = new int [heap_size]();
}

Heap::~Heap(){
    delete [] S;
}

void Heap::set_heap_size(const int size){
    heap_size = size;
}

void Heap::set_heap_full(const int size, const int* const S_in){
    delete [] S;

    heap_size = size;
    S = new int [heap_size]();
    for(int i = 0;i<heap_size;++i){
        S[i] = S_in[i];
    }
}

void Heap::set_heap_root(const int value){
    S[0] = value;
}

void Heap::set_heap_tail(const int value){
    S[heap_size-1] = value;
}

void Heap::set_heap_index(const int index, const int value){
    S[index] = value;
}

int Heap::get_heap_size(){
    return heap_size;
}

int* Heap::get_heap_full(){
    return S;
}

int Heap::get_heap_root(){
    return S[0];
}

int Heap::get_heap_tail(){
    return S[heap_size-1];
}

int Heap::get_heap_index(const int index){
    return S[index];
}
