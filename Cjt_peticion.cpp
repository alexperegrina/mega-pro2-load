#include "Cjt_peticion.hpp"
#include "Peticion.hpp"



Cjt_peticion::Cjt_peticion() {
  cont = 0;
  list<Peticion> listpet;
}

Cjt_peticion::~Cjt_peticion() {}

//privada
void Cjt_peticion::pushList(Peticion p) {
  list<Peticion>::iterator it = listpet.begin();
  if (not listpet.empty()) {
    while (it != listpet.end() and (*it).getT_f() < p.getT_f()){
      ++it;
    } 
    listpet.insert(it,p);
  }
  else listpet.insert(listpet.begin(),p);
}

void Cjt_peticion::anadir_peticion(Peticion p) {
  pushList(p);
}

void Cjt_peticion::incrementId(Peticion &p) {
  p.setId(cont);
  ++cont;
}

int Cjt_peticion::mida() const {
  return listpet.size();
}

void Cjt_peticion::peticion_sinFinalizar(int t) {
  list<Peticion> l(listpet);
  bool b = false;
  cout << "Peticiones pendientes " << endl;
  if (not listpet.empty()) {
    list<Peticion>::iterator it;
    for(it = listpet.begin(); it != listpet.end() ; ++it) {
      if((*it).getT_f() > t) {
    	b = true;
    	cout <<  (*it).getId();
    	cout << " " << (*it).getIdPelicula();
    	cout << " " << (*it).getT_i();
    	cout << " " << (*it).getT_f() << endl;
      }
    }
  }
  if (not b) cout << "0" << endl;
}

void Cjt_peticion::pelicula_solicitada(int t1, int t2, int n) {
  //Pre: t1 <= t2, n es el numero de peliculas en el Conjunto de peliculas
  vector<int> pel(n,0);//contiene el numero de peticiones
  pair<int,int> max(n,0);//first=id, second=numero de peticions
  list<Peticion>::iterator it = listpet.begin();
  
  //Inv: pel= vector con la misma mida que el conjunto de peliculas donde cada posicion del vector(idPelicula-1) indica el numero de 
  // 	peticiones a esa pelicula,
  //	max = estructura para tener guardado el id y el numero de peticiones maximo de la lista de peticiones.
  //	it = iterador que recorre la lista desde inicio a fin.
  while (it != listpet.end()) {
    if((*it).getT_i() >= t1 and (*it).getT_i() <= t2) {
      ++pel[(*it).getIdPelicula()-1];
      if(max.second <= pel[(*it).getIdPelicula()-1]) {
    	if (max.second == pel[(*it).getIdPelicula()-1]) {
    	  if (max.first > (*it).getIdPelicula()) {
    	    max.first = (*it).getIdPelicula();
    	  }
    	}
    	else {
    	  max.first = (*it).getIdPelicula();
    	  max.second = pel[(*it).getIdPelicula()-1];
    	}
      }
    }
    ++it;
  }
  if (max.second == 0) max.first = 0;
  cout << "Pelicula mas solicitada" << endl;
  cout << max.first << " " << max.second << endl;
  //Post: Mostramos por pantalla la pelicula mas solicitada con t1 <= ti <= t2 
}
