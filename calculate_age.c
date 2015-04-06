#include <stdio.h>
#include <time.h>

typedef struct {
    time_t birthdate;
    int age;
} User;

time_t User_get_birthdate(User *user)
{
    return user->birthdate;
}

int User_get_age(User *user)
{
    return user->age;
}

void User_set_birthdate(User *user, int mm, int dd, int yyyy)
{
    struct tm time_info;
    time_t epoch_time;

    time_info.tm_mon = mm - 1;
    time_info.tm_mday = dd;
    time_info.tm_year = yyyy - 1900;
    time_info.tm_hour = 0;
    time_info.tm_min = 0;
    time_info.tm_sec = 0;
    time_info.tm_isdst = -1;

    epoch_time = mktime(&time_info);
    user->birthdate = epoch_time;
}

void User_set_age(User *user, time_t birthdate)
{
    time_t now = time(NULL); 
    time_t difference_in_time = now - birthdate;
    int age = difference_in_time / 31536000;
    
    user->age = age;
}

int main(void)
{
    User user1;
    int mm, dd, yyyy;

    printf("Please enter your birthdate, in the format MM-DD-YYYY: ");
    scanf(" %d-%d-%d", &mm, &dd, &yyyy);
    User_set_birthdate(&user1, mm, dd, yyyy); 

    time_t birthdate = User_get_birthdate(&user1);
    User_set_age(&user1, birthdate);

    printf("You are %d years old.\n", User_get_age(&user1));

    return 0;
}
