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

void Exchange(int &x, int &y){
    int tmp = 0;
    tmp = x;
    x = y;
    y = tmp;
}

void SelectionSort(const int low, const int high, int* S){
    for(int i=low;i<=high;++i){
        int smallest = i;
        for(int j=i+1;j<=high;++j){
            if(S[j]<S[smallest]){
                smallest = j;
            }
        }
        Exchange(S[i], S[smallest]);
    }
}

int main(){
    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before SelectionSort---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");
    SelectionSort(0, n-1, a);
    std::cout<<"---after SelectionSort---"<<std::endl;
    PrintArray(n, a, "S");

    delete [] a;
    return EXIT_SUCCESS;
}
