#include "livros.h"
#include <iostream>

Livros::Livros(int id, std::string nome, std::string autor, int versao){
    _id = id;
    _nome = nome;
    _autor = autor;
    _versao = versao;
}

int Livros::get_id(){
    return _id;
}

std::string Livros::get_nome(){
    return _nome;
}

std::string Livros::get_autor(){
    return _autor;
}

int Livros::get_versao(){
    return _versao;
}