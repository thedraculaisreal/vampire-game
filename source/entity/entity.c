#include "entity.h"

void create_entity(struct entity ent, const char* name, Vector2 pos)
{
    const Vector2 size = {100, 100};
    ent.name = name;
    ent.health = 100;
    ent.damage = 10;
    ent.pos = pos;
    ent.size = size;
};

void draw_entity(struct entity ent)
{
    DrawRectangleV(ent.pos, ent.size, RED);
    Vector2 health_bar_pos = {ent.pos.x - 11, ent.pos.y};
    Vector2 health_bar_size = {10, ent.health};
    DrawRectangleV(health_bar_pos, health_bar_size, GREEN);
    DrawText(ent.name, ent.pos.x + 20, ent.pos.y + 20, 20, WHITE);
};

Vector2 move_entity(struct entity ent, Vector2 move)
{
    ent.pos.x += move.x;
    ent.pos.y += move.y;
    return ent.pos;
}

int take_damage(struct entity ent, struct entity ent2)
{
    return ent.health -= ent2.damage;
};

bool is_alive(struct entity ent)
{
    if (ent.health > 0)
    {
	return true;
    }
    else
    {
	return false;
    }
}
