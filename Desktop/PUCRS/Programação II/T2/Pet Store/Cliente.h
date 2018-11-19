#include <iostream>

using namespace std;

class Cliente{
    private:
        string nome;
        string cpf;
        string dataNascimento;

    public:
        Cliente (string nome, string cpf, string dataNascimento){
            this->nome = nome;
            this->cpf = cpf;
            this->dataNascimento = dataNascimento;
        }

        void setNome (int nome){
            this->nome = nome;
        }
        string getNome (){
            return nome;
        }
        void setCpf (int cpf){
            this->cpf = cpf;
        }
        string getCpf (){
            return cpf;
        }
        void setDataNascimento (String dataNascimento){
            this->dataNascimento = dataNascimento;
        }
        string getDataNascimento (){
            return DataNascimento;
        }
}