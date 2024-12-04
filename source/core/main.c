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
    entity entity_human;
    entity entity_vampire;
    bullet bullet_a;
    bullet bullet_d;
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
	movement(&entity_vampire, &entity_human); // takes keyboard input
	if (!is_alive(&entity_vampire) || !is_alive(&entity_human)) break; // check if alive

	// for right shooting bullet.
	if (IsKeyPressed(KEY_A))
	{
	    create_bullet(&bullet_a, &entity_vampire, 4);
	}
	if (bullet_a.alive)
	{
	    bullet_position(&bullet_a);
	    check_collision_bul(&bullet_a, &entity_human);
	}
	// for left shooting bullet.
	if (IsKeyPressed(KEY_D))
	{
	    create_bullet(&bullet_d, &entity_vampire, -4);
	}
	if (bullet_d.alive)
	{
	    bullet_position(&bullet_d);
	    check_collision_bul(&bullet_d, &entity_human);
	}

	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(&entity_vampire); // draw entities to screen
	draw_entity(&entity_human);
	draw_bullet(&bullet_a);
	draw_bullet(&bullet_d);

	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
