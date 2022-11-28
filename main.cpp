#include <iostream>
#include <string>
#include <fstream>
#include "funcionario.h"
#include "livros.h"

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


int main(){
    int tipo;
    tipo=login();

    switch(tipo){
        case -1:
            main();
        break;
        case 1:
            Funcionario func(1, "Otavio");
            Livros livro(4, "Teste", "Teste2", 4);
            func.removerLivro(livro);
        break;
    }

    return 0;
}