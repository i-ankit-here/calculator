#include "stdio.h"
#include "math.h"
#include "function.c"
int choice;
int main()
{
    do
    {
        float x=0,y=0,result=0;
        printf("Scientific Calculator\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        printf("5. Square Root\n6. Exponentiation\n7. Trigonometric Functions\n");
        printf("8. Matrix Addition\n9. Matrix Substraction\n10. Matrix Multiplication\n11. Determinant Of a Matrix\n");
        printf("12. Show History\n13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        FILE *fp;
        fp=fopen("hist.dat","a");
        if ( fp == NULL )
        {
            puts( "cannot open file" ) ;
            exit( 1 ) ;
        }
        switch(choice)
        {
        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &x, &y);
            result = x + y;
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &x, &y);
            result = x - y;
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &x, &y);
            result = x * y;
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &x, &y);
            if (y != 0)
            {
                result = x / y;
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
            }
            else
            {
                printf("Division by zero is not allowed.\n");
                continue;
            }
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%f", &x);
            if (x >= 0)
            {
                result = sqrt(x);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
            }
            else
            {
                printf("Invalid input for square root.\n");
                continue;
            }
            break;
        case 6:
            printf("Enter base and exponent: ");
            scanf("%f %f", &x, &y);
            result = pow(x, y);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 7:
            printf("1. Sine\n2. Cosine\n3. Tangent\n4. Cotangent\n5. Secant\n6. Cosecant\nEnter your choice: ");
            int trigChoice;
            scanf("%d", &trigChoice);
            printf("Enter an angle in degrees: ");
            scanf("%f", &x);
            switch (trigChoice)
            {
            case 1:
                result = sin(x * M_PI / 180);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
                break;
            case 2:
                result = cos(x * M_PI / 180);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
                break;
            case 3:
                result = tan(x * M_PI / 180);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
                break;
            case 4:
                result = sin(x * M_PI / 180);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
                break;
            case 5:
                result = cos(x * M_PI / 180);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
                break;
            case 6:
                result = tan(x * M_PI / 180);
                data.result=result;
                fwrite(&data, sizeof(data),1,fp);
                fclose(fp);
                break;
            default:
                printf("Invalid choice for trigonometric function.\n");
                continue;
            }
            break;
        case 12:
            fclose(fp);
            printHistory();
            continue;
        case 0:
            printf("Exiting the calculator.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            continue;
        }


    }
    while(choice!=0);
}
