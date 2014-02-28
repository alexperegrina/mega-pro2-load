/** @file Cjt_pelicula.hpp
    @brief Especificación de la clase Cjt_pelicula
*/

#ifndef _CJTPELICULA_HPP_
#define _CJTPELICULA_HPP_
#include "utils.PRO2"
#include <vector>
#include "Pelicula.hpp"

/** @class Cjt_pelicula
    @brief Representa un conjunto de Pelicula. 
*/
class Cjt_pelicula
{
private:
  /** @brief Vector que contiene las peliculas. */
  vector<Pelicula> vecpel;
  
public:
  //Constructoras

  /** @brief Creadora por defecto. 
      Se ejecuta automáticamente al declarar un Cjt_peliculas.
      \pre cierto
      \post El resultado es un Cjt_peliculas vacio
  */  
  Cjt_pelicula();

   //Destructora
  /** @brief Destructora. */
  ~Cjt_pelicula();

  //Modificadoras
  
  /** @brief Lee las peliculas
      \pre cierto
      \post cierto
  */
  void leer_peliculas();

  /* Consultoras */
   
  /** @brief Consulta de la pelicula segun del ID
      \pre 1 <= id <= tamaño Cjt_peliculas
      \post Pelicula
  */
  Pelicula getPeliculaId(int &id);
  
  /** @brief Consulta el mida del Cjt_peliculas
      \pre cierto
      \post mida del Cjt_peliculas
  */
  int mida();
 
  /** @brief Escribe la lista de peliculas
      \pre cierto
      \post cierto
  */
  void escribir_peliculas();
};
#endif

