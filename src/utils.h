#include "event_manager.h"
#include <stdio.h>
void clear_screen();
void menu();
void wait_command();
int read_data(FILE* file_ptr, Event* event);
void write_data(FILE* file_ptr, Event event);
void delete_data(FILE* file_ptr, int id);
void change_data(FILE* file_ptr, int id, Event new_event);