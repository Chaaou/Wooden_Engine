/*
 * Surface.h
 *
 *  Created on: 21 июля 2014 г.
 *      Author: snickers
 */

#ifndef SURFACE_H_
#define SURFACE_H_

#include <string>
#include <iostream>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Core/Vec2.h"
#include "GUI/Window.h"
#include "GUI/colors.h"
#include "../constants.h"

class Surface {

public:
    static SDL_Texture* LoadTexture(std::string fpath);
    static void OnDraw(SDL_Texture* texture, SDL_Rect* dstrect);
    static void OnDraw(SDL_Texture* texture, SDL_Rect* srcrect,
            SDL_Rect* dstrect);
    static void OnDraw(SDL_Texture* texture, SDL_Rect* srcrect,
            SDL_Rect* dstrect, const double& angle);
    static void DrawRect(SDL_Rect* rect, SDL_Color color);
    static void DrawRect(SDL_Rect* rect, const Uint8 r, const Uint8 g,
            const Uint8 b, const Uint8 a);
    static void DrawTexturedRect(SDL_Texture* src, SDL_Rect* src_rect,
            SDL_Rect* dst_rect, int tile_size);

    static void GetSkinnedRect(SDL_Texture* src, SDL_Texture* dst, Vec2* pos,
            SDL_Rect* dst_rect, int size = 8);

    static void OnCleanUp();

private:
    static std::map<std::string, SDL_Texture*> Textures;

};

#endif /* SURFACE_H_ */
