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

void Merge(const int u_size, const int v_size, const int* u, const int* v, int* S){
    int index_u = 0;
    int index_v = 0;
    int index_s = 0;
    
    while((index_u <= (u_size-1)) && (index_v <= (v_size-1))){
        if(u[index_u] < v[index_v]){
            S[index_s] = u[index_u];
            ++index_u;
        }else{
            S[index_s] = v[index_v];
            ++index_v;
        }
        ++index_s;
    }
    if(index_u > (u_size-1)){
        MoveArray(v, S, (v_size - index_v), index_s, index_v);
    }else{
        MoveArray(u, S, (u_size - index_u), index_s, index_u);
    }
}

void MergeSort(const int n, int* S){
    int h = floor(n/2);
    int m = n - h;
    int *u = new int[h]();
    int *v = new int[m]();

    MoveArray(S, u, h, 0, 0);
    MoveArray(S, v, m, 0, h);

//    PrintArray(h, u, "u");
//    PrintArray(m, v, "v");
    if(n > 1){
        MergeSort(h, u);
        MergeSort(m, v);
    }
    Merge(h, m, u, v, S);

    delete [] u;
    delete [] v;
}

int main(){
    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before MergeSort---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");

    MergeSort(n, a);
    std::cout<<"---after MergeSort---"<<std::endl;
    PrintArray(n, a, "S");

    delete [] a;
    return EXIT_SUCCESS;
}
