#include "persistencia.h"
#include "dados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- CLIENTES ---

void salvarClientesCSV(void) {
    FILE *f = fopen("data/Clientes.csv", "w");
    if (f == NULL) return; // Erro

    // Formato: ID;TIPO;NOME/RAZAO;CPF/CNPJ;TELEFONE;EMAIL;ENDERECO
    for (int i = 0; i < numClientes; i++) {
        struct Cliente c = listaClientes[i];
        fprintf(f, "%d;%d;", c.id, c.tipo);

        if (c.tipo == PESSOA_FISICA) {
            fprintf(f, "%s;%s;", c.dados.pf.nome, c.dados.pf.cpf);
        } else {
            fprintf(f, "%s;%s;", c.dados.pj.razaoSocial, c.dados.pj.cnpj);
        }

        fprintf(f, "%s;%s;%s\n", c.telefone, c.email, c.endereco);
    }
    fclose(f);
}

void carregarClientesCSV(void) {
    FILE *f = fopen("data/Clientes.csv", "r");
    if (f == NULL) return; // Arquivo não existe

    numClientes = 0;
    char linha[512];

    while (fgets(linha, sizeof(linha), f) && numClientes < MAX_CLIENTES) {
        struct Cliente c;
        int tipoInt;
        char nomeRazao[100], doc[20];

        sscanf(linha, "%d;%d;%[^;];%[^;];%[^;];%[^;];%[^\n]",
               &c.id, &tipoInt, nomeRazao, doc,
               c.telefone, c.email, c.endereco);

        c.tipo = (enum TipoCliente)tipoInt;

        if (c.tipo == PESSOA_FISICA) {
            strcpy(c.dados.pf.nome, nomeRazao);
            strcpy(c.dados.pf.cpf, doc);
        } else {
            strcpy(c.dados.pj.razaoSocial, nomeRazao);
            strcpy(c.dados.pj.cnpj, doc);
        }

        listaClientes[numClientes] = c;
        numClientes++;
    }
    fclose(f);
}

// --- PRODUTOS ---

void salvarProdutosCSV(void) {
    FILE *f = fopen("data/Produtos.csv", "w");
    if (f == NULL) return;

    // Formato: ID;DESCRICAO;PRECO;ESTOQUE
    for (int i = 0; i < numProdutos; i++) {
        fprintf(f, "%d;%s;%.2f;%d\n",
                listaProdutos[i].id,
                listaProdutos[i].descricao,
                listaProdutos[i].preco,
                listaProdutos[i].estoque);
    }
    fclose(f);
}

void carregarProdutosCSV(void) {
    FILE *f = fopen("data/Produtos.csv", "r");
    if (f == NULL) return;

    numProdutos = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), f) && numProdutos < MAX_PRODUTOS) {
        struct Produto p;
        sscanf(linha, "%d;%[^;];%lf;%d",
               &p.id, p.descricao, &p.preco, &p.estoque);

        listaProdutos[numProdutos] = p;
        numProdutos++;
    }
    fclose(f);
}

// ================= PEDIDOS =================
void salvarPedidosCSV(void) {
    // Salva os Pedidos
    FILE *f = fopen("data/Pedidos.csv", "w");
    if (f != NULL) {
        for (int i = 0; i < numPedidos; i++) {
            fprintf(f, "%d;%d;%s;%.2f\n",
                    listaPedidos[i].id,
                    listaPedidos[i].clienteId,
                    listaPedidos[i].data,
                    listaPedidos[i].total);
        }
        fclose(f);
    }

    // Salva os Itens dos Pedidos
    f = fopen("data/ItensPedido.csv", "w");
    if (f != NULL) {
        for (int i = 0; i < numItensPedido; i++) {
            fprintf(f, "%d;%d;%d;%.2f\n",
                    listaItensPedido[i].pedidoId,
                    listaItensPedido[i].produtoId,
                    listaItensPedido[i].quantidade,
                    listaItensPedido[i].subtotal);
        }
        fclose(f);
    }
}

void carregarPedidosCSV(void) {
    // Carrega os Pedidos
    FILE *f = fopen("data/Pedidos.csv", "r");
    if (f != NULL) {
        numPedidos = 0;
        char linha[256];
        while (fgets(linha, sizeof(linha), f) && numPedidos < MAX_PEDIDOS) {
            struct Pedido p;
            sscanf(linha, "%d;%d;%[^;];%lf",
                   &p.id, &p.clienteId, p.data, &p.total);
            listaPedidos[numPedidos] = p;
            numPedidos++;
        }
        fclose(f);
    }

    // Carrega os Itens
    f = fopen("data/ItensPedido.csv", "r");
    if (f != NULL) {
        numItensPedido = 0;
        char linha[256];
        while (fgets(linha, sizeof(linha), f) && numItensPedido < MAX_ITENS_PEDIDO) {
            struct ItemPedido item;
            sscanf(linha, "%d;%d;%d;%lf",
                   &item.pedidoId, &item.produtoId, &item.quantidade, &item.subtotal);
            listaItensPedido[numItensPedido] = item;
            numItensPedido++;
        }
        fclose(f);
    }
}
