#include <stdio.h>

double add(double num1, double num2)
{
    return num1 + num2;
}
double subtract(double num1, double num2)
{
    return num1 - num2;
}
double multiply(double num1, double num2)
{
    return num1 * num2;
}
double divide(double num1, double num2)
{
    if (num2 != 0)
    {
        return num1 / num2;
    }
    else
    {
        printf("Error: Division by zero is not allowed.\n");
        return 0.0;
    }
}
int main()
{
    int ch;
    double num1, num2, result;

    printf("Select any number to :\n1. Add(+) \n2. Substract(-) \n3. Multiply(*) \n4. Division(/)\n");
    while (1)
    {
        printf("Enter your choice for calculator : ");
        scanf("%d", &ch);
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);
        switch (ch)
        {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            result = divide(num1, num2);
            if (result != 0.0)
            {
                printf("Result: %.2lf\n", result);
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
        }
        printf("\nDo you want to continue: Press 1 for Continue & Press 0 for Exit\n");
        int choice;
        printf("Press (1/0) : ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            break;
        }
    }
    return 0;
}