#include <stdio.h>

struct student
{
    char name[20];
    int age;
    int roll_no;
    float marks;
};

void print(char name[], int age, int roll_no, float marks)
{
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Roll No: %d\n", roll_no);
    printf("Marks: %.2f\n", marks);
}

int main()
{
    struct student s1 = {"John", 20, 101, 85.5};
    print(s1.name, s1.age, s1.roll_no, s1.marks);
    return 0;
}
