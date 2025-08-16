#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int Discr(int arg[]);
void Solv(int arg[], int x1, int x2);

int main(){
    int ind = 0, arg[3]; //вспомогательная переменная и массив для хранения коэффициентов
    float x1, x2; //переменные для решений уравнения
    char symb, str[100]; //переменная и массив для ввода коэффициентов

    printf("Enter coefficients separated by space\n");
    
    while(1){ //цикл ввода коэффициентов
        scanf("%s",str);
        arg[ind] = strtol(str,NULL,10); 
        ind++;

        if(ind >= 3){     
            break;
        }
    }

    Solv(arg,x1,x2);
    
    return 0;
}



int Discr(int arg[]){ //расчет дискриминанта
            return arg[1]*arg[1] - 4*arg[0]*arg[2];
        }



void Solv(int arg[], int x1, int x2){

    if (arg[0] == 0){//проверка на нулевой коэффициент
        printf("It's not a square equation, enter correct coefficients");

    }else{
        if(Discr(arg) > 0){ //решения при дискриминанте >0
            x1 = (-arg[1] + sqrt(Discr(arg)))/(2*arg[0]);
            x2 = (-arg[1] - sqrt(Discr(arg)))/(2*arg[0]);
            printf("Solutions: %.2f %.2f \n",x1,x2);

        } else if (Discr(arg) == 0){ //решения при дискриминанте =0
            x1 = -arg[1]/(2*arg[0]);
            printf("Solution: %.2f \n",x1);

        } else{ //случай отсутствия решений
            printf("There is no rational solutions");

        }
    }
}
