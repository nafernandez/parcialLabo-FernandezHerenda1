/*
 * Cliente.h
 *
 *  Created on: 14 may. 2020
 *      Author: natalia
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define ESPACIO_CUIL 20

typedef struct{
	char nombre[51];
	char apellido[51];
	char cuil[ESPACIO_CUIL];
	int isEmpty;
	int ID;
}Cliente;

/**
 * \brief Inicializa el array de cliente
 * \param aCliente para ser actualizado si es vacio
 * \param  Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int inicializarCliente(Cliente* aCliente, int len);

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 */
int buscarPrimerPosicionVacia(Cliente* aCliente, int len);

/**
 * \brief imprime un cliente del array de clientes
 * \param aCliente para usar el array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirCliente(Cliente* aCliente);
/**
 * \brief Imprime el array de todos los clientes
 * \param aCliente para usar el array entero
 * \param  Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirArrayClientes(Cliente* aCliente,int len);
/**
 * \brief Da de alta a un cliente
 * \param aCliente para usar el array entero
 * \param  Limite del array de clientes
 *\ param indice para asignarle la posicion en el array
 *\ id del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaDeCLiente(Cliente* aCliente, int len, int indice, int* id);
/**
* \brief Da de alta a un cliente
 * \param aCliente para usar el array entero
 * \param  Limite del array de clientes
 *\param indice para asignarle la posicion en el array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modificarCliente(Cliente* aCliente, int len, int indice);
/**
 * \brief busca un cliente por ID
 * \param aCliente para usar el array entero
 * \param  Limite del array de clientes
 * \ valor buscado ingresado por usuario
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int buscarClientePorId(Cliente* aCliente, int len, int valorBuscado);
/**
 * \brief Da de baja a un cliente
 * \param aCliente para usar el array entero
 * \param  Limite del array de clientes
 * \ pide el indice del cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int darDeBajaCliente(Cliente* aCliente, int len, int indice);
#endif /* CLIENTE_H_ */
