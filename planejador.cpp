#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "planejador.h"

using namespace std;

/* *************************
   * CLASSE IDPONTO        *
   ************************* */

/// Atribuicao de string
void IDPonto::set(string&& S)
{
  t=move(S);
  if (!valid()) t.clear();
}

/* *************************
   * CLASSE IDROTA         *
   ************************* */

/// Atribuicao de string
void IDRota::set(string&& S)
{
  t=move(S);
  if (!valid()) t.clear();
}

/* *************************
   * CLASSE PONTO          *
   ************************* */

/// Distancia entre 2 pontos (formula de haversine)
double Ponto::distancia(const Ponto& P) const
{
  // Gera excecao se pontos invalidos
  if (!valid() || !P.valid())
    throw invalid_argument("distancia: ponto(s) invalido(s)");

  // Tratar logo pontos identicos
  if (id == P.id) return 0.0;
  // Constantes
  static const double MY_PI = 3.14159265358979323846;
  static const double R_EARTH = 6371.0;
  // Conversao para radianos
  double lat1 = MY_PI*this->latitude/180.0;
  double lat2 = MY_PI*P.latitude/180.0;
  double lon1 = MY_PI*this->longitude/180.0;
  double lon2 = MY_PI*P.longitude/180.0;
  // Seno das diferencas
  double sin_dlat2 = sin((lat2-lat1)/2.0);
  double sin_dlon2 = sin((lon2-lon1)/2.0);
  // Quadrado do seno do angulo entre os pontos
  double a = sin_dlat2*sin_dlat2 + cos(lat1)*cos(lat2)*sin_dlon2*sin_dlon2;
  // Em vez de utilizar a funcao arcosseno, asin(sqrt(sin2_ang)),
  // vou utilizar a funcao arcotangente, menos sensivel a erros numericos.
  // Distancia entre os pontos
  return 2.0*R_EARTH*atan2(sqrt(a),sqrt(1-a));
}

/* *************************
   * CLASSE ROTA           *
   ************************* */

/// Retorna a outra extremidade da rota, a que nao eh o parametro.
/// Gera excecao se o parametro nao for uma das extremidades da rota.
IDPonto Rota::outraExtremidade(const IDPonto& ID) const
{
  if (extremidade[0]==ID) return extremidade[1];
  if (extremidade[1]==ID) return extremidade[0];
  throw invalid_argument("outraExtremidade: invalid IDPonto parameter");
}

/* *************************
   * CLASSE PLANEJADOR     *
   ************************* */

/// Torna o mapa vazio
void Planejador::clear()
{
  pontos.clear();
  rotas.clear();
}

/// Retorna um Ponto do mapa, passando a id como parametro.
/// Se a id for inexistente, gera excecao.
Ponto Planejador::getPonto(const IDPonto& Id) const
{
  // Procura um ponto que corresponde aa Id do parametro
  /* ***********  /
  /  FALTA FAZER  /  feito()
  /  *********** */
  auto iter = find(pontos.begin(), pontos.end(), Id);
  // Em caso de sucesso, retorna o ponto encontrado
  if(iter != pontos.end())
  {
    return *iter;
  }
  else
  {
    // Se nao encontrou, gera excecao
    throw invalid_argument("getPonto: invalid IDPonto parameter");

  }
}

/// Retorna um Rota do mapa, passando a id como parametro.
/// Se a id for inexistente, gera excecao.
Rota Planejador::getRota(const IDRota& Id) const
{
  // Procura uma rota que corresponde aa Id do parametro
  /* ***********  /
  /  FALTA FAZER  /  feito()
  /  *********** */
  auto iter = find(rotas.begin(), rotas.end(), Id);
  // Em caso de sucesso, retorna o ponto encontrado
  if(iter != rotas.end())
  {
    return *iter;
  }
  else
  {
    // Se nao encontrou, gera excecao
    throw invalid_argument("getRota: invalid IDRota parameter");
  }
}

/// Imprime os pontos do mapa no console
void Planejador::imprimirPontos() const
{
  for (const auto& P : pontos)
  {
    cout << P.id << '\t' << P.nome
         << " (" <<P.latitude << ',' << P.longitude << ")\n";
  }
}

/// Imprime as rotas do mapa no console
void Planejador::imprimirRotas() const
{
  for (const auto& R : rotas)
  {
    cout << R.id << '\t' << R.nome << '\t' << R.comprimento << "km"
         << " [" << R.extremidade[0] << ',' << R.extremidade[1] << "]\n";
  }
}

/// Leh um mapa dos arquivos arq_pontos e arq_rotas.
/// Caso nao consiga ler dos arquivos, deixa o mapa inalterado e gera excecao ios_base::failure.
void Planejador::ler(const std::string& arq_pontos,
                     const std::string& arq_rotas)
{
  // Listas temporarias para armazenamento dos Pontos e Rotas lidos.
  /* ***********  /
  /  FALTA FAZER  /   feito()
  /  *********** */

  list<Ponto> temp_pontos;
  list<Rota> temp_rotas;

  // Leh os Pontos do arquivo e armazena na lista temporaria de Pontos.
  // 1) Abre o arquivo de Pontos (Em caso de erro, codigo 1)
  // 2) Leh e testa o cabecalho do arquivo: "ID;Nome;Latitude;Longitude"
  //    (Em caso de erro, codigo 2)
  // 3) Leh os Pontos, um em cada linha, ateh que o arquivo acabe:
  //    3.1) Leh a ID (Em caso de erro, codigo 3)
  //    3.2) Leh o nome (Em caso de erro, codigo 4)
  //    3.3) Leh a latitude (Em caso de erro, codigo 5)
  //    3.4) Leh a longitude (Em caso de erro, codigo 6)
  //    3.5) Confirma que o Ponto com esses parametros lidos eh valido
  //         (Em caso de erro, codigo 7)
  //    3.6) Confirma que nao existe Ponto com a mesma ID na lista temporaria
  //         de Pontos (Em caso de erro, codigo 8)
  //    3.7) Insere o Ponto lido na lista temporaria de Pontos
  //    Em caso de qualquer erro, gera excecao ios_base::failure com mensagem:
  //      "Erro <CODIGO> na leitura do arquivo de pontos <ARQ_PONTOS>"
  // 4) Fecha o arquivo de Pontos
  /* ***********  /
  /  FALTA FAZER  / feito()
  /  *********** */



  try
  {
    fstream pontos_in(arq_pontos);
    if(!pontos_in.is_open()) throw 1;

    string cabecalho;
    pontos_in >> cabecalho;
    if(cabecalho != "ID;Nome;Latitude;Longitude"  || pontos_in.fail()) throw 2;
    do
    {

      Ponto prov;
      string id_prov;

      pontos_in >> ws;
      getline(pontos_in, id_prov, ';');

      if(!pontos_in) throw 3;
      prov.id.set(move(id_prov));

      getline(pontos_in, prov.nome, ';');
      if(!pontos_in) throw 4;

      pontos_in.ignore(1, ';');

      pontos_in >> prov.latitude;
      if(!pontos_in) throw 5;

      pontos_in.ignore(1, ';');

      pontos_in >> prov.longitude;
      if(!pontos_in) throw 6;

      pontos_in >> ws; //ignorando delimitadores
      //teste de validade
      if(!prov.valid()) throw 7;

      auto iter = find(temp_pontos.begin(), temp_pontos.end(), prov.id);
      if(iter != temp_pontos.end()) throw 8; // ja existe um ponto com esse id na lista
      else temp_pontos.push_back(prov);

    } while (!pontos_in.eof());
    pontos_in.close();
  }
  catch(int i)
  {

    string msg_err = "Erro " + to_string(i) + " na leitura do arquivo de pontos" + arq_pontos;
    throw ios_base::failure(msg_err);
  }




  // Leh as Rotas do arquivo e armazena na lista temporaria de Rotas.
  // 1) Abre o arquivo de Rotas (Em caso de erro, codigo 1)
  // 2) Leh e testa o cabecalho do arquivo: "ID;Nome;Extremidade 1;Extremidade 2;Comprimento"
  //    (Em caso de erro, codigo 2)
  // 3) Leh as Rotas, uma em cada linha, ateh que o arquivo acabe:
  //    3.1) Leh a ID (Em caso de erro, codigo 3)
  //    3.2) Leh o nome (Em caso de erro, codigo 4)
  //    3.3) Leh a ID da extremidade[0] (Em caso de erro, codigo 5)
  //    3.4) Leh a ID da extremidade[1] (Em caso de erro, codigo 6)
  //    3.5) Leh o comprimento (Em caso de erro, codigo 7)
  //    3.6) Confirma que a Rota com esses parametros lidos eh valida
  //         (Em caso de erro, codigo 8)
  //    3.7) Confirma que a Id da extremidade[0] corresponde a um ponto lido
  //         na lista temporaria de Pontos (Em caso de erro, codigo 9)
  //    3.8) Confirma que a Id da extremidade[1] corresponde a um ponto lido
  //         na lista temporaria de Pontos (Em caso de erro, codigo 10)
  //    3.9) Confirma que nao existe Rota com a mesma ID na lista temporaria
  //         de Rotas (Em caso de erro, codigo 11)
  //    3.10) Insere a Rota lida na lista temporaria de Rotas
  //    Em caso de qualquer erro, gera excecao ios_base::failure com mensagem:
  //      "Erro <CODIGO> na leitura do arquivo de rotas <ARQ_ROTAS>"
  // 4) Fecha o arquivo de Rotas
  /* ***********  /
  /  FALTA FAZER  /  feito()
  /  *********** */

  try
  {
    fstream rotas_in(arq_rotas);
    if(!rotas_in.is_open()) throw 1;
    string cabecalho;
    getline(rotas_in, cabecalho);  // tem espaço em branco ent usa getline
    if(cabecalho.back() == '\r') cabecalho.pop_back(); // meu getline estava pegando um char a mais

    if(cabecalho != "ID;Nome;Extremidade 1;Extremidade 2;Comprimento"  || rotas_in.fail()) throw 2;
    do
    {
      Rota prov;

      string id_prov;
      getline(rotas_in, id_prov, ';');
      if(!rotas_in) throw 3;

      prov.id.set(move(id_prov));

      getline(rotas_in, prov.nome, ';');
      if(!rotas_in) throw 4;

      getline(rotas_in, id_prov, ';');
      prov.extremidade[0].set(move(id_prov));
      if(!rotas_in) throw 5;


      getline(rotas_in, id_prov, ';');
      prov.extremidade[1].set(move(id_prov));
      if(!rotas_in) throw 6;

      rotas_in >> prov.comprimento;
      if(!rotas_in) throw 7;

      rotas_in.ignore(1, ';');

      if(!prov.valid()) throw 8;

      //tem que existir os pontos das extremidades já na lista temporaria de pontos
      auto iter_ponto = find(temp_pontos.begin(), temp_pontos.end(), prov.extremidade[0]);
      if(iter_ponto == temp_pontos.end()) throw 9;
      iter_ponto = find(temp_pontos.begin(), temp_pontos.end(), prov.extremidade[1]);
      if(iter_ponto == temp_pontos.end()) throw 10;

      auto iter_rotas = find(temp_rotas.begin(), temp_rotas.end(), prov.id);
      if(iter_rotas != temp_rotas.end()) throw 11; //já existe uma rota com esse id na lista
      else temp_rotas.push_back(prov);

      rotas_in >> ws;
    } while (!rotas_in.eof());
    rotas_in.close();
  }
  catch(int i)
  {

    string msg_err = "Erro " + to_string(i) + " na leitura do arquivo de rotas" + arq_rotas;
    throw ios_base::failure(msg_err);
  }

  // Faz as listas temporarias de Pontos e Rotas passarem a ser
  // as listas de Pontos e Rotas do planejador.
  /* ***********  /
  /  FALTA FAZER  /  feito()
  /  *********** */

  pontos.resize(temp_pontos.size());
  rotas.resize(temp_rotas.size());



  copy(temp_pontos.begin(), temp_pontos.end(), pontos.begin());
  copy(temp_rotas.begin(), temp_rotas.end(), rotas.begin());

}

/// *******************************************************************************
/// Calcula o caminho entre a origem e o destino do planejador usando o algoritmo A*
/// *******************************************************************************

/// Noh: os elementos dos conjuntos de busca do algoritmo A*
/* ***********  /
/  FALTA FAZER  /  feito()
/  *********** */

// classe que armazena informacoes de um noh

struct Noh
{
  IDPonto id_pt;
  IDRota id_rt;


  double g; // custo passado

  double h; // custo futuro

  double f; // custo total f() = g + h


  // construtor default
  Noh(): id_pt(), id_rt(), g(0), h(0), f(0) {}

  Noh(const Noh &N): id_pt(N.id_pt), id_rt(N.id_rt), g(N.g), h(N.h), f(N.f) {}

  // sobrecarga de operadores
  bool operator==(const IDPonto& ID)
  {
      return id_pt == ID;
  }
  bool operator<(const Noh& N)
  {
      return f < N.f;
  }
  friend ostream& operator<<(ostream& X, const Noh& N)
  {
    return X<< "IDPonto: " << N.id_pt << " IDRota; " << N.id_rt;
  }

};

/// Calcula o caminho mais curto no mapa entre origem e destino, usando o algoritmo A*
/// Retorna o comprimento do caminho encontrado (<0 se nao existe caminho).
/// O parametro C retorna o caminho encontrado (vazio se nao existe caminho).
/// O parametro NA retorna o numero de nos (>=0) em Aberto ao termino do algoritmo A*,
/// mesmo quando nao existe caminho.
/// O parametro NF retorna o numero de nos (>=0) em Fechado ao termino do algoritmo A*,
/// mesmo quando nao existe caminho.
/// Em caso de parametros de entrada invalidos ou de erro no algoritmo, gera excecao.
double Planejador::calculaCaminho(const IDPonto& id_origem,
                                  const IDPonto& id_destino,
                                  Caminho& C, int& NA, int& NF)
{
  // Zera o caminho resultado
  C.clear();

  try
  {
    // Mapa vazio
    if (empty()) throw 1;

    Ponto pt_orig, pt_dest;
    // Calcula os pontos que correspondem a id_origem e id_destino.
    // Se algum nao existir, throw 2
    try
    {
      pt_orig = getPonto(id_origem);
      pt_dest = getPonto(id_destino);
    }
    catch(...)
    {
      throw 2;
    }

    /* *****************************  /
    /  IMPLEMENTACAO DO ALGORITMO A*  /
    /  ***************************** */

    /* ***********  /
    /  FALTA FAZER  / fazendo()
    /  *********** */

    Noh atual;
    atual.id_pt = id_origem;
    atual.g = 0;
    atual.h = pt_orig.distancia(pt_dest);
    atual.f = atual.h + atual.g;

    list<Noh> Aberto;
    list<Noh> Fechado;

    Aberto.push_front(atual); // insere atual no aberto


    do
    {
        atual = *Aberto.begin(); // leh o 1 noh (de menor custo) de Aberto
        Aberto.pop_front(); // exclui o 1 noh de Aberto


        Fechado.push_front(atual); // inclui atual em Fechado

        // expande se n eh solucao
        if(atual.id_pt != id_destino)
        {
            // gera sucessores de atual
            auto iter_suc = rotas.begin();
            do
            {
                if(iter_suc != rotas.begin() || iter_suc != rotas.end())
                {
                    iter_suc++;
                }
                // procura sucessor a partir da 1 posicao dps do ultimo sucessor
                iter_suc = find(iter_suc, rotas.end(), atual.id_pt);
                // achou rota?
                if(iter_suc != rotas.end())
                {
                    Rota suc_rota(*iter_suc);
                    // gera noh sucessor "suc"
                    Noh suc;
                    // extremidade rota_suc != do ponto atual
                    suc.id_pt = suc_rota.outraExtremidade(atual.id_pt);
                    // achando o ponto que corresponde a esse ID
                    Ponto pt_suc = getPonto(suc.id_pt);

                    suc.id_rt = suc_rota.id;
                    suc.g = atual.g + suc_rota.comprimento;
                    suc.h = pt_suc.distancia(pt_dest);
                    suc.f = suc.h + suc.g;


                    // inicialmente, assume que n existe igual a "suc"
                    bool eh_inedito(true);
                    //procura Noh igual "suc" em fechado
                    auto old_iter = find(Fechado.begin(), Fechado.end(), suc.id_pt);


                    if(old_iter != Fechado.end())
                    {
                        eh_inedito = false;
                    }
                    else
                    {
                        // procura Noh igual "suc" em aberto
                        old_iter = find(Aberto.begin(), Aberto.end(), suc.id_pt);
                        // achou algum noh?
                        if(old_iter != Aberto.end())
                        {

                            // o custo dele eh menor?
                            Noh old(*old_iter);
                            if(suc.f < old.f)
                            {
                                // excluindo anterior
                                Aberto.erase(old_iter);
                            }
                            else
                            {
                                // Noh ja existe
                                eh_inedito = false;
                            }
                        }
                        else{
                        }
                    }

                    // n existe igual?
                    if(eh_inedito)
                    {
                        // acha "big", 1 Noh de Aberto com f maior
                        // que o f de suc
                        auto big = lower_bound(Aberto.begin(), Aberto.end(), suc);
                        // insere "suc" em aberto
                        Aberto.insert(big, suc);
              /*          cout << "Tamanho Aberto: " << Aberto.size() << " Tamanho Fechado: " << Fechado.size() <<endl;
                        // bora mostrar td em Aberto
                        cout << "ABERTO (" << Aberto.size() << ") | ";
                        for(auto& n : Aberto)
                        {
                            cout << n << " | ";
                        }
                        cout << endl;
                        cout << "FECHADO (" << Fechado.size() << ") | ";
                        for(auto& n : Fechado)
                        {
                            cout << n << " | ";
                        }
                        cout << endl;    */

                    }

                }
            }while(iter_suc != rotas.end());
        }

    // repita enqanto nao encontrou solução
    // e ha Nohs em aberto
    }while(!Aberto.empty() && pt_dest != atual.id_pt );

    //calcula nmr de Nohs da busca
    NA = Aberto.size();
    NF = Fechado.size();

    // inicialmente, caminho vazio
    C.clear();

    // encontrou solucao ou nao?
    if(pt_dest != atual.id_pt)
    {
        // nao existe solucao
        return -1.0;
        // caminho permanece vazio

    }
    else
    {
        // calcula caminho e comprimento
        double compr = atual.g;

        // refaz o caminho, procurando Nohs antecessores
        // em fechado
        while(atual.id_rt.valid())
        {
            // acrescenta trecho atual no topo (inicio)
            // de "caminho"
            Trecho trecho_temp(atual.id_rt, atual.id_pt);
            C.push_front(trecho_temp);

            // recupera o antecessor

            // obtem "rota_ant", rota que levou ate atual
            Rota rota_ant = getRota(atual.id_rt);

            // calcula o id do antecessor
            IDPonto id_pt_ant(rota_ant.outraExtremidade(atual.id_pt));
            // procura Noh igual a id_pt_ant em Fechado
            auto iter_noh = find(Fechado.begin(), Fechado.end(), id_pt_ant);
            // (duvida) preciso verificar se eh valido???
            atual = *iter_noh;
        }

        // acrescenta origem no topo ,
        // (inicio) de caminho
        Trecho trecho_inicial(atual.id_rt, atual.id_pt);
        C.push_front(trecho_inicial);
        return compr;  // SUBSTITUA pelo return do valor correto
    }

    // O try tem que terminar retornando o comprimento calculado
  }
  catch(int i)
  {
    string msg_err = "Erro " + to_string(i) + " no calculo do caminho\n";
    throw invalid_argument(msg_err);
  }
}
