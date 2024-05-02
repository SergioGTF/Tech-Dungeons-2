#include <raylib.h>

#define LARGURA_TELA 900
#define ALTURA_TELA 800


void Jogador();
void DesenharMenu();
void DesenharTutorial();
void Jogar();

int main() {
    InitWindow(LARGURA_TELA, ALTURA_TELA, "TECH DUNGEONS 2");

    SetTargetFPS(60);

    enum { MENU, TUTORIAL, JOGANDO } gameState = MENU;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RED); 

        switch (gameState) {
            case MENU:
                DesenharMenu();
                break;
            case TUTORIAL:
                DesenharTutorial();
                break;
            case JOGANDO:
                Jogar();
                Jogador();
                break;
        }

        EndDrawing();
        
        if (IsKeyPressed(KEY_T)) {
            if (gameState == MENU) gameState = TUTORIAL;
            else if (gameState == TUTORIAL) gameState = MENU;
        } else if (IsKeyPressed(KEY_J)) {
            if (gameState == MENU) gameState = JOGANDO;
            else if (gameState == JOGANDO) gameState = MENU;
        }
    }

    CloseWindow();

    return 0;
}

void DesenharTextoCentralizado(const char* texto, int fontSize, int y, Color cor) {
    int textoWidth = MeasureText(texto, fontSize);
    int x = (LARGURA_TELA - textoWidth) / 2;
    DrawText(texto, x, y, fontSize, cor);
}

void DesenharMenu() {
    DesenharTextoCentralizado("TECH DUNGEONS 2", 40, 10, BLACK);
    DesenharTextoCentralizado("Pressione T para acessar o Tutorial", 20, 50, BLACK);
    DesenharTextoCentralizado("Pressione J para jogar", 20, 80, BLACK);
    DesenharTextoCentralizado("Pressione ESC para sair", 20, 110, BLACK);
}

void DesenharTutorial() {
    DesenharTextoCentralizado("Tutorial", 40, 10, BLACK);
    DesenharTextoCentralizado("Objetivo: Passar por três níveis.", 20, 50, GREEN);
    DesenharTextoCentralizado("Comandos:", 20, 80, GREEN);
    DesenharTextoCentralizado("W: Mover para cima", 20, 110, GREEN);
    DesenharTextoCentralizado("A: Mover para esquerda", 20, 140, GREEN);
    DesenharTextoCentralizado("S: Mover para baixo", 20, 170, GREEN);
    DesenharTextoCentralizado("D: Mover para direita", 20, 200, GREEN);
    DesenharTextoCentralizado("I: Interagir com objeto", 20, 230, GREEN);
    DesenharTextoCentralizado("Simbologia:", 20, 260, GREEN);
    DesenharTextoCentralizado("&: Jogador", 20, 290, GREEN);
    DesenharTextoCentralizado("*: Parede", 20, 320, GREEN);
    DesenharTextoCentralizado("@: Chave", 20, 350, GREEN);
    DesenharTextoCentralizado("D: Porta fechada", 20, 380, GREEN);
    DesenharTextoCentralizado("=: Porta aberta", 20, 410, GREEN);
    DesenharTextoCentralizado("O: Botão", 20, 440, GREEN);
    DesenharTextoCentralizado("#: Espinho", 20, 470, GREEN);
    DesenharTextoCentralizado(">: Teletransporte", 20, 500, GREEN);
    DesenharTextoCentralizado("X: Monstro Nível 1", 20, 530, GREEN);
    DesenharTextoCentralizado("K: Monstro Nível 2", 20, 560, GREEN);
    DesenharTextoCentralizado("Pressione ENTER para retornar ao Menu.", 20, 590, GREEN);
}

void Jogar() {
}

void Jogador() {
}
