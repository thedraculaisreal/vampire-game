#include "game.h"

void check_collision(bullet* b, entity* ent)
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

void movement(entity* ent)
{
    if (IsKeyDown(KEY_RIGHT))
    {
	ent->pos.x += 4.0;
    }
    if (IsKeyDown(KEY_LEFT))
    {
	ent->pos.x -= 4.0;
    }
    if (IsKeyDown(KEY_UP))
    {
	ent->pos.y -= 4.0;
    }
    if (IsKeyDown(KEY_DOWN))
    {
	ent->pos.y += 4.0;
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
