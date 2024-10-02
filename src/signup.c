#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_USER_LEN 100
#define MAX_PASS_LEN 100

void signup() {
    char username[MAX_USER_LEN], password[MAX_PASS_LEN], role[10];
    FILE *fp;
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    }


    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);
    
    printf("Enter Role (user/admin): ");
    scanf("%s", role);


    printf("Attempting to open file: ../data/users.txt\n");
    fp = fopen("../data/users.txt", "a");
    if (fp == NULL) {
        printf("Error opening file: ../data/users.txt\n");
        return;
    }


    fprintf(fp, "%s %s %s\n", username, password, role);
    fclose(fp);

    printf("Signup successful! You can now log in.\n");
}
