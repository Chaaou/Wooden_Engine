/*
 * FPScounter.cpp
 *
 *  Created on: 06 нояб. 2014 г.
 *      Author: Админ
 */

#include "FPScounter.h"

#include <iostream>

FPS_counter::FPS_counter() {
	old_time = 0;
	last_time = 0;

	speed_factor = 0;

	frames = 0;
	num_frames = 0;
}

FPS_counter::~FPS_counter() {
//деструктор
}

void FPS_counter::OnUpdate(){
    if(old_time + 1000 < SDL_GetTicks()) {
        old_time = SDL_GetTicks();

        num_frames = frames;

        frames = 0;

        std::cout << "FPS debug: " << num_frames << std::endl;
    }

    speed_factor = ((SDL_GetTicks() - last_time) / 1000.0f) * 32.0f;

    last_time = SDL_GetTicks();

    frames++;
}

int FPS_counter::GetFPS() {
	return num_frames;
}
