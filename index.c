#include "function.c"
int choice;
int main()
{
    do
    {
        printf("Scientific Calculator\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        printf("5. Square Root\n6. Exponentiation\n7. Trigonometric Functions\n");
        printf("8. Show History\n0. Exit\n");
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
            sum();
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 2:
            substraction();
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 3:
            multiplication();
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 4:
            division();
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 5:
            sqroot();
            data.result=result;
            fwrite(&data, sizeof(data),1,fp);
            fclose(fp);
            break;
        case 6:
            exponent();
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
