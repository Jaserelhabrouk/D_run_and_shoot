#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include <stdlib.h>




#define ARROW_DOWN 80 
#define ARROW_UP 72


/** Block: Adjust the selector - first release* Assigned to:
* Updates the selector position according to input key.
* Input: menu_p, arrowKey
* Output: menu_p
*Return: void 
*/
void update_selector(menu_t* menu,int arrow_Key){
    if (ARROW_DOWN == arrow_Key) {
        if(MENU_ITEM_EXIT == menu->selector){
            menu->selector = MENU_ITEM_USER_MANUAL;
        }
        else{
            menu->selector+=1;
        }
    }
    if (ARROW_UP == arrow_Key) {
        if(MENU_ITEM_USER_MANUAL == menu->selector){
            menu->selector = MENU_ITEM_EXIT;
        }
        else{
            menu->selector-=1;
        }
    }
}