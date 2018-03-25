#include <iostream>
#include <cmath>
#include <linked_list.h>

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

int CalculateNDigit(const int num, const int nth){
    int tmp_mod_data = num%(int(pow(10, nth)));
    return(tmp_mod_data/(pow(10, (nth-1))));
}

void CountingSort(const int low, const int high, int* S, const int nth){
    int final_count = 0;

    LinkedList* list_of_k = new LinkedList[10];//number : 0-9
    for(int i=low;i<=high;++i){
        int key = CalculateNDigit(S[i], nth);
        list_of_k[key].InsertTail(S[i]);
    }

    for(int i=0;i<=9;++i){
        int size_of_the_list = list_of_k[i].GetListSize();
        if(size_of_the_list != 0){
            int* ret_data = new int[size_of_the_list]();
            list_of_k[i].GetAllData(ret_data);

            for(int j=0;j<size_of_the_list;++j){
                S[j+final_count] = ret_data[j];
            }
            final_count+=size_of_the_list;
            delete [] ret_data;
            list_of_k[i].CleanAll();
        }
    }    
    delete [] list_of_k;
}
void RadixSort(const int low, const int high, int* S){
    int k_value = S[low];
    int digit_value = 0;

    for(int i=low+1;i<=high;++i){
        if(S[i]>k_value){
            k_value = S[i];
        }
    }
    digit_value = log10(k_value);
    
    //CountingSort form 1 to digit_value
    for(int i=1;i<=digit_value+1;++i){
        CountingSort(low, high, S, i);
    }
}

int main(){
    const int n = 10;
    int *a = new int[n];

    //initialize random seed
    srand(time(NULL));

    std::cout<<"---before RadixSort---"<<std::endl;
    for(int i=0;i<n;++i){
        a[i] = rand()%1000+1;
    }
    PrintArray(n, a, "S");
    RadixSort(0, n-1, a);
    std::cout<<"---after RadixSort---"<<std::endl;
    PrintArray(n, a, "S");

    delete [] a;
    return EXIT_SUCCESS;
}
