//var 10
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

int main(){
    int A;
    int n = 0;
    for (int a = 3; a < 100000; a++)
    {
        A = a;
        while (A >= 4)
        {
            if (A % 10 == 4 || A % 100 == 13)
            {
                n++;
                break;
            }
            A /= 10;
        }
    }
    cout << n;
    return 0;
}