#include <iostream>
#include <exception>
#include <memory>

#include "../include/gui.h"
#include "../include/personaje.h"

Gui::Gui(){}

Gui::~Gui(){}

void Gui::run() {
	
	SDL sdl(SDL_INIT_VIDEO);
	SDLTTF ttf;

	SDL_DisplayMode displayMode;
 	int monitorIndex = 1;

    int screenWidth = 600;
    int screenHeight = 800;


	Window window("SDL2pp demo",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			screenHeight, screenWidth,
			SDL_WINDOW_RESIZABLE);

	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::unique_ptr<Personaje> spaz = std::make_unique<Spaz>(renderer);
	Texture sprites_beach(renderer, Surface(IMG_PATH "/beach.png")
			.SetColorKey(true, 0));

	int animacion =0;
	int animacion_prev =0;

	unsigned int prev_ticks = SDL_GetTicks();

	while (1) {
		SDL_Event event;
		animacion_prev = animacion;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return;
			} else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE: 
					case SDLK_q:
						return;
					case SDLK_RIGHT: 
						animacion = 1;
						break;
					case SDLK_LEFT:
						animacion = 2;
						break;
				}
			} else if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
					case SDLK_RIGHT: 
						animacion = 0; 
						break;
					case SDLK_LEFT: 
						animacion = 0; 
						break;
				}
			}
		}

		// Clear screen
		renderer.Clear();
		spaz->animacion(animacion);
		renderer.Present();
		unsigned int frame_ticks = SDL_GetTicks();
		int rest = 10 - (frame_ticks - prev_ticks);
		if (rest < 0){
			int behind = -rest;
			int lost = behind - behind % 10;
			prev_ticks += lost;
		} else {
			SDL_Delay(rest);	
		}
		prev_ticks += 10;
		SDL_Delay(1);
	}

	// Here all resources are automatically released and libraries deinitialized
	//return 0;
}