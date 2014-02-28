/** @file Servidor.hpp
    @brief Especificación de la clase Servidor
*/

#ifndef _SERVIDOR_HPP_
#define _SERVIDOR_HPP_
#include "utils.PRO2"
#include <vector>

/** @class Servidor
    @brief Representa un Servidor. 
*/
class Servidor
{
private:
  
  /** @brief Identificador del servidor */
  int id;
  /** @brief Ancho de banda del servidor en mb */
  int ancho;
  /** @brief tiempo en el que el servidor finaliza de servir una peticion */
  int tiempo;
  /** @brief Identificador de la peticion serviendo en el servidor*/
  int idpet;
  /** @brief Vector de peliculas que contiene el servidor */
  vector<bool> lpel;
  
public:
  
  //Constructoras

  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un servidor
      \pre cierto
      \post El resultado es un servidor sin valor
  */  
  Servidor();
 
  /** @brief Creadora copiadora. 
      \pre cierto
      \post El resultado es una cubeta igual que c
  */  
  Servidor(const Servidor& s);

   //Destructora
    /** @brief Destructora. */
  ~Servidor();
  
  //Modificadoras

  /** @brief Lee los parametros del servidor
      \pre id del servidor, n = mida del Cjt de peliculas
      \post  
  */
  void leer_servidor(int i, int n);
  
  /** @brief Actualiza el servidor
   * \pre tiempo a comparar
   * \post cierto 
   */
  void actualizar(int t);
  
  /** @brief Actualiza el Pelicules de servidor
   * \pre cierto
   * \post cierto 
   */
  void actualizar_pelicula();
  
  /** @brief Modifica el tiempo del servidor
   * \pre tiempo del servidor
   * \post cierto
   */
  void setTiempo(int tf);
  
  /** @brief Modifica el id de la peticion que esta sirviendo
   * \pre id de la peticion, -1 si no esta sirviendo ninguna
   * \post cierto 
   */
  void setIdpet(int idp);
  
  /* lista peliculas */
  /** @brief Añadir peliculas al servidor
      \pre n es el numero de pelicules a añadir
      \post cierto
  */
  void addPeliculas(int n);
  
  /** @brief Eliminar una pelicula del servidor
      \pre n es el numero de pelicules a eliminar
      \post cierto
  */
  void deletePeliculas(int n);
  
  /* Consultoras */
  
  /** @brief Consulta del ID del servidor
      \pre cierto
      \post Id del servidor
  */
  int getId() const;
  
  /** @brief Consulta el tiempo del servidor
      \pre cierto
      \post tiempo del servidor
  */
  int getTiempo() const;
  
  /** @brief Consulta el ancho de banda del servidor
      \pre cierto
      \post ancho de banda del servidor
  */
  int getAncho() const;
  
  /** @brief Consulta el id de la peticion del servidor, si esta sirviendo una
   * si no esta sirviendo una peticion Idpet = -1
      \pre cierto
      \post id de la peticion
  */
  int getIdpet() const;
  
  /** @brief Consulta las peliculas del servidor(para hacer la copia del servidor)
      \pre cierto
      \post ancho de banda del servidor
  */
  vector<bool> getPeliculas() const;
  
  /** @brief Consulta la pelicula con el id = id 
      \pre  1 < id <= lpel.size()
      \post true si contiene la pelicula, false si no la contiene
  */
  bool contPelicula(int& id) const;
  
};
#endif
