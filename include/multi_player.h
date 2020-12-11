/**
 * @file multi_player.h
 * @brief function declaration and type definition for multi player mode.
 */
#pragma once
#ifndef MULTI_PLAYER_H_
#define MULTI_PLAYER_H_
#include "single_player.h"

/**
 * \brief multi_player function
 *
 * This is the main function which handle multi player mode.
 * Different functions are called here: first a map file is loaded and then
 * according to the input key different entities is updated and a view will be generated.
 * A timer is initialized to update every thing in each TIMER_INTERVAL seconds.
 * @param[in] p_window a SDL window which is passed from the main function.
 * @return bool if window is quit or back_space key is pressed, return true.
 */
bool multi_player(SDL_Window* p_window);

Uint32 timer_callback(Uint32, void*);


#endif /* MULTI_PLAYER_H_ */
#pragma once
