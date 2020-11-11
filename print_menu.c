#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include <stdlib.h>

/**
* Block: Print the menu - first release
* Assigned to:* Prints the game start up menu on the consol.
* Input: menu
* Return: void 
*/
void print_menu(menu_t menu){
    // system("clear");
    for (int i = 0; i < MENU_ITEM_NUM_OF_ITEMS; i++) {
        if (menu.selector == i) {
            printf("---> ");
        }
        else
        {
            printf(" ");
        }
        printf("%s\n", menu.items[i].str);
    }
}