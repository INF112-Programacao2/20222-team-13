#ifndef INF112_FUNCIONARIO_H
#define INF112_FUNCIONARIO_H

#include <string>
#include <pessoa.h>
#include <cliente.h>

class Funcionario : public Pessoa {
    public:
        void cadastrarLivro();
        void cadastrarCliente();
        void pegarLivro(cliente);
        void pagarMulta(double valor);
        void devolverLivro(Cliente cliente)
        void removerLivro(/*livro*/): void
}
#endif
