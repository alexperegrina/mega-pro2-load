/** @file Cjt_servidor.hpp
    @brief Especificación de la clase Cjt_servidor
*/

#ifndef _CJTSERVIDOR_HPP_
#define _CJTSERVIDOR_HPP_

#include "utils.PRO2"
#include "Servidor.hpp"
#include "Peticion.hpp"
#include "Pelicula.hpp"
#include "Arbre.hpp"
#include <vector>
#include <list>

/** @class Cjt_servidor
    @brief Representa un conjunto de Servidor. 
 */
class Cjt_servidor 
{
private:
  /** @brief Arbol que contiene la estructura de los servidores */
  Arbre<int> estructura; 
  /** @brief Vector de servidores */
  vector<Servidor> servidors;
  
  /** @brief Lectura de la estructura del arbol de servidor
   *  \pre marca de parade de lectura de servidores
   *  \post a contiene la estructura de servidores
   */
  void llegir_estructura_arbre(Arbre<int> &a,int marca,int &numser);
  
  /** @brief Lectura de un arbol binario de servidor
   * 
   * \pre n es el numero de peliculas 
   * \post cierto
   */
  void llegir_serv(int &numpel);
  
  /** @brief metodo para marcar los servidores seleccionados por la peticion, el tiempo final y el id de la peticion, 
   *  mostrar por pantalla los servidores seleccionados.
   * \pre lista inicialicada, d = tiempo final calculado, id de la peticion
   * \post cierto
   */
  void marcaje(list<int> &l, int d, int idp);
  
  /** @brief metodo para calcular el tiempo final en una unica unidad de tiempo
   * \pre Arbol inicializado,lista inicializada,pelicula inicializada, ancho para para pasar en la recursividad, 
   *  	altura para saber la altura maxima y profundida para saber la profundidad del servidor que servira la peticion
   * \post bool para indicar si a podido en una unidad de tiempo
   */
  bool condicio1(Arbre<int> &a,list<int> &l,Pelicula &pel, int &ancho, int &alt, int &prof);
  
  /** @brief metodo para calcular el tiempo final cojiendo el mejor ancho de banda segun los criterios
   * \pre Arbol inicializado,lista inicializada,pelicula inicializada, ancho para para pasar en la recursividad, 
   *  	altura para saber la altura maxima y profundida para saber la profundidad del servidor que servira la peticion
   * \post cierto
   */
  void condicio2(Arbre<int> &a,list<int> &l,Pelicula &pel, int &ancho, int &alt, int &prof);
  
  /** @brief calculo de la division redondeando hacia arriba
   * \pre Tamaño de la pelicula, suma de anchos de banda 
   * \post tiempo final de la peticion
   */  
  int roundUp(int a, int b);
  
public:
 
  //Constructoras
  /** @brief Creadora por defecto. 
      Se ejecuta automáticamente al declarar una cubeta.
      \pre cierto
      \post es un conjunto de servidores vacio
  */  
  Cjt_servidor();
  
  //destructora
  ~Cjt_servidor();
  
  //modificadoras

  /** @brief Lectura de la estructura del arbol y de los servidors
   * 
   * \pre n = mida del Cjt_pelicula
   * \post cierto
   */
  void llegir_arbre_serv(int numpel);
  
  /** @brief actalizacion de los servidore
   * si t > tiempo del servidor, tiempo = 0 y  estado = false
   * \pre variable de tiempo;
   * \post cierto
   */  
  void actualizar(int t);
  
  /** @brief actualizacion Alta/Baja de peliculas en el servidor 
   *  \pre cierto
   *  \post cierto  
   */
  void actualizar_servidor();
  
  /** @brief calculo del tiempo final de la peticion(realiza los calculos apartir de las 3 condiciones)
   * \pre Peticion inicializada, Pelicula inicializada
   * \post cierto
   */
  void calcular_tiempoFinal(Peticion &pet, Pelicula &pel);
   
  //consultoras  
  
  /** @brief consulta de numero de servidores
   *  \pre cierto
   *  \post cierto  
   */
  int numeroServidores();
  
  //escritura
  
  /** @brief escritura de servidores ocupados en el tiempo t
   * \pre variable de tiempo;
   * \post cierto
   */
  void escriure_servidorOcupats(int t);

};
#endif