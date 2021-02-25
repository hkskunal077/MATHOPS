#include<iostream>
#include "mathops.h"

//add two numbers
int add(int a, int b){return a+b;}

//make a number negative
int negative(int a){return -1*a;}

//subtract two numbers
int subtract(int a, int b){return add(a, negative(b));}

//multiply two numbers
int multiply(int a, int b){
    int answer = 0;
    for(int j =0;j<b;j++)
    answer = add(answer, a);
    return answer;
}

//divide two numbers
int divide (int a, int b){
    int counter = 0;
    int temp = a;
    while(temp>=b && b!=0){
        temp = subtract(temp, b);
        counter = add(counter, 1);
    }return counter;
}

//find modulus of a number with respect to another number
int mod(int a, int b){
    int temp = a;
    while (temp>=b && b!=0){
        temp = subtract(temp, b);
    }
    return temp;
}

//find power of a number with respect to another number
int power (int a, int b) {
    int answer = 1;
    for(int j = 0; j<b; j++){
        answer = multiply(answer, a);
    }return answer;
}

//find bth root of a
int root (int a, int b){
    int temp = a;
    int counter = 0;
    while(temp>=b && b!=0){
        temp = divide(temp, b);
        counter = add(counter, 1);
    }return counter;
}

//check if a number is prime or not
bool isPrime(int a){
    bool flag = true;
    for(int j = 2; j<divide(a, 2); j++){
        if(mod(a, j) == 0) {flag = false; break;}
    }
    return flag;
}

//calculate factorial of a number
int factorial(int a){
    int answer = 1;
    for(int j=a; j>0; j--){
        answer = multiply(answer, j);
    }
    return answer;
}

//find log of a with base base
int log(int a, int base){
    for(int j=0; j<a; j++){
        if (power(base, j) > a){
            return subtract(j, 1);
        }

    }
}

//convert a number into string data type, can be used for string formatting
string stringify(int num){
    string outputStr ="";
    int num_length = add(log(num, 10), 1);
    int temp = num;
    for(int j = num_length-1; j>=0; j--){
        int currentNum = divide(temp, power(10, j));
        cout<<"Current Num "<<currentNum<<" temp "<<temp<<"\n";
        temp = mod(temp, power(10, j));
        outputStr = outputStr + (char)(currentNum+48);w
    }return outputStr;
}

//convert a string into a number, useful when data to be read from a file
int numberfy (string str) {
    int answer = 0;
    for(int j=0; j<str.length(); j++){
        int digit = (int)(str[j]-48)*power(10, (str.length()-j-1));
        answer = answer + digit;
    }return answer;
}