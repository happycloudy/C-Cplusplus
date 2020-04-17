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
    }while( (fabs(S1-S2))>Eps );
    

    FILE * file;
    file = fopen("output.txt", "w");
    fprintf(file,"площадь интеграла методом правых прямоугольников равна = %lf\n", S2);
    fclose(file);
};

void method_simpson(){
    double h,S1,S2;
    int n = 1;

    int A = -1;
    int B = 10;
    

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

    }while( (fabs(S1-S2))>Eps );


    FILE *file;
    file = fopen("output.txt", "a");
    fprintf(file,"площадь интеграла методом Симпсона равна = %lf\n", S2);
    fclose(file);
};

int main(){
    method_right_rectangle();
    method_simpson();
    return 0;
}