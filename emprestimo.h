#ifndef INF112_EMPRESTIMO_H
#define INF112_EMPRESTIMO_H

#include <string>
#include <chrono>
#include <ctime>   
#include "pessoa.h"
#include "cliente.h"
#include "livros.h"

class Emprestimo {
    private:
        int _id;
        int _idCliente;
        int _idLivro;
        int _idFuncionario;
        int _valorASerPago;
        int _diasDevolucao;
    public:
        Emprestimo(int idCliente, int idLivro, int idFuncionario);
        int get_id();
        int get_idCliente();
        int get_idLivro();
        int get_idFuncionario();
};
#endif
