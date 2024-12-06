#include "rooms.h"

void room_1(bullet* b, bullet* b1, Rectangle (*rec)[8], entity* ent, entity* ent1, Rectangle* rec1)
{
    BeginDrawing();
    ClearBackground(BLACK); // background color
    draw_wall(rec);
    draw_entity(ent); // draw entities to screen
    draw_entity(ent1);
    draw_bullet(b);
    draw_bullet(b1);
    draw_door(rec1);
    EndDrawing();
}

void draw_door(Rectangle* rec)
{
    DrawRectangleRec(*rec, GREEN);
}

void room_2(bullet* b, bullet* b1, Rectangle (*rec)[8], entity* ent, entity* ent1, Rectangle* rec1)
{
    BeginDrawing();
    ClearBackground(BLACK); // background color
    draw_wall(rec);
    draw_entity(ent); // draw entities to screen
    draw_bullet(b);
    draw_bullet(b1);
    draw_door(rec1);
    EndDrawing();
}
