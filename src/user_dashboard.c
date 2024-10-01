#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_menu();
void place_order(const char *username);
void delete_order(const char *username);
void view_user_orders(const char *username); // New function to view user's orders

void user_dashboard(const char *username) {
    int choice;

    while (1) {
        printf("\n--- User Dashboard ---\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. View Your Orders\n"); // New option
        printf("4. Delete Order\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_menu();
                break;
            case 2:
                place_order(username);
                break;
            case 3:
                view_user_orders(username); // Call to new function
                break;
            case 4:
                delete_order(username);
                break;
            case 5:
                return; // Logout
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void view_menu() {
    FILE *fp = fopen("data/menu.txt", "r");
    char item[100];
    
    if (fp == NULL) {
        printf("Error opening menu.\n");
        return;
    }

    printf("Café Menu:\n");
    while (fgets(item, sizeof(item), fp)) {
        printf("%s", item);
    }

    fclose(fp);
}

void place_order(const char *username) {
    char order[100];
    FILE *fp = fopen("data/orders.txt", "a");

    if (fp == NULL) {
        printf("Error opening orders file.\n");
        return;
    }

    printf("Enter your order: ");
    scanf(" %[^\n]", order);
    fprintf(fp, "%s ordered: %s\n", username, order);
    fclose(fp);

    printf("Order placed successfully!\n");
}

void delete_order(const char *username) {
    FILE *fp = fopen("data/orders.txt", "r");
    FILE *temp_fp = fopen("data/temp_orders.txt", "w");
    char order[100];
    int found = 0;

    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening orders file.\n");
        return;
    }

    printf("Your current orders:\n");
    while (fgets(order, sizeof(order), fp)) {
        printf("%s", order);
    }

    // Prompt for order to delete
    printf("Enter the order to delete: ");
    char order_to_delete[100];
    scanf(" %[^\n]", order_to_delete);

    rewind(fp); // Reset file pointer to start
    while (fgets(order, sizeof(order), fp)) {
        // Check if the order matches
        if (strstr(order, order_to_delete) == NULL) {
            fputs(order, temp_fp); // Write to temp file if not a match
        } else {
            found = 1; // Mark that we found the order to delete
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove("data/orders.txt"); // Delete original orders file
    rename("data/temp_orders.txt", "data/orders.txt"); // Rename temp file to original

    if (found) {
        printf("Order deleted successfully!\n");
    } else {
        printf("Order not found!\n");
    }
}

// New function to view user's specific orders
void view_user_orders(const char *username) {
    FILE *fp = fopen("data/orders.txt", "r");
    char order[100];

    if (fp == NULL) {
        printf("Error opening orders file.\n");
        return;
    }

    printf("Your Orders:\n");
    int found = 0; // Flag to check if any orders are found
    while (fgets(order, sizeof(order), fp)) {
        if (strstr(order, username) != NULL) { // Check if order belongs to user
            printf("%s", order);
            found = 1; // Mark that we found at least one order
        }
    }

    if (!found) {
        printf("You have no orders placed.\n");
    }

    fclose(fp);
}
