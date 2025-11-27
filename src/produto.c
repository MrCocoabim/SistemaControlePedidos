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
