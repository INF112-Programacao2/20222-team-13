#ifndef INF112_VIP_H
#define INF112_VIP_H

#include <string>
#include "pessoa.h"
#include "cliente.h"

class ClienteVip : public Cliente {
    protected:
        int _numeroDias;
        double _valorPago;
    public:
        ClienteVip(std::string nome, std::string endereco, double saldoDevedor);
        int get_numeroDias();
        double get_valorPago();
};
#endif
