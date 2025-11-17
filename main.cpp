#include <iostream>
#include "inventario.h"
#include "produto.h"

using namespace std;

int main() {
    Inventario inventario;
  
    inventario.adicionarProduto(Produto("Celular", 2500.00, 5, "Eletrônicos"));
    inventario.adicionarProduto(Produto("Mouse", 50.00, 10, "Eletrônicos"));
    inventario.adicionarProduto(Produto("Casaco", 70.00, 20, "Vestuário"));
    inventario.adicionarProduto(Produto("Livro", 100.00, 15, "Livros"));
    
    inventario.listarTodasCategorias();
    inventario.contarProdutosPorCategoria();

    Produto* produto = inventario.buscarProduto("Celular");
    if (produto != nullptr) {
        cout << "Produto encontrado: " << produto->getNome() 
             << " - R$ " << produto->getValor() 
             << " - Estoque: " << produto->getEstoque() << endl;
    }
    
    auto eletronicos = inventario.listarProdutosPorCategoria("Eletrônicos");
    for (const auto& prod : eletronicos) {
        cout << "- " << prod.getNome() << " (R$ " << prod.getValor() 
             << ", Estoque: " << prod.getEstoque() << ")" << endl;
    }
    
    double total = inventario.calcularValorTotalInventario();
    cout << "Valor total: R$ " << total << endl;
    
    inventario.registrarVenda("Mouse", 3);
    
    inventario.listarHistoricoVendas();
    
    inventario.contarProdutosPorCategoria();
    
    return 0;
}
