#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USER_LEN 100
#define MAX_PASS_LEN 100

void user_dashboard(const char *username);
void admin_dashboard();

// Function to authenticate the user
int authenticate(const char *username, const char *password, char *role) {
    FILE *fp = fopen("data/users.txt", "r");
    char file_user[MAX_USER_LEN], file_pass[MAX_PASS_LEN], file_role[10];

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    while (fscanf(fp, "%s %s %s", file_user, file_pass, file_role) != EOF) {
        if (strcmp(username, file_user) == 0 && strcmp(password, file_pass) == 0) {
            strcpy(role, file_role);
            fclose(fp);
            return 1; // Authentication successful
        }
    }

    fclose(fp);
    return 0; // Authentication failed
}

// Login function
void login() {
    char username[MAX_USER_LEN], password[MAX_PASS_LEN], role[10];

    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    if (authenticate(username, password, role)) {
        if (strcmp(role, "admin") == 0) {
            printf("Login successful! Redirecting to Admin Dashboard...\n");
            admin_dashboard();
        } else {
            printf("Login successful! Redirecting to User Dashboard...\n");
            user_dashboard(username);
        }
    } else {
        printf("Login failed! Invalid credentials.\n");
    }
}
