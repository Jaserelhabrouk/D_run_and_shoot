#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include <stdlib.h>






#define ARROW_DOWN 80 
#define ARROW_UP 72




/**
* Block: Print the menu - first release
* Assigned to:* Prints the game start up menu on the consol.
* Input: menu
* Return: void 
*/
void printMenu(menu_t menu){
    system("clear");
    if (MENU_ITEM_USER_MANUAL == menu.selector){
        puts("   User Manual <-- ");

    }else{
        puts("   User Manual  ");
    }
    if (MENU_ITEM_SINGLE_PLAYER == menu.selector){
        puts("   Single Player <-- ");
    }else{
        puts("   Single Player  ");
    }
    if (MENU_ITEM_MULTI_PLAYER == menu.selector){
        puts("   Multi Player <-- ");

    }else{
        puts("   Multi Player  ");
    }
    if (MENU_ITEM_OPTION == menu.selector){
        puts("   Option  ");

    }else{
        puts("   Option ");
    }
    if (MENU_ITEM_CREDIT == menu.selector){
        puts("   Credit <-- ");

    }else{
        puts("   Credit  ");
    }
    if (MENU_ITEM_EXIT == menu.selector){
        puts("   Exit <-- ");

    }else{
        puts("   Exit  ");
    }

    
}


/** Block: Adjust the selector - first release* Assigned to:
* Updates the selector position according to input key.
* Input: menu_p, arrowKey
* Output: menu_p
*Return: void 
*/
void updateSelector(menu_t* menu,int arrowKey){
    if (ARROW_DOWN == arrowKey) {
        if(MENU_ITEM_EXIT == menu->selector){
            menu->selector = MENU_ITEM_USER_MANUAL;
        }
        else{
            menu->selector+=1;
        }
    }
    if (arrowKey == ARROW_UP) {
        if(MENU_ITEM_USER_MANUAL == menu->selector){
            menu->selector = MENU_ITEM_EXIT;
        }
        else{
            menu->selector-=1;
        }
    }
}



/**
 * A function to test printMenu as well as Update selector
*/

void testMenu(){
    menu_t menu;
    // menu.selector = MENU_ITEM_USER_MANUAL;
    // updateSelector(&menu, ARROW_DOWN);
    // assert(menu.selector == MENU_ITEM_SINGLE_PLAYER);
    // printMenu(menu);
    menu.selector = MENU_ITEM_EXIT;
    updateSelector(&menu, ARROW_DOWN);
    assert(menu.selector == MENU_ITEM_USER_MANUAL);
    printMenu(menu);
    menu.selector = MENU_ITEM_OPTION;
    updateSelector(&menu, ARROW_UP);
    assert(menu.selector == MENU_ITEM_MULTI_PLAYER);
    printMenu(menu);
}


