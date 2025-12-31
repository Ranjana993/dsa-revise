#include <iostream>
using namespace std;

class Queue{
  public:
  int *arr;
  int size;
  int front ;
  int rear;

  Queue(int size){
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  // push();
  void push(int data){
    if(rear == size){
      cout <<"Q is full . "<<endl;
    }
    arr[rear] = data;
    rear++;
  }

  // pop();
  void pop(){
    if(front == rear ){
      cout <<"Q is empty . "<<endl;
      return;
    }
    arr[front] = -1;
    front++;
    if(front == rear ){
      front = 0 ;
      rear = 0;
    }
  }


  // get size ;
  int getSize(){
    return rear - front;
  }

  // getFront ;
  int getFront(){
    if(front == rear){
      cout <<"Q is empty ." <<endl;
      return -1;
    }
    return arr[front];

  }
  


  // empty()
  bool isEmpty(){
    return rear == front;
  }
};

int main() {
  Queue q(10);
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  cout << "The front is : "<<q.getFront() <<endl;

  cout <<"The size of q is : "<<q.getSize() <<endl;
  q.pop();
  cout <<"The size of q is : "<<q.getSize() <<endl;

  if(q.isEmpty()){
    cout<<"Q is empty . "<<endl;
  }
  else{
    cout <<"Q is not empty . "<<endl;
  }




  return 0;
}