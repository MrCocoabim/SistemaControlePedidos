#include "pedido.h"
#include "dados.h"
#include <stdio.h>


// Procura um pedido pelo ID.
int procurarPedidoPorId(int id) {
    for (int i = 0; i < numPedidos; i++) {
        if (listaPedidos[i].id == id) {
            return 1;
        }
    }
    return 0;
}


// Retorna a posição do pedido no array.
int obterIndicePedido(int id) {
    for (int i = 0; i < numPedidos; i++) {
        if (listaPedidos[i].id == id) {
            return i;
        }
    }
    return -1;
}


// Remove um pedido e todos os seus itens associados.
int excluirPedido(int id) {
    int indice = obterIndicePedido(id);
    if (indice == -1) return 0; // Pedido não existente

    // Remover todos os itens deste pedido
    int i = 0;
    while (i < numItensPedido) {
        if (listaItensPedido[i].pedidoId == id) {
            // Remover o item
            for (int j = i; j < numItensPedido - 1; j++) {
                listaItensPedido[j] = listaItensPedido[j + 1];
            }
            numItensPedido--;
        } else {
            i++; // avança se não removeu
        }
    }

    // Remover o pedido
    for (int j = indice; j < numPedidos - 1; j++) {
        listaPedidos[j] = listaPedidos[j + 1];
    }
    numPedidos--;

    return 1;
}
