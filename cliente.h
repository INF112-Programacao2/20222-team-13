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
        double  get_saldoDevedor();
        void renovarEmprestimo(int livro);
        void pagarMulta(double valor);
};
#endif
