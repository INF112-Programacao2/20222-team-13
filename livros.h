#ifndef INF112_LIVROS_H
#define INF112_LIVROS_H

#include <string>

class Livros {
    private:
        int _id;
        std::string _nome;
        std::string _descricao;
        int _exemplares;
        int _versao;
    public:
        Livros(std::string nome, std::string descricao, int versao);
        int get_id();
        std::string get_nome();
        std::string get_descricao();
        int get_versao();
        int get_exemplares();
};
#endif