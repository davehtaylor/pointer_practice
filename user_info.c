#include <stdio.h>

typedef struct {
    int age;
    int birthdate;
} User;

void swap_nums(int *, int *);
void User_add_age(User *, int);
void User_add_birthdate(User *, int);
int User_get_age(User *);
int User_get_birthdate(User *);

int main(void)
{
    User user1;
    int input_age;
    int input_birthdate;

    printf("Please enter your age: ");
    scanf(" %d", &input_age);
    User_add_age(&user1, input_age);
    printf("Please enter the day of the month you were born: ");
    scanf(" %d", &input_birthdate);
    User_add_birthdate(&user1, input_birthdate);
    printf("Ok, let's swap them.\n");

    swap_nums(&user1.age, &user1.birthdate);

    printf("Your age is %d and the date you were born is %d.\n",
            User_get_age(&user1), User_get_birthdate(&user1));
    return 0;
}

void swap_nums(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void User_add_age(User *user, int age)
{
    user->age = age;
}

void User_add_birthdate(User *user, int birthdate)
{
    user->birthdate = birthdate;
}

int User_get_age(User *user)
{
    int age = user->age;
    return age;
}

int User_get_birthdate(User *user)
{
    int birthdate = user->birthdate;
    return birthdate;
}
