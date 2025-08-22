#define PILHA_H
#define max_str 31

struct funcionarios{
    long int matricula;
    char nome[max_str], setor;
    float salario;
};

typedef struct funcionarios * funcionario;
typedef struct Pilha * pilha;
