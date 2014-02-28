/** @file Cjt_peticion.hpp
    @brief Especificación de la clase Cjt_peticion
*/

#ifndef _CJTPETICION_HPP_
#define _CJTPETICION_HPP_

#include "Peticion.hpp"
#include "utils.PRO2"
#include <queue>
#include <vector>
#include <list>


/** @class Cjt_peticion
    @brief Representa un conjunto de Peticion. 
*/
class Cjt_peticion
{
private:
  
  /** @brief Variable para tener el autoincremento del id de la peticion. */
  int cont; 
  
  /** @brief Lista que contiene todas las peticiones acceptadas. */
  list<Peticion> listpet;
  
  /** @brief Metodo para insertar un elemento en la lista ordenado ascendente por tiempo final
   * \pre lista inicialicada, id del servidor
   * \post cierto
   */
  void pushList(Peticion p);
  
public:
  
  //Constructores
  
  /** @brief Creadora por defecto. 
      Se ejecuta automáticamente al declarar un cjt_peticiones.
      \pre cierto
      \post El resultado es una Peticion sin parametros
  */  
  Cjt_peticion();

  //Destructora
  /** @brief Destructora. */
  ~Cjt_peticion();
   
  //Modificadores
  
  /** @brief Añadir una peticion al conjunto 
      \pre cierto
      \post cierto
  */
  void anadir_peticion(Peticion p);
  
  /** @brief Autoincremento del id de la peticon (id unico) 
      \pre peticion inicializada
      \post cierto
  */
  void incrementId(Peticion &p);
  
  /** @brief Consulta de el numero de peticiones del conjunto 
      \pre cierto
      \post numero de peticiones
  */ 
  int mida() const;
  
  /** @brief Escrive las peticiones sin finalizar en un cierto tiempo
   * es la opcion 2 del menu
   * \pre variable de tiempo
   * \post cierto
   */
  void peticion_sinFinalizar(int t);
  
  /** @brief Escritura de la pelicula mas solicitada entre los dos tiempos
   * \pre t1 <= t2 , n = Cjt_peliculas.mida()
   * \post cierto
   */  
  void pelicula_solicitada(int t1, int t2, int n);
  	
};
#endif