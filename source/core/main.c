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
    static const Vector2 right_move = {4 , 0};
    static const Vector2 left_move = {-4 , 0};
    static const Vector2 up_move = {0 , -4};
    static const Vector2 down_move = {0 , 4};
    struct entity entity_human;
    struct entity entity_vampire;
    Rectangle box_collision = { 0 };
    bool collision = false;
    SetTargetFPS(250); // set game fps.

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
	Rectangle vampire_rect;
	vampire_rect.x = entity_vampire.pos.x;
	vampire_rect.y = entity_vampire.pos.y;
	vampire_rect.height = entity_vampire.size.y;
	vampire_rect.width = entity_vampire.size.x;
	Rectangle human_rect;
	human_rect.x = entity_human.pos.x;
	human_rect.y = entity_human.pos.y;
	human_rect.height = entity_human.size.y;
	human_rect.width = entity_human.size.x;

	if (CheckCollisionRecs(vampire_rect, human_rect))
	{
	    collision = true;
	}
	else
	{
	    collision = false;
	}
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
