#include <iostream>
#include <string>
#include <fstream>
#include "funcionario.h"
#include "livros.h"
#include "convencional.h"
#include "cliente.h"
#include "vip.h"

int login(){
  std::string senha, login;
  std::cout<<"\n==========================\n";
  std::cout<<"Faca o Login para continuar!\n";
  std::cout<<"============================\n";
  std::cout<<"\nInforme o nome de usuario: ";
  std::cin>>login;
  std::cout<<"Informe a senha: ";
  std::cin>>senha;
  
  std::string u, s;
  int id, tipo;
  std::ifstream arquivo("usuarios.txt");
  bool logou=false;
  while(arquivo >> id >> u >> s >>tipo){
    if(login==u && senha==s){
      return tipo;
    }
  }
  arquivo.close();
  std::cout<<"\nUsuario ou senha invalidos!"<< std::endl;
  return -1;
}

void funcionario(){
    int opcao = 0;
    Funcionario func(1, "Otavio");

    std::cout << "Seja bem vindo funcionario!" << std::endl;

    while(opcao != -1)
    {
        std::cout << "Escolha uma operação\n 1 - Cadastrar Livro\n 2 - Remover Livro\n 3 - Cadastrar Cliente\n 4 - Emprestar Livro \n 5 - Devolver Livro \n -1 Fechar Programa" << std::endl;
        std::cin >> opcao;

        if(opcao == -1)
            return;
        else if(opcao == 1)
            func.cadastrarLivro();
        else if(opcao == 2)
            {
                int id;
                std::string nome;
                std::string autor;

                std::cout << "Informe o id do livro: " << std::endl;
                std::cin >> id;

                std::cout << "Informe o nome do livro: " << std::endl;
                std::cin >> nome;

                std::cout << "Informe o nome do livro: " << std::endl;
                std::cin >> autor;

                Livros livro(id, nome, autor, 1);

                func.removerLivro(livro);
            }
        else if(opcao == 3)
            try{
                func.cadastrarCliente();
            }catch(const std::invalid_argument& e){
                std::cout << "Nao foi possivel cadastrar o cliente" << std::endl;
            }
            
        else if(opcao == 4)
            {
                int id, tipo;
                std::string nome;
                std::string endereco;
                std::string autor;

                std::cout << "Informe o id do cliente: " << std::endl;
                std::cin >> id;

                std::cout << "Informe o nome do cliente: " << std::endl;
                std::cin >> nome;

                std::cout << "Informe o endereco do cliente: " << std::endl;
                std::cin >> endereco;

                std::cout << "Informe o tipo do cliente: " << std::endl;
                std::cin >> tipo;
                
                ClienteConvencional cliente(id, nome, endereco, 1);
                ClienteVip cliente1(id, nome, endereco, 2);

                std::cout << "Informe o id do livro: " << std::endl;
                std::cin >> id;

                std::cout << "Informe o nome do livro: " << std::endl;
                std::cin >> nome;

                std::cout << "Informe o autor do livro: " << std::endl;
                std::cin >> autor;

                Livros livro(id, nome, autor, 1);

                if(tipo==1)
                    func.pegarLivro(cliente, livro);
                else
                    func.pegarLivro(cliente1, livro);
            }
        else if(opcao == 5)
            {
                int id, tipo;
                std::string nome;
                std::string endereco;
                std::string autor;

                std::cout << "Informe o id do cliente: " << std::endl;
                std::cin >> id;

                std::cout << "Informe o nome do cliente: " << std::endl;
                std::cin >> nome;

                std::cout << "Informe o endereco do cliente: " << std::endl;
                std::cin >> endereco;

                std::cout << "Informe o tipo do cliente: " << std::endl;
                std::cin >> tipo;
                
                ClienteConvencional cliente(id, nome, endereco, 1);
                ClienteVip cliente1(id, nome, endereco, 2);

                std::cout << "Informe o id do livro: " << std::endl;
                std::cin >> id;

                std::cout << "Informe o nome do livro: " << std::endl;
                std::cin >> nome;

                std::cout << "Informe o autor do livro: " << std::endl;
                std::cin >> autor;

                Livros livro(id, nome, autor, 1);

                if(tipo==1)
                    func.devolverLivro(cliente, livro);
                else
                    func.devolverLivro(cliente1, livro);
            }
    }
}

void usuario(){

    std::cout << "Bem vindo usuario!" << std::endl;
    std::cout << "Aqui sera feita a renovacao do seu livro." << std::endl;

    int id, tipo, idLivro;
    std::string nome;
    std::string endereco;
    std::string autor;

    std::cout << "Informe o id do cliente: " << std::endl;
    std::cin >> id;

    std::cout << "Informe o nome do cliente: " << std::endl;
    std::cin >> nome;

    std::cout << "Informe o endereco do cliente: " << std::endl;
    std::cin >> endereco;

    std::cout << "Informe o tipo do cliente: " << std::endl;
    std::cin >> tipo;

    std::cout << "Insira o id do livro que deseja renovar: " << std::endl;
    std::cin >> tipo;
    
    ClienteConvencional cliente(id, nome, endereco, 1);
    ClienteVip cliente1(id, nome, endereco, 2);

    if(tipo==1)
        cliente.renovarEmprestimo(idLivro);
    else
        cliente1.renovarEmprestimo(idLivro);
}

int main(){
    int tipo;
    tipo=login();

    switch(tipo){
        case -1:
            main();
        break;
        case 1:
            funcionario();
        break;
        case 2:
            usuario();
        break;
    }

    return 0;
}