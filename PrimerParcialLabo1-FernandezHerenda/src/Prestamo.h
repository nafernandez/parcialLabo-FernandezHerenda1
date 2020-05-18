/*
 * Prestamo.h
 *
 *  Created on: 14 may. 2020
 *      Author: natalia
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_

typedef struct{
	int idCliente;
	int idPrestamo;
	float importe;
	int cuotas;
	int isEmpty;
	int saldado;

}Prestamo;

/**
 * \brief Da de alta un prestamo
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaDePrestamo(Prestamo* aPrestamo, int len, int indicePrestamoVacio, int* idPrestamo, int idCliente);
/**
 * \brief Busca la primer posicion vacia en el prestamo
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int buscarPrimerPosicionVaciaPrestamo(Prestamo* aPrestamo, int len);
/**
 * \brief Inicializa el prestamo poniendo isEmpty en 0
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarPrestamo(Prestamo* aPrestamo, int len);
/**
 * \brief Imprime un prestamo
 * \param aPrestamo para usar el array completo
 * return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirPrestamo(Prestamo* aPrestamo);
/**
 * \brief Imprime el arrray de prestamo
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 *return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirArrayPrestamo(Prestamo* aPrestamo,int len);
/**
 * \brief Salda el prestamo
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \param pide al usuario el indice del prestamo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int saldarPrestamo(Prestamo* aPrestamo, int len, int indice);
/**
 * \brief Da la opcion de reanudar un prestamo luego de ser saldado.
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \param pide al usuario el indice de prestamo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int reanudarPrestamo(Prestamo* aPrestamo, int len, int indice);
/**
 * \brief Imprime el array del prestamo que antes es filtrado por si es saldado o no.
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \param Pide al usuario si busca el saldado o no
 * \param pide el ID del cliente
 * return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirArrayPrestamoFiltradoPorSaldado(Prestamo* aPrestamo, int len, int saldado, int idCliente);
/**
 * \brief Busca el prestamo por el ID de prestamo
 * \param aPrestamo para usar el array completo
 * \param longitud Es la longitud del array resultado
 * \param ID del prestamo
 * return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int buscarPrestamoPorIdDePrestamo(Prestamo* aPrestamo, int len, int id);
#endif /* PRESTAMO_H_ */
