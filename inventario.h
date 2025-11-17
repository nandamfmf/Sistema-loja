#include <set>
#include <map>
#include <string>
#include <vector>
#include <list>
#include "produto.h"

#ifndef INVENTARIO_H
#define INVENTARIO_H

class Inventario {
    private:
    std::vector<Produto> listaProdutos;
    std::set<std::string> listaCategorias;
    std::map<std::string, int> contaCategoria;
    std::map<std::string, double> valorCategoria;
    std::list<std::string> historicoVendas;

    public:
    Inventario();
    void adicionarProduto(const Produto& produto);
    void removerProduto(const std::string& nomeProduto);
    Produto* buscarProduto(const std::string& nomeProduto);
    std::vector<Produto> listarProdutosPorCategoria(const std::string& categoria);
    double calcularValorTotalInventario(); 
    void contarProdutosPorCategoria();
    void registrarVenda(const std::string& nomeProduto, int quantidade);
    void listarTodasCategorias() const;
    void listarHistoricoVendas() const;
};  

#endif 