#include "Peticion.hpp"

Peticion::Peticion() {
  id = -1;
  t_i = -1;
  t_f = -1;
  idpelicula = -1;
}

Peticion::Peticion(int idPel, int tini) {
  id = -1;
  t_i = tini;
  t_f = -1;
  idpelicula = idPel;
}

Peticion::Peticion(const Peticion& p) {
  id = p.getId();
  t_i = p.getT_i();
  t_f = p.getT_f();
  idpelicula = p.getIdPelicula();
}

Peticion::~Peticion() {}

void Peticion::setTf(int t) {
  t_f = t + t_i;
}

void Peticion::setId(int i) {
  id = i;
}

int Peticion::getId() const {
  return id;
}

int Peticion::getT_i() const {
  return t_i;
}

int Peticion::getT_f() const {
  return t_f;
}

int Peticion::getIdPelicula() const {
  return idpelicula;
}