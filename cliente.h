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
        int virtual get_numeroDias() = 0;
        double virtual get_valorPago() = 0;
        void virtual renovarEmprestimo(int idLivro) = 0;
};
#endif
