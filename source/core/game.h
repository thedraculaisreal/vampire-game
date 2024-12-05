#include "../entity/entity.h"

typedef struct bullet
{
    Vector2 pos;
    Vector2 size;
    float x_change;
    bool alive;
} bullet;

void check_collision_bul(bullet* b, entity* ent);
void movement(entity* ent, entity* ent1);
void draw_bullet(bullet* b);
void create_bullet(bullet* b, entity* ent, float change);
void bullet_position(bullet* b);
bool check_collision_ent(entity* ent, entity* ent1);
void draw_wall(Rectangle (*rec)[8]);
void create_walls(Rectangle (*rec)[8]);
Rectangle create_wall(int x, int y, float w, float h);
