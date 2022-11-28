#ifndef INF112_FUNCIONARIO_H
#define INF112_FUNCIONARIO_H

#include <string>
#include <vector>
#include "pessoa.h"
#include "cliente.h"
#include "livros.h"

class Funcionario : public Pessoa {
    public:
        Funcionario(int id, std::string nome);
        void cadastrarLivro();
        void cadastrarCliente();
        void pegarLivro(Cliente &cliente, Livros &livro);
        void devolverLivro(Cliente &cliente, Livros &livro);
        void removerLivro(Livros &livro);
};
#endif
