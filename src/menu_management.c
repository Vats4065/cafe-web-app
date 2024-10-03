#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_management.h"

// common view-menu function

void view_menu() {
    FILE *fp = fopen("../data/menu.txt", "r");
    char menu_item[100];

    if (fp == NULL) {
        printf("Error opening menu file.\n");
        return;
    }

    printf("\nCurrent Menu:\n");
    while (fgets(menu_item, sizeof(menu_item), fp)) {
        printf("%s", menu_item );
    }
    printf("\n");

    fclose(fp);
}

// admin-dashboard functions

void add_menu_item() {
    FILE *fp = fopen("../data/menu.txt", "a+");
    char item[100];
    float price;
    int item_number = 1;

    if (fp == NULL) {
        printf("Error opening menu file.\n");
        return;
    }

   
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        item_number++;
    }

    printf("Enter new item to add to the menu: ");
    scanf(" %[^\n]", item);
    printf("Enter price for %s: ", item);
    scanf("%f", &price);

    fprintf(fp, "%d: %s - %.2f\n", item_number, item, price);
    fclose(fp);

    printf("Menu updated successfully! Item added with number: %d\n", item_number);
}


void edit_menu_item() {
    FILE *fp = fopen("../data/menu.txt", "r");
    FILE *temp_fp = fopen("../data/temp_menu.txt", "w");
    char menu_item[100];
    char item_to_edit[100];
    char new_item[100];
    float new_price;
    int choice, found = 0;

    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening menu file.\n");
        return;
    }

    printf("Do you want to edit by (1) Item Number or (2) Item Name? ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the item number to edit: ");
        int item_number_to_edit;
        scanf("%d", &item_number_to_edit);


        while (fgets(menu_item, sizeof(menu_item), fp)) {
            int current_item_number;
            sscanf(menu_item, "%d:", &current_item_number); 

            if (current_item_number == item_number_to_edit) {
                found = 1;
                printf("Editing item: %s", menu_item);
                printf("Enter new item name: ");
                scanf(" %[^\n]", new_item);
                printf("Enter new price: ");
                scanf("%f", &new_price);
                fprintf(temp_fp, "%d: %s - %.2f\n", item_number_to_edit, new_item, new_price);  
            } else {
                fputs(menu_item, temp_fp);  
            }
        }
    } else {
        printf("Enter the item name to edit: ");
        scanf(" %[^\n]", item_to_edit);


        while (fgets(menu_item, sizeof(menu_item), fp)) {
            if (strstr(menu_item, item_to_edit) != NULL) {
                found = 1;
                printf("Editing item: %s", menu_item);
                printf("Enter new item name: ");
                scanf(" %[^\n]", new_item);
                printf("Enter new price: ");
                scanf("%f", &new_price);
              
                int current_item_number;
                sscanf(menu_item, "%d:", &current_item_number);
                fprintf(temp_fp, "%d: %s - %.2f\n", current_item_number, new_item, new_price);  
            } else {
                fputs(menu_item, temp_fp); 
            }
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove("../data/menu.txt");
    rename("../data/temp_menu.txt", "../data/menu.txt");

    if (found) {
        printf("Item updated successfully!\n");
    } else {
        printf("Item not found in the menu.\n");
    }
}

void delete_menu_item() {
    FILE *fp = fopen("../data/menu.txt", "r");
    FILE *temp_fp = fopen("../data/temp_menu.txt", "w");
    char menu_item[200];
    int delete_by_number;
    char item_to_delete[100];
    int found = 0;

    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening menu file.\n");
        return;
    }

    printf("Do you want to delete by (1) Item Number or (2) Item Name? ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the item number to delete: ");
        scanf("%d", &delete_by_number);
    } else {
        printf("Enter the item name to delete: ");
        scanf(" %[^\n]", item_to_delete);
    }

    while (fgets(menu_item, sizeof(menu_item), fp)) {
        int current_item_number;
        sscanf(menu_item, "%d:", &current_item_number); 

     
        if ((choice == 1 && current_item_number != delete_by_number) || 
            (choice == 2 && strstr(menu_item, item_to_delete) == NULL)) {
            fputs(menu_item, temp_fp);  
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove("../data/menu.txt");
    rename("../data/temp_menu.txt", "../data/menu.txt");

    if (found) {
        printf("Item deleted successfully!\n");
    } else {
        printf("Item not found in the menu.\n");
    }
}


void view_orders() {
    FILE *fp = fopen("../data/orders.txt", "r");
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

void view_users() { 
    FILE *fp = fopen("../data/users.txt", "r");
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

//user-dashboard functions

void place_order(const char *username) {
    view_menu(); 
    int item_number;
    int quantity;
    float price = 0.0;
    int order_number = 1;  

    FILE *menu_fp = fopen("../data/menu.txt", "r");
    FILE *orders_fp = fopen("../data/orders.txt", "a+");

    if (menu_fp == NULL || orders_fp == NULL) {
        printf("Error opening menu or orders file.\n");
        return;
    }

   
    char line[200];
    while (fgets(line, sizeof(line), orders_fp)) {
        order_number++;
    }

    printf("\nEnter the item number you want to order: "); 
    scanf("%d", &item_number);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    char item[100];
    float item_price;
    int item_found = 0;


    while (fgets(line, sizeof(line), menu_fp)) {
        int current_item_number;
        sscanf(line, "%d: %[^\n]", &current_item_number, item);
       
        char *price_string = strrchr(line, '-'); 
        if (price_string != NULL) {
            item_price = atof(price_string + 1); 
        }
        
        if (current_item_number == item_number) {
            price = item_price;
            item_found = 1;
            break; 
        }
    }

    fclose(menu_fp); 

    if (item_found) {
        float total_price = price * quantity; 
       
        fprintf(orders_fp, "%d: %s ordered %d x %s at $%.2f each, Total: $%.2f\n",
                order_number, username, quantity, item, price, total_price);
        printf("Order placed successfully! Total price: $%.2f (Order No: %d)\n", total_price, order_number);
    } else {
        printf("Item not found in the menu.\n");
    }

    fclose(orders_fp); // Close the orders file
}

void delete_order(const char *username) {
    FILE *fp = fopen("../data/orders.txt", "r");
    FILE *temp_fp = fopen("../data/temp_orders.txt", "w");
    char order[200];
    int found = 0, order_number_to_delete;
    char order_item_to_delete[100];

    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening orders file.\n");
        return;
    }

    printf("\nYour current orders:\n");
    while (fgets(order, sizeof(order), fp)) {
        printf("%s", order);
    }

    printf("\nDo you want to delete by (1) Order Number or (2) Order Name? ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the order number to delete: ");
        scanf("%d", &order_number_to_delete);
    } else {
        printf("Enter the order name to delete: ");
        scanf(" %[^\n]", order_item_to_delete);
    }

    rewind(fp);
    while (fgets(order, sizeof(order), fp)) {
        int current_order_number;
        sscanf(order, "%d:", &current_order_number);  

        if ((choice == 1 && current_order_number != order_number_to_delete) || 
            (choice == 2 && strstr(order, order_item_to_delete) == NULL)) {
            fputs(order, temp_fp); 
            found = 1;  
        }
    }

    fclose(fp);
    fclose(temp_fp);

    remove("../data/orders.txt");
    rename("../data/temp_orders.txt", "../data/orders.txt");

    if (found) {
        printf("Order deleted successfully!\n");
    } else {
        printf("Order not found!\n");
    }
}


void view_user_orders(const char *username) {
    FILE *fp = fopen("../data/orders.txt", "r");
    char order[100];

    if (fp == NULL) {
        printf("Error opening orders file.\n");
        return;
    }

    printf("\nYour Orders:\n");
    int found = 0; 
    while (fgets(order, sizeof(order), fp)) {
        if (strstr(order, username) != NULL) { 
            printf("%s", order);
            found = 1; 
        }
    }

    if (!found) {
        printf("You have no orders placed.\n");
    }

    fclose(fp);
}
