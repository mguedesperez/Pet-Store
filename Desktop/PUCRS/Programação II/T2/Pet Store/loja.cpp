#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <time.h>

#include "Produto.h"
#include "Cliente.h"

using namespace std;

void carregar(vector<Produto> & lista) {

    int codigo;
    string descricao;
    float valor;
    int quantidade;

	ifstream estoque;

	estoque.open("estoque.txt");
	
	if ( ! estoque.is_open() ) {
		cerr << "Erro ao abrir arquivo de entrada!" << endl;
		exit(-1);
	}
	
	estoque >> codigo;
	estoque >> descricao;
	estoque >> valor;
	estoque >> quantidade;	 

	while (estoque.good()) {
			
		Produto p(codigo,descricao,valor,quantidade);
		lista.push_back(p);
		
		estoque >> codigo;
		estoque >> descricao;
		estoque >> valor;
		estoque >> quantidade;	 
	
	}
	estoque.close();

}

void mostrar(vector<Produto> lista) {
	for(int i = 0; i < lista.size(); i++) {
		cout << lista[i].getCodigo() << " - " << lista[i].getDescricao() << " - " << lista[i].getValor() << endl;
	}
}

void venda(vector<Produto> & estoque, vector<Produto> & carrinho) {
    int codigo;
    int quantidade;

    while (true) {
        
        cout << "\n#########" << endl;
        cout << "Pet Store" << endl;
        cout << "#########\n" << endl;

        while (true){
            cout << "Produtos disponiveis:" << endl;
            mostrar(estoque);
            cout << "Digite o codigo do produto para adicionar ao carrinho: (0 - Finalizar)" << endl;
            cin >> codigo;

            if (codigo == 0) {
                break;
            }
            else{
                for(int i = 0; i < estoque.size(); i++) {
                    if (estoque[i].getCodigo() == codigo){
                        if(estoque[i].getQuantidade() > 0){
                            cout << "Digite a quantidade" << endl;
                            cin >> quantidade;
                            if(quantidade <= estoque[i].getQuantidade()){
                                Produto novo (estoque[i].getCodigo(), estoque[i].getDescricao(), estoque[i].getValor(), quantidade); 
                                carrinho.push_back(novo);
                                estoque[i].setQuantidade(estoque[i].getQuantidade()-quantidade);

                                cout << "\n**" << endl;
                                cout << "Voce adicionou "<< quantidade << " unidades de " << estoque[i].getDescricao()  << endl;
                                cout << "**\n" << endl;
                            }
                            else{
                                cout << "\n*Quantidade indisponivel*\n"  << endl;
                                break;
                            }
                        }
                        else{
                            cout << "\n*Produto indisponivel*\n"  << endl;
                            break;
                        }
                        break;
                    }
                }
            }
        }
        break;

    }
    cout << "\nCompra finalizada. Verifique o relatorio com os dados.\n" << endl;
    cout << "\nObrigado. Volte sempre!\n" << endl;

}

void relatorio(vector<Produto> estoque, vector<Produto> carrinho){
    ofstream relatorio;
    cout << "Gravando relatorio de vendas e recibo..." << endl;

    relatorio.open("relatorio.txt");

    relatorio << "Estoque atual" << endl;
    for(int i = 0; i < estoque.size(); i++) {
        relatorio << estoque[i].getCodigo() << " - " << estoque[i].getDescricao() << " - " << estoque[i].getValor() << " - " << estoque[i].getQuantidade() << endl;
    }

    relatorio << "\n\nRecibo de Venda\n" << endl;
    float total = 0;
    for(int i = 0; i < carrinho.size(); i++) {
        float parcial = carrinho[i].getValor() * carrinho[i].getQuantidade();
        relatorio << carrinho[i].getCodigo() << " - " << carrinho[i].getDescricao() << " - " << carrinho[i].getValor() << " - " << carrinho[i].getQuantidade() << " = " << parcial << endl;
        total = total + parcial;
    }
    relatorio << "Total = " << total << endl;

    relatorio.close();


}


int main(){
    vector<Produto> estoque;

	carregar(estoque);

    while (true){
        vector<Produto> carrinho;
        Cliente cliente;
        int opcao;
        cout << "\n Ola, deseja comprar? (1 - Sim, 0 - Nao)" << endl;
        cin >> opcao;
        if(opcao == 0){
            break;
        }
        cout << "Digite seu nome" << endl;
        cin >> cliente.nome;
        cout << "Digite seu cpf" << endl;
        cin >> cliente.cpf;
        cout << "Digite sua data de nascimento" << endl;
        cin >> cliente.dataNascimento;

        venda(estoque, carrinho);
    }

    //relatorio(estoque, carrinho);
    return 0;
}
