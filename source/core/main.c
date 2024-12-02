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
    Vector2 bullet_pos = {0 , 0};
    const Vector2 size_bullet = {10 , 5};
    struct entity entity_human;
    struct entity entity_vampire;
    Rectangle box_collision = { 0 };
    bool collision = false;
    bool bullet_alive = false; // if draw_bullet.
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
	entity_vampire.pos = movement(collision, entity_vampire.pos); // takes keyboard input
	if (!is_alive(entity_vampire) || !is_alive(entity_human)) break; // check if alive

	if (IsKeyPressed(KEY_A))
	{
	    bullet_pos = entity_vampire.pos;
	    bullet_pos.x += (entity_vampire.size.x + 1); // account for size of vampire body which is 100 by 100;
	    bullet_pos.y += (entity_vampire.size.y / 2);
	    bullet_alive = true;
	}

	BeginDrawing();
	ClearBackground(BLACK); // background color
	draw_entity(entity_vampire); // draw entities to screen
	draw_entity(entity_human);
	if (bullet_alive)
	{
	    DrawRectangleV(bullet_pos, size_bullet, RED);
	    bullet_pos.x += 4.0;
	    collision = check_collision(bullet_pos, size_bullet,
	    entity_human.pos, entity_human.size); // collision checks
	}
	if (collision)
	{
	    //DrawText("Collision = true", 400, 20, 20, WHITE);
	    //DrawText("Collision = false", 400, 20, 20, WHITE);
	    bullet_alive = false;
	    entity_human.health = take_damage(entity_human, 10);
	    collision = false;
	}

	EndDrawing();
    }

    // cleanup
    CloseWindow();
}
