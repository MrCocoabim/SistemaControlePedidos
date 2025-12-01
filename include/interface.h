#ifndef INTERFACE_H
#define INTERFACE_H

void inicializarInterface(void);
void finalizarInterface(void);
int mostrarMenuPrincipal(void);

// Funções do submenu
void mostrarMenuClientes(void);
void mostrarMenuProdutos(void);
void mostrarMenuPedidos(void);

// Telas de cliente
void telaCadastrarCliente(void);
void telaListarClientes(void);
void telaConsultarCliente(void);
void telaRemoverCliente(void);

// Telas de Produto
void telaCadastrarProduto(void);
void telaListarProdutos(void);
void telaConsultarProduto(void);
void telaRemoverProduto(void);

// Telas de Pedido
void telaCadastrarPedido(void);
void telaListarPedidos(void);
void telaConsultarPedido(void);
void telaRemoverPedido(void);

#endif // INTERFACE_H

