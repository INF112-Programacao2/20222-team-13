#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pessoa.h"
#include "cliente.h"
#include "livros.h"
#include "funcionario.h"

Funcionario::Funcionario(int id, std::string nome){
    _id = id;
    _nome = nome;
}

void Funcionario::cadastrarLivro(){
    
    std::string nome;
    std::string autor;
    int versao;
    int id;

    std::cout << "Qual o nome do livro que deseja cadastrar? ";
    std::cin >> nome;
    std::cout << "Qual autor do livro? ";
    std::cin >> autor;
    std::cout << "Qual a versao do livro? ";
    std::cin >> versao;
    std::cout << "Qual o id do livro? ";
    std::cin >> id;
    std::ofstream arquivo("livros.txt", std::ios::app);
        arquivo<< nome << " " << autor << " "<< versao << " " << id << std::endl;
        arquivo.close(); 
    std::cout<<"\nLivro cadastrado com sucesso!\n";
}
void Funcionario::cadastrarCliente(){
    std::string nome;
    std::string senha;
    int tipo;
    int id;

    std::cout << "Qual o id do cliente?";
    std::cin >> id;
    std::cout << "Qual o nome do usuario? ";
    std::cin >> nome;
    std::cout << "Qual a senha? ";
    std::cin >> senha;
    std::cout << "Qual a permissao? (1. Convencional; 2. Vip): ";
    std::cin >> tipo;
    if(tipo>2 || tipo<1){
        throw std::invalid_argument("Tipo do cliente invalido.");
    }
    else{
        std::ofstream arquivo("usuarios.txt", std::ios::app);
        arquivo << std::endl << id << " " << nome << " " << senha << " " << tipo;
        std::cout<<"\nUsuario cadastrado com sucesso!\n";
        arquivo.close();
    }
}
void Funcionario::pegarLivro(Cliente &cliente, Livros &livro){
    int id;

    std::cout << "Qual o id do emprestimo?";
    std::cin >> id;
    
    std::ofstream arquivo("emprestimo.txt", std::ios::app);
    arquivo << std::endl << id << " " << cliente.get_id() << " " << livro.get_id() << " " << this->get_id() << " " << cliente.get_numeroDias() << " " << cliente.get_valorPago();

    std::cout<<"\nEmprestimo cadastrado com sucesso!\n";

    arquivo.close();
}

void Funcionario::devolverLivro(Cliente &cliente, Livros &livro){
    bool existe = false;
    int id;
    int idCliente;
    int idLivro;
    int idFuncionario;

    std::ifstream arquivo("emprestimo.txt");
    if(!arquivo.is_open()){
        std::cout<<"Falha ao abrir o arquivo!";
        return;
    }
    std::ofstream temp("temp.txt");
    while(arquivo>> id >> idCliente >> idLivro >> idFuncionario){
        if(livro.get_id()==idLivro && cliente.get_id()==idCliente){
            existe = true;
            std::cout<<"\nLivro devolvido com sucesso!"<< std::endl;
        }
        if(livro.get_id()!=idLivro || cliente.get_id()==idCliente){
            temp << id << " " << idCliente << " " << idLivro << " " << idFuncionario << std::endl;
        }
    }
    if(!existe){
        std::cout<<"\nEmprestimo nao encontrado!"<< std::endl;
    }
    arquivo.close();
    temp.close();
    remove("emprestimo.txt");
    rename("temp.txt", "emprestimo.txt");
}

void Funcionario::removerLivro(Livros &livro){
    bool existe = false;
    std::string nome;
    std::string autor;
    int versao;
    int id;

    std::ifstream arquivo("livros.txt");
    if(!arquivo.is_open()){
        std::cout<<"Falha ao abrir o arquivo!";
        return;
    }
    std::ofstream temp("temp.txt");
    while(arquivo>> nome >> autor >> versao >> id){
        if(livro.get_id()==id){
            existe = true;
            std::cout<<"\nLivro " << livro.get_nome() << " do autor " << livro.get_autor() << " excluido com sucesso!"<< std::endl;
        }
        if(livro.get_id()!=id){
            temp<< nome << " " << autor << " " << versao << " " << id << std::endl;
        }
    }
    if(!existe){
        std::cout<<"\nLivro nao encontrado!"<< std::endl;
    }
    arquivo.close();
    temp.close();
    remove("livros.txt");
    rename("temp.txt", "livros.txt");
}