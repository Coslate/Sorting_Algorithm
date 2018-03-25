#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
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

void InsertionSort(const int low, const int high, int* S){
    for(int i = low+1;i<=high;++i){
        int value_to_insert = S[i];
        int j = i-1;
        while((j>=0) && (S[j]>value_to_insert)){
            S[j+1] = S[j];
            --j;
        }
        S[j+1] = value_to_insert;
    }
}

int main(){
    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before InsertionSort---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");
    InsertionSort(0, n-1, a);
    std::cout<<"---after InsertionSort---"<<std::endl;
    PrintArray(n, a, "S");

    delete [] a;
    return EXIT_SUCCESS;
}
