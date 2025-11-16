#include "cliente.h"
#include "dados.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que verifica se todos os dígitos são iguais
static int todosDigitosIguais(char *str, int len) {
    for (int i = 1; i < len; i++) {
        if (str[i] != str[0]) {
            return 0; // Dígito diferente
        }
    }
    return 1; // Dígitos são iguais
}

// Valida um CPF (aceita com ou sem pontuação)
int validarCPF(char* cpf) {
    char cpfLimpo[12];
    int j = 0;
    int soma, resto, digito1, digito2;

    // Limpa a string
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            if (j < 11) {
                cpfLimpo[j] = cpf[i];
                j++;
            }
        }
    }
    cpfLimpo[j] = '\0';

    // Verifica se tem 11 dígitos
    if (j != 11) {
        return 0; // Inválido
    }

    // Verifica se os 11 dígitos são iguais
    if (todosDigitosIguais(cpfLimpo, 11)) {
        return 0;// Inválido
    }

    // Cálculo do primeiro dígito verificador
    soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpfLimpo[i] - '0') * (10 - i);
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : (11 - resto);

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpfLimpo[i] - '0') * (11 - i);
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : (11 - resto);

    // Compara os dígitos calculados com os dígitos reais
    if ((digito1 == (cpfLimpo[9] - '0')) && (digito2 == (cpfLimpo[10] - '0'))) {
        return 1; // Válido
    }

    return 0; // Inválido
}

// Valida CNPJ
int validarCNPJ(char* cnpj) {
    char cnpjLimpo[15];
    int j = 0;
    int soma, resto, digito1, digito2;
    int pesos1[] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int pesos2[] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

    // Limpa a string
    for (int i = 0; cnpj[i] != '\0'; i++) {
        if (isdigit(cnpj[i])) {
            if (j < 14) {
                cnpjLimpo[j] = cnpj[i];
                j++;
            }
        }
    }
    cnpjLimpo[j] = '\0';

    // Verifica se tem 14 dígitos
    if (j != 14) {
        return 0; // Inválido
    }

    // Verifica se todos os dígitos são iguais
    if (todosDigitosIguais(cnpjLimpo, 14)) {
        return 0; // Inválido
    }

    // Cálculo do primeiro dígito verificador
    soma = 0;
    for (int i = 0; i < 12; i++) {
        soma += (cnpjLimpo[i] - '0') * pesos1[i];
    }
    resto = soma % 11;
    digito1 = (resto < 2) ? 0 : (11 - resto);

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 13; i++) {
        soma += (cnpjLimpo[i] - '0') * pesos2[i];
    }
    resto = soma % 11;
    digito2 = (resto < 2) ? 0 : (11 - resto);

    // Compara os dígitos calculados com os dígitos reais
    if ((digito1 == (cnpjLimpo[12] - '0')) && (digito2 == (cnpjLimpo[13] - '0'))) {
        return 1; // Válido
    }

    return 0; // Inválido
}

// --- Funções de Busca (Analisar Cliente) --

int procurarClientePorId(int id) {
    
    for (int i = 0; i < numClientes; i++) {
        if (listaClientes[i].id == id) {
            return 1;
        }
    }
    return 0;
}

int procurarClientePorDocumento(char* documento) {
    char docLimpo[20];
    int j = 0;

    // Limpa o documento
    for (int i = 0; documento[i] != '\0'; i++) {
        if (isdigit(documento[i])) {
            docLimpo[j] = documento[i];
            j++;
        }
    }
    docLimpo[j] = '\0';

    for (int i = 0; i < numClientes; i++) {
        if (listaClientes[i].tipo == PESSOA_FISICA) {
            // Compara com CPF
            if (strcmp(listaClientes[i].dados.pf.cpf, docLimpo) == 0) {
                return 1;
            }
        } else {
                if (strcmp(listaClientes[i].dados.pj.cnpj, docLimpo) == 0) {
                return 1;
            }
        }
    }
    return 0;
}
