#include "entity.h"

struct entity create_entity()
{
    struct entity black;
    black.health = 25;
    black.damage = 10;
    return black;
};

void print_entity(struct entity ent)
{
    printf("Entity_Health:%d\nEntity_damage:%d\n", ent.health, ent.damage);
};
