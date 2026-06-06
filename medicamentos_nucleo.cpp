#include <iostream>
#include <fstream>
#include <ostream>
#include <string>

using namespace std;

struct Medicamento{

    int id;
    string nome_comercial;
    string principio_ativo;
    float dosagem;
    string laboratorio;
    bool mostrar;

};

void Ler_Medicamento(Medicamento medicamento){

    cout << "Id: " << medicamento.id << endl; 
    cout << "Nome Comercial: " << medicamento.nome_comercial << endl; 
    cout << "Principio Ativo: " << medicamento.principio_ativo << endl; 
    cout << "Dosagem: " << medicamento.dosagem << " mg"<<  endl; 
    cout << "Laboratorio: " << medicamento.laboratorio << endl; 

}

void Receber_Valor(Medicamento *destino, Medicamento &origem){

  destino->id = origem.id;
  destino->nome_comercial = origem.nome_comercial;
  destino->principio_ativo = origem.principio_ativo;
  destino->dosagem = origem.dosagem;
  destino->laboratorio = origem.laboratorio;
  destino->mostrar = origem.mostrar;

}
  

int main(){
    
    ifstream arquivo_medicamentos("medicamentos.csv");

    if (!arquivo_medicamentos){
      cout << "Não foi possível abrir o arquivo" << endl;
    }
    else{

      char letra;
      string linha;

      int capacidade = 35;
      int tamanho = 0;


      getline(arquivo_medicamentos, linha);
      
      Medicamento *vet_medicamentos = new Medicamento[capacidade];
      
      int j = 0;

      while(arquivo_medicamentos >> vet_medicamentos[j].id){
        arquivo_medicamentos >> letra >> letra;

        getline(arquivo_medicamentos, vet_medicamentos[j].nome_comercial, '"');

        arquivo_medicamentos >> letra >> letra;

        getline(arquivo_medicamentos, vet_medicamentos[j].principio_ativo, '"');

        arquivo_medicamentos >> letra;

        arquivo_medicamentos >> vet_medicamentos[j].dosagem;

        arquivo_medicamentos >> letra >> letra;

        getline(arquivo_medicamentos, vet_medicamentos[j].laboratorio, '"');

        vet_medicamentos[j].mostrar = true;

        j++;
        tamanho++;

        if (tamanho >= capacidade){
          capacidade += 5;

          Medicamento *vet_temp = new Medicamento[capacidade];

          for(int i=0; i<(capacidade-5); i++){

            Receber_Valor(&vet_temp[i], vet_medicamentos[i]);

          }

          delete []vet_medicamentos; 
          vet_medicamentos = vet_temp;

        }

      }

      int opcao = 0;

      do{
        
        cout << "Opcões: " << endl 
             << "1 - Inserir novo medicamento;" << endl 
             << "2 - Remover medicamento;" << endl
             << "3 - Buscar medicamento;" << endl
             << "4 - Mostrar medicamentos;" << endl
             << "5 - Salvar alterações;" << endl
             << "6 - Sair" << endl;
      
        cout << "Insira uma opção:";
        cin >> opcao;

        switch(opcao){
          case 1:
            cout << "Opção em desenvolvimento" << endl;
            break;

          case 2:
            cout << "Opção em desenvolvimento" << endl;
            break;

          case 3:
            cout << "Opção em desenvolvimento" << endl;
            break;

          case 4:{

              int inicio, fim;

              do {
                cout << "Insira o começo do intervalo de medicamentos que deseja ver." << endl
                     << "O número inserido deve estar entre 1 e " << tamanho << ": ";
                cin >> inicio;
              }while (inicio <= 0 || inicio > tamanho);

              do {
                cout << "Insira o fim do intervalo de medicamentos que deseja ver." << endl 
                     << "O número inserido deve estar entre " << inicio << " e " << tamanho << ": "; 
                cin >> fim;
              }while (fim < inicio || fim > tamanho);
              
              int k = 0;
              for(int i=0; i < fim; i++){
                
                if(i >= inicio - 1 && vet_medicamentos[k].mostrar){
                  cout << endl;
                  cout << i+1 << "º Medicamento: " << endl;
                  Ler_Medicamento(vet_medicamentos[k]);
                  cout << endl;
                  cout << "---" << endl;
                }else if(!vet_medicamentos[k].mostrar){
                  i--;
                }

                k++;

              }

            }
            break;
          
          case 5:
            cout << "Opção em desenvolvimento" << endl;
            break;

          case 6:
            char salvar;
            cout << "Deseja salvar o arquivo? (s/N)" << endl;
            cin >> salvar;

            if (salvar == 's'){
              cout << "Opção em desenvolvimento" << endl;
            }

            cout << "Saindo..." << endl;
            break;

          default:
            cout << "Opção inexistente." << endl;

        }

        cout << endl;


      }while(opcao != 6);

      delete []vet_medicamentos;

    } 
    arquivo_medicamentos.close();
    
    

    return 0;
}
