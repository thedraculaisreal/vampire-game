#include "../entity/entity.h"

struct bullet
{
    Vector2 pos;
    Vector2 size;
    float x_change;
    bool alive;
};

bool check_collision(Vector2 pos, Vector2 size, Vector2 pos1, Vector2 size1);
Vector2 movement(Vector2 move);
void draw_bullet(struct bullet b);
struct bullet create_bullet(struct bullet b, struct entity ent, float change);
float bullet_position(struct bullet b);
