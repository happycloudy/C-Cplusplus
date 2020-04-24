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
    double Height,Square1,Square2;
    int Numb = 1;

    int BottomLimit = 0;
    int TopLimit = 4;
    FILE * file;
    file = fopen("output.txt", "w");
    fprintf(file, "Функция f = 1 / (5 - x)\nПределы интегрирования: BottomLimit = %d, TopLimit = %d\nE = %lf \nПодсчет площади методом правых прямоугольников...\n", BottomLimit, TopLimit, Eps);
    do{
        Height=(double)(TopLimit-BottomLimit)/Numb;
        Square1=0;

        for(int i=0; i < Numb; i++)
        {
            Square1+=Height*funcRightRect(BottomLimit+(i+1)*Height);
        }

        Numb*=2;
        Square2=0;
        Height=(double)(TopLimit-BottomLimit)/Numb;
        
        for(int i=0;i < Numb;i++)
        {
            Square2+=Height*funcRightRect(BottomLimit+(i+1)*Height);
        }
        fprintf(file,"Square1-Square2 = %lf\tSquare1 = %lf\tSquare2 = %lf\tHeight = %lf\tn = %d\n",Square1-Square2, Square1, Square2, Height, Numb);
    }while( (fabs(Square1-Square2))>Eps );
    
    
    fprintf(file,"Интеграл равен = %lf\n\n\n", Square2);
    fclose(file);
};

void method_simpson(){
    double Height,Square1,Square2;
    int Numb = 2;

    int BottomLimit = -1;
    int TopLimit = 10;
    
    FILE *file;
    file = fopen("output.txt", "a");
    fprintf(file, "Функция f = sin(x) + 2\nПределы интегрирования: BottomLimit = %d, TopLimit = %d\nE = %lf \nПодсчет площади методом Симпсона...\n", BottomLimit, TopLimit, Eps);

    do{
        Height=(double)(TopLimit-BottomLimit)/(2*Numb);
        Square1=0;

        for(int i=0; i < Numb; i++)
        {
            Square1+= (Height/3)*(funcSimpson(BottomLimit+(2*i*Height)) + 4*(funcSimpson(BottomLimit+Height+(2*i*Height))) + funcSimpson(BottomLimit+(2*Height) + (2*i*Height)));
        }
        
        Numb*=2;
        Square2=0;
        Height=(double)(TopLimit-BottomLimit)/(2*Numb);
        
        for(int i=0;i<Numb;i++)
        {
            Square2+=(Height/3)*(funcSimpson(BottomLimit+(2*i*Height)) + 4*(funcSimpson(BottomLimit+Height+(2*i*Height))) + funcSimpson(BottomLimit+(2*Height) + (2*i*Height)));
        }
        fprintf(file,"Square1-Square2 = %lf\tSquare1 = %lf\tSquare2 = %lf\tHeight = %lf\tn = %d\n",Square1-Square2, Square1, Square2, Height, Numb);
    }while( (fabs(Square1-Square2))>Eps );


    
    fprintf(file,"Интеграл равен = %lf\n", Square2);
    fclose(file);
};

int main(){
    method_right_rectangle();
    method_simpson();
    return 0;
}