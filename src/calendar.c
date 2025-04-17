#include "calendar.h"
#include <stdio.h>

int get_month_days_count(int year, int month) {
    int count = 0;
    if (month == 2) {
        if (is_leap(year)) count = 29;
        else count = 28;
    }
    else if (month == 12) count = 31;
    else count = month % 2 == 1 ? 31 : 30;
    return count;
}

int is_leap(int year) {
    return year % 4 == 0 && ((year % 100 == 0 && year % 400 == 0) || year % 100 != 0);
}

int get_week_day(int year, int month, int day) {
    if (month == 1) {
        year--;
        month = 13;
    }
    else if (month == 2) {
        year--;
        month = 14;
    }
    int century = year / 100;
    int yearOfCentury = year % 100;
    int h = (day + (13 * (month + 1)) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century) % 7;
    h = h < 2 ? h + 6 : h - 1;
    return h;
}

void print_header(int year, int month) {
    printf("- - - -\n");
    printf("%d/%d\n", month, year);
    printf("- - - -\n");
    printf("ПН ВТ СР ЧТ ПТ СБ ВС\n");
}

void show_calendar(int year, int month, CalendarParameters params) {
    print_header(year, month);
    int week_day = get_week_day(year, month, 1);
    int day_count = get_month_days_count(year, month);
    int day_number = 1;
    int rows = day_count % 7 == 0 ? day_count / 7 : day_count / 7 + 1;
    rows += ((week_day + day_count) / 7 + ((week_day + day_count) % 7 > 0)) > rows ? 1 : 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 7 * i; j < (day_count - 7 * (i + 1) >= 0 ? 7 * (i + 1) : day_count); j++) {
            if (week_day != 1) {
                printf("   ");
                week_day--;
                day_count++;
            }
            else {
                if (params.eventdays[day_number - 1] == 1) {
                    printf(day_number >= 10 ? "\033[1;31m%d \033[0m" : "\033[1;31m %d \033[0m", day_number);
                } else printf(day_number >= 10 ? "%d " : " %d ", day_number);
                day_number++;
            } 
        }
        printf("\n");
    }
}