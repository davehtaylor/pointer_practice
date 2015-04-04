#include <stdio.h>

typedef struct {
    int age;
    int birthdate;
} User;

void swap_nums(int *, int *);

int main(void)
{
    User user1;
    printf("Please enter your age: ");
    scanf(" %d", &user1.age);
    printf("Please enter the day of the month you were born : ");
    scanf(" %d", &user1.birthdate);
    printf("Ok, let's swap them.\n");

    swap_nums(&user1.age, &user1.birthdate);

    printf("Your age is %d and the date you were born is %d.\n",
            user1.age, user1.birthdate);
    return 0;
}

void swap_nums(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
