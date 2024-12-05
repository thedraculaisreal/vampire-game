#include "game.h"

void check_collision_bul(bullet* b, entity* ent)
{
    // make our rectangles for collision checks.
    Rectangle rect;
    rect.x = b->pos.x;
    rect.y = b->pos.y;
    rect.height = b->size.y;
    rect.width = b->size.x;
    Rectangle rect1;
    rect1.x = ent->pos.x;
    rect1.y = ent->pos.y;
    rect1.height = ent->size.y;
    rect1.width = ent->size.x;

    if (CheckCollisionRecs(rect, rect1)) // if collision, it returns true if not returns false.
    {
	b->alive = false;
	ent->health -= 10; // bullet damage
    }
    else
    {
	return;
    }
}

bool check_collision_ent(entity* ent, entity* ent1)
{
    // make our rectangles for collision checks.
    Rectangle rect;
    rect.x = ent->pos.x;
    rect.y = ent->pos.y;
    rect.height = ent->size.y;
    rect.width = ent->size.x;
    Rectangle rect1;
    rect1.x = ent1->pos.x;
    rect1.y = ent1->pos.y;
    rect1.height = ent1->size.y;
    rect1.width = ent1->size.x;

    return (CheckCollisionRecs(rect, rect1)); // if collision, it returns true if not returns false.
}

void movement(entity* ent, entity* ent1)
{
    if (IsKeyDown(KEY_RIGHT))
    {
	ent->pos.x += 4.0;
	if (check_collision_ent(ent, ent1))
	{
	    ent->pos.x -= 6.0;
	    take_damage(ent, 1);
	    take_damage(ent1, 1);
	}
    }
    if (IsKeyDown(KEY_LEFT))
    {
	ent->pos.x -= 4.0;
	if (check_collision_ent(ent, ent1))
	{
	    ent->pos.x += 6.0;
	    take_damage(ent, 1);
	    take_damage(ent1, 1);
	}
    }
    if (IsKeyDown(KEY_UP))
    {
	ent->pos.y -= 4.0;
	if (check_collision_ent(ent, ent1))
	{
	    ent->pos.y += 6.0;
	    take_damage(ent, 1);
	    take_damage(ent1, 1);
	}
    }
    if (IsKeyDown(KEY_DOWN))
    {
	ent->pos.y += 4.0;
	if (check_collision_ent(ent, ent1))
	{
	    ent->pos.y -= 6.0;
	    take_damage(ent, 1);
	    take_damage(ent1, 1);
	}
    }
}

const static Vector2 bullet_size = {10 , 5};

void create_bullet(bullet* b, entity* ent, float change)
{
    b->pos = ent->pos;
    if (change > 0)
    {
	b->pos.x += ent->size.x + 1;
	b->pos.y += ent->size.y / 2;
    }
    else
    {
	b->pos.x -= 11;
	b->pos.y += ent->size.y / 2;
    }
    b->size = bullet_size;
    b->x_change = change;
    b->alive = true;
}

void draw_bullet(bullet* b)
{
    if (!b->alive) return;

    DrawRectangleV(b->pos, b->size, YELLOW);
}

void bullet_position(bullet* b)
{
    b->pos.x += b->x_change;
}

void draw_wall(Rectangle (*rec)[8])
{
    for(int i = 0; i <= 7; i++)
    {
	//if (rec[i] == NULL) continue;
	DrawRectangleRec((*rec)[i], YELLOW);
    }
}

void create_walls(Rectangle (*rec)[8])
{
    (*rec)[0] = create_wall(0, 750, 600, 50);
    (*rec)[1] = create_wall(800, 750, 600, 50);
    (*rec)[2] = create_wall(1350, 500, 50, 300);
    (*rec)[3] = create_wall(1350, 0, 50, 300);
    (*rec)[4] = create_wall(800, 0, 600, 50);
    (*rec)[5] = create_wall(0, 0, 600, 50);
    (*rec)[6] = create_wall(0, 0, 50, 300);
    (*rec)[7] = create_wall(0, 500, 50, 300);
}

Rectangle create_wall(int x, int y, float w, float h)
{
    Rectangle rec = { x, y, w, h};
    return rec;
}
