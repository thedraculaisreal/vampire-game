#include "entity.h"
#include "raylib.h"

int main(void)
{
    InitWindow(1800, 900, "vampire-game");

    while(!WindowShouldClose())
    {
	BeginDrawing();
	ClearBackground(WHITE);
	DrawText("First window", 400, 200, 12, RED);
	EndDrawing();
    }

    CloseWindow();

    return 0;
}


/*struct entity ent = create_entity("vampie");
struct entity ent2 = create_entity("human");
print_entity(ent);
ent.health = take_damage(ent, ent2);
print_entity(ent);*/
