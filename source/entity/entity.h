#include <stdio.h>
#include "raylib.h"

typedef struct entity
{
    const char* name;
    int health;
    int damage;
    Vector2 pos;
    Vector2 size;
} entity;

entity create_entity(const char* name, Vector2 pos);
void draw_entity(entity* ent);
void take_damage(entity* ent, int damage);
bool is_alive(entity* ent);
void move_entity(entity* ent, Vector2 move);
