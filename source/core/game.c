#include "game.h"

bool check_collision(struct entity ent, struct entity ent2)
{
    // make our rectangles for collision checks.
    Rectangle vampire_rect;
    vampire_rect.x = ent.pos.x;
    vampire_rect.y = ent.pos.y;
    vampire_rect.height = ent.size.y;
    vampire_rect.width = ent.size.x;
    Rectangle human_rect;
    human_rect.x = ent2.pos.x;
    human_rect.y = ent2.pos.y;
    human_rect.height = ent2.size.y;
    human_rect.width = ent2.size.x;

    return (CheckCollisionRecs(vampire_rect, human_rect)); // if collision, it returns true if not returns false.
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
