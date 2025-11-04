#ifndef PEDIDO_H
#define PEDIDO_H

// Define a struct Pedido
struct Pedido {
    int id;
    int clienteId; // ID de Referência para Cliente
    char data[11]; // Formato: dd/mm/aaaa
    double total;
};

// Define a struct ItemPedido
// Esta struct "conecta" um Pedido a um Produto
struct ItemPedido {
    int pedidoId; // ID de Referência para Pedido
    int produtoId; // ID de Referência para Produto
    int quantidade;
    double subtotal; // subtotal = quantidade * preco do produto
};

#endif // PEDIDO_H