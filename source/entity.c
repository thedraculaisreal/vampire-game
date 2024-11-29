#include "entity.h"

struct entity create_entity()
{
    struct entity ent;
    ent.health = 100;
    ent.damage = 10;
    return ent;
};

void print_entity(struct entity ent)
{
    printf("entity_health = %d\entity_damage = %d\n", ent.health, ent.damage);
    printf("The entity attacks itself, entity loses health\n");
    printf("entity_new_health = %d\n", ent.health -= ent.damage);
};
