#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login();
void signup();
void user_dashboard(const char *username);
void admin_dashboard();

int main() {
    int choice;
    
    while (1) {
        printf("Welcome to the Café Management System\n");
        printf("1. Login\n");
        printf("2. Signup\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                signup();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
