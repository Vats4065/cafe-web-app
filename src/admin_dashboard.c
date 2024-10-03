#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_management.h" 

void manage_menu();

void admin_dashboard() {
    int choice;

    while (1) {
        printf("\n--- Admin Dashboard ---\n");
        printf("1. Manage Menu\n");
        printf("2. View Orders\n");
        printf("3. View Users\n"); 
        printf("4. View Menu\n"); 
        printf("5. Exit\n");
        printf("6. Logout\n");

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
                view_users(); 
                break;
            case 4:
                view_menu();
                break;
            case 5:
                exit(0);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}



void manage_menu() {
    int choice;

    while (1) {
        printf("\n--- Manage Menu ---\n");
        printf("1. Add Menu Item\n");
        printf("2. Edit Menu Item\n");
        printf("3. Delete Menu Item\n");
        printf("4. View Menu Item\n");
        printf("5. Return to Admin Dashboard\n");
        printf("6. Exit Application\n");  
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_menu_item();
                break;
            case 2:
                edit_menu_item();
                break;
            case 3:
                delete_menu_item();
                break;
            case 4:
                view_menu();  
                break;
            case 5:
                return;  
            case 6:
                exit(0);  
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


