#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

int main(){
    int a, b, c;
    int ind = 0, len = 0, arg[3];
    char symb, str[MAXSIZE];
    
    // scanf("%s",str);
    // len = strlen(str);
    // printf("%s",str);

    while(1){
        scanf("%s",str);
        arg[ind] = strtol(str,NULL,10);
        printf("%ld\n",arg[ind]); 
        ind++;

        if(ind >= 3){     
            break;
        }
    }

    return 0;
}
