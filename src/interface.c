#include "interface.h"
#include <ncurses.h>
#include <string.h>

void inicializarInterface(void) {
    initscr();            // Inicializa a tela ncurses
    cbreak();             // Desabilita o buffer de linha
    noecho();             // Não mostra o que o usuário digita
    keypad(stdscr, TRUE); // Habilita teclas especiais (setas, etc.)
    start_color();        // Inicializa o sistema de cores

    // Branco no Preto
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // Preto no Branco
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
}

void finalizarInterface(void) {
    endwin(); // Restaura o terminal ao modo original
}

//Desenha o menu principal
int mostrarMenuPrincipal (void){
	char *opcoes[] = {
        "1. Gerenciar Clientes",
        "2. Gerenciar Produtos",
        "3. Gerenciar Pedidos",
        "4. Sair"
    };
    int numOpcoes = 4;
    int destacado = 0; // Opção destacada quando selecionada
    int escolha = -1;
    int ch;

    // Cria a janela do menu no centro da tela
    int altura = 10;
    int largura = 40;
    int y = (LINES - altura) / 2; // Posição Y linha
    int x = (COLS - largura) / 2; // Posição X coluna
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE); // Habilita setas na janela

    while (escolha == -1) {
        wclear(menuWin); // Limpa a janela do menu
        box(menuWin, 0, 0); // Desenha a borda

        // Título
        wattron(menuWin, COLOR_PAIR(2)); // Liga cor de destaque
        mvwprintw(menuWin, 1, (largura - 24) / 2, "Sistema de Pedidos (SCP)");
        wattroff(menuWin, COLOR_PAIR(2)); // Desliga cor

        // Imprime as opções
        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2)); // Destaque ligano
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2)); // Destaque desligado
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }

        wrefresh(menuWin); // Atualiza a janela do menu

        ch = wgetch(menuWin); // Espera o usuário pressionar uma tecla

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10: // Tecla ENTER
                escolha = destacado;
                break;
        }
    }

    delwin(menuWin); // Apaga a janela do menu

    // Retorna a escolha
    // Adiciona +1 para corresponder ao número da opção
    return escolha + 1;
}


// ########## MENU DE CLIENTES ##########
void mostrarMenuClientes(void) {
    char *opcoes[] = {
        "1. Cadastrar Cliente",
        "2. Listar Clientes",
        "3. Consultar Cliente",
        "4. Remover Cliente",
        "5. Voltar"
    };
    int numOpcoes = 5;
    int destacado = 0;
    int escolha = -1;
    int ch;

    int altura = 12;
    int largura = 40;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE);

    while (escolha == -1) {
        wclear(menuWin);
        box(menuWin, 0, 0);

        wattron(menuWin, COLOR_PAIR(2));
        mvwprintw(menuWin, 1, (largura - 20) / 2, "GERENCIAR CLIENTES");
        wattroff(menuWin, COLOR_PAIR(2));

        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2));
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2));
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }
        wrefresh(menuWin);
        ch = wgetch(menuWin);

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10: // ENTER
                escolha = destacado + 1;
                if (escolha == 5) // Voltar
                    escolha = -2;
                break;
        }
        if (escolha == -2) // Sair do loop
            break;

    }
    delwin(menuWin);
}



// ########## MENU DE PRODUTOS ##########
void mostrarMenuProdutos(void) {
    char *opcoes[] = {
        "1. Cadastrar Produto",
        "2. Listar Produtos",
        "3. Consultar Produto",
        "4. Remover Produto",
        "5. Voltar"
    };
    int numOpcoes = 5;
    int destacado = 0;
    int escolha = -1;
    int ch;

    int altura = 12;
    int largura = 40;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE);

    while (escolha == -1) {
        wclear(menuWin);
        box(menuWin, 0, 0);

        wattron(menuWin, COLOR_PAIR(2));
        mvwprintw(menuWin, 1, (largura - 20) / 2, "GERENCIAR PRODUTOS");
        wattroff(menuWin, COLOR_PAIR(2));

        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2));
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2));
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }
        wrefresh(menuWin);
        ch = wgetch(menuWin);

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10: // ENTER
                escolha = destacado + 1;
                if (escolha == 5) // "Voltar"
                    escolha = -2;
                break;
        }
        if (escolha == -2) // Sair do loop
            break;

    }
    delwin(menuWin);
}



// ########## MENU DE PEDIDOS ##########
void mostrarMenuPedidos(void) {
    char *opcoes[] = {
        "1. Cadastrar Pedido",
        "2. Listar Pedidos",
        "3. Consultar Pedido",
        "4. Remover Pedido",
        "5. Voltar"
    };
    int numOpcoes = 5;
    int destacado = 0;
    int escolha = -1;
    int ch;

    int altura = 12;
    int largura = 40;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE);

    while (escolha == -1) {
        wclear(menuWin);
        box(menuWin, 0, 0);

        wattron(menuWin, COLOR_PAIR(2));
        mvwprintw(menuWin, 1, (largura - 19) / 2, "GERENCIAR PEDIDOS");
        wattroff(menuWin, COLOR_PAIR(2));

        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2));
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2));
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }
        wrefresh(menuWin);
        ch = wgetch(menuWin);

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10: // ENTER
                escolha = destacado + 1;
                if (escolha == 5) // "Voltar"
                    escolha = -2;
                break;
        }
        if (escolha == -2) // Sair do loop
            break;

    }
    delwin(menuWin);
}
