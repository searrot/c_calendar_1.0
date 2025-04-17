#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void menu() {

}

void write_data(FILE* file_ptr, Event event) {
    fprintf(file_ptr, "%d\n%d/%d/%d\n%s\n%s\n", event.id, event.year, event.month, event.day, event.title, event.description);
}

int read_data(FILE* file_ptr, Event* event) {
   int status = fscanf(file_ptr, "%d\n%d/%d/%d\n%s\n%s\n", &event->id, &event->year, &event->month, &event->day, event->title, event->description);
    printf("%d", status);
    return status;
}

void delete_data(FILE* file_ptr, int id) {
    Event events[366];
    int c = 0;
    Event event;
    int status = 0;
    while (read_data(file_ptr, &event) > 0) {
        printf("%d", status);
        if (event.id != id) {
            events[c++] = event;
            printf("reading\n");
        } else status = 1;
    }
    if (status) {
        printf("ready to rewind\n");
        rewind(file_ptr);
        for (int i = 0; i < c; i++){
            printf("writing data...\n");
            write_data(file_ptr, events[i]);
        }
        printf("process...\n");
        ftruncate(fileno(file_ptr), ftell(file_ptr));
    }
}

void change_data(FILE* file_ptr, int id, Event new_event) {
    Event events[366];
    int c = 0;
    Event event;
    while (read_data(file_ptr, &event) > 0) {
        if (event.id != id) {
            events[c++] = event;
        } else {
            events[c++] = new_event;
        }
    }
    rewind(file_ptr);
    for (int i = 0; i < c; i++){
        write_data(file_ptr, events[i]);
    }
}