/* This program takes in the user's birthdate. It converts it to epoch time
 * and stores it in a struct. Then, and function will be called to calculate
 * the user's age based on that birthdate. */

#include <stdio.h>
#include <time.h>

/* Define a struct for the user called User.  */
typedef struct {
    time_t birthdate;
} User;

/* Get birthdate from the struct. Take in the instantiated struct name.  */
time_t 
User_get_birthdate(User *user)
{
    return user->birthdate;
}

/* Set birthdate in the struct. Take in the instantiated struct name,
 * and the month, day and year that the user has entered.  */
void
User_set_birthdate(User *user, int mm, int dd, int yyyy)
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

/* Take the birthdate and use it to calculate the user's age.  */
int 
calculate_age(time_t birthdate)
{
    time_t now = time(NULL); 
    time_t difference_in_time = now - birthdate;
    int age = difference_in_time / 31536000;
    
    return age;
}

/* Instantiate the User struct and declare variables for the month, day
 * and year that the user will enter. Ask the user for that information,
 * set the birthdate, grab the birthdate from the struct and use that to
 * calculate the user's age. Then return that age to the user.  */
int 
main(void)
{
    User user1;
    int mm, dd, yyyy;

    printf("Please enter your birthdate, in the format MM-DD-YYYY: ");
    scanf(" %d-%d-%d", &mm, &dd, &yyyy);
    User_set_birthdate(&user1, mm, dd, yyyy); 

    time_t birthdate = User_get_birthdate(&user1);

    printf("You are %d years old.\n", calculate_age(birthdate));

    return 0;
}
