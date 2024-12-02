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

    return (CheckCollisionRecs(rect, rect1)); // if collision, it returns true if not returns false.
}

Vector2 movement(bool collision, Vector2 move)
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
