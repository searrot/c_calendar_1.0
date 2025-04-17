#include "calendar.h"
#include <locale.h>
#include <stdio.h>
#include <Windows.h>
#include "event_manager.h"

int main() {
    setlocale(LC_ALL, "ru_RU.utf-8");
    Event event = {0};
    Event event1 = {0};
    (&event)->id = 228;
    (&event)->year = 2000;
    (&event)->month = 4;
    (&event)->day = 15;
    strncpy(event.title, "lorem pipsum", 100);
    strncpy(event.description, "pis pis", 100);
    (&event1)->id = 229;
    (&event1)->year = 2000;
    (&event1)->month = 4;
    (&event1)->day = 15;
    strncpy(event1.title, "lorem pipsum", 100);
    strncpy(event1.description, "pis pis", 100);
    change_event(event, event1);
}