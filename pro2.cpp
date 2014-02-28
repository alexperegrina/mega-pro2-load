

/** @mainpage MEGA-PRO2-LOAD
 *  @file main.cpp
    @brief programa principal
*/
#include "Cjt_peticion.hpp"
#include "Cjt_pelicula.hpp"
#include "Cjt_servidor.hpp"
#include "Peticion.hpp"
#include "Pelicula.hpp"

int main() {
  int n;
  Cjt_pelicula peliculas;
  peliculas.leer_peliculas();
  Cjt_servidor servers;
  servers.llegir_arbre_serv(peliculas.mida());
  Cjt_peticion peticiones;
  n = readint();
  while(n != -6 ) {
    if(n == -1) {
      int t,peli;
      peli = readint();
      t = readint();
      servers.actualizar(t);
      Peticion p(peli,t);
      peticiones.incrementId(p);
      Pelicula pel = peliculas.getPeliculaId(peli);
      servers.calcular_tiempoFinal(p,pel);
      if (p.getT_f() != -1) peticiones.anadir_peticion(p);
    }
    if(n == -2) {
      int t;
      t = readint();
      servers.actualizar(t);
      peticiones.peticion_sinFinalizar(t);
    }
    if(n == -3) {
      int t;
      t = readint();
      servers.actualizar(t);
      servers.escriure_servidorOcupats(t);
    }
    if(n == -4) {
      servers.actualizar_servidor();
    }
    if(n == -5) {
      int t1,t2;
      t1 = readint();
      t2 = readint();
      peticiones.pelicula_solicitada(t1,t2,peliculas.mida());
    }
    n = readint();
  }
  
}