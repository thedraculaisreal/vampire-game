#include <stdio.h>

struct entity
{
    const char* name;
    int health;
    int damage;
};

struct entity create_entity(const char* name);
void print_entity(struct entity ent);
int take_damage(struct entity ent, struct entity ent2);
