#include "inventario.h"
#include "produto.h"
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>
#include <iostream>

Inventario::Inventario() {}

// Adiciona um produto ao inventário, atualizando as categorias e contagens
void Inventario::adicionarProduto(const Produto& produto) {
    listaProdutos.push_back(produto);
    listaCategorias.insert(produto.getCategoria());
    contaCategoria[produto.getCategoria()]++;
    valorCategoria[produto.getCategoria()] += produto.getValor() * produto.getEstoque();  
}

// Remove um produto pelo nome, atualizando as categorias e contagens
void Inventario::removerProduto(const std::string& nomeProduto) {
    for (auto iterador = listaProdutos.begin(); iterador != listaProdutos.end(); iterador++) {
        if (iterador->getNome() == nomeProduto) {
        std::string categoria = iterador->getCategoria();
            
        contaCategoria[categoria]--;
        valorCategoria[categoria] -= iterador->getValor() * iterador->getEstoque();
    
        listaProdutos.erase(iterador);
        
        // Remover categoria se não houver mais produtos
        if (contaCategoria[categoria] == 0) {
            contaCategoria.erase(categoria);
            valorCategoria.erase(categoria);
            listaCategorias.erase(categoria);
            }

            std::cout << "Produto removido!" << std::endl;
            return;
        }
    }
    std::cout << "Produto não encontrado" << std::endl;
}

// Busca um produto pelo nome, através de um iterador, e retorna um ponteiro para ele ou nullptr se não encontrado
Produto* Inventario::buscarProduto(const std::string& nomeProduto) {
    for (auto iterador = listaProdutos.begin(); iterador != listaProdutos.end(); iterador++) {
        if (iterador->getNome() == nomeProduto) {
            return &(*iterador);
        }
    }

    return nullptr;  
}

// Lista produtos de uma categoria específica
std::vector<Produto> Inventario::listarProdutosPorCategoria(const std::string& categoria) {
    std::vector<Produto> produtosDaCategoria;
    
    for (auto it = listaProdutos.begin(); it != listaProdutos.end(); ++it) {
        if (it->getCategoria() == categoria) {
            produtosDaCategoria.push_back(*it);
        }
    }
    
    return produtosDaCategoria;
}

// Calcula o valor total do inventário somando o valor de todos os produtos em estoque
double Inventario::calcularValorTotalInventario() {
    double total = 0.0;
    
    for (auto iterador = listaProdutos.begin(); iterador != listaProdutos.end(); iterador++) {
        total += iterador->getValor() * iterador->getEstoque();
    }
    
    return total;
}

// Conta o número de produtos por categoria
void Inventario::contarProdutosPorCategoria() {
    std::cout << "Contagem de produtos por categoria: " << std::endl;
    if(listaProdutos.empty()){
        std::cout << "Nenhum produto no inventário" << std::endl;
        return;
    }

    for(const auto& par: contaCategoria){
        std::string categoria = par.first;
        int quantidade = par.second;
        double valor = valorCategoria[categoria];
        
        std::cout << categoria << " : " << quantidade << " produtos R$ " << valor << std::endl;

    }
}

// Registra uma venda, atualiza o estoque, o histórico de vendas, e os mapas de contagem e valor por categoria
void Inventario::registrarVenda(const std::string& nomeProduto, int quantidade) {
    Produto* produto = buscarProduto(nomeProduto);
    
    if (produto != nullptr && produto->getEstoque() >= quantidade) {
        produto->setEstoque(produto->getEstoque() - quantidade);
        
        std::string registro = "Vendido: " + nomeProduto + ", Quantidade: " + std::to_string(quantidade);
        historicoVendas.push_back(registro);
        
        std::string categoria = produto->getCategoria();
        valorCategoria[categoria] -= produto->getValor() * quantidade;
        
        std::cout << "Venda registrada com sucesso!" << std::endl;
        
        if (produto->getEstoque() == 0) {
            // Busca novamente para encontrar a posição e remover
            for (auto it = listaProdutos.begin(); it != listaProdutos.end(); ++it) {
                if (it->getNome() == nomeProduto) {
                    listaProdutos.erase(it);
                    break;
                }
            }
            
            contaCategoria[categoria]--;
            
            if (contaCategoria[categoria] == 0) {
                contaCategoria.erase(categoria);
                valorCategoria.erase(categoria);
                listaCategorias.erase(categoria);
            }
            
            std::cout << "Produto '" << nomeProduto << "' removido por estoque zerado." << std::endl;
        }
    }
    else {
        std::cout << "Venda não realizada: Produto não encontrado ou estoque insuficiente." << std::endl;
    }
}

void Inventario::listarTodasCategorias() const {
    std::cout << "Categorias disponíveis: " << "\n";
    for (auto iterador = listaCategorias.begin(); iterador != listaCategorias.end(); iterador++) {
    std::cout << "- " << *iterador << "\n";
    }
}

void Inventario::listarHistoricoVendas() const {
    std::cout << "Histórico de vendas: << \n";
    for (auto iterador = historicoVendas.begin(); iterador != historicoVendas.end(); iterador++) {
        std::cout << "- " << *iterador << "\n";
    }
}