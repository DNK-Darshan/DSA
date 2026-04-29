#include <stdio.h>

int main(void)
{
    float salary, rate;
    int years;

    printf("Enter initial salary: ");
    scanf("%f", &salary);

    printf("Enter yearly increment (%%): ");
    scanf("%f", &rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    for (int i = 0; i < years; i++)
    {
        salary = salary + (salary * rate / 100);
    }

    printf("\nSalary after %d years = %.2f\n", years, salary);

    return 0;
}
