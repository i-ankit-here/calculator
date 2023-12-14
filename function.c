#include "math.h"
#include "stdio.h"
#include "stdlib.h"
struct Data
{
    char expression[50];
    float result;
} data;
float x,y,result;
void sum()
{
    printf("Enter two numbers: ");
    scanf("%f %f", &x, &y);
    result = x + y;
    printf("%.2f + %.2f = %.2f\n",x,y,result);
    printf("\n");
}
void substraction()
{
    printf("Enter two numbers: ");
    scanf("%f %f", &x, &y);
    result = x - y;
    printf("%.2f - %.2f = %.2f\n",x,y,result);
    printf("\n");
}
void multiplication()
{
    printf("Enter two numbers: ");
    scanf("%f %f", &x, &y);
    result = x * y;
    printf("%.2f x %.2f = %.2f\n",x,y,result);
    printf("\n");
}
void division()
{
    printf("Enter the dividend and divisor: ");
    scanf("%f %f", &x, &y);
    if (y != 0)
    {
        result = x / y;
        printf("%.2f / %.2f = %.2f\n",x,y,result);
    }
    else
    {
        printf("Division by zero is not allowed.\n");
    }
    printf("\n");
}
void sqroot()
{
    printf("Enter a number: ");
    scanf("%f", &x);
    if (x >= 0)
    {
        result = sqrt(x);
        printf("square root of %.2f is %.2f\n",x,result);
    }
    else
    {
        printf("Invalid input for square root.\n");
    }
    printf("\n");
}
void exponent()
{
    printf("Enter base and exponent: ");
    scanf("%f %f", &x, &y);
    result = pow(x, y);
    printf("%.2f ^ %.2f = %.2f\n",x,y,result);
    printf("\n");
}
void trigno()
{
    printf("1. Sine\n2. Cosine\n3. Tangent\n4. Cotangent\n5. Secant\n6. Cosecant\nEnter your choice: ");
    int trigChoice;
    scanf("%d", &trigChoice);
    printf("Enter an angle in degrees: ");
    scanf("%f", &x);
    switch (trigChoice)
    {
    case 1:
        result = sin(x * M_PI / 180);
        printf("sin(%.2f) = %.2f\n",x,result);
        sprintf(data.expression,"sin(%.2f) = ",x);
        break;
    case 2:
        result = cos(x * M_PI / 180);
        sprintf(data.expression,"cos(%.2f) = ",x);
        printf("cos(%.2f) = %.2f\n",x,result);
        break;
    case 3:
        result = tan(x * M_PI / 180);
        printf("tan(%.2f) = %.2f\n",x,result);
        sprintf(data.expression,"tan(%.2f) = ",x);
        break;
    case 4:
        result = 1/(tan(x * M_PI / 180));
        printf("cot(%.2f) = %.2f\n",x,result);
        sprintf(data.expression,"cot(%.2f) = ",x);
        break;
    case 5:
        result = 1/(cos(x * M_PI / 180));
        printf("sec(%.2f) = %.2f\n",x,result);
        sprintf(data.expression,"sec(%.2f) = ",x);
        break;
    case 6:
        result = 1/sin((x * M_PI / 180));
        printf("cosec(%.2f) = %.2f\n",x,result);
        sprintf(data.expression,"cosec(%.2f) = ",x);
        break;
    default:
        printf("Invalid choice for trigonometric function.\n");
    printf("\n");
    }
}
void clearHistory()
{
    FILE *fpr;
    fpr=fopen("hist.dat","wb");
    if ( fpr == NULL )
    {
        puts("cannot open file") ;
        exit(1) ;
    }
    printf("\n\n*****HISTORY IS CLEARED*****\n\n");
    fclose(fpr);
}
void printHistory()
{
    FILE *fpr;
    fpr=fopen("hist.dat","rb");
    if ( fpr == NULL )
    {
        puts("cannot open file") ;
        exit(1) ;
    }
    int i=1;
    while(fread(&data, sizeof(data),1,fpr)==1)
    {
        printf("%d. %s%.2f\n",i,data.expression,data.result);
        i++;
    }
    fclose(fpr) ;
    printf("\n\n*** End Of History ***\n");
    printf("\n");
}
