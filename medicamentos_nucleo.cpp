// NOMES:
// Henrique César Rosa Silva de Paiva;
// Katriel Felipe Reis Carvalho;
// Pedro Victor Tavares Duarte.
//
// TURMA: 10A 
//
// TEMA: Medicamentos

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Medicamento{

  unsigned id;
  string nome_comercial;
  string principio_ativo;
  float dosagem;
  string laboratorio;
  bool mostrar;

};

void Receber_Medicamento(Medicamento &medicamento, unsigned id){

  medicamento.mostrar = true;
  medicamento.id = id;

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

void Remover_Medicamento(Medicamento vet_medicamentos[], unsigned remover){

  vet_medicamentos[remover].mostrar = false;

}


void Ler_Medicamento(Medicamento medicamento){

  cout << "Id: " << medicamento.id << endl;
  cout << "Nome Comercial: " << medicamento.nome_comercial << endl;
  cout << "Principio Ativo: " << medicamento.principio_ativo << endl;
  cout << "Dosagem: " << medicamento.dosagem << " mg"<<  endl;
  cout << "Laboratorio: " << medicamento.laboratorio << endl;

}

void Salvar_Medicamentos(Medicamento vet_medicamentos[], unsigned tamanho){

  ofstream arquivo_medicamentos_saida("medicamentos.csv");
  arquivo_medicamentos_saida << "#id,\"nome_comercial\",\"principio_ativo\",dosagem(mg),\"laboratorio\""<<endl;

  for(unsigned i=0; i<tamanho; i++){

    if(vet_medicamentos[i].mostrar == true){
      arquivo_medicamentos_saida << vet_medicamentos[i].id << ','
        << '"' << vet_medicamentos[i].nome_comercial
        << '"' << "," << '"' << vet_medicamentos[i].principio_ativo<<'"'
        <<','<< vet_medicamentos[i].dosagem <<','
        << '"' << vet_medicamentos[i].laboratorio << '"'<<endl;
    }

  }

}

void Intercala_Nome(Medicamento vet_medicamentos[], unsigned inicio, unsigned meio, unsigned fim){

  unsigned tamanho = fim - inicio + 1;
  Medicamento *vet_aux = new Medicamento[tamanho];
  unsigned i = inicio, j = meio + 1, k = 0;
  while(i<=meio && j<=fim){

    if(vet_medicamentos[i].nome_comercial > vet_medicamentos[j].nome_comercial){

      vet_aux[k] = vet_medicamentos[j];
      j++;

    }else if(vet_medicamentos[i].nome_comercial < vet_medicamentos[j].nome_comercial){

      vet_aux[k] = vet_medicamentos[i];
      i++;

    }else if(vet_medicamentos[i].nome_comercial == vet_medicamentos[j].nome_comercial){

      if(vet_medicamentos[i].id > vet_medicamentos[j].id){
        vet_aux[k] = vet_medicamentos[j];
        j++;
      }else {
        vet_aux[k] = vet_medicamentos[i];
        i++;
      }

    }
    k++;

  }

  while(i <= meio){
    vet_aux[k] = vet_medicamentos[i];
    i++;
    k++;
  }

  while(j <= fim){
    vet_aux[k] = vet_medicamentos[j];
    j++;
    k++;
  }

  for(unsigned index = 0; index < tamanho; index++){

    vet_medicamentos[inicio + index] = vet_aux[index];

  }


  delete[] vet_aux;

}
void Intercala_Id(Medicamento vet_medicamentos[], unsigned inicio, unsigned meio, unsigned fim){

  unsigned tamanho = fim - inicio + 1;
  Medicamento *vet_aux = new Medicamento[tamanho];
  unsigned i = inicio, j = meio + 1, k = 0;
  while(i<=meio && j<=fim){

    if(vet_medicamentos[i].id > vet_medicamentos[j].id){

      vet_aux[k] = vet_medicamentos[j];
      j++;

    }else{

      vet_aux[k] = vet_medicamentos[i];
      i++;

    }    
    k++;

  }

  while(i <= meio){
    vet_aux[k] = vet_medicamentos[i];
    i++;
    k++;
  }

  while(j <= fim){
    vet_aux[k] = vet_medicamentos[j];
    j++;
    k++;
  }

  for(unsigned index = 0; index < tamanho; index++){

    vet_medicamentos[inicio + index] = vet_aux[index];

  }


  delete[] vet_aux;


}

void Merge_Sort(Medicamento vet_medicamentos[], unsigned inicio, unsigned fim, int opc_ordena){


  if(inicio != fim){

    unsigned meio = (inicio + fim)/2;

    Merge_Sort(vet_medicamentos, inicio, meio, opc_ordena);
    Merge_Sort(vet_medicamentos, meio+1, fim, opc_ordena);

    if(opc_ordena == 1)
      Intercala_Id(vet_medicamentos, inicio, meio, fim);
    else
      Intercala_Nome(vet_medicamentos, inicio, meio, fim);

  }


}

int Busca_Binaria_Nome(Medicamento vet_medicamentos[], unsigned inicio, unsigned fim, string valor_buscado){
  if(inicio > fim){
    return -1;
  }

  int medio = (inicio+fim)/2;

  if(valor_buscado == vet_medicamentos[medio].nome_comercial){
    return medio;
  }
  else if(vet_medicamentos[medio].nome_comercial < valor_buscado){
    return Busca_Binaria_Nome(vet_medicamentos, medio+1, fim, valor_buscado);
  }
  else{
    return Busca_Binaria_Nome(vet_medicamentos, 0, medio-1, valor_buscado);
  }
}

int Busca_Binaria_Id(Medicamento *vet_medicamentos, unsigned inicio, unsigned fim, unsigned valor_buscado){
  if(inicio > fim){
    return -1;
  }

  unsigned medio = (inicio+fim)/2;

  if(valor_buscado == vet_medicamentos[medio].id){
    return medio;
  }
  else if(vet_medicamentos[medio].id < valor_buscado){
    return Busca_Binaria_Id(vet_medicamentos, medio+1, fim, valor_buscado);
  }
  else{
    return Busca_Binaria_Id(vet_medicamentos, 0, medio-1, valor_buscado);
  }
}

int main(){

  ifstream arquivo_medicamentos_entrada("medicamentos.csv");

  if (!arquivo_medicamentos_entrada){
    cout << "Não foi possível abrir o arquivo" << endl;
  }
  else{

    char letra_lixo;
    string linha_lixo;

    unsigned capacidade = 40;
    unsigned tamanho = 0;


    getline(arquivo_medicamentos_entrada, linha_lixo);

    Medicamento *vet_medicamentos = new Medicamento[capacidade];

    unsigned j = 0;

    while(arquivo_medicamentos_entrada >> vet_medicamentos[j].id){
      arquivo_medicamentos_entrada >> letra_lixo >> letra_lixo;

      getline(arquivo_medicamentos_entrada, vet_medicamentos[j].nome_comercial, '"');

      arquivo_medicamentos_entrada >> letra_lixo >> letra_lixo;

      getline(arquivo_medicamentos_entrada, vet_medicamentos[j].principio_ativo, '"');

      arquivo_medicamentos_entrada >> letra_lixo;

      arquivo_medicamentos_entrada >> vet_medicamentos[j].dosagem;

      arquivo_medicamentos_entrada >> letra_lixo >> letra_lixo;

      getline(arquivo_medicamentos_entrada, vet_medicamentos[j].laboratorio, '"');

      vet_medicamentos[j].mostrar = true;

      j++;
      tamanho++;

      if (tamanho >= capacidade){
        capacidade += 5;

        Medicamento *vet_aux = new Medicamento[capacidade];

        for(unsigned i=0; i<(capacidade-5); i++){

          Copiar_Medicamento(&vet_aux[i], vet_medicamentos[i]);

        }

        delete []vet_medicamentos;
        vet_medicamentos = vet_aux;

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

                 char prosseguir;
                 cout << "Ao inserir um elemento o vetor será ordenado de acordo com o ID!" << endl;
                 cout << "Deseja prosseguir (s/N)? ";
                 cin >> prosseguir;

                 if(prosseguir == 's'){

                   Merge_Sort(vet_medicamentos, 0, tamanho-1, 1);

                   Receber_Medicamento(vet_medicamentos[j], vet_medicamentos[j-1].id + 1);

                   j++;
                   tamanho++;

                   if (tamanho >= capacidade){
                     capacidade += 5;

                     Medicamento *vet_temp = new Medicamento[capacidade];

                     for(unsigned i=0; i<(capacidade-5); i++){

                       Copiar_Medicamento(&vet_temp[i], vet_medicamentos[i]);

                     }

                     delete []vet_medicamentos;
                     vet_medicamentos = vet_temp;

                   }

                   cout << "Medicamento inserido com sucesso!" << endl;
                   cout << endl;
                 }

               }break;

        case 2:{

                 int opc_ordena;
                 cout<<"Opções para buscar o elemento para remove-lo, os medicamentos serão ordenados com base na sua opção!"<<endl;
                 cout<<"1- Por ID \n" << "2- Pelo nome comercial" <<endl;
                 cout<<"Insira uma opção: ";
                 cin>>opc_ordena;

                 while(opc_ordena != 1 and opc_ordena!= 2){
                   cout<<"ENTRADA INVALIDA! DIGITE NOVAMENTE"<<endl;
                   cin>>opc_ordena;
                 }

                 Merge_Sort(vet_medicamentos, 0, tamanho-1, opc_ordena);

                 unsigned posicao_remover;

                 if(opc_ordena == 1){

                   unsigned medicamento_remover;
                   cout<< "ID do medicamento a ser removido: ";
                   cin >> medicamento_remover;
                   posicao_remover = Busca_Binaria_Id(vet_medicamentos, 0, capacidade, medicamento_remover);

                 } else{

                   string medicamento_remover;
                   cout<< "Nome comercial do medicamento a ser removido: ";
                   cin.ignore();
                   getline(cin, medicamento_remover);
                   posicao_remover = Busca_Binaria_Nome(vet_medicamentos, 0, capacidade, medicamento_remover);
                 }
                 if(posicao_remover != -1){
                   tamanho--;
                   Remover_Medicamento(vet_medicamentos, posicao_remover);
                 }else{
                   cout << "Não há nenhum elemento com o parametro no qual você quer deletar"<< endl;
                 }

               }break;

        case 3:{
                 int opc_ordena;
                 cout<<"Opções para buscar o elemento, os medicamentos serão ordenados com base na sua escolha!"<<endl;
                 cout<<"1- Por ID \n" << "2- Pelo nome comercial" <<endl;
                 cout<<"Insira uma opção: ";
                 cin>>opc_ordena;

                 while(opc_ordena != 1 and opc_ordena!= 2){
                   cout<<"ENTRADA INVALIDA! DIGITE NOVAMENTE"<<endl;
                   cin>>opc_ordena;
                 }

                 Merge_Sort(vet_medicamentos, 0, tamanho-1, opc_ordena);

                 unsigned posicao_procurar;

                 if(opc_ordena == 1){

                   unsigned medicamento_procurar;
                   cout<< "ID do medicamento a ser procurado: ";
                   cin >> medicamento_procurar;
                   posicao_procurar = Busca_Binaria_Id(vet_medicamentos, 0, capacidade, medicamento_procurar);

                 } else{

                   string medicamento_remover;
                   cout<< "Nome comercial do medicamento a ser procurado: ";
                   cin.ignore();
                   getline(cin, medicamento_remover);
                   posicao_procurar = Busca_Binaria_Nome(vet_medicamentos, 0, capacidade, medicamento_remover);
                 }
                 if(posicao_procurar != -1){
                   cout << endl;
                   Ler_Medicamento(vet_medicamentos[posicao_procurar]);
                 }else{
                   cout << "Não há nenhum elemento com esse parametro"<< endl;
                 }

               }break;

        case 4:{

                 unsigned inicio, fim;

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

                 unsigned k = 0;
                 for(unsigned i=0; i < fim; i++){

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

               Salvar_Medicamentos(vet_medicamentos, tamanho);

               break;

        case 6:
               char salvar;
               cout << "Deseja salvar o arquivo? (s/N)" << endl;
               cin >> salvar;

               if (salvar == 's'){
                 Salvar_Medicamentos(vet_medicamentos, tamanho);
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
  arquivo_medicamentos_entrada.close();



  return 0;
}
