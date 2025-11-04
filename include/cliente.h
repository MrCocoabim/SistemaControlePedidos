#ifndef CLIENTE_H
#define CLIENTE_H

// Enum para diferenciar Pessoa Física de Jurídica
enum TipoCliente {
    PESSOA_FISICA,
    PESSOA_JURIDICA
};

// Struct para dados de Pessoa Física
struct PessoaFisica {
    char nome[100];
    char cpf[15]; // Formato: XXX.XXX.XXX-XX
    char celular[20];
};

// Struct para dados de Pessoa Jurídica
struct PessoaJuridica {
    char razaoSocial[100];
    char cnpj[20]; // Formato: XX.XXX.XXX/XXXX-XX
    char nomeContato[100];
};

// Struct principal do Cliente
struct Cliente {
    int id;
    char endereco[200];
    char telefone[20];
    char email[100];
    
    enum TipoCliente tipo; // Armazena se é PF ou PJ
    
    union {
        struct PessoaFisica pf;
        struct PessoaJuridica pj;
    } dados;
};

#endif // CLIENTE_H