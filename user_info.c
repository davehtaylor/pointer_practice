#include <stdio.h>

typedef struct {
    int age;
    int birthdate;
} User;

void 
swap_nums(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void 
User_set_age(User *user, int age)
{
    user->age = age;
}

void 
User_set_birthdate(User *user, int birthdate)
{
    user->birthdate = birthdate;
}

int 
User_get_age(User *user)
{
    return user->age;
}

int 
User_get_birthdate(User *user)
{
    return user->birthdate;
}

void 
User_swap_vals(User *user)
{
    swap_nums(&user->age, &user->birthdate);
}

int 
main(void)
{
    User user1;
    int temp;

    printf("Please enter your age: ");
    scanf(" %d", &temp);
    User_set_age(&user1, temp);

    printf("Please enter the day of the month you were born: ");
    scanf(" %d", &temp);
    User_set_birthdate(&user1, temp);

    printf("Ok, let's swap them.\n");
    User_swap_vals(&user1);

    printf("Your age is %d and the date you were born is %d.\n",
            User_get_age(&user1), User_get_birthdate(&user1));

    return 0;
}
