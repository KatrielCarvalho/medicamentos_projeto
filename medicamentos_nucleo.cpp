#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Medicamento{

    int id;
    string nome_comercial;
    string principio_ativo;
    float dosagem;
    string laboratorio;

};

int main(){

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

        cout << 'A';
      
      }
    }   
    arquivo_medicamentos.close();
    return 0;
}
