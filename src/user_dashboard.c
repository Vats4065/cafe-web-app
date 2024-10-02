#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_menu();
void place_order(const char *username);
void delete_order(const char *username);
void view_user_orders(const char *username);

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

void view_menu() {
    FILE *fp = fopen("../data/menu.txt", "r");
    char item[100];
    float price;

    if (fp == NULL) {
        printf("Error opening menu.\n");
        return;
    }

    printf("Café Menu:\n");
    while (fscanf(fp, "%s %f", item, &price) != EOF) {
        printf("%s - $%.2f\n", item, price);
    }

    fclose(fp);
}

void place_order(const char *username) {
    char order_item[100];
    int quantity;
    float price = 0.0;
    FILE *menu_fp = fopen("../data/menu.txt", "r");
    FILE *orders_fp = fopen("../data/orders.txt", "a");

    if (menu_fp == NULL || orders_fp == NULL) {
        printf("Error opening menu or orders file.\n");
        return;
    }

  
    printf("Enter the item you want to order: ");
    scanf(" %[^\n]", order_item);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);


    char item[100];
    float item_price;
    int item_found = 0;

    while (fscanf(menu_fp, "%s %f", item, &item_price) != EOF) {
        if (strcmp(item, order_item) == 0) {
            price = item_price;
            item_found = 1;
            break;
        }
    }

    fclose(menu_fp);

    if (item_found) {
        float total_price = price * quantity;
        fprintf(orders_fp, "%s ordered %d x %s at $%.2f each, Total: $%.2f\n",
                username, quantity, order_item, price, total_price);
        printf("Order placed successfully! Total price: $%.2f\n", total_price);
    } else {
        printf("Item not found in the menu.\n");
    }

    fclose(orders_fp);
}

void delete_order(const char *username) {
    FILE *fp = fopen("../data/orders.txt", "r");
    FILE *temp_fp = fopen("../data/temp_orders.txt", "w");
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

   
    printf("Enter the order to delete: ");
    char order_to_delete[100];
    scanf(" %[^\n]", order_to_delete);

    rewind(fp); 
    while (fgets(order, sizeof(order), fp)) {
   
        if (strstr(order, order_to_delete) == NULL) {
            fputs(order, temp_fp); 
        } else {
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

    printf("Your Orders:\n");
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
