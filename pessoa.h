#ifndef INF112_PESSOA_H
#define INF112_PESSOA_H

#include <string>

class Pessoa {
    protected:
        int _id;
        std::string _nome;

    public:
        int get_id();
        std::string get_nome();
};
#endif
