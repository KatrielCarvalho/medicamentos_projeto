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
void Ordena(Medicamento *ptVetMedicamento, int capac, int opcOrdena){
    for(int i=1; i<capac; i++){
        Medicamento valor_pivo = ptVetMedicamento[i];
        int j = i-1;
           if(opcOrdena == 1){
            while((j>=0) and (valor_pivo.id <ptVetMedicamento[j].id)){
                ptVetMedicamento[j+1] = ptVetMedicamento[j];
                j--;
            }
                ptVetMedicamento[j+1] = valor_pivo;
        }
           else if(opcOrdena == 2){
                  while((j>=0) and (valor_pivo.dosagem <ptVetMedicamento[j].dosagem)){
                    ptVetMedicamento[j+1] = ptVetMedicamento[j];
                    j--;
                }
        }
            ptVetMedicamento[j+1] = valor_pivo;
   }
}
int buscaBinaria(Medicamento *ptMedicamentos, int inicio, int fim, int remover){
    if(inicio > fim){
        return -1;
    }
    int medio = (inicio+fim)/2;

    if(remover == ptMedicamentos[medio].id){
        return medio;
    }
    else if(ptMedicamentos[medio].id < remover){
        return buscaBinaria(ptMedicamentos, medio+1, fim, remover);
    }
    else{
        return buscaBinaria(ptMedicamentos, 0, medio-1, remover);
    }
}

void Remover_Medicamento(Medicamento* ptMedicamento, int tam, int remover){

        ptMedicamento[remover].mostrar = false;

}



void Receber_Medicamento(Medicamento &medicamento){

  medicamento.mostrar = true;

  cout << "Insira o id do remédio: ";
  cin >> medicamento.id;

  cin.ignore();
  cout << "Insira o nome comercial do medicamento: ";
  getline(cin, medicamento.nome_comercial);

  cout << "Insira o principio ativo do medicamento: ";
  getline(cin, medicamento.principio_ativo);

  cout << "Insira a dosagem do medicamento: ";
  cin >> medicamento.dosagem;
  cin.ignore();

  cout << "Insira o laboratorio do medicamento: ";
  getline(cin, medicamento.laboratorio);

}

void Copiar_Medicamento(Medicamento *destino, Medicamento &origem){

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

            Copiar_Medicamento(&vet_temp[i], vet_medicamentos[i]);

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
          case 1:{

            Receber_Medicamento(vet_medicamentos[j]);

            j++;
            tamanho++;

            if (tamanho >= capacidade){
              capacidade += 5;

              Medicamento *vet_temp = new Medicamento[capacidade];

              for(int i=0; i<(capacidade-5); i++){

                Copiar_Medicamento(&vet_temp[i], vet_medicamentos[i]);

              }

              delete []vet_medicamentos;
              vet_medicamentos = vet_temp;

            }

            cout << "Medicamento inserido com sucesso!" << endl;
            cout << endl;

          }break;

          case 2:
            int opcOrdena;
            cout<<"Escolha a forma de ordenar para a busca binaria"<<endl;
            cout<< "1- Por ID \n" << "2- Por dosagem" <<endl;
            cin>>opcOrdena;

            while(opcOrdena != 1 and opcOrdena!= 2){
                cout<<"ENTRADA INVALIDA! DIGITE NOVAMENTE"<<endl;
                 cin>>opcOrdena;
            }
            Ordena(vet_medicamentos, capacidade, opcOrdena);

            int opcRemover, posicaoRemover;
            if(opcOrdena == 1){
                cout<< "ID do medicamento a ser removido";

            }
            else{
                cout<< "Dosagem do medicamento a ser removido";
            }
                cin>>opcRemover;

                posicaoRemover = buscaBinaria(vet_medicamentos, 0, capacidade, opcRemover);

                Remover_Medicamento(vet_medicamentos, capacidade, posicaoRemover);

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

          }break;

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
