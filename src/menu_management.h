#ifndef MENU_MANAGEMENT_H
#define MENU_MANAGEMENT_H

void add_menu_item();
void edit_menu_item();
void delete_menu_item();
void view_menu();
void view_users();
void view_orders();
void place_order(const char *username);
void delete_order(const char *username);
void view_user_orders(const char *username);

#endif
