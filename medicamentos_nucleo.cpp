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
    
    char letra;
    string linha;

    int num_registros = 0;

    getline(arquivo_medicamentos, linha);
    arquivo_medicamentos >> num_registros;
    arquivo_medicamentos.ignore();
    
    Medicamento vet_medicamentos[num_registros];

    arquivo_medicamentos >> vet_medicamentos[0].id;
    
    arquivo_medicamentos >> letra;

    getline(arquivo_medicamentos, vet_medicamentos[0].nome_comercial, ',');

    arquivo_medicamentos >> letra;

    getline(arquivo_medicamentos, vet_medicamentos[0].principio_ativo, ',');


    arquivo_medicamentos.close();
    return 0;
}
