#include "entity.h"

struct entity create_entity(const char* name, Vector2 pos)
{
    const Vector2 size = {100, 100};
    struct entity ent;
    ent.name = name;
    ent.health = 100;
    ent.damage = 10;
    ent.pos = pos;
    ent.size = size;
    return ent;
};

void draw_entity(struct entity ent)
{
    DrawRectangleV(ent.pos, ent.size, RED);
    Vector2 health_bar_pos = {ent.pos.x - 11, ent.pos.y};
    Vector2 health_bar_size = {10, ent.health};
    DrawRectangleV(health_bar_pos, health_bar_size, GREEN);
    DrawText(ent.name, ent.pos.x + 20, ent.pos.y + 20, 20, WHITE);
};

float move_entity(struct entity ent, float x)
{
    return ent.pos.x + x;
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
