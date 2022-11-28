#ifndef INF112_CLIENTE_H
#define INF112_CLIENTE_H

#include <string>
#include "pessoa.h"

class Cliente : public Pessoa {
    protected:
        std::string _endereco;
        double _saldoDevedor;
    public:
        std::string get_endereco();
        double get_saldoDevedor();
        void virtual renovarEmprestimo(int livro) = 0;
        void virtual pagarMulta(double valor) = 0;
};
#endif
