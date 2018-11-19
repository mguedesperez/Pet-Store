#include <iostream>
#include <Cliente.h>
#include <Produto.h>

using namespace std;

class Venda{
    private:
        int codigo;
        Cliente cliente;
        Produto produto;
        int quantidade;

    public:
        Venda(int codigo, Cliente cliente, Produto produto, int quantidade){
            this->codigo = codigo;
            this->cliente = cliente;
            this->produto = produto;
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
        void setProduto (Produto produto){
            this->produto = produto;
        }
        Produto getProduto (){
            return produto;
        }
        void setQuantidade (int quantidade){
            this->cliente = cliente;
        }
        int getQuantidade (){
            return quantidade;
        }
}