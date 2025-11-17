#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>
#ifndef PRODUTO_H
#define PRODUTO_H

class Produto {
    private:
    std::string Nome;
    double Valor;
    int Estoque;
    std::string Categoria;

    public:
    Produto(std::string nome, double valor, int estoque, std::string categoria){
        Nome = nome;
        Valor = valor;
        Estoque = estoque;
        Categoria = categoria;
    }
    
    const std::string getNome() const {return Nome;}
    const double getValor() const {return Valor;}
    const int getEstoque() const {return Estoque;}
    const std::string getCategoria() const {return Categoria;}
    void setEstoque(int estoque) {Estoque = estoque;}
    void setValor(double valor) {Valor = valor;}
    void setNome(std::string nome) {Nome = nome;}
    void setCategoria(std::string categoria) {Categoria = categoria;}
};

#endif 