#ifndef EVENT_MANAGER
#define EVENT_MANAGER
typedef struct {
    int id;
    int year, month, day;
    char title[100];
    char description[255];
} Event;

void create_event(Event event);
void delete_event(Event event);
void read_event(Event event);
void change_event(Event event, Event new_event);
#endif // EVENT_MANAGER