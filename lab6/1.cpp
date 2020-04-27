//var 10
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
#define N 3
#define A -10
#define B 10

void setArr(int arr[]){
    for (int i = 0; i < N; i++)
    {
        arr[i] = A + rand() % (B - A + 1);
        cout << arr[i] << " ";
    }
}



int MoreThanNumb(int arr[],int C){
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if(arr[i]>C) count++;
    }
    return count;
}

int main() 
{ 
    int arr[N];
    int C;
    srand(time(0));
    setArr(arr);
    
    cout << endl <<"Введите С " << endl ;
    cin >> C;
    int count =MoreThanNumb(arr,C);
    cout << "More Than C = " << count << endl; 
    
    int index = 0;
    int max = 0; 
    for (int i = 0; i < N; i++)
    {
        if (abs(max) < abs(arr[i]))
        {
            max = arr[i];
            index = i;
        }
    }
    int proizv = 1;
    for (int i = index + 1; i < N; i++)
    {
        proizv *= arr[i];
    }
    cout << "Произведение чисел после максимального элемента = " << proizv;

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            int t = arr[i];
            for (int j = i; j < N-1; ++j)
            {
                arr[j] = arr[j + 1];
            }
            arr[N-1] = t;
        }
    }
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";   
    }
    
    return 0;
}