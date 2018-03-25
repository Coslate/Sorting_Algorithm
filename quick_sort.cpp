#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <string>
#include <math.h>

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

void Exchange(int &x, int &y){
    int tmp = 0;
    tmp = x;
    x = y;
    y = tmp;
}

void Partition(const int low, const int high, int &pivotpoint, int* S){
    int pivot = S[low];
    int j = low;

    for(int i = low+1;i<high+1;++i){
        if(S[i] < pivot){
            ++j;
            Exchange(S[i], S[j]);
        }   
    }
    pivotpoint = j;
    Exchange(S[low], S[j]);
}

void QuickSort(const int low, const int high, int* S){
    int pivotpoint = 0;

    if(low < high){
        Partition(low, high, pivotpoint, S);
        QuickSort(low, pivotpoint-1, S);
        QuickSort(pivotpoint+1, high, S);
    }
}

int main(){
    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before QuickSort---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");
    QuickSort(0, n-1, a);
    std::cout<<"---after QuickSort---"<<std::endl;
    PrintArray(n, a, "S");

    delete [] a;
    return EXIT_SUCCESS;
}
