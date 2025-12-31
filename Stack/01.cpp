#include <iostream>
using namespace std;


class Stack{
  public:
  int top;
  int *arr;
  int  size;

  // signature..
  Stack(int size){
    arr = new int[size];
    this->size = size;
    top = -1;
  }

  // behaviour ...
  void push(int data){
    if(size - top > 1 ){
      top++;
      arr[top] = data;
    }
    else{
      cout <<"Stack overflow" <<endl;
    }
  }

  void pop(){
    if(top == -1){
      cout <<"Stack is underflow"<<endl;
    }
    else{
      top--;
    }
  }

  int getTop(){
    if(top == -1){
      cout <<"There is no element in stack "<<endl;
      return -1;
    }
    else{
      return arr[top];
    }
  }

  int getSize(){
    return top+1;
  }

  bool isEmpty(){
    if(top == -1){
      return true;
    }
    else{
      return false;
    }
  }

};


int main() {
  Stack s(4);
  s.push(10);
  s.push(20);
  s.push(30);

  while(!s.isEmpty()){
    cout << s.getTop() <<" ";
    s.pop();
  }
  return 0;
}