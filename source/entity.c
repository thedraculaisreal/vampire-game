#include "entity.h"

struct entity create_entity(const char* name)
{
    struct entity ent;
    ent.name = name;
    ent.health = 100;
    ent.damage = 10;
    return ent;
};

void print_entity(struct entity ent)
{
    printf("entity_name = %s entity_health = %d entity_damage = %d\n", ent.name, ent.health, ent.damage);
};

int take_damage(struct entity ent, struct entity ent2)
{
    return ent.health -= ent2.damage;
};
