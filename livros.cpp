#include "livros.h"
#include <iostream>

Livros::Livros(std::string nome, std::string descricao, int versao){
    _nome = nome;
    _descricao = descricao;
    _versao = versao;
}

int Livros::get_id(){
    return _id;
}

std::string Livros::get_nome(){
    return _nome;
}

std::string Livros::get_descricao(){
    return _descricao;
}

int Livros::get_versao(){
    return _versao;
}

int Livros::get_exemplares(){
    return _exemplares;
}