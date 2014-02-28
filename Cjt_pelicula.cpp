#include "Cjt_pelicula.hpp"
#include "Pelicula.hpp"

Cjt_pelicula::Cjt_pelicula() {
  vecpel = vector<Pelicula> (0);
}

Cjt_pelicula::~Cjt_pelicula() {}

void Cjt_pelicula::leer_peliculas() {
  int n;
  n = readint();
  vecpel = vector<Pelicula> (n);
  for(int i = 0; i < n; ++i) {
    Pelicula p;
    p.leer_pelicula(i);
    vecpel[i] = p;
  }
}

Pelicula Cjt_pelicula::getPeliculaId(int &id) {
  int i = 0;
  bool trobat = false;
  while (i < vecpel.size() and not trobat) {
    if(vecpel[i].getId() == id-1) trobat = true;
    else ++i; 
  }
  return vecpel[i];
}

int Cjt_pelicula::mida() {
  return vecpel.size();
}

void Cjt_pelicula::escribir_peliculas() {
  int n = vecpel.size();
  cout << "Llista de pelicules: " << endl;
  for (int i = 0; i < vecpel.size(); ++i) {
    cout << " ID: " << vecpel[i].getId() << endl;
    cout << " Tamany: " << vecpel[i].getTamano() << endl;
    cout << "----------------" << endl;
  }
}