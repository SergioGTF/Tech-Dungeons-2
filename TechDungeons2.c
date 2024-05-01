#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void Lógicadojogo();
void Jogador();
void DesenharMenu();
void DesenharTutorial();

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Masmorra Tecnológica 2");

    SetTargetFPS(60);

    enum { MENU, TUTORIAL } gameState = MENU;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (gameState) {
            case MENU:
                DesenharMenu();
                break;
            case TUTORIAL:
                DesenharTutorial();
                break;
        }

        EndDrawing();
        
        if (IsKeyPressed(KEY_ENTER)) {
            if (gameState == MENU) gameState = TUTORIAL;
            else if (gameState == TUTORIAL) gameState = MENU;
        }
    }

    CloseWindow();

    return 0;
}

void DesenharTextoCentralizado(const char* texto, int fontSize, int y, Color cor) {
    int textoWidth = MeasureText(texto, fontSize);
    int x = (SCREEN_WIDTH - textoWidth) / 2;
    DrawText(texto, x, y, fontSize, cor);
}

void DesenharMenu() {
    DesenharTextoCentralizado("Masmorra Tecnológica 2", 40, 10, BLACK);
    DesenharTextoCentralizado("Pressione ENTER para acessar o Tutorial", 20, 50, GRAY);
    DesenharTextoCentralizado("Pressione ESC para sair", 20, 80, GRAY);
}

void DesenharTutorial() {
    DesenharTextoCentralizado("Tutorial", 40, 10, BLACK);
    DesenharTextoCentralizado("Pressione ENTER para retornar ao Menu", 20, 50, GRAY);
    DesenharTextoCentralizado("Setas para cima/baixo para rolar", 20, 100, GRAY);
}
