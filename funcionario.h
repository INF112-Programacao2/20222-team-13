#ifndef INF112_FUNCIONARIO_H
#define INF112_FUNCIONARIO_H

#include <string>
#include <vector>
#include "pessoa.h"
#include "cliente.h"
#include "livros.h"

class Funcionario : public Pessoa {
    public:
        void cadastrarLivro();
        void cadastrarCliente();
        void pegarLivro(Cliente &cliente);
        void pagarMulta(double valor);
        void devolverLivro(Cliente cliente);
        //void removerLivro(std::vector<Livro*>& livros);
};
#endif
