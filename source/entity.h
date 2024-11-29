#include <stdio.h>

struct entity
{
    int health;
    int damage;
};

struct entity create_entity();
void print_entity(struct entity ent);
