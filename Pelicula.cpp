#include "Pelicula.hpp"

Pelicula::Pelicula() {
  id = -1;
  tam = -1;
}

Pelicula::Pelicula(const Pelicula& p) {
  id = p.getId();
  tam = p.getTamano();
}

Pelicula::~Pelicula(){}

void Pelicula::leer_pelicula(int &i) {
  id = i;
  tam = readint();
}

int Pelicula::getId() const{
  return id;
}

int Pelicula::getTamano() const{
  return tam;
}