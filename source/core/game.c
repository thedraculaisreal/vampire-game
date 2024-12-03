#include "game.h"

bool check_collision(Vector2 pos, Vector2 size, Vector2 pos1, Vector2 size1)
{
    // make our rectangles for collision checks.
    Rectangle rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.height = size.y;
    rect.width = size.x;
    Rectangle rect1;
    rect1.x = pos1.x;
    rect1.y = pos1.y;
    rect1.height = size1.y;
    rect1.width = size1.x;

    return CheckCollisionRecs(rect, rect1); // if collision, it returns true if not returns false.
}

Vector2 movement(Vector2 move)
{
    if (IsKeyDown(KEY_RIGHT))
    {
	move.x += 4.0;
    }
    if (IsKeyDown(KEY_LEFT))
    {
	move.x -= 4.0;
    }
    if (IsKeyDown(KEY_UP))
    {
	move.y -= 4.0;
    }
    if (IsKeyDown(KEY_DOWN))
    {
	move.y += 4.0;
    }

    return move;
}

const static Vector2 bullet_size = {10 , 5};

struct bullet create_bullet(struct bullet b, struct entity ent, float change)
{
    b.pos = ent.pos;
    b.pos.x += ent.size.x + 1;
    b.pos.y += ent.size.y / 2;
    b.size = bullet_size;
    b.x_change = change;
    b.alive = true;
    return b;
}

void draw_bullet(struct bullet b)
{
    if (!b.alive) return;

    DrawRectangleV(b.pos, b.size, YELLOW);
}

float bullet_position(struct bullet b)
{
    return b.pos.x += b.x_change;
}
