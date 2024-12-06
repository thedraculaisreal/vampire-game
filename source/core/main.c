#include "rooms.h"
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
    const Vector2 pos2 = { 700, 400};
    Rectangle array_walls[8];
    entity entity_human;
    entity entity_vampire;
    bullet bullet_a;
    bullet bullet_d;
    Rectangle door = { 600, 0, 200, 50};
    SetTargetFPS(60); // set game fps.

    // Create entitys
    entity_vampire = create_entity("vampire", pos1);
    entity_human = create_entity("human", pos2);
    create_walls(&array_walls);
    // variables for window and rectangles
    const int window_width = 1400;
    const int window_height = 800;
    const char* window_name = "kill-humans";
    bool switch_rooms = false;

    // raylib initialization.
    InitWindow(window_width, window_height, window_name);
    while(!WindowShouldClose())
    {
	movement(&entity_vampire, &entity_human, &array_walls); // takes keyboard input
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

	if (!switch_rooms)
	{
	    room_1(&bullet_a, &bullet_d, &array_walls, &entity_vampire, &entity_human, &door);
	}
	else
	{
	    room_2(&bullet_a, &bullet_d, &array_walls, &entity_vampire, &entity_human, &door);
	}

	if (check_collision_wall(&entity_vampire, door))
	{
	    switch_rooms = !switch_rooms;
	    if (switch_rooms)
	    {
		door.x = 600; door.y = 750;
		entity_vampire.pos.x = 700; entity_vampire.pos.y = 600;
		entity_human.pos.x = 0; entity_human.pos.y = 0; entity_human.size.y = 0; // getting rid of ent1
	    }
	    else
	    {
		door.x = 600; door.y = 0;
		entity_vampire.pos.x = 700; entity_vampire.pos.y = 100;
		entity_human.pos = pos2; entity_human.size.y = 100; // getting rid of ent1
	    }
	}
    }

    // cleanup
    CloseWindow();
}
