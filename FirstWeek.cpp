// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    //----- add of two numbers;
    // int a , b;
    // cout <<"Enter the value of a :";
    // cin>>a;
    // cout <<"Enter the value of b :";
    // cin >>b;
    // int sum = a+b;
    // cout <<"The sum of a and b is :" << sum <<endl;
    
    //---- Perimeter of triangle 
    // int side1 , side2 , side3;
    // cout <<"Enter the value of side 1:";
    // cin>>side1;
    // cout <<"Enter the value of side 2 :" ;
    // cin>>side2;
    // cout <<"Enter the value of side 3 :";
    // cin>>side3;
    // int perimeter = side1+side2+side3;
    // cout <<"The perimeter of triangle is " << perimeter<<endl;

// ------------find the simple interest ..
//  int principle , rate , year ;
//  cout <<"Enter the value of principle: ";
//  cin >> principle;
//  cout <<"Enter the rate of priniciple :" ;
//  cin >>rate;
//  cout <<"Enter the time of principle: ";
//  cin >>year;
//  int SI = (principle * rate *year)/100;
//  cout <<"Your S.I is :" <<SI<<endl;


// ----------Print the number till 1-N;
// int num;
// cout<<"Enter the number you want to print :";
// cin >>num;
// for(int i = 0 ; i < num ; i++){
//     cout <<i+1 <<endl; 
// }

// ---------Print the factorial of a number....
// int num , ans = 1;
// cout <<"Enter the number you want to do factorial: " ;
// cin >> num;
// for(int i = num ; i>0 ; i--){
//     ans =  i *ans;
// }
// cout << ans << endl;


// -----------------------Check if a number is prime or not..
// int num ;
// cout <<"Enter the number to check if it is prime or not: ";
// cin>>num;
// for(int i = 2 ;i < num ; i++){
//     if(num%i==0){
//         cout <<"Not prime";
//         break;
//     }
//     else{
//         cout <<"Prime";
//         break;
//     }
// }



// --check if a given triangle is valid or not...
// int side1 , side2 ,side3;
// cout <<"Enter the first side : ";
// cin>>side1;
// cout <<"Enter the second side : ";
// cin >>side2;
// cout <<"Enter the third side : ";
// cin >>side3;
// if(((side1+side2) >= side3) and ((side2+side3) >= side3) and ((side1 + side3) >= side2)){
//     cout<<"Yes it is a valid triangle ." ;
// }
// else{
//     cout <<"No, it is not a valid triangle.";
// }



// -------Print even number from 1-N;
// int n;
// cout << "Enter the number you want to print even number : ";
// cin >>n;
// for(int i = 0 ; i<n ; i++){
//     if(i%2 ==0){
//         cout<< i <<" " <<endl;
//     }
// }



// ----Print the largest number out of 3s.
// int num1 , num2 , num3;
// cout <<"Enter the first number : ";
// cin>>num1 ;
// cout <<"Enter the second number: ";
// cin>>num2 ;
// cout <<"Enter the third number : ";
// cin >>num3;

// if((num1 > num2) and (num1 > num3)){
//     cout <<"First number is the largest number : "<<num1 ;
// }
// else if(num2 > num3){
//     cout <<"Number 2 is the largest number : " <<num2 <<endl;
// }
// else{
//     cout <<"Third number is the largest number :"<<num3 <<endl;
// }




// PATTERNS ;
// Solid Square...
// int n ;
// cout <<"Enter the number you want to print the square : ";
// cin>>n;
// for(int i = 0 ; i< n; i++){
//     for(int j = 0 ; j < n ; j++){
//         cout <<" * ";
//     }
//     cout <<endl;
// }



// HOLLOW Square ...
// int n ;
// cout <<"Enter the number you want to print hollow square : ";
// cin >>n;
// for(int i = 0 ; i< n ;i++){
//     for(int j = 0 ; j < n ;j++){
//         if(i == 0 || i == n-1 || j==0 || j == n-1 ){
//             cout <<" * ";
//         }
//         else{
//          cout <<"   ";
//         }
//     }
//     cout <<endl;
// }


// -----INVERTED HOLLOW PYRAMID....
// int n;
// cout <<"Enter the value you want to print inverted hollow pyramid : ";
// cin >>n ;
// for(int i = 0 ; i < n ; i++){
//     for(int j = 0 ; j < n ; j++){
//         if(i == 0 || j ==0 || j == n -i-1){
//             cout <<" * ";
//         }
//         else{
//             cout <<"   ";
//         }
//     }
//     cout <<endl;
// }


// ----INVERTED HOLLOW FULL PYRAMID....
// int n ;
// cout <<"Enter the value you want to print the hollow full pyramid : ";
// cin>> n;
// for(int i = 0 ; i< n ;i++){
//     int k = 0;
//     for(int j = 0 ; j < 2 * n - 1 ; j++){
//         if(j < n-i-1){
//             cout <<" ";
//         }
//         else if( k < 2*i+1 ){
//             if(k ==0 || k == 2*i || i == n-1)
//                 cout <<"*";
//             else
//                 cout <<" ";
//             k++;
//         }
//         else{
//             cout <<" ";
//         }
//     }
//     cout <<endl;
// }


    return 0;
}