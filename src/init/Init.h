#pragma once

#include <SDL2/SDL.h>


/*
 * @brief Initializes window.
 * @throws Error that occured during init process.
 * @returns Window pointer.
 */
SDL_Window* init(void);
