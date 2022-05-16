/*
 * Interactive Command-Line Program
 * Main Menu Screen, you can add/remove/sort reminders
 * Importing files?
 * add GUI (opengl)
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char *message;
    int priority;
} Reminder;

typedef struct {
    Reminder *reminder;
    int capacity;
    int n;
} Reminders;

void printReminders(Reminders *);
void printMainMenu();
void addReminder(Reminder, int);

const float VERSION = 1.0f;
const char EXEC_TYPES[7] = {'a', 'd','e','s','i','x','q'};
Reminders reminders = {0, 10, 0};

int main(int argc, char **argv) {
    printf("Welcome to Remindatron 2000 v%.1f\n", VERSION);
    printf("Created by future :-> (05/16/2022)\n\n");
    reminders.reminder = malloc(10 * sizeof(Reminders));
    while (1) {
        char input;
        Reminder reminder;
        int priority = -1, found = 0;
        printMainMenu();
        printf("Input Choice:");
        scanf("%c", &input);
        for (int i = 0; i < sizeof(EXEC_TYPES) / sizeof(EXEC_TYPES[0]); i++) {
            if (EXEC_TYPES[i] == input) {
                found = 1;
            }
        }
       if (!found) {
           printf("\nInvalid input choice specified, please try again.\n");
           continue;
       }
        switch (input) {
            case 'a':
                printf("What would you like to be reminded about?\n");
                scanf("%s", reminder.message);
                do {
                    printf("What's the priority for this reminder? (1-3)\n");
                    scanf("%d", &priority);
                    if (priority < 0 || priority > 4) {
                        printf("A reminder's priority must be between ranges (1-3)!\n");
                    }
                } while (priority < 0 || priority > 4);
                addReminder(reminder, priority);
                printf("Successfully created reminder!\n");
                break;
            case 'd':
                printf("Nice you chose d\n");
                break;
            case 'e':
                printf("Nice you chose e\n");
                break;
            case 's':
                printf("Nice you chose s\n");
                break;
            case 'i':
                printf("Nice you chose f\n");
                break;
            case 'x':
                printf("Nice you chose x\n");
                break;
            case 'q':
                free(reminders.reminder);
                printf("Nice you chose q\n");
                exit(0);
        }
    }
    free(reminders.reminder);
    return 0;
}

void printReminders(Reminders *_reminders) {
    for (int i = 0; i < _reminders->n; i++) {
        printf("%d. %s\n", i + 1, _reminders->reminder);
    }
}

void printMainMenu() {
    printf("Your Current Reminders: \n");
    printf("---------------------------\n");
    printf("| Reminder   |   Priority |\n");
    printf("---------------------------\n");
    printReminders(&reminders);
    printf("---------------------------\n");
    printf("A - Add Reminder,    E - Edit Reminder,   I - Import Reminders From File\nD - Delete Reminder, S - Sort Reminders,  X - Export Reminders To File,   Q - Quit\n");
}

void addReminder(Reminder reminder, int priority) {
    if (reminders.n == reminders.capacity) {
        reminders.capacity *=2;
        reminders.reminder = realloc(reminders.reminder, reminders.capacity);
    }
    reminder.priority = priority;
    reminders.reminder[reminders.n++] = reminder;
}
