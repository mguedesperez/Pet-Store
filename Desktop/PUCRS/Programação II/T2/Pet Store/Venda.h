#include <iostream>
#include "Cliente.h"
#include "Produto.h"

using namespace std;

class Venda{
    private:
        int codigo;
        Cliente cliente;
        vector<Produto> produtos;
        int quantidade;

    public:
        Venda(int codigo, Cliente cliente, vector<Produto> produtos, int quantidade){
            this->codigo = codigo;
            this->cliente = cliente;
            this->produtos = produtos;
            this->quantidade = quantidade;
        }

        void setCodigo (int codigo){
            this->codigo = codigo;
        }
        int getCodigo (){
            return codigo;
        }
        void setCliente (Cliente cliente){
            this->cliente = cliente;
        }
        Cliente getCliente (){
            return cliente;
        }
        void setProdutos (vector<Produto> produtos){
            this->produtos = produtos;
        }
        vector<Produto> getProdutos (){
            return produto;
        }
        void setQuantidade (int quantidade){
            this->cliente = cliente;
        }
        int getQuantidade (){
            return quantidade;
        }

};