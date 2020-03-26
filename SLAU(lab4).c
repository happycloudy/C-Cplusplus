#include <stdio.h>
#include <time.h>
#include <math.h>
#define E 0.0001
#define N 5
#define M 6




void read_data(float a[N][M])
{
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf("file does not exists");
        exit(0);
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            fscanf(file, "%f", &a[i][j]);
        }   
    }
}

void print(float a[N]){

    FILE *file;
    file = fopen("answer_data.txt", "w");
    char ch[] = "abcde";
    for (int i = 0; i < N; i++){
        fprintf(file, "%c=%.10lf", ch[i], a[i]);
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void change(float x, float y){
    float t = x;
    x = y;
    y = t;
}

void method_Gauss()
{
    float a[N][M];
    read_data(a);
    int index;
    int count;
    int c = 1;
    while (c > 0){
        c = 0;
        for (int i = 0; i < N; i++){
            index = i;
            count = 0;
            while ((a[index][i] == 0) && (count < N)){
                index = (index + 1) % N;
                count++;
            }
            if (index != i){
                c = 1;
                for (int j = 0; j < M; j++){
                    change(a[i][j], a[index][j]);
                }
                    
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = M - 1; j >= 0; j--){
            a[i][j] /= a[i][i];
        }
            
        for (int k = i + 1; k < N; k++){
            for (int j = M - 1; j >= 0; j--){
                a[k][j] -= a[i][j] * a[k][i];
            }
        }
    }

    float b[M];
    for (int i = 0; i < N; i++){
        b[i] = a[i][N];
    }
        
    for (int i = N - 2; i >= 0; i--){
        for (int j = i + 1; j < N; j++){
            b[i] -= b[j] * a[i][j];
        }
    }
    print(b);
    read_data(a);
    printf("Gauss\n");
    double S;
    for (int i = 0; i < N; i++){
        S = 0;
        for (int j = 0; j < M - 1; j++){
            S += a[i][j] * b[j];
        }
        printf("S%d = %f\tAverage = %f \n", i, S, fabs(S - a[i][M - 1]));
    }
}

void method_Gauss_Zeidel()
{
    float a[N][M], old[N], new[N], err[N], max;
    int index;
    int count;
    int c = 1;
    read_data(a);
    while (c > 0){
        c = 0;
        for (int i = 0; i < N; i++){
            index = i;
            count = 0;
            while ((a[index][i] == 0) && (count < N)){
                index = (index + 1) % N;
                count++;
            }
            if (index != i){
                c = 1;
                for (int j = 0; j < M; j++)
                {
                    change(a[i][j], a[index][j]);
                }
            }
        }
    }
    do{
        for (int i = 0; i < N; i++){
            old[i] = new[i];
        }
        c = 0;
        for (int i = 0; i < N; i++){
            new[i] = a[i][M - 1];
            for (int j = 0; j < (M - 1); j++){
                if (i == j)
                    continue;
                new[i] -= (a[i][j] * new[j]);
            }
            new[i] /= a[i][i];
        }
        for (int i = 0; i < N; i++){
            err[i] = fabs((new[i] - old[i]) / new[i]);
            if (i == 0)
                max = err[i];
            else
                max = ((err[i - 1] < err[i]) ? err[i] : max);
        }
    } while (max > E);
    print(new);
    printf("Gauss_Zeidel\n");
    double S;
    for (int i = 0; i < N; i++){
        S = 0;
        for (int j = 0; j < M - 1; j++){
            S += a[i][j] * new[j];
        }
        printf("S%d = %f\tAverage = %f \n", i, S, fabs(S - a[i][M - 1]));
    }
}

int main(void){
    method_Gauss();
    method_Gauss_Zeidel();
    return 0;
}
