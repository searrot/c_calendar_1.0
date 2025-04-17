#ifndef CALENDAR
#define CALENDAR

typedef struct {
    int eventdays[31];
} CalendarParameters;
#endif // CALENDAR
void show_calendar(int year, int month, CalendarParameters params);
int get_month_days_count(int year, int month);
int is_leap(int year);
void print_header(int year, int month);
