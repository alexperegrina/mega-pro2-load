/** @file Pelicula.hpp
    @brief Especificación de la clase Pelicula
*/

#ifndef _PELICULA_HPP_
#define _PELICULA_HPP_
#include "utils.PRO2"


/** @class Pelicula
    @brief Representa una Pelicula. 
*/
class Pelicula
{
private:
  
  /** @brief Identificador de la pelicula */
  int id;
  /** @brief Tamaño de la pelicula en mb. */
  int tam;
  
public:
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar una Pelicula.
      \pre cierto
      \post El resultado es una Pelicula sin parametros
  */  
  Pelicula();
 
  /** @brief Creadora copiadora. 

      Permite declarar una Pelicula nueva como copia de otra ya existente.
      \pre cierto
      \post El resultado es una peliucla igual que p
  */  
  Pelicula(const Pelicula& p);

   //Destructora
  /** @brief Destructora. */
  ~Pelicula();

  //Modificadoras
    
  /** @brief Lee los parametros de la pelicula
      \pre identificador assignado por el conjunto
      \post  cierto
  */
  void leer_pelicula(int &i);

  /* Consultoras */
   
  /** @brief Consulta del ID de la pelicula
      \pre cierto
      \post ID de la pelicular
  */
  int getId() const;
  
  /** @brief Consulta el tamaño de la pelicula
      \pre cierto
      \post tamaño de la pelicula
  */
  int getTamano() const;

};
#endif

