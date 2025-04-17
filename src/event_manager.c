#include "event_manager.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#define FILENAME "./data/data.txt"

void create_event(Event event) {
    FILE* file_ptr;
    file_ptr = fopen(FILENAME, "a+");
    if (file_ptr == NULL) {
        printf("Writing data error.");
    } else {
    write_data(file_ptr, event);
    fclose(file_ptr);
    }  
}

void delete_event(Event event) {
    FILE* file_ptr;
    file_ptr = fopen(FILENAME, "r+");
    if (file_ptr == NULL) {
        printf("Writing data error.");
    } else {
    delete_data(file_ptr, event.id);
    fclose(file_ptr);
    }  
}

void change_event(Event event, Event new_event) {
    FILE* file_ptr;
    file_ptr = fopen(FILENAME, "r+");
    if (file_ptr == NULL) {
        printf("Writing data error.");
    } else {
    change_data(file_ptr, event.id, new_event);
    fclose(file_ptr);
    }  
}
