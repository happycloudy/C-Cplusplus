//Var 8
#include <iostream>
#include <cstring>
#include <iomanip>

#include <cstdlib>
#include <fstream>
#include "shoes.h"
#include "sneakers.h"
#define N 10
using namespace std;
#include "read.h"
#include "output.h"



int main() 
{ 
    Shoes shoeses[N];
    Read(shoeses);
    Output(shoeses);
    Shoes shoesesCopy[N];
    for (int i = 0; i < N; i++)
    {
        shoesesCopy[i] = shoeses[i];
    }
    // сout << endl << "Now will be copy of main array" << endl;
    Output(shoesesCopy);
    return 0;
}