#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_LEN 100
#define MAX_PASS_LEN 100

// Signup function
void signup() {
    char username[MAX_USER_LEN], password[MAX_PASS_LEN], role[10];
    FILE *fp;

    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    
    printf("Enter Role (user/admin): ");
    scanf("%s", role);

    fp = fopen("data/users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(fp, "%s %s %s\n", username, password, role);
    fclose(fp);

    printf("Signup successful! You can now log in.\n");
}
