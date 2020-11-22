#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include <stdlib.h>

/**
 * A function to test the print menu function
*/

void print_menu_test(){
    menu_t menu = {
    .selector = 0,
    .items[0].str = "user manual",
    .items[1].str = "single player",
    .items[2].str = "multi player",
    .items[3].str = "options",
    .items[4].str = "credit",
    .items[5].str = "exit",
    };
    menu.selector = MENU_ITEM_USER_MANUAL;
    update_selector(&menu, ARROW_DOWN);
    assert(menu.selector == MENU_ITEM_SINGLE_PLAYER);
    print_menu(menu);
    menu.selector = MENU_ITEM_EXIT;
    update_selector(&menu, ARROW_DOWN);
    assert(menu.selector == MENU_ITEM_USER_MANUAL);
    print_menu(menu);
    menu.selector = MENU_ITEM_OPTION;
    update_selector(&menu, ARROW_UP);
    assert(menu.selector == MENU_ITEM_MULTI_PLAYER);
    print_menu(menu);
}