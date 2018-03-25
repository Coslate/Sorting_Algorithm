#include <iostream>
#include <cstdlib>
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

void Merge2(const int low, const int mid, const int high, int* S){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int *u = new int[(high - low + 1)]();

    while((i<=mid) && (j<=high)){
        if(S[i]<S[j]){
            u[k] = S[i];
            ++i;
        }else{
            u[k] = S[j];
            ++j;
        }
        ++k;
    }
    if(i > mid){
        MoveArray(S, u, (high - j + 1), k, j);
    }else{
        MoveArray(S, u, (mid - i + 1), k, i);
    }
    MoveArray(u, S, (high - low + 1), low, 0);

    delete [] u;
}

void MergeSort2(const int low, const int high, int* S){
    int mid;

    if(low < high){
        mid = floor((low+high)/2);
        MergeSort2(low, mid, S);
        MergeSort2(mid+1, high, S);
        Merge2(low, mid, high, S);
    }
}

int main(){
    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before MergeSort2---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");

    MergeSort2(0, n-1, a);
    std::cout<<"---after MergeSort2---"<<std::endl;
    PrintArray(n, a, "S");

    delete [] a;
    return EXIT_SUCCESS;
}
