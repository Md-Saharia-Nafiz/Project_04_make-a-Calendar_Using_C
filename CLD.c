
#include <stdio.h>

#define true 1
#define false 0


int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; //Dates from every month have been included here.

char *month_names[] =
{
    " ",
    "\n\n\nJanuary",
    "\n\n\nFebruary",
    "\n\n\nMarch",
    "\n\n\nApril",
    "\n\n\nMay",      //Names of all the months are included here.
    "\n\n\nJune",
    "\n\n\nJuly",
    "\n\n\nAugust",
    "\n\n\nSeptember",
    "\n\n\nOctober",
    "\n\n\nNovember",
    "\n\n\nDecember",
};

int inputyear(void)
{
    int year;
    printf("Please enter a year (example: 2016): ");
    scanf("%d", &year);
    return year;
}

int determineleapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//Code to determine a leap year.
    {
        days_in_month[2] = 29;
        return true;
    }
    else
    {
        days_in_month[2] = 28;
        return false;
    }
}

int determinedaycode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;

    daycode = (year + d1 - d2 + d3) % 7;
    return daycode;
}

void calendar(int year, int daycode)
{
    int month, day;

    for (month = 1; month <= 12; month++)
    {
        printf("%s", month_names[month]);
        printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");//Code to check which day falls on a particular date.

        for (int i = 0; i < daycode; i++) // Print initial spaces.
        {
            printf("     ");
        }

        for (day = 1; day <= days_in_month[month]; day++)
        {
            printf("%3d  ", day);

            if ((day + daycode) % 7 == 0)
            {
                printf("\n");
            }
        }

        // Calculate daycode for next month
        daycode = (daycode + days_in_month[month]) % 7;
        printf("\n");
    }
}

int main(void)
{
    int year, daycode, leapyear;

    year = inputyear();
    leapyear = determineleapyear(year);
    daycode = determinedaycode(year);
    calendar(year, daycode);

    return 0;
}
