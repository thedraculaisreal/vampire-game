#include "entity.h"

int main()
{
    struct entity ent = create_entity("vampie");
    struct entity ent2 = create_entity("human");
    print_entity(ent);
    ent.health = take_damage(ent, ent2);
    print_entity(ent);
    return 0;
}
