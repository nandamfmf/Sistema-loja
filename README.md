# Sistema de Inventário de Loja

Sistema completo de gerenciamento de inventário desenvolvido em C++ usando STL com:
Gerenciamento de produtos (adicionar, remover, buscar), registro de vendas com histórico,
contagem de produtos por categoria, dentre outras funcionalidades.

## Estruturas STL Utilizadas
- `vector<Produto>` - Lista de produtos
- `set<string>` - Categorias únicas
- `map<string, int>` - Contagem por categoria
- `map<string, double>` - Valor total por categoria
- `list<string>` - Histórico de vendas

## Como compilar
No terminal:
g++ -o s main.cpp inventario.cpp 
./s
