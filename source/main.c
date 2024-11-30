#include "entity.h"
#include <unistd.h>

void init_raylib(void);

int main(void)
{
    init_raylib();
    return 0;
}

void init_raylib(void)
{
    Vector2 pos1 = { 200, 200};
    Vector2 pos2 = { 700, 200};

    // Create entitys
    struct entity ent = create_entity("xyo", pos1);
    struct entity ent2 = create_entity("himothy", pos2);

    // variables for window and rectangles
    const int window_width = 1400;
    const int window_height = 800;
    const char* window_name = "kill-himothy-game";

    // raylib initialization.
    InitWindow(window_width, window_height, window_name);

    while(!WindowShouldClose())
    {
	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(ent); // draw entities to screen
	draw_entity(ent2);
	ent.pos.x = move_entity(ent, 0.01f);
	if (!is_alive(ent))
	{
	    break;
	}
	if (!is_alive(ent2))
	{
	    break;
	}
	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
