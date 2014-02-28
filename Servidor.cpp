#include "Servidor.hpp"

Servidor::Servidor(){
  tiempo = 0;
  ancho = 0;
  idpet = -1;
}
Servidor::Servidor(const Servidor &s){
  id = s.getId();
  ancho = s.getAncho();
  tiempo = s.getTiempo();
  lpel = s.getPeliculas();
  idpet = s.getIdpet();
}
Servidor::~Servidor(){}
void Servidor::leer_servidor(int i, int n){
  id = i+1;
  lpel = vector<bool>(n,false);
  int x;
  x = readint();
  ancho = x;
  x = readint();
  addPeliculas(x);
}
void Servidor::actualizar(int t){
  if(t>= tiempo) {
    tiempo = 0;
    idpet = -1;
  }
}
void Servidor::actualizar_pelicula(){
  int x;
  x = readint();
  addPeliculas(x);
  x = readint();
  deletePeliculas(x);
}

void Servidor::setTiempo(int t) {
  tiempo = t;
}

void Servidor::setIdpet(int idp) {
  idpet = idp;
}

int Servidor::getId() const{
  return id;
}
int Servidor::getTiempo() const{
  return tiempo;
}
int Servidor::getAncho() const{
  return ancho;
}

int Servidor::getIdpet() const {
  return idpet;
}

vector<bool> Servidor::getPeliculas() const {
  return lpel;
}

bool Servidor::contPelicula(int& id) const{
  return lpel[id];
}

void Servidor::addPeliculas(int n){
  int x;
  for(int i = 0; i < n; ++i) {
    x = readint();
    lpel[x-1] = true;
  }
}
void Servidor::deletePeliculas(int n){
  int x; 
  for(int i = 0; i < n; ++i) {
    x = readint();
    lpel[x-1] = false;
  }
}
/*void Servidor::llistar_peliculas(){
  int n = lpel.size();
  cout << "Llista de pelicules: " << endl;
  for (int i = 0; i < lpel.size(); ++i) {
    cout << " ID: " << i << endl;
    cout << " Estado: " << lpel[i] << endl;
    cout << "----------------" << endl;
  }
}*/
