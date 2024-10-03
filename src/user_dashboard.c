#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_management.h"



void user_dashboard(const char *username) {
    int choice;

    while (1) {
        printf("\n--- User Dashboard ---\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. View Your Orders\n");
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
                view_user_orders(username);
                break;
            case 4:
                delete_order(username);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


