#ifndef INF112_CONVENCIONAL_H
#define INF112_CONVENCIONAL_H

#include <string>
#include "pessoa.h"
#include "cliente.h"

class ClienteConvencional : public Cliente {
    protected:
        int _numeroDias;
        double _valorPago;
    public:
        ClienteConvencional(int id, std::string nome, std::string endereco, double saldoDevedor);
        int get_numeroDias();
        double get_valorPago();
        void renovarEmprestimo(int idLivro);
};
#endif
