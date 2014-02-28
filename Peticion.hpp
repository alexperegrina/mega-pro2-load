/** @file Peticion.hpp
    @brief Especificación de la clase Peticion
*/

#ifndef _PETICION_HPP_
#define _PETICION_HPP_

#include <list>

/** @class Peticion
    @brief Representa una Peticion. 
*/
class Peticion
{
private:
  
  /** @brief Identificador de la peticion */
  int id;
  /** @brief Tiempo inicial de la peticion */
  int t_i;
  /** @brief Tiempo final de la peticion */
  int t_f;
  /** @brief Identificador de la pelicula servida */
  int idpelicula;
  
public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una Peticion.
      \pre cierto
      \post El resultado es una Peticion sin parametros
  */  
  Peticion();
  
  /** @brief Creadora con parametros. 
      \pre id de la pelicula, tiempo inicial
      \post El resultado es una Peticion
  */  
  Peticion(int idPel,int tini);
 
  /** @brief Creadora copiadora. 

      Permite declarar una Peliculla nueva como copia de otra ya existente.
      \pre cierto
      \post El resultado es una Peticion igual que p
  */  
  Peticion(const Peticion& p);

   //Destructora
  /** @brief Destructora. */
  ~Peticion();

  //Modificadoras
    
  /** @brief Modifica el tiempo final de la Peticion
      \pre peticion inicializada
      \post  cierto
  */
  void setTf(int t);
  
  /** @brief Modifica el id de la Peticion
      \pre peticion inicializada
      \post  cierto
  */  
  void setId(int i);
   
  /** @brief Consulta del ID de la peticion
      \pre cierto
      \post ID de la peticion
  */
  int getId() const;
  
  /** @brief Consulta el tiempo de inicio de la peticion
      \pre cierto
      \post tiempo de inicio de la peticion
  */
  int getT_i() const;
  
  /** @brief Consulta el tiempo final de la peticion
      \pre cierto
      \post tiempo de final de la peticion
  */
  int getT_f() const;
  
  /** @brief Consulta el ID de la  pelicula de la peticion
      \pre cierto
      \post ID de la pelicula de la peticion
  */
  int getIdPelicula() const;
 
};
#endif
