#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "pessoa.h"
#include "cliente.h"
#include "livros.h"
#include "funcionario.h"

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
    std::cin >> versao;
    std::ofstream arquivo("livros.txt", std::ios::app);
        arquivo<<std::endl<<nome<<" "<<autor<<" "<<versao;
        arquivo.close(); 
    std::cout<<"\nLivro cadastrado com sucesso!\n";
}
void Funcionario::cadastrarCliente(){
    std::string nome;
    std::string senha;
    int tipo;
    int id;

    std::cout << "Qual o nome do usuário? ";
    std::cin >> nome;
    std::cout << "Qual a senha? ";
    std::cin >> senha;
    std::cout << "Qual a permissão? (1. Convencional; 2. Vip): ";
    std::cin >> tipo;
    if(tipo>2 || tipo<1){
        std::cout<<"\nOpção impossível, tente novamente!\n";
    }
    else{
        std::ofstream arquivo("usuarios.txt", std::ios::app);
        arquivo << std::endl << nome << " " << senha << " " << tipo;
        std::cout<<"\nUsuário cadastrado com sucesso!\n";
        arquivo.close();
    }
}
void Funcionario::pegarLivro(Cliente &cliente){

}
void Funcionario::pagarMulta(double valor){

}
void Funcionario::devolverLivro(Cliente cliente){

}
//void Funcionario::removerLivro(std::vector<Livro*>& livros){}