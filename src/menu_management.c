// menu_management.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_menu() {
    FILE *fp = fopen("../data/menu.txt", "r");
    char menu_item[100];

    if (fp == NULL) {
        printf("Error opening menu file.\n");
        return;
    }

    printf("Current Menu:\n");
    while (fgets(menu_item, sizeof(menu_item), fp)) {
        printf("%s", menu_item);
    }

    fclose(fp);
}
