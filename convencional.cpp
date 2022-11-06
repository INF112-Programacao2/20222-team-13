#include <iostream>
#include <string>
#include "convencional.h"

ClienteConvencional::ClienteConvencional(std::string nome, std::string endereco, double saldoDevedor){
    _nome = nome;
    _endereco = endereco;
    _saldoDevedor = saldoDevedor;
    _numeroDias = 7;
    _valorPago = 1;
}