#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
char *dayName;
int date, month, year;
char *activity;
};

struct Day* createCalendar(int numDays) {
struct Day *calendar = (struct Day*)malloc(numDays * sizeof(struct Day));
if (calendar == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
for(int i = 0; i < numDays; i++) {
calendar[i].dayName = (char*)malloc(20 * sizeof(char));
calendar[i].activity = (char*)malloc(100 * sizeof(char));
}
return calendar;
}

void readDay(struct Day *day) {
printf("Enter day name: ");
scanf("%s", day->dayName);
printf("Enter date: ");
scanf("%d%d%d", &(day->date),&(day->month),&(day->year));
printf("Enter activity description: ");
scanf(" %[^\n]", day->activity);
}

void displayCalendar(struct Day *calendar, int numDays) {
printf("\nWeek's Activity Details:\n");
for (int i = 0; i < numDays; i++) {
printf("Day: %s\n", calendar[i].dayName);
printf("Date: %d%d%d\n", calendar[i].date, calendar[i].month, calendar[i].year);
printf("Activity: %s\n", calendar[i].activity);
printf("\n");
}
}

int main() {
int numDays;
printf("Enter the number of days in the week: ");
scanf("%d", &numDays);
struct Day *calendar = createCalendar(numDays);
for (int i = 0; i < numDays; i++) {
printf("Enter details for Day %d:\n", i + 1);
readDay(&calendar[i]);
}
displayCalendar(calendar, numDays);

for (int i = 0; i < numDays; i++) {
free(calendar[i].dayName);
free(calendar[i].activity);
}
free(calendar);

return 0;
}
