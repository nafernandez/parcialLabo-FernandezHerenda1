/*
 * Prestamo.c
 *
 *  Created on: 14 may. 2020
 *      Author: natalia
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Prestamo.h"
#include "utn.h"
#include "Cliente.h"

int imprimirPrestamo(Prestamo* aPrestamo)
{
	int retorno=-1;

		if(aPrestamo != NULL && aPrestamo->isEmpty == 0)
		{
			retorno=0;
			printf("\nEl prestamo es:\n  ID:%d\nImporte: %.2f\nCuotas: %d\nSaldado(1 es si, 0 es no): %d\n",aPrestamo->idPrestamo,aPrestamo->importe,aPrestamo->cuotas, aPrestamo->saldado);
		}
		return retorno;


}
int imprimirArrayPrestamo(Prestamo* aPrestamo,int len)
{
	int respuesta = -1;
	int i;
	if(aPrestamo != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			imprimirPrestamo(&aPrestamo[i]);
		}
	}
	return respuesta;
}

int imprimirArrayPrestamoFiltradoPorSaldado(Prestamo* aPrestamo, int len, int saldado, int idCliente)
{
	int respuesta = -1;
	int i;
	if(aPrestamo != NULL && len > 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aPrestamo[i].saldado==saldado && (aPrestamo[i].idCliente==idCliente || idCliente==-1))
			{
				imprimirPrestamo(&aPrestamo[i]);
			}
		}
	}
	return respuesta;
}
int inicializarPrestamo(Prestamo* aPrestamo, int len)
{
	int respuesta=-1;
	int i;

	if(aPrestamo!=NULL && len > 0)
	{
		respuesta=0;
	}
	for (i=0; i<len; i++)
	{
		aPrestamo[i].isEmpty= 1;
		aPrestamo[i].saldado=0;
	}
	return respuesta;
}
int buscarPrimerPosicionVaciaPrestamo(Prestamo* aPrestamo, int len)
{
	int respuesta= -1;
	int i;
	if(aPrestamo!=NULL && len > 0)
		{
			respuesta=0;
		}
		for (i=0; i<len; i++)
		{
			if(aPrestamo[i].isEmpty== 1)
			{
				respuesta=i;
				break;
			}
		}
	return respuesta;
}
int altaDePrestamo(Prestamo* aPrestamo, int len, int indicePrestamoVacio, int* idPrestamo, int idCliente)
{
	int respuesta=-1;
	Prestamo bufferPrestamo;

	if(aPrestamo != NULL && len > 0 && indicePrestamoVacio < len && indicePrestamoVacio >= 0 && idPrestamo != NULL)
	{
		if(utn_getNumeroFlotante(&bufferPrestamo.importe, "\nIngrese el importe a solicitar\n", "\nError, no se puede solicitar ese importe\n", 1000, 100000, 1)==0 && utn_getNumero(&bufferPrestamo.cuotas, "Ingrese el numero de cuotas", "Error, reingrese el numero de cuotas", 1, 48, 1)==0)
		{
			bufferPrestamo.idCliente=idCliente;
			bufferPrestamo.idPrestamo= *idPrestamo+1;
			bufferPrestamo.isEmpty=0;
			respuesta=0;
			aPrestamo[indicePrestamoVacio]=bufferPrestamo;
			(*idPrestamo)++;
			 imprimirPrestamo(&aPrestamo);
		}
	}

	return respuesta;

}

int saldarPrestamo(Prestamo* aPrestamo, int len, int indice)
{
	int respuesta=-1;
	if(aPrestamo != NULL && len > 0 && indice < len && indice >= 0 && aPrestamo[indice].isEmpty == 0)
	{
		aPrestamo[indice].saldado=1;
		respuesta=0;
	}
	return respuesta;
}

int reanudarPrestamo(Prestamo* aPrestamo, int len, int idPrestamo)
{
	int respuesta=-1;
	int indice = idPrestamo - 1;
	if (aPrestamo != NULL && len > 0 && indice < len && indice >= 0
			&& aPrestamo[indice].isEmpty == 0
			&& aPrestamo[indice].saldado == 1)
	{
		respuesta=0;
		aPrestamo[indice].saldado=0;

	}
	return respuesta;
}


int buscarPrestamoPorIdDeCliente(Prestamo* aPrestamo, int len, int id)
{
	int respuesta = -1;
	int i;
	if(aPrestamo != NULL && len >= 0 && id >= 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aPrestamo[i].idCliente == id)
			{
				respuesta = i+1;
				break;
			}
		}
	}
	return respuesta;
}

int buscarPrestamoPorIdDePrestamo(Prestamo* aPrestamo, int len, int id)
{
	int respuesta = -1;
	int i;
	if(aPrestamo != NULL && len >= 0 && id >= 0)
	{
		respuesta = 0;
		for(i=0;i<len;i++)
		{
			if(aPrestamo[i].idPrestamo == id)
			{
				respuesta = i+1;
				break;
			}
		}
	}
	return respuesta;
}

