#include <iostream>
#include "vip.h"

ClienteVip::ClienteVip(std::string nome, std::string endereco, double saldoDevedor){
    _nome = nome;
    _endereco = endereco;
    _saldoDevedor = saldoDevedor;
    _numeroDias = 14;
    _valorPago = 0.7;
}