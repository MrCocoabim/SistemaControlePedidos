#include "interface.h"
#include <ncurses.h>
#include <string.h>
#include "dados.h"
#include <stdlib.h>


void inicializarInterface(void) {
    initscr();            // Inicializa a tela ncurses
    cbreak();             // Desabilita o buffer de linha
    noecho();             // Não mostra o que o usuário digita
    keypad(stdscr, TRUE); // Habilita teclas especiais (setas, etc.)
    start_color();        // Inicializa o sistema de cores

    // Branco no Preto
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // Preto no Branco
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
}

void finalizarInterface(void) {
    endwin(); // Restaura o terminal ao modo original
}

//Desenha o menu principal
int mostrarMenuPrincipal (void){
	char *opcoes[] = {
        "1. Gerenciar Clientes",
        "2. Gerenciar Produtos",
        "3. Gerenciar Pedidos",
        "4. Sair"
    };
    int numOpcoes = 4;
    int destacado = 0; // Opção destacada quando selecionada
    int escolha = -1;
    int ch;

    // Cria a janela do menu no centro da tela
    int altura = 10;
    int largura = 40;
    int y = (LINES - altura) / 2; // Posição Y linha
    int x = (COLS - largura) / 2; // Posição X coluna
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE); // Habilita setas na janela

    while (escolha == -1) {
        wclear(menuWin); // Limpa a janela do menu
        box(menuWin, 0, 0); // Desenha a borda

        // Título
        wattron(menuWin, COLOR_PAIR(2)); // Liga cor de destaque
        mvwprintw(menuWin, 1, (largura - 24) / 2, "Sistema de Pedidos (SCP)");
        wattroff(menuWin, COLOR_PAIR(2)); // Desliga cor

        // Imprime as opções
        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2)); // Destaque ligano
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2)); // Destaque desligado
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }

        wrefresh(menuWin); // Atualiza a janela do menu

        ch = wgetch(menuWin); // Espera o usuário pressionar uma tecla

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10: // Tecla ENTER
                escolha = destacado;
                break;
        }
    }

    delwin(menuWin); // Apaga a janela do menu

    // Retorna a escolha
    // Adiciona +1 para corresponder ao número da opção
    return escolha + 1;
}


// ########## MENU DE CLIENTES ##########
void mostrarMenuClientes(void) {
    char *opcoes[] = {
        "1. Cadastrar Cliente",
        "2. Listar Clientes",
        "3. Consultar Cliente",
        "4. Remover Cliente",
        "5. Voltar"
    };
    int numOpcoes = 5;
    int destacado = 0;
    int escolha = -1;
    int ch;

    int altura = 12;
    int largura = 40;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE);

    while (escolha == -1) {
        wclear(menuWin);
        box(menuWin, 0, 0);

        wattron(menuWin, COLOR_PAIR(2));
        mvwprintw(menuWin, 1, (largura - 20) / 2, "GERENCIAR CLIENTES");
        wattroff(menuWin, COLOR_PAIR(2));

        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2));
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2));
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }
        wrefresh(menuWin);
        ch = wgetch(menuWin);

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10:
                escolha = destacado + 1;
                if (escolha == 5)
                    escolha = -2;
                break;
        }

        if (escolha == -2) {
            break;
        }

        if (escolha != -1) { 
            switch (escolha) {
                case 1:// Cadastrar Cliente
                    clear();
                    refresh();
                    telaCadastrarCliente();
                    escolha = -1;// Reseta
                    break;
                case 2: // Listar
                    clear();
                    refresh();
                    telaListarClientes();
                    escolha = -1;
                    break;
                case 3:// Consultar
                    clear();
                    refresh();
                    telaConsultarCliente();
                    escolha = -1;
                    break;
                case 4: // Remover
                    clear();
                    refresh();
                    telaRemoverCliente();
                    escolha = -1; // Reseta
                    break;
            }
        }
    }
    delwin(menuWin);
}

// ########## MENU DE PRODUTOS ##########
void mostrarMenuProdutos(void) {
    char *opcoes[] = {
        "1. Cadastrar Produto",
        "2. Listar Produtos",
        "3. Consultar Produto",
        "4. Remover Produto",
        "5. Voltar"
    };
    int numOpcoes = 5;
    int destacado = 0;
    int escolha = -1;
    int ch;

    int altura = 12;
    int largura = 40;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE);

    while (escolha == -1) {
        wclear(menuWin);
        box(menuWin, 0, 0);

        wattron(menuWin, COLOR_PAIR(2));
        mvwprintw(menuWin, 1, (largura - 20) / 2, "GERENCIAR PRODUTOS");
        wattroff(menuWin, COLOR_PAIR(2));

        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2));
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2));
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }
        wrefresh(menuWin);
        ch = wgetch(menuWin);

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10:
                escolha = destacado + 1;
                if (escolha == 5)
                    escolha = -2;
                break;
        }

        if (escolha == -2) {
            break;
        }

        if (escolha != -1) {
            switch (escolha) {
                case 1: // Cadastrar
                    clear(); refresh();
                    telaCadastrarProduto();
                    escolha = -1;
                    break;
                case 2: // Listar
                    clear(); refresh();
                    telaListarProdutos();
                    escolha = -1;
                    break;
                case 3: // Consultar
                    clear(); refresh();
                    telaConsultarProduto();
                    escolha = -1;
                    break;
                case 4: // Remover
                    clear(); refresh();
                    telaRemoverProduto();
                    escolha = -1;
                    break;
            }
        }
     }
    delwin(menuWin);
}

// ######## MENU DE PEDIDOS ##########
void mostrarMenuPedidos(void) {
    char *opcoes[] = {
        "1. Cadastrar Pedido",
        "2. Listar Pedidos",
        "3. Consultar Pedido",
        "4. Remover Pedido",
        "5. Voltar"
    };
    int numOpcoes = 5;
    int destacado = 0;
    int escolha = -1;
    int ch;

    int altura = 12;
    int largura = 40;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *menuWin = newwin(altura, largura, y, x);
    keypad(menuWin, TRUE);

    while (escolha == -1) {
        wclear(menuWin);
        box(menuWin, 0, 0);

        wattron(menuWin, COLOR_PAIR(2));
        mvwprintw(menuWin, 1, (largura - 19) / 2, "GERENCIAR PEDIDOS");
        wattroff(menuWin, COLOR_PAIR(2));

        for (int i = 0; i < numOpcoes; i++) {
            if (i == destacado) {
                wattron(menuWin, COLOR_PAIR(2));
                mvwprintw(menuWin, i + 3, 4, "-> %s", opcoes[i]);
                wattroff(menuWin, COLOR_PAIR(2));
            } else {
                mvwprintw(menuWin, i + 3, 4, "   %s", opcoes[i]);
            }
        }
        wrefresh(menuWin);
        ch = wgetch(menuWin);

        switch (ch) {
            case KEY_UP:
                destacado = (destacado == 0) ? numOpcoes - 1 : destacado - 1;
                break;
            case KEY_DOWN:
                destacado = (destacado == numOpcoes - 1) ? 0 : destacado + 1;
                break;
            case 10: // ENTER
                escolha = destacado + 1;
                if (escolha == 5) // "Voltar"
                    escolha = -2;
                break;
        }
        if (escolha == -2) // Sair do loop
            break;

    }
    delwin(menuWin);
}


// ########## TELA DE CADASTRO DE CLIENTE ##########
void telaCadastrarCliente(void) {
    // --- Verifica se está cheio ---
    if (numClientes >= MAX_CLIENTES) {
        clear();
        mvprintw(LINES / 2, (COLS - 30) / 2, "ERRO: Limite de clientes atingido!");
        mvprintw(LINES / 2 + 1, (COLS - 30) / 2, "Pressione qualquer tecla...");
        refresh();
        getch();
        return;
    }

    // --- Cria a janela do formulário ---
    int altura = 20, largura = 70;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *formWin = newwin(altura, largura, y, x);
    box(formWin, 0, 0);

    wattron(formWin, COLOR_PAIR(2));
    mvwprintw(formWin, 1, (largura - 20) / 2, "CADASTRAR NOVO CLIENTE");
    wattroff(formWin, COLOR_PAIR(2));

    // Variáveis temporárias
    char idStr[10], tipoClienteStr[3], documento[20];
    struct Cliente novoCliente; // Cliente temporário

    echo();

    // Obter e Validar ID
    mvwprintw(formWin, 3, 2, "ID (numerico): ");
    wgetnstr(formWin, idStr, 9);
    novoCliente.id = atoi(idStr);

    if (novoCliente.id <= 0) {
        mvwprintw(formWin, 16, 2, "ERRO: ID deve ser um numero positivo! Pressione tecla...");
        noecho(); wgetch(formWin); delwin(formWin); return;
    }
    if (procurarClientePorId(novoCliente.id) == 1) {
        mvwprintw(formWin, 16, 2, "ERRO: ID ja cadastrado! Pressione tecla...");
        noecho(); wgetch(formWin); delwin(formWin); return;
    }

    // Validar Tipo e Documento
    mvwprintw(formWin, 4, 2, "Tipo (PF ou PJ): ");
    wgetnstr(formWin, tipoClienteStr, 2);

    if (tipoClienteStr[0] == 'p') tipoClienteStr[0] = 'P';
    if (tipoClienteStr[1] == 'f') tipoClienteStr[1] = 'F';
    if (tipoClienteStr[1] == 'j') tipoClienteStr[1] = 'J';

    if (strcmp(tipoClienteStr, "PF") == 0) {
        novoCliente.tipo = PESSOA_FISICA;
        mvwprintw(formWin, 6, 2, "Nome: ");
        wgetnstr(formWin, novoCliente.dados.pf.nome, 99);
        mvwprintw(formWin, 7, 2, "CPF (com ou sem pontos): ");
        wgetnstr(formWin, documento, 14);

        if (validarCPF(documento) == 0) {
            mvwprintw(formWin, 16, 2, "ERRO: CPF invalido! Pressione tecla...");
            noecho(); wgetch(formWin); delwin(formWin); return;
        }
        strcpy(novoCliente.dados.pf.cpf, documento);

    } else if (strcmp(tipoClienteStr, "PJ") == 0) {
        novoCliente.tipo = PESSOA_JURIDICA;
        mvwprintw(formWin, 6, 2, "Razao Social: ");
        wgetnstr(formWin, novoCliente.dados.pj.razaoSocial, 99);
        mvwprintw(formWin, 7, 2, "CNPJ (com ou sem pontos): ");
        wgetnstr(formWin, documento, 19);

        if (validarCNPJ(documento) == 0) {
            mvwprintw(formWin, 16, 2, "ERRO: CNPJ invalido! Pressione tecla...");
            noecho(); wgetch(formWin); delwin(formWin); return;
        }
        strcpy(novoCliente.dados.pj.cnpj, documento);
    } else {
        mvwprintw(formWin, 16, 2, "ERRO: Tipo invalido (use PF ou PJ)! Pressione tecla...");
        noecho(); wgetch(formWin); delwin(formWin); return;
    }

    // Analisar Cliente
    if (procurarClientePorDocumento(documento) == 1) {
         mvwprintw(formWin, 16, 2, "ERRO: CPF/CNPJ ja cadastrado! Pressione tecla...");
         noecho(); wgetch(formWin); delwin(formWin); return;
    }


    // Obtem Dados Comuns
    mvwprintw(formWin, 9, 2, "Endereco: ");
    wgetnstr(formWin, novoCliente.endereco, 199);
    mvwprintw(formWin, 10, 2, "Telefone: ");
    wgetnstr(formWin, novoCliente.telefone, 19);
    mvwprintw(formWin, 11, 2, "Email: ");
    wgetnstr(formWin, novoCliente.email, 99);

    noecho();

    // Salvar
    listaClientes[numClientes] = novoCliente;
    numClientes++; // Incrementa o contador global

    mvwprintw(formWin, 16, 2, "Cliente cadastrado com sucesso! Pressione tecla...");
    wrefresh(formWin);
    wgetch(formWin);
    delwin(formWin);
}

// ########## TELA DE LISTAGEM DE CLIENTES ##########
void telaListarClientes(void) {
    // --- Cria uma nova janela para a listagem ---
    int altura = LINES - 2;
    int largura = COLS - 2;
    int y = 1;
    int x = 1;
    WINDOW *listWin = newwin(altura, largura, y, x);
    box(listWin, 0, 0); // Desenha a borda

    // Título
    wattron(listWin, COLOR_PAIR(2));
    mvwprintw(listWin, 1, (largura - 18) / 2, "LISTA DE CLIENTES");
    wattroff(listWin, COLOR_PAIR(2));

    // Cabeçalho da tabela
    mvwprintw(listWin, 3, 2, "ID | Tipo | Documento         | Nome / Razao Social");
    mvwprintw(listWin, 4, 2, "---+------+-------------------+--------------------------");

    // Verifica se há clientes para listar
    if (numClientes == 0) {
        mvwprintw(listWin, 6, 2, "Nenhum cliente cadastrado.");
    } else {
        // Lista os clientes
        for (int i = 0; i < numClientes; i++) {
            int linhaAtual = 6 + i;

            // Imprime os dados comuns
            mvwprintw(listWin, linhaAtual, 2, "%-2d |", listaClientes[i].id);

            if (listaClientes[i].tipo == PESSOA_FISICA) {
                mvwprintw(listWin, linhaAtual, 7, " PF  | %-17s | %s", 
                          listaClientes[i].dados.pf.cpf, 
                          listaClientes[i].dados.pf.nome);
            } else {
                mvwprintw(listWin, linhaAtual, 7, " PJ  | %-17s | %s", 
                          listaClientes[i].dados.pj.cnpj, 
                          listaClientes[i].dados.pj.razaoSocial);
            }
        }
    }

    // Rodapé
    mvwprintw(listWin, altura - 2, 2, "Total de clientes: %d. Pressione qualquer tecla para voltar...", numClientes);
    wrefresh(listWin);
    wgetch(listWin); // Espera

    delwin(listWin); // Apaga a janela
}

// ########## TELA DE CONSULTAR CLIENTE ##########
void telaConsultarCliente(void) {
    int altura = 16, largura = 60;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *win = newwin(altura, largura, y, x);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 1, (largura - 17) / 2, "CONSULTAR CLIENTE");
    wattroff(win, COLOR_PAIR(2));

    echo();
    char idStr[10];
    mvwprintw(win, 3, 2, "Digite o ID do Cliente: ");
    wgetnstr(win, idStr, 9);
    noecho();

    int id = atoi(idStr);
    int indice = obterIndiceCliente(id);

    if (indice == -1) {
        wattron(win, COLOR_PAIR(1) | A_BOLD);
        mvwprintw(win, 5, 2, "ERRO: Cliente com ID %d nao encontrado.", id);
        wattroff(win, COLOR_PAIR(1) | A_BOLD);
    } else {
        // Mostra os dados do cliente
        struct Cliente c = listaClientes[indice];

        mvwprintw(win, 5, 2, "ID: %d", c.id);
        if (c.tipo == PESSOA_FISICA) {
            mvwprintw(win, 6, 2, "Tipo: Pessoa Fisica");
            mvwprintw(win, 7, 2, "Nome: %s", c.dados.pf.nome);
            mvwprintw(win, 8, 2, "CPF: %s", c.dados.pf.cpf);
        } else {
            mvwprintw(win, 6, 2, "Tipo: Pessoa Juridica");
            mvwprintw(win, 7, 2, "Razao Social: %s", c.dados.pj.razaoSocial);
            mvwprintw(win, 8, 2, "CNPJ: %s", c.dados.pj.cnpj);
        }
        mvwprintw(win, 9, 2, "Telefone: %s", c.telefone);
        mvwprintw(win, 10, 2, "Email: %s", c.email);
        mvwprintw(win, 11, 2, "Endereco: %s", c.endereco);
    }

    mvwprintw(win, 14, 2, "Pressione qualquer tecla para voltar...");
    wrefresh(win);
    wgetch(win);
    delwin(win);
}

// ########## TELA DE REMOVER CLIENTE ##########
void telaRemoverCliente(void) {
    int altura = 12, largura = 60;
    int y = (LINES - altura) / 2;
    int x = (COLS - largura) / 2;
    WINDOW *win = newwin(altura, largura, y, x);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 1, (largura - 15) / 2, "REMOVER CLIENTE");
    wattroff(win, COLOR_PAIR(2));

    echo();
    char idStr[10];
    mvwprintw(win, 3, 2, "Digite o ID para remover: ");
    wgetnstr(win, idStr, 9);
    noecho();

    int id = atoi(idStr);
    int indice = obterIndiceCliente(id);

    if (indice == -1) {
        mvwprintw(win, 5, 2, "ERRO: Cliente ID %d nao encontrado.", id);
        mvwprintw(win, 7, 2, "Pressione qualquer tecla para voltar...");
        wgetch(win);
    } else {
        // Mostra o nome para confirmar
        struct Cliente c = listaClientes[indice];
        char nome[100];
        if (c.tipo == PESSOA_FISICA) strcpy(nome, c.dados.pf.nome);
        else strcpy(nome, c.dados.pj.razaoSocial);

        mvwprintw(win, 5, 2, "Cliente: %s", nome);
        mvwprintw(win, 6, 2, "Tem certeza? (S/N): ");

        int ch = wgetch(win);
        if (ch == 's' || ch == 'S') {
            excluirCliente(id);
            mvwprintw(win, 8, 2, "SUCESSO: Cliente removido.");
        } else {
            mvwprintw(win, 8, 2, "Operacao cancelada.");
        }
        mvwprintw(win, 10, 2, "Pressione qualquer tecla...");
        wgetch(win);
    }

    delwin(win);
}

// ########## TELA DE CADASTRAR PRODUTO ##########
void telaCadastrarProduto(void) {
    if (numProdutos >= MAX_PRODUTOS) {
        mvprintw(0, 0, "ERRO: Limite de produtos atingido!");
        getch();
        return;
    }

    int altura = 16, largura = 60;
    WINDOW *win = newwin(altura, largura, (LINES - altura) / 2, (COLS - largura) / 2);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 1, (largura - 20) / 2, "CADASTRAR PRODUTO");
    wattroff(win, COLOR_PAIR(2));

    char idStr[10], precoStr[20], estoqueStr[10];
    struct Produto novoProd;

    echo();

    // 1. ID
    mvwprintw(win, 3, 2, "ID (numerico): ");
    wgetnstr(win, idStr, 9);
    novoProd.id = atoi(idStr);

    if (novoProd.id <= 0 || procurarProdutoPorId(novoProd.id)) {
        mvwprintw(win, 14, 2, "ERRO: ID invalido ou ja existe!");
        noecho(); wgetch(win); delwin(win); return;
    }

    // 2. Descrição
    mvwprintw(win, 5, 2, "Descricao: ");
    wgetnstr(win, novoProd.descricao, 99);

    // 3. Preço
    mvwprintw(win, 7, 2, "Preco (ex: 10.50): ");
    wgetnstr(win, precoStr, 19);
    novoProd.preco = atof(precoStr); // Converte string para double

    // 4. Estoque
    mvwprintw(win, 9, 2, "Qtd em Estoque: ");
    wgetnstr(win, estoqueStr, 9);
    novoProd.estoque = atoi(estoqueStr);

    noecho();

    // Salvar
    listaProdutos[numProdutos] = novoProd;
    numProdutos++;

    mvwprintw(win, 12, 2, "Produto cadastrado com sucesso!");
    mvwprintw(win, 14, 2, "Pressione qualquer tecla...");
    wrefresh(win);
    wgetch(win);
    delwin(win);
}

// ########## TELA DE LISTAR PRODUTOS ##########
void telaListarProdutos(void) {
    int altura = LINES - 2, largura = COLS - 2;
    WINDOW *win = newwin(altura, largura, 1, 1);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 1, (largura - 17) / 2, "LISTA DE PRODUTOS");
    wattroff(win, COLOR_PAIR(2));

    mvwprintw(win, 3, 2, "ID | Descricao                      | Preco      | Estoque");
    mvwprintw(win, 4, 2, "---+--------------------------------+------------+--------");

    if (numProdutos == 0) {
        mvwprintw(win, 6, 2, "Nenhum produto cadastrado.");
    } else {
        for (int i = 0; i < numProdutos; i++) {
            mvwprintw(win, 6 + i, 2, "%-2d | %-30s | R$ %-7.2f | %d",
                      listaProdutos[i].id,
                      listaProdutos[i].descricao,
                      listaProdutos[i].preco,
                      listaProdutos[i].estoque);
        }
    }

    mvwprintw(win, altura - 2, 2, "Pressione qualquer tecla para voltar...");
    wrefresh(win);
    wgetch(win);
    delwin(win);
}

// ########## TELA DE CONSULTAR PRODUTO ##########
void telaConsultarProduto(void) {
    int altura = 14, largura = 60;
    WINDOW *win = newwin(altura, largura, (LINES - altura) / 2, (COLS - largura) / 2);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 1, (largura - 17) / 2, "CONSULTAR PRODUTO");
    wattroff(win, COLOR_PAIR(2));

    echo();
    char idStr[10];
    mvwprintw(win, 3, 2, "Digite o ID do Produto: ");
    wgetnstr(win, idStr, 9);
    noecho();

    int id = atoi(idStr);
    int indice = obterIndiceProduto(id);

    if (indice == -1) {
        mvwprintw(win, 5, 2, "ERRO: Produto ID %d nao encontrado.", id);
    } else {
        struct Produto p = listaProdutos[indice];
        mvwprintw(win, 5, 2, "ID: %d", p.id);
        mvwprintw(win, 6, 2, "Descricao: %s", p.descricao);
        mvwprintw(win, 7, 2, "Preco: R$ %.2f", p.preco);
        mvwprintw(win, 8, 2, "Estoque: %d", p.estoque);
    }

    mvwprintw(win, 11, 2, "Pressione qualquer tecla para voltar...");
    wrefresh(win);
    wgetch(win);
    delwin(win);
}

// ########## TELA DE REMOVER PRODUTO ##########
void telaRemoverProduto(void) {
    int altura = 14, largura = 60;
    WINDOW *win = newwin(altura, largura, (LINES - altura) / 2, (COLS - largura) / 2);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(2));
    mvwprintw(win, 1, (largura - 15) / 2, "REMOVER PRODUTO");
    wattroff(win, COLOR_PAIR(2));

    echo();
    char idStr[10];
    mvwprintw(win, 3, 2, "ID do Produto a remover: ");
    wgetnstr(win, idStr, 9);
    noecho();

    int id = atoi(idStr);
    int indice = obterIndiceProduto(id);

    if (indice == -1) {
        mvwprintw(win, 5, 2, "ERRO: Produto ID %d nao encontrado.", id);
    } else {
        // Verifica dependência em pedidos
        if (verificarProdutoEmPedidos(id)) {
            wattron(win, COLOR_PAIR(2));
            mvwprintw(win, 5, 2, "ERRO: Produto esta em PEDIDOS!");
            mvwprintw(win, 6, 2, "Nao e permitido excluir.");
            wattroff(win, COLOR_PAIR(2));
        } else {
            // Produto livre, liberado para excluir
            struct Produto p = listaProdutos[indice];
            mvwprintw(win, 5, 2, "Produto: %s", p.descricao);
            mvwprintw(win, 6, 2, "Tem certeza? (S/N): ");

            int ch = wgetch(win);
            if (ch == 's' || ch == 'S') {
                excluirProduto(id);
                mvwprintw(win, 8, 2, "SUCESSO: Produto removido.");
            } else {
                mvwprintw(win, 8, 2, "Operacao cancelada.");
            }
        }
    }

    mvwprintw(win, 11, 2, "Pressione qualquer tecla...");
    wrefresh(win);
    wgetch(win);
    delwin(win);
}
