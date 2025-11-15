#include "interface.h"
#include <ncurses.h>

int main() {

    // Inicializar a ncurses
	inicializarInterface();

    int escolha = 0;
    // Loop principal do menu
    while (escolha != 4) {

        clear(); // Limpa a tela toda
        refresh(); // Atualiza a tela

        escolha = mostrarMenuPrincipal();

        switch (escolha) {
            case 1:
                mostrarMenuClientes();
                break;
            case 2:
                mostrarMenuProdutos();
                break;
            case 3:
                mostrarMenuPedidos();
                break;
            case 4:
                // Sair
                break;
        }

    }

    finalizarInterface();
    return 0;
}
