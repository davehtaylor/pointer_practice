#include <stdio.h>

struct user {
    char first_name[10];
    char last_name[10];
} user1;

void swap_names(char *, char *);

int main(void)
{
    printf("Please enter your first name: ");
    scanf(" %s", &user1.first_name);
    printf("Please enter your last name: ");
    scanf(" %s", &user1.last_name);
    printf("Ok, let's swap them.\n");

    swap_names(&user1.first_name, user1.last_name);

    printf("Now your name is %s %s.\n", user1.first_name, user1.last_name);
    return 0;
}

void swap_names(char *first, char *last)
{
    char temp[10];
    temp = *first;
    *first = *last;
    *last = temp;
}
