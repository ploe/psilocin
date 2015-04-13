#include "psilocin.h"

/* Destroy function for the STAGE - the return value isn't important */
static ps_CrewStatus DestroyStage(ps_Crew *c) {
	ps_Stage *stage = (ps_Stage *) c->attr;
	SDL_DestroyWindow(stage->window);
	SDL_Quit();

	return ps_CUT;
}

/* Update method for the STAGE - called every frame */
static ps_CrewStatus UpdateStage(ps_Crew *c) {
	puts("again again");
	return ps_LIVE;
}

/* The init function/type for the STAGE */
ps_CrewStatus ps_STAGE(ps_Crew *c) {
	c->type = ps_STAGE;
	c->destroy = DestroyStage;
	c->update = UpdateStage;

	if (SDL_Init( SDL_INIT_VIDEO ) < 0) ps_Panic(ps_EOSTAGE_INIT, "ps_STAGE: SDL_Init Failed");
	ps_Stage *stage = calloc(1, sizeof(ps_Stage));
	stage->window = SDL_CreateWindow("psilocin", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 160, 144, SDL_WINDOW_SHOWN);
	if (!stage->window) ps_Panic(ps_EOSTAGE_INIT, "ps_STAGE: Failed to create STAGE window.");
	stage->surface = SDL_GetWindowSurface(stage->window);

	c->attr = stage;
	return 0;
}

