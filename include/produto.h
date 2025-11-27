#ifndef PRODUTO_H
#define PRODUTO_H

// Define a struct Produto
struct Produto {
    int id;
    char descricao[100];
    double preco;
    int estoque;
};

int procurarProdutoPorId(int id);
int obterIndiceProduto(int id);
int verificarProdutoEmPedidos(int id);
int excluirProduto(int id);


#endif // PRODUTO_H
