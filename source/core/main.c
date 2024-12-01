#include "game.h"
#include <unistd.h>
#include <pthread.h>

void init_raylib(void);

int main(void)
{
    init_raylib();
    return 0;
}

void init_raylib(void)
{
    const Vector2 pos1 = { 200, 200};
    const Vector2 pos2 = { 700, 200};
    struct entity entity_human;
    struct entity entity_vampire;
    Rectangle box_collision = { 0 };
    bool collision = false;
    SetTargetFPS(60); // set game fps.

    // Create entitys
    entity_vampire = create_entity("vampire", pos1);
    entity_human = create_entity("human", pos2);

    // variables for window and rectangles
    const int window_width = 1400;
    const int window_height = 800;
    const char* window_name = "kill-humans";

    // raylib initialization.
    InitWindow(window_width, window_height, window_name);

    while(!WindowShouldClose())
    {
	collision = check_collision(entity_vampire, entity_human); // collision checks
	entity_vampire.pos = movement(collision, entity_vampire.pos); // takes keyboard input
	if (!is_alive(entity_vampire) || !is_alive(entity_human)) break; // check if alive

	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(entity_vampire); // draw entities to screen
	draw_entity(entity_human);
	if (collision)
	{
	    DrawText("Collision = true", 400, 20, 20, WHITE);
	}
	else
	{
	    DrawText("Collision = false", 400, 20, 20, WHITE);
	}

	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
