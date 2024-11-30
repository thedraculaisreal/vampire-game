#include "../entity/entity.h"
#include "keypress.h"
#include <unistd.h>
#include <pthread.h>

void init_raylib(void);

void* keypress_thread()
{
    init_keystrokes();
}

int main(void)
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, keypress_thread, NULL);
    pthread_detach(thread_id);
    init_raylib();
    return 0;
}

void init_raylib(void)
{
    Vector2 pos1 = { 200, 200};
    Vector2 pos2 = { 700, 200};

    // Create entitys
    create_entity(entity_vampire ,"vampire", pos1);
    create_entity(entity_human ,"human", pos2);

    // variables for window and rectangles
    const int window_width = 1400;
    const int window_height = 800;
    const char* window_name = "kill-humans";

    // raylib initialization.
    InitWindow(window_width, window_height, window_name);

    while(!WindowShouldClose())
    {
	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(entity_vampire); // draw entities to screen
	draw_entity(entity_human);
	if (!is_alive(entity_vampire))
	{
	    break;
	}
	if (!is_alive(entity_human))
	{
	    break;
	}
	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
