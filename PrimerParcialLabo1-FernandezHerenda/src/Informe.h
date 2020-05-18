/*
 * Informe.h
 *
 *  Created on: 14 may. 2020
 *      Author: natalia
 */

#ifndef INFORME_H_
#define INFORME_H_

/**
* \brief Muestra el cliente con mas prestamos
 * \param aCliente para usar el array entero
 * \param  Limite del array de clientes
 *\param aPrestamo para usar el array entero
 *\param lenPrestamos para limite de prestamos
 *\param saldados para pedirle al usuario si quiere ver los saldados o los no saldados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int mostrarClienteConMasPrestamos(Cliente* aCliente, int lenClientes, Prestamo* aPrestamo, int lenPrestamos, int saldados);
/**
* \brief DMuestra la cantidad de prestamos que tiene un cliente
 * \param aPrestamo para usar el array entero
 * \param  Limite del array de prestamos
 *\param ID del cliente para asignarlo al prestamo
 *\param saldados para pedirle al usuario si quiere ver los saldados o los no saldados
 * \return Retorna el contador de prestamos
 *
 */
int cantidadDePrestamosParaCliente(Prestamo* aPrestamo, int lenPrestamos, int idCliente,int saldados);

/**
* \brief DMuestra la cantidad de prestamos mayores a $1000
 * \param aPrestamo para usar el array entero
 * \param  Limite del array de prestamos
 *\param importe ingresado por el usuario
 * \return Retorna el contador de prestamos
 *
 */
int mostrarCantidadPrestamosMayoresAImporteSeleccionado(Prestamo* aPrestamo, int len, int importe);
#endif /* INFORME_H_ */
