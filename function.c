#include "math.h"
#include "stdio.h"
#include "stdlib.h"
struct Data
{
    int result;
    int mat_result[][100];
};
struct Data data;
sum(){

}
substraction(){

}
multiplication(){

}
division(){

}
sqroot(){

}
exponent(){

}
tigno(){

}
mat_add(){

}
mat_sub(){

}
mat_mul(){

}
mat_det(){

}
printHistory()
{
    char ch;
    FILE *fpr;
    fpr=fopen("hist.dat","rb");
    if ( fpr == NULL )
    {
        puts("cannot open file") ;
        exit(1) ;
    }
    while(fread(&data, sizeof(data),1,fpr)==1)
    {
        int i;
        printf("%d. %d\n",i,data.result);
        i++;
    }
    printf("\n") ;
    fclose(fpr) ;
}
