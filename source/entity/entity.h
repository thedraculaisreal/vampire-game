#include <stdio.h>
#include "raylib.h"

struct entity
{
    const char* name;
    int health;
    int damage;
    Vector2 pos;
    Vector2 size;
};

struct entity create_entity(const char* name, Vector2 pos);
void draw_entity(struct entity ent);
int take_damage(struct entity ent, int damage);
bool is_alive(struct entity ent);
Vector2 move_entity(struct entity ent, Vector2 move);
