#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int testFunction(int x);
int testFunction2(int x);

int main(){
    /* Variable Pointer
    int test = 10;
    int *test2 = &test;
    cout << test << *test2 << endl;
    *test2 = 20;
    cout << test << *test2 << endl;
    */
    /* Function Pointer
    int (*testFunctionPointer)(int) = testFunction;
    cout << testFunctionPointer(4) << endl;
    */
    /* Function Array Pointer
    srand(time(NULL));
    int sum = 0;
    int (*testFunctionsPointer[])(int) = {testFunction, testFunction2};
    cout << testFunctionsPointer[0](4) << endl << testFunctionsPointer[1](4) << endl << testFunctionsPointer[rand()%2](rand()%9);
    */
    FILE *myFile = fopen("filename","w");

    struct myStruct {
        int age;
        int grade;
        char name[20];
    };

    typedef struct{
        int age;
        int grade;
        char name[20];
    } human;

    human myHuman = {11,5, "BOB BILLY"};
    myStruct test = {10,4, "BILLY BOB"};

    printf("Age:%d \nGrade:%d \nName:%s\n",myHuman.age,myHuman.grade,myHuman.name);
    printf("Age:%d \nGrade:%d \nName:%s\n",test.age,test.grade,test.name);
    cout << test.age << endl << test.grade << endl << test.name << endl;

    return 0;
}


int testFunction(int x){
    return x;
}
int testFunction2(int x){
    return x*2;
}
