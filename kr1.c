//var 14, Mikolae Arion
#include <stdio.h>
#include <math.h>
#define Eps 1e-4


double funcRightRect(double x){
    return 1 / (5 - x);
}

double funcSimpson(double x){
    return sin(x)+2;
}


void method_right_rectangle(){
    double h,S1,S2;
    int n = 1;

    int A = 0;
    int B = 4;
    FILE * file;
    file = fopen("output.txt", "w");
    fprintf(file, "Функция f = 1 / (5 - x)\nПределы интегрирования: A = %d, B = %d\nE = %lf \nПодсчет площади методом правых прямоугольников...\n", A, B, Eps);
    do{
        h=(double)(B-A)/n;
        S1=0;

        for(int i=0; i < n; i++)
        {
            S1+=h*funcRightRect(A+(i+1)*h);
        }

        n*=2;
        S2=0;
        h=(double)(B-A)/n;
        
        for(int i=0;i<n;i++)
        {
            S2+=h*funcRightRect(A+(i+1)*h);
        }
        fprintf(file,"S1-S2 = %lf\tS1 = %lf\tS2 = %lf\th = %lf\tn = %d\n",S1-S2, S1, S2, h, n);
    }while( (fabs(S1-S2))>Eps );
    
    
    fprintf(file,"Интеграл равна = %lf\n\n\n", S2);
    fclose(file);
};

void method_simpson(){
    double h,S1,S2;
    int n = 2;

    int A = -1;
    int B = 10;
    
    FILE *file;
    file = fopen("output.txt", "a");
    fprintf(file, "Функция f = sin(x) + 2\nПределы интегрирования: A = %d, B = %d\nE = %lf \nПодсчет площади методом Симпсона...\n", A, B, Eps);

    do{
        h=(double)(B-A)/(2*n);
        S1=0;

        for(int i=0; i < n; i++)
        {
            S1+= (h/3)*(funcSimpson(A+(2*i*h)) + 4*(funcSimpson(A+h+(2*i*h))) + funcSimpson(A+(2*h) + (2*i*h)));
        }
        
        n*=2;
        S2=0;
        h=(double)(B-A)/(2*n);
        
        for(int i=0;i<n;i++)
        {
            S2+=(h/3)*(funcSimpson(A+(2*i*h)) + 4*(funcSimpson(A+h+(2*i*h))) + funcSimpson(A+(2*h) + (2*i*h)));
        }
        fprintf(file,"S1-S2 = %lf\tS1 = %lf\tS2 = %lf\th = %lf\tn = %d\n",S1-S2, S1, S2, h, n);
    }while( (fabs(S1-S2))>Eps );


    
    fprintf(file,"Интеграл равен = %lf\n", S2);
    fclose(file);
};

int main(){
    method_right_rectangle();
    method_simpson();
    return 0;
}