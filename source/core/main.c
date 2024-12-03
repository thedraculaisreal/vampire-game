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
    struct bullet bullet_a;
    struct bullet bullet_d;
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
	entity_vampire.pos = movement(entity_vampire.pos); // takes keyboard input
	if (!is_alive(entity_vampire) || !is_alive(entity_human)) break; // check if alive

	if (IsKeyPressed(KEY_A))
	{
	    bullet_a = create_bullet(bullet_a, entity_vampire, 4);
	}
	if (bullet_a.alive)
	{
	    bullet_a.pos.x = bullet_position(bullet_a);
	    if (check_collision(bullet_a.pos, bullet_a.size, entity_human.pos, entity_human.size))
	    {
		bullet_a.alive = false;
		entity_human.health = take_damage(entity_human, 50); // 50 is amount of damage they take.
	    }
	}

	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(entity_vampire); // draw entities to screen
	draw_entity(entity_human);
	draw_bullet(bullet_a);

	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
