#include <stdio.h>
#include <queue>
#include <stack>
#include <iostream>

int continua = 0;
using namespace std;

void rec(int num,queue<string> teste, int cont);

void rec(int num,queue<string> teste, int cont=0){
    if(cont < num){
        cout << "\t" <<"Item "<<cont<<":"<< teste.front() << "\n";
        teste.pop();            
            rec(num, teste,++cont);
    }
}

void printar(queue<string> copia){
    while (!copia.empty()) {
        cout << '\t'<<copia.front();
        copia.pop();
    }
    cout << '\n';
}
void printarp(stack<string> clone){
    while(!clone.empty()){
        cout << '\t' << clone.top();
        clone.pop();
    }
    cout << '\n';
}
int main(){
	int res;
	queue<string> lista;
	stack<string> pilha;
	while (continua == 0){
		printf("\nOla! Escolha a opcao desejada\n1-Adicionar mercadorias na fila.\n2-Remover mercadorias da fila.\n3-Ver dados da fila.\n4-Enviar os produtos para o estoque.\n5-Verificar itens no estoque.\n6-Contar itens da fila.\n7-Sair do programa.\n");
		scanf("%d", &res);
		if ( res == 1 ){
			char item[] = "";
			printf("Qual item deseja adicionar a lista?");
			scanf("%s", &item);
			lista.push(item);
		} else if ( res == 2 ){
			int itm;
			int cnt = 0;
			printf("Quantos itens da lista voce deseja retirar?\n");
			scanf("%d", &itm);
			while(itm != cnt){
			    lista.pop();
			    cnt++;
			}
		} else if ( res == 3 ){
			cout << "\n\nTamanho da fila: "<< lista.size() << "\n";
			cout << "Primeiro item da fila: " << lista.front() << "\n";
			cout << "Ultimo item da fila: "<< lista.back() << "\n";
			cout << "Lista completa: "<< endl;
			printar(lista);
			printf("\n\n");
		} else if ( res == 4 ){
		    printf("Agora que os produtos foram enfileirados iremos coloca-los em pilhas dentro do estoque.\n");
		    while(!lista.empty()){
		        string topp = lista.front();
		        lista.pop();
		        pilha.push(topp);
		    }
		    printarp(pilha);

		} else if ( res == 5 ) {
		  printf("Segue os itens empilhados no estoque:\n\n");
		  printarp(pilha);
		    
		} else if ( res == 6){
		  int tam = lista.size();
		  rec(tam,lista);  
		} else if( res == 7){
			printf("Obrigado por usar nosso código!");
			continua = 1;
		} else if(res < 1 or res > 7){
		    printf("Opção inválida!\n");
		}

	}
}
