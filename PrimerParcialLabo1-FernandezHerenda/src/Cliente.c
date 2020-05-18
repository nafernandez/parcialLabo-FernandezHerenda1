/*
 * Cliente.c
 *
 *  Created on: 14 may. 2020
 *      Author: natalia
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Cliente.h"
#include "utn.h"

int inicializarCliente(Cliente* aCliente, int len)
{
	int respuesta=-1;
	int i;

	if(aCliente!=NULL && len > 0)
	{
		respuesta=0;
	}
	for (i=0; i<len; i++)
	{
		aCliente[i].isEmpty= 1;
	}
	return respuesta;
}

int buscarPrimerPosicionVacia(Cliente* aCliente, int len)
{
	int respuesta= -1;
	int i;
	if(aCliente!=NULL && len > 0)
		{
			respuesta=0;
		}
		for (i=0; i<len; i++)
		{
			if(aCliente[i].isEmpty== 1)
			{
				respuesta=i;
				break;
			}
		}
	return respuesta;
}

int imprimirCliente(Cliente* aCliente)
{
	int retorno=-1;

		if(aCliente != NULL && aCliente->isEmpty == 0)
		{
			retorno=0;
			printf("\nID: %d\nNombre: %s\nApellido: %s\nCuil: %s",aCliente->ID,aCliente->nombre,aCliente->apellido,aCliente->cuil);
		}
		return retorno;

}

int imprimirArrayClientes(Cliente* aCliente,int len)
{
	int respuesta = -1;
	int i;
	if(aCliente != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aCliente[i].isEmpty==0)
			{
				imprimirCliente(&aCliente[i]);
			}
		}
	}
	return respuesta;
}

int altaDeCLiente(Cliente* aCliente, int len, int indice, int* id)
{
	int respuesta=-1;
	Cliente bufferCliente;

	///if(aCliente != NULL && indice>=0)
	if(aCliente != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(utn_getNombre(bufferCliente.nombre,len,"Ingrese el nombre: \n", "ERROR, reingrese", 2)==0 && utn_getNombre(bufferCliente.apellido,len,"Ingrese el apellido: \n", "ERROR, reingrese", 2)==0 && utn_getCuil(bufferCliente.cuil, 20,"Ingrese el CUIL: \n", "Error, reingrese", 2)==0)
		{
				respuesta = 0;
				bufferCliente.ID= (*id)+1;
				bufferCliente.isEmpty = 0;
				aCliente[indice] = bufferCliente;
				(*id)++;
		}

	}

	return respuesta;

}

int modificarCliente(Cliente* aCliente, int len, int indice)
{
	int respuesta = -1;
		Cliente bufferCliente;

		if(aCliente != NULL && len > 0 && indice < len && indice >= 0 && aCliente[indice].isEmpty == 0)
		{
			if(	utn_getNombre(bufferCliente.nombre,50,"\nNombre?\n","\nERROR\n",2) == 0 &&
				utn_getNombre(bufferCliente.nombre,50,"\Apellido?\n","\nERROR\n",2) == 0 &&
				utn_getCuil(bufferCliente.cuil,20,"\nDNI?\n","\nERROR\n",2) == 0
				)
			{
				respuesta = 0;
				bufferCliente.ID = aCliente[indice].ID;
				bufferCliente.isEmpty = 0;
				aCliente[indice] = bufferCliente;
			}
		}
		return respuesta;
}

int buscarClientePorId(Cliente* aCliente, int len, int id)
{
	int respuesta = -1;
	int i;
	if(aCliente != NULL && len >= 0 && id >= 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aCliente[i].ID == id)
			{
				respuesta = i+1;
				break;
			}
		}
	}
	return respuesta;
}

int darDeBajaCliente(Cliente* aCliente, int len, int indice)
{
	int respuesta=-1;
	if(aCliente != NULL && len > 0 && indice < len && indice >= 0 && aCliente[indice].isEmpty == 0)
	{
		aCliente[indice].isEmpty=1;
		respuesta=0;
	}
	return respuesta;
}







