#include <iostream>
#include "cliente.h"

std::string Cliente:: get_endereco(){
    return _endereco;
}

double Cliente::get_saldoDevedor(){
    return _saldoDevedor;
}