/**
* @file update_view.c
* @author Jin
*/

#include"../include/map.h"
#include<stdio.h>


/* Block: generate a view- first release
* Assigned to: Jin
* Generate a 2d graphic map using updated information
* Input: map
* Return: void */
void update_view(map_t map) {
    if (map.barrier != NULL)
    {
        update_barrier(map.barrier, &map);
    }
    if (map.arrow != NULL)
    {
        //update_arrow(map.arrow, map.space);
    }

    //updatePlayerPos(&map.player, arrowKey);

}
