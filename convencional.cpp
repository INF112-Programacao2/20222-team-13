#include <iostream>
#include <string>
#include <fstream>
#include "convencional.h"

ClienteConvencional::ClienteConvencional(int id, std::string nome, std::string endereco, double saldoDevedor){
    _id = id;
    _nome = nome;
    _endereco = endereco;
    _saldoDevedor = saldoDevedor;
    _numeroDias = 7;
    _valorPago = 1;
}

int ClienteConvencional::get_numeroDias(){
    return _numeroDias;
}

double ClienteConvencional::get_valorPago(){
    return _valorPago * _numeroDias;
}

void ClienteConvencional::renovarEmprestimo(int idLivroEmp){
    bool existe = false;
    int id;
    int idCliente;
    int idLivro;
    int idFuncionario;
    int numeroDias;
    double valorPago;

    std::ifstream arquivo("emprestimo.txt");
    if(!arquivo.is_open()){
        std::cout<<"Falha ao abrir o arquivo!";
        return;
    }
    std::ofstream temp("temp.txt");
    while(arquivo>> id >> idCliente >> idLivro >> idFuncionario >> numeroDias >> valorPago){
        if(idLivroEmp==idLivro && this->get_id()==idCliente){
            existe = true;
            temp << id << " " << idCliente << " " << idLivro << " " << idFuncionario << " " << numeroDias + this->get_numeroDias() << " " << valorPago + this->get_valorPago() << std::endl;
            std::cout<<"\nLivro renovado com sucesso!"<< std::endl;
        }
        if(idLivroEmp!=idLivro || this->get_id()!=idCliente){
            temp << id << " " << idCliente << " " << idLivro << " " << idFuncionario << " " << numeroDias << " " << valorPago << std::endl;
        }
    }
    if(!existe){
        std::cout<<"\nEmprestimo nao localizado para esse cliente!"<< std::endl;
    }
    arquivo.close();
    temp.close();
    remove("emprestimo.txt");
    rename("temp.txt", "emprestimo.txt");
}