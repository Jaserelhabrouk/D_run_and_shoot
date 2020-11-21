#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include <stdlib.h>

/**
 * A function to test the update selector function
*/

void update_selector_test(){
    menu_t menu;
    menu.selector = MENU_ITEM_USER_MANUAL;
    update_selector(&menu, ARROW_DOWN);
    assert(menu.selector == MENU_ITEM_SINGLE_PLAYER);
    menu.selector = MENU_ITEM_EXIT;
    update_selector(&menu, ARROW_DOWN);
    assert(menu.selector == MENU_ITEM_USER_MANUAL);
    menu.selector = MENU_ITEM_OPTION;
    update_selector(&menu, ARROW_UP);
    assert(menu.selector == MENU_ITEM_MULTI_PLAYER);
}