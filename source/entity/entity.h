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

struct entity entity_human;
struct entity entity_vampire;

void create_entity(struct entity ent, const char* name, Vector2 pos);
void draw_entity(struct entity ent);
int take_damage(struct entity ent, struct entity ent2);
bool is_alive(struct entity ent);
Vector2 move_entity(struct entity ent, Vector2 move);