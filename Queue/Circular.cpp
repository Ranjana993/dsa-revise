// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class cirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    
    cirQueue(int size){
        this->size =size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    // push.
    void push(int data){
        // condition 1:
        // agr queue full hai ..
        if(front == 0 && rear == size-1){
            cout <<"Queue is full ."<<endl;
        }
        //  condition 2: agr front aur rear -1 p hai ;
        if(front == -1){
            front = rear = 0;
            arr[rear] = data ;
        }
        
        // condition 3: agr front 0th p nhi hai aur rear size -1 p hai ..
        if(front != 0 && rear == size-1){
            rear = 0 ;
            arr[rear]= data;
        }
        // default case ...
        else{
            rear++;
            arr[rear] =data;
        }
        
    }
    
    
    // pop..
    
    void pop(){
        // consition 1: empty queue..
        if(front == -1){
            cout <<"Queue is empty ."<<endl;
        }
        // consition 2: single element ..
        else if(front == rear ){
            arr[front] = -1;
            front = rear = -1;
        }
        // condition 3: circular nature.
        if(front == size -1){
            front = 0;
        }
        // default contition :
        else{
            arr[front] = -1;
            front++;
        }
    }
};




int main() {
    cout << "Try programiz.pro";

    return 0;
}