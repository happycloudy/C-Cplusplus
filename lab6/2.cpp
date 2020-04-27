//var 10
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
#define n 5

int main()
{
    int sign= -1, x = 1, y = 0;
    int **matrix{new int *[n]};

    
    for (int x = 0; x < n; x++)
        matrix[x] = new int[n]{};

    matrix[0][0] = 1;

    for (size_t val = 2; val <= n * n; ++val)
    {

        matrix[x][y] = val;

        if ((x + sign < 0 && y - sign >= 0 && y - sign < n) || x + sign >= n)
        {
            ++y;
            sign = -sign;
        }
        else if ((y - sign < 0 && x + sign >= 0) || y - sign >= n)
        {
            ++x;
            sign = -sign;
        }
        else
        {
            x += sign;
            y -= sign;
        }
    }

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            cout << matrix[x][y] << '\t';

        cout << '\n';
    }
    for (int x = 0; x < n; x++)
        delete[] matrix[x];

    delete[] matrix;

    return 0;
}