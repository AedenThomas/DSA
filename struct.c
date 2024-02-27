#include <stdio.h>

struct student
{
    /* data */
    int roll;
    char name[20];
    float fees;
    char DOB[10];
};

int main()
{
    struct student s1, s2;

    scanf("%d", &s1.roll);
    scanf("%s", s1.name);
    scanf("%f", &s1.fees);
    scanf("%s", s1.DOB);

    scanf("%d", &s2.roll);
    scanf("%s", s2.name);
    scanf("%f", &s2.fees);
    scanf("%s", s2.DOB);

    printf("\nOutputting details\n");

    printf("\n%d", s1.roll);
    printf("\n%s", s1.name);
    printf("\n%0.2f", s1.fees);
    printf("\n%s", s1.DOB);

    printf("\n%d", s2.roll);
    printf("\n%s", s2.name);
    printf("\n%0.f", s2.fees);
    printf("\n%s", s2.DOB);
    


    printf("\n");
}