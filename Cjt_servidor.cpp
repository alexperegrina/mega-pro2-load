#include "Cjt_servidor.hpp"
#include "Servidor.hpp"


Cjt_servidor::Cjt_servidor() {}

Cjt_servidor::~Cjt_servidor() {}

//privada
void Cjt_servidor::llegir_estructura_arbre(Arbre<int> &a,int marca, int &numser){
  Arbre<int> a1;
  Arbre<int> a2;
  int x;
  cin >> x;
  if (x!= marca and numser <= servidors.size()) {
    ++numser;
    llegir_estructura_arbre(a1,marca, numser);
    llegir_estructura_arbre(a2,marca, numser);
    a.plantar(x,a1,a2);
  }
}

//privada
void Cjt_servidor::llegir_serv(int &numpel) {
  for(int i = 0; i < servidors.size(); ++i) {
    servidors[i].leer_servidor(i,numpel);
  }
}

void Cjt_servidor::llegir_arbre_serv(int numpel) {
  int numservidors = readint();
  servidors = vector<Servidor>(numservidors);//inicialitzem el vector de servidors
  int numser = 0; //variable per contar el numero de servidor introduits en el arbre
  llegir_estructura_arbre(estructura,0,numser);
  llegir_serv(numpel);
}

void Cjt_servidor::actualizar(int t) {
  for(int i = 0; i < servidors.size(); ++i) {
    servidors[i].actualizar(t);
  }
}

void Cjt_servidor::escriure_servidorOcupats(int t) {
  bool b = false;
  cout << "Servidores ocupados" << endl;
  for(int i = 0; i < servidors.size(); ++i) {
    if (servidors[i].getTiempo() > t) {
      cout << servidors[i].getId() << " ";
      cout << servidors[i].getIdpet() << " ";
      cout << servidors[i].getTiempo() - t << endl;
      b = true;
    } 
  }
  if (not b) cout << "0"<< endl;
}

void Cjt_servidor::actualizar_servidor() {
  int x;
  x = readint();
  servidors[x-1].actualizar_pelicula();
}

int Cjt_servidor::numeroServidores() {
  return servidors.size();
}

void Cjt_servidor::marcaje(list<int> &l, int d, int idp){
  //Pre: l = L, d >= 0, 0 <= idp < mida conjunto peticion
  if (not l.empty()) {   
    list<int>::const_iterator it= l.begin();
    //Inv: it = iterador que recorre la lista desde inicio a fin.
    while (it != l.end()){
      cout << *it << " "; 
      servidors[*it-1].setTiempo(d);
      servidors[*it-1].setIdpet(idp);
      ++it;
    }                      
    cout << endl;
  } 
  //Post: Mostramos por pantalla la pelicula mas solicitada con t1 <= ti <= t2 
}

//privada
bool Cjt_servidor::condicio1(Arbre<int> &a,list<int> &l,Pelicula &pel, int &ancho, int &alt, int &prof) {
  //Pre: a = A, l = L, pel = Pelicula, ancho contine la suma de los anchos de banda de los nodos superiores, alt indica en que altura estamos encada momento,
  // prof se utiliza para indicar al nodo padre la profundidad maxima del servidor que contiene la pelicula
  bool b = false;
  if (not a.es_buit() and ancho < pel.getTamano()){
    alt++;
    int valor = a.arrel();
    int n = pel.getId();
    if(servidors[valor-1].contPelicula(n) and servidors[valor-1].getTiempo() == 0) {//el servido visitado contiene la pelicula
      ancho += servidors[valor-1].getAncho();
      l.insert(l.begin(),valor);
      prof = alt;
    }
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    list<int> ret1,ret2;
    int ancho1,ancho2;
    ancho1 = ancho2 = ancho;
    int alt1,alt2,prof1,prof2;
    alt1 = alt2 =  alt;
    prof1 = prof2 = prof;
    bool b1 = condicio1(a1,ret1,pel,ancho1,alt1,prof1);//ancho1  = ancho + (ancho de todo lo demas)
    bool b2 = condicio1(a2,ret2,pel,ancho2,alt2,prof2);//ancho2  = ancho + (ancho de todo lo demas)
    //HI: ancho1 indica el ancho de banda total de a1,ancho2 indica el ancho de banda total de a2,
    // prof1 indica la profundidad maxima del servidor que contiene la pelicula de a1,
    // prof2 indica la profundidad maxima del servidor que contiene la pelicula de a2,   
    a.plantar(valor,a1,a2); 
    if(b1 and b2) {
      if(prof1 <= prof2) {
    	ancho = ancho1;
    	l.splice(l.end(),ret1);
    	alt = alt1;
    	prof = prof1;
      }
      else {
    	ancho = ancho2;
    	l.splice(l.end(),ret2);
    	alt = alt2;
    	prof = prof2;
      } 
    }
    else if (b1){
      ancho = ancho1;
      l.splice(l.end(),ret1);
      alt = alt1;
      prof = prof1;
    }
    else if (b2){
      ancho = ancho2;
      l.splice(l.end(),ret2);
      alt = alt1;
      prof = prof1;
    }   
    if(ancho >= pel.getTamano()) b = true;
    else b = false;
  } 
  return b;
  //Post: El resultado indica si la peticion se a podido servir en una unica unidad de tiempo 
}

//privada
void Cjt_servidor::condicio2(Arbre<int> &a,list<int> &l,Pelicula &pel, int &ancho, int &alt, int &prof) {
  //Pre: a = A, l = L, pel = Pelicula, ancho contine la suma de los anchos de banda de los nodos superiores, alt indica en que altura estamos encada momento,
  // prof se utiliza para indicar al nodo padre la profundidad maxima del servidor que contiene la pelicula
  if (not a.es_buit()){
    alt++;
    int valor = a.arrel();
    int n = pel.getId();
    if(servidors[valor-1].contPelicula(n) and servidors[valor-1].getTiempo() == 0) {//el servido visitado contiene la pelicula
      ancho += servidors[valor-1].getAncho();
      l.insert(l.begin(),valor);
      prof = alt;
    }
    Arbre<int> a1,a2;
    a.fills(a1,a2);
    list<int> ret1,ret2;
    int ancho1,ancho2;
    ancho1 = ancho2 = ancho;
    int alt1,alt2,prof1,prof2;
    alt1 = alt2 =  alt;
    prof1 = prof2 = prof;
    condicio2(a1,ret1,pel,ancho1,alt1,prof1);//ancho1  = ancho + (ancho de todo lo demas)
    condicio2(a2,ret2,pel,ancho2,alt2,prof2);//ancho2  = ancho + (ancho de todo lo demas)
    //HI: ancho1 indica el ancho de banda total de a1,ancho2 indica el ancho de banda total de a2,
    // prof1 indica la profundidad maxima del servidor que contiene la pelicula de a1,
    // prof2 indica la profundidad maxima del servidor que contiene la pelicula de a2,   
    a.plantar(valor,a1,a2);   
    if(ancho1 >= ancho2 ) {
      if(ancho1 == ancho2) {
    	if(prof1 <= prof2) { 
    	  ancho = ancho1;
    	  l.splice(l.end(),ret1);
    	  alt = alt1;
    	  prof = prof1;
    	}
    	else {
    	  ancho = ancho2;
    	  l.splice(l.end(),ret2);
    	  alt = alt2;
    	  prof = prof2;
    	} 
      }
      else{
    	ancho = ancho1;
    	l.splice(l.end(),ret1);
    	alt = alt1;
    	prof = prof1;
      }
    } 
    else {
      ancho = ancho2;
      l.splice(l.end(),ret2);
      alt = alt2;
      prof = prof2;
    }     
  } 
}

//privada
int Cjt_servidor::roundUp (int a, int b){
  if (a%b == 0) return a/b;
  else return (a/b)+1;
}

void Cjt_servidor::calcular_tiempoFinal(Peticion &p,Pelicula &pel) {
  list<int> ret;
  int ancho,alt,tiempo,prof;
  ancho = tiempo = 0;
  alt = prof = -1;
  bool b = condicio1(estructura,ret,pel,ancho,alt,prof);
  if(not b) {
    ret.clear();
    ancho = tiempo = 0;
    alt = prof = -1;
    condicio2(estructura,ret,pel,ancho,alt,prof);
  }
  double d = 0;
  cout << "Peticion procesada y servidores " << endl;
  if (ancho != 0) {
    tiempo = roundUp(pel.getTamano(),ancho);
    p.setTf(tiempo);
    cout << p.getId() << " " << tiempo << endl;
    marcaje(ret,p.getT_f(),p.getId());  
  }
  else cout << p.getId() << " " << tiempo << endl;
}
