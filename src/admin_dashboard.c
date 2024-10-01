#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void manage_menu();
void view_orders();
void view_users(); // New function to view user information

void admin_dashboard() {
    int choice;

    while (1) {
        printf("\n--- Admin Dashboard ---\n");
        printf("1. Manage Menu\n");
        printf("2. View Orders\n");
        printf("3. View Users\n"); // New option
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manage_menu();
                break;
            case 2:
                view_orders();
                break;
            case 3:
                view_users(); // Call to new function
                break;
            case 4:
                return; // Logout
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void manage_menu() {
    FILE *fp = fopen("data/menu.txt", "a");
    char item[100];
    float price; // Variable to store price

    if (fp == NULL) {
        printf("Error opening menu file.\n");
        return;
    }

    printf("Enter new item to add to the menu: ");
    scanf(" %[^\n]", item);
    printf("Enter price for %s: ", item);
    scanf("%f", &price); // Read price

    fprintf(fp, "%s - %.2f\n", item, price); // Save item and price
    fclose(fp);

    printf("Menu updated successfully!\n"); 
}

void view_orders() {
    FILE *fp = fopen("data/orders.txt", "r");
    char order[100];

    if (fp == NULL) {
        printf("Error opening orders file.\n");
        return;
    }

    printf("Café Orders:\n");
    while (fgets(order, sizeof(order), fp)) {
        printf("%s", order);
    }

    fclose(fp);
}

void view_users() { // New function to view user information
    FILE *fp = fopen("data/users.txt", "r");
    char user_info[100];

    if (fp == NULL) {
        printf("Error opening users file.\n");
        return;
    }

    printf("Registered Users:\n");
    while (fgets(user_info, sizeof(user_info), fp)) {
        printf("%s", user_info);
    }

    fclose(fp);
}
