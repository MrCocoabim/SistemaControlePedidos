#include "produto.h"
#include "dados.h"
#include <stdio.h>


// Procura um produto pelo ID.
int procurarProdutoPorId(int id) {
    for (int i = 0; i < numProdutos; i++) {
        if (listaProdutos[i].id == id) {
            return 1;
        }
    }
    return 0;
}


// Retorna a posição do produto no array.
int obterIndiceProduto(int id) {
    for (int i = 0; i < numProdutos; i++) {
        if (listaProdutos[i].id == id) {
            return i;
        }
    }
    return -1;
}

 // Verifica se o produto está sendo usado em algum pedido.
int verificarProdutoEmPedidos(int id) {
    for (int i = 0; i < numItensPedido; i++) {
        if (listaItensPedido[i].produtoId == id) {
            return 1; // Está em uso.
        }
    }
    return 0; // Não está em nenhum pedido.
}


// Remove um produto e reorganiza o array.
int excluirProduto(int id) {
    int indice = obterIndiceProduto(id);
    if (indice == -1) return 0;

    for (int i = indice; i < numProdutos - 1; i++) {
        listaProdutos[i] = listaProdutos[i + 1];
    }
    numProdutos--;
    return 1;
}
