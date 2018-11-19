#include <iostream>

using namespace std;

class Produto{
    private:
        int codigo;
        string descricao;
        float valor;

    public:
        Produto (int codigo, string descricao, float valor){
            this->codigo = codigo;
            this->descricao = descricao;
            this->valor = valor;
        }

        void setCodigo (int codigo){
            this->codigo = codigo;
        }
        int getCodigo (){
            return codigo;
        }
        void setDescricao (string descricao){
            this->descricao = descricao;
        }
        string getDescricao (){
            return descricao;
        }
        void setValor (string valor){
            this->valor = valor;
        }
        float getValor (){
            return Valor;
        }
    

}