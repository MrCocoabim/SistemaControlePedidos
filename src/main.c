#include "interface.h"
#include <ncurses.h>
#include "cliente.h"
#include "persistencia.h"

int main() {

    // Carrega os dados do disco
    carregarClientesCSV();
    carregarProdutosCSV();
    carregarPedidosCSV();
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
                break;
        }

    }

    finalizarInterface();
    // Salva os dados no disco quando sai
    salvarClientesCSV();
    salvarProdutosCSV();
    salvarPedidosCSV();

    return 0;
}
