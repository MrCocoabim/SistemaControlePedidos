#ifndef DADOS_H
#define DADOS_H

#include "cliente.h"
#include "produto.h"
#include "pedido.h"

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100
#define MAX_PEDIDOS 100
#define MAX_ITENS_PEDIDO 500

// --- Arrays globais ---

extern struct Cliente listaClientes[MAX_CLIENTES];
extern int numClientes; // Contador de clientes

extern struct Produto listaProdutos[MAX_PRODUTOS];
extern int numProdutos; // Contador de produtos

extern struct Pedido listaPedidos[MAX_PEDIDOS];
extern int numPedidos; // Contador de pedidos

extern struct ItemPedido listaItensPedido[MAX_ITENS_PEDIDO];
extern int numItensPedido; // Contador de itens

#endif // DADOS_H
