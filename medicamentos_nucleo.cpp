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

int main(){
    
    int capacidade;

    ifstream arquivo_medicamentos("medicamentos.csv");

    if (!arquivo_medicamentos){
      cout << "Não foi possível abrir o arquivo" << endl;
    }
    else{
      char letra;
      string linha;

      int num_registros = 0;

      getline(arquivo_medicamentos, linha);
      arquivo_medicamentos >> num_registros;
      capacidade = num_registros;
      arquivo_medicamentos.ignore();
      
      Medicamento vet_medicamentos[num_registros];

      for(int i=0; i<num_registros; i++){
      
        arquivo_medicamentos >> vet_medicamentos[i].id;
        
        arquivo_medicamentos >> letra;

        getline(arquivo_medicamentos, vet_medicamentos[i].nome_comercial, ',');

        getline(arquivo_medicamentos, vet_medicamentos[i].principio_ativo, ',');

        arquivo_medicamentos >> vet_medicamentos[i].dosagem;

        arquivo_medicamentos >> letra;

        getline(arquivo_medicamentos, vet_medicamentos[i].laboratorio);
        
        vet_medicamentos[i].mostrar = true;
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
                     << "O número inserido deve estar entre 1 e " << capacidade << ": ";
                cin >> inicio;
              }while (inicio <= 0 || inicio > capacidade);

              do {
                cout << "Insira o fim do intervalo de medicamentos que deseja ver." << endl 
                     << "O número inserido deve estar entre " << inicio << " e " << capacidade << ": "; 
                cin >> fim;
              }while (fim < inicio || fim > capacidade);
              
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

    } 
    arquivo_medicamentos.close();
    
    

    return 0;
}
