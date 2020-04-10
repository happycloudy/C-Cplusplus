#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6
#define M 7
#define n 9

void read_data(double a[2][n])
{
    FILE *file;
    if ((file = fopen("input_data.txt", "r")) == NULL)
    {
        printf("error");
        exit(1);
    }
    for (int i = 0; i < 2; i++)
    {
        if (i == 0)
            printf("x");
        else
            printf("y");
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%lf", &a[i][j]);
            printf("%10.2lf", a[i][j]);
        }
        printf("\n");
    }
    fclose(file);
}

void method_Gauss(double a[N][M], double x[N])
{
    double tmp;
    int ind, count, check;
    check = 1;
    while (check > 0)
    {
        check = 0;
        for (int i = 0; i < N; i++)
        {
            ind = i;
            count = 0;
            while ((a[ind][i] == 0) && (count < N))
            {
                ind = (ind + 1) % N;
                count++;
            }
            if (ind != i)
            {
                check++;
                for (int j = 0; j < M; j++)
                {
                    tmp = a[i][j];
                    a[i][j] = a[ind][j];
                    a[ind][j] = tmp;
                }
            }
        }
    }

    double numb, numb1;
    for (int i = 0; i < N; i++)
    {
        numb = a[i][i];
        for (int j = 0; j < M; j++)
            a[i][j] /= numb;
        for (int k = i + 1; k < N; k++)
        {
            numb1 = a[k][i];
            for (int j = 0; j < M; j++)
            {
                a[k][j] += (numb1 * (-1) * a[i][j]);
                a[k][j] = (a[k][j] == 0) ? 0 : a[k][j];
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        x[i] = a[i][M - 1];
        for (int j = M - 2; j > i; j--)
        {
            x[i] -= (x[j] * a[i][j]);
        }
        x[i] /= a[i][i];
    }
    FILE*file;
    file = fopen("output.txt","w");
    
    printf("Метод Гауса\nКоэффиценты:\n");
    for (int i = 0; i < N; i++)
    {
        
        printf("a[%d]=%.4lf\n", i, x[i]);
    }
    fprintf(file,"%.4lf + %.4lf*x + %.4lf*x^2 + %.4lf*x^3 + %.4lf*x^4 + %.4lf*x^5", x[0],x[1],x[2],x[3],x[4],x[5]);
}

void method_mnk()
{
    double xy[2][n], mincheck, ytmp;
    read_data(xy);
    double arr[N][M] = {{0}};
    double x[N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            for (int k = 0; k < n; k++)
                arr[i][j] += pow(xy[0][k], i + j);
        for (int k = 0; k < n; k++)
            arr[i][N] += xy[1][k] * pow(xy[0][k], i);
    }
    method_Gauss(arr, x);
    mincheck = 0;
    printf("\nПроверка точек: \n");
    for (int i = 0; i < n; i++)
    {
        ytmp = 0;
        printf("x = %.2lf \t", xy[0][i]);
        for (int j = 0; j < N; j++)
            ytmp += pow(xy[0][i], j) * x[j];
        printf("y = %lf\n", ytmp);
        mincheck += pow((xy[1][i] - ytmp), 2);
    }
    printf("R = %.10lf \n", mincheck);
}

int main(void)
{
    method_mnk();
    return 0;
}