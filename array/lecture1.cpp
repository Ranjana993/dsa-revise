// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <climits>


void print(int arr[] , int size){
    for(int i = 0 ; i < size ; i++){
        cout <<arr[i]<< " ";
    }
    cout <<endl;
}


int linearSearch(int arr[] , int size , int k){
    for(int i = 0 ; i< size;i++ ){
        if(arr[i] == k){
            return arr[i];
            break;
        }
    }
    return -1;
}

void count01(int arr[] , int size){
    int  count0 = 0;
    int count1 = 0;
    for(int i = 0 ; i< size ; i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i] == 1){
            count1++;
        }
    }
    cout <<"The number of 0s is : " << count0<< " the number of 1s is :"<<count1<< endl;
}

int findMax(int arr[] , int size){
    int maxi = INT_MIN ;
    for(int i = 0 ; i< size ; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}

int findMin(int arr[] , int size){
    int mini = INT_MAX;
    for(int i = 0 ; i< size ; i++){
        if(arr[i] < mini){
            mini= arr[i];
        }
    }
    return mini;
}

void extremePrint(int arr[] , int size){
    int start = 0 , end = size-1;
    while(start<=end){
        if(start==end){
            cout <<arr[start] <<" ";
        }
        else{
            cout<<arr[start]<<" " << arr[end] <<" ";
        }
        
        start++;
        end--;
    }
}

void reverseArray(int arr[] , int size){
    int start = 0 , end= size -1;
    while(start <= end){
        swap(arr[start] ,arr[end]);
        start++;
        end--;
    }
}

int main() {
  //! printing array...
    // int arr[] = {1,2,3,4,5,6};
    // int size = 6;
    // print(arr , 6);
    // cout << "Ans found :"  << linearSearch(arr , size , 8);
    
    //! count 0s ,s and 1s ...
    // int arr[] = {0,0,0,0,0,1,1,1,1,0};
    // int size = 10;
    // count01(arr , size);
    
    //! maximum number in an array.....
    // int arr[] = {2,3,1,8,5,9,4,6};
    // int size = 8;
    // cout << "The maximum number is : " <<findMax(arr , size) <<endl;
    // cout <<"The minimum nunberis : "<< findMin(arr , size) <<endl;
    
    int arr [] = {10,20,30,40,50,60,70 ,80};
    int size = 8;
    extremePrint(arr , size);
    cout <<endl;
    reverseArray(arr , size);
    print(arr , size);
    
    
    return 0;
}