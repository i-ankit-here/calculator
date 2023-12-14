#include "function.c"
int choice;
int main()
{
    do
    {
        printf("\nScientific Calculator\n");
        printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        printf("5. Square Root\n6. Exponentiation\n7. Trigonometric Functions\n");
        printf("8. Show History\n9. Clear History\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");
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
            sum();
            sprintf(data.expression,"%.2f + %.2f = ",x,y);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 2:
            substraction();
            sprintf(data.expression,"%.2f - %.2f = ",x,y);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 3:
            multiplication();
            sprintf(data.expression,"%.2f x %.2f = ",x,y);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 4:
            division();
            sprintf(data.expression,"%.2f / %.2f = ",x,y);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 5:
            sqroot();
            sprintf(data.expression,"sqrt(%.2f) = ",x);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 6:
            exponent();
            sprintf(data.expression,"%.2f ^ %.2f = ",x,y);
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 7:
            trigno();
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 8:
            fclose(fp);
            printHistory();
            continue;
        case 9:
            fclose(fp);
            clearHistory();
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
