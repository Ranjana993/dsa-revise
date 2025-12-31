#include <iostream>
using namespace std;

class Stack
{
public:
  int *arr;
  int top1;
  int top2;
  int size;

  Stack(int size)
  {
    arr = new int[size];
    this->size = size;
    top1 = -1;
    top2 = size;
  }

  void push1(int data)
  {
    if (top2 - top1 <= 1)
    {
      cout << "Stack overflow" << endl;
    }
    else
    {
      top1++;
      arr[top1] = data;
    }
  }
  void pop1()
  {
    if (top1 == -1)
    {
      cout << "Stack underflow in stack 1" << endl;
    }
    else
    {
      top1--;
    }
  }

  void push2(int data)
  {
    if (top2 - top1 <= 1)
    {
      cout << "Stack overFlow " << endl;
    }
    else
    {
      top2--;
      arr[top2] = data;
    }
  }

  void pop2()
  {
    if (top2 == size)
    {
      cout << "Stack underflow in stack 2" << endl;
    }
    else
    {
      top2++;
    }
  }
  void print()
  {
    cout << endl;
    cout << "Top1: " << top1 << endl;
    cout << "Top2: " << top2 << endl;
    cout << "Array contents: ";

    for (int i = 0; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Stack st(6);

  st.push1(10);
  st.push1(20);
  st.push2(40);
  st.push2(50);
  st.push2(60);
  st.print();
  return 0;
}