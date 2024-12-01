#include "../entity/entity.h"
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
    static const Vector2 right_move = {.01 , 0};
    static const Vector2 left_move = {-0.01 , 0};
    static const Vector2 up_move = {0 , -0.01};
    static const Vector2 down_move = {0 , 0.01};
    struct entity entity_human;
    struct entity entity_vampire;

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
	if (IsKeyDown(KEY_RIGHT))
	{
	    entity_vampire.pos = move_entity(entity_vampire, right_move);
	}
	if (IsKeyDown(KEY_LEFT))
	{
	    entity_vampire.pos = move_entity(entity_vampire, left_move);
	}
	if (IsKeyDown(KEY_UP))
	{
	    entity_vampire.pos = move_entity(entity_vampire, up_move);
	}
	if (IsKeyDown(KEY_DOWN))
	{
	    entity_vampire.pos = move_entity(entity_vampire, down_move);
	}

	if (!is_alive(entity_vampire))
	{
	    break;
	}
	if (!is_alive(entity_human))
	{
	    break;
	}

	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(entity_vampire); // draw entities to screen
	draw_entity(entity_human);

	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
