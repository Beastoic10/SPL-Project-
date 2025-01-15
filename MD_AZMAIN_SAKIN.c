#include <stdio.h>
#include <string.h>

int main() {
    FILE *fptr;
    char database[200];
    char search_string[50];

    printf("Welcome to Counselling Hour Database !!! \t\n");
    printf("Search faculties by name to know available Counselling Hours\n");
    printf("Enter name or part of name(in uppercase) : ");
    scanf("%s", search_string);

    fptr = fopen("Data.txt", "r");
    if (fptr == NULL) {
        printf("File doesn't exist.\n");
        return 1;
    }

    int found = 0;
    while (fgets(database, 200, fptr) != NULL) {
        if (strstr(database, search_string) != NULL) {
            char *name = strtok(database, ",");
            char *email = strtok(NULL, ",");
            char *counselling_hours = strtok(NULL, ",");

            printf("NAME : %s\n", name);
            printf("EMAIL : %s\n", email);
            printf("COUNSELLING HOUR : %s\n", counselling_hours);
            found = 1;
        }
    }

    if (!found) {
        printf("Requested data not found.\n");
    }

    fclose(fptr);
    return 0;
}
