#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <math.h>
#include <MaxHeap.h>

void PrintArray(const int size, const int* arr, const std::string arr_name){
    std::cout<<arr_name<<" = [";
    for(int i=0;i<size;++i){
        if(i == 0){
            std::cout<<arr[i];
        }else if(i == size - 1){
            std::cout<<", "<<arr[i]<<"]"<<std::endl; 
        }else{
            std::cout<<", "<<arr[i];
        }
    }
}

void MoveArray(const int* from_arr, int* to_arr, const int to_size, const int to_begin_index, const int from_begin_index){
    int index = to_begin_index;
    for(int i=from_begin_index; i<from_begin_index+to_size; ++i){
        to_arr[index] = from_arr[i];
        ++index;
    }
}

void HeapSort_V01::SiftDown(Heap &H, const int index){
    int parent             = index;
    int sift_key           = H.get_heap_index(parent);
    int heap_size          = H.get_heap_size();
    int larger_child_index = 0;
    bool spot_found        = false;

    while(((parent*2+1) < heap_size) && (!spot_found)){
        if((parent*2+1) == (heap_size-1)){
            larger_child_index = parent*2 + 1;
        }else if ((parent*2+1) < (heap_size-1)){
            if(H.get_heap_index(parent*2+1) < H.get_heap_index(parent*2+2)){
                larger_child_index = parent*2+2;
            }else{
                larger_child_index = parent*2+1;
            }
        }
        if(sift_key < H.get_heap_index(larger_child_index)){
            H.set_heap_index(parent, H.get_heap_index(larger_child_index));
            parent = larger_child_index;
        }else{
            spot_found = true;
        }
    }
    H.set_heap_index(parent, sift_key);
}

void HeapSort_V01::MakeHeap(const int size, Heap &H){
    for(int i = (floor(size/2)-1); i>=0; --i){
        SiftDown(H, i);
    }
}

int HeapSort_V01::Root(Heap &H){
    int root_key = H.get_heap_root();
    H.set_heap_root(H.get_heap_tail());
    H.set_heap_size(H.get_heap_size() - 1);
    SiftDown(H, 0);
    return root_key;
}

void HeapSort_V01::RemoveKey(const int size, Heap &H){
    for(int i = size-1;i>=0;--i){
        H.set_heap_index(i, Root(H));
    }
    H.set_heap_size(size);
}

void HeapSort_V01::HeapSort(const int size, Heap &H){
    MakeHeap(size, H);
    RemoveKey(size, H);
}

int main(){
    const int n = 10;
    Heap H(n);

    std::cout<<"---H.S initialize---"<<std::endl;
    PrintArray(H.get_heap_size(), H.get_heap_full(), "H.S");

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before HeapSort---"<<std::endl;
    for(int i=0;i<n;++i){
        H.set_heap_index(i, rand()%1000+1);
    }
    PrintArray(H.get_heap_size(), H.get_heap_full(), "H.S");

    HeapSort_V01::HeapSort(n, H);
    std::cout<<"---after HeapSort---"<<std::endl;
    PrintArray(H.get_heap_size(), H.get_heap_full(), "H.S");
    return EXIT_SUCCESS;
}
