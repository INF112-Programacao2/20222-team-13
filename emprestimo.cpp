#include "emprestimo.h"

Emprestimo::Emprestimo(int idCliente, int idLivro, int idFuncionario){
    _idCliente = idCliente;
    _idLivro = idLivro;
    _idFuncionario = idFuncionario;
    _mesDevolucao = _mesDevolucao;
    _anoDevolucao = _anoDevolucao;
}

int Emprestimo::get_id(){
    return _id;
}
int Emprestimo::get_idCliente(){
    return _idCliente;
}
int Emprestimo::get_idLivro(){
    return _idLivro;
}
int Emprestimo::get_idFuncionario(){
    return _idFuncionario;
}