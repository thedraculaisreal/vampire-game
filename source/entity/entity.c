#include "entity.h"

entity create_entity(const char* name, Vector2 pos)
{
    entity ent;
    const Vector2 size = { 100, 100};
    ent.name = name;
    ent.health = 100;
    ent.damage = 10;
    ent.pos = pos;
    ent.size = size;
    return ent;
};

void draw_entity(entity* ent)
{
    DrawRectangleV(ent->pos, ent->size, RED);
    Vector2 health_bar_pos = {ent->pos.x - 11, ent->pos.y};
    Vector2 health_bar_size = {10, ent->health};
    DrawRectangleV(health_bar_pos, health_bar_size, GREEN);
    DrawText(ent->name, ent->pos.x + 20, ent->pos.y + 20, 20, WHITE);
};

void move_entity(entity* ent, Vector2 move)
{
    ent->pos.x += move.x;
    ent->pos.y += move.y;
};

void take_damage(entity* ent, int damage)
{
    ent->health -= damage;
};

bool is_alive(entity* ent)
{
    if (ent->health > 0)
    {
	return true;
    }
    else
    {
	return false;
    }
}
