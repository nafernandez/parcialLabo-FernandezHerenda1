/*
 * informe.c
 *
 *  Created on: 17 may. 2020
 *      Author: natalia
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "Prestamo.h"
#include "Cliente.h"

int mostrarClienteConMasPrestamos(Cliente* aCliente, int lenClientes, Prestamo* aPrestamo, int lenPrestamos, int saldados)
{
	int respuesta=-1;
	int cantidadMaximaDePrestamos=-1;
	Cliente clienteConMasPrestamos;
	int i;


	if(aCliente!= NULL && aPrestamo!=NULL)
	{
		respuesta=0;
		for(i=0; i<lenClientes; i++)
		{
			int cantidadPrestamoCliente= cantidadDePrestamosParaCliente(aPrestamo, lenPrestamos, aCliente[i].ID, saldados);

			if (cantidadMaximaDePrestamos<cantidadPrestamoCliente)
			{
				cantidadMaximaDePrestamos=cantidadPrestamoCliente;
				clienteConMasPrestamos= aCliente[i];
			}
		}
		imprimirCliente(&clienteConMasPrestamos);
		if(saldados==1)
		{
			printf("La cantidad de prestamos activos son: %d \n", cantidadMaximaDePrestamos);
		}else
		{
			printf("La cantidad de prestamos saldados son: %d \n", cantidadMaximaDePrestamos);
		}

	}
	return respuesta;
}

int cantidadDePrestamosParaCliente(Prestamo* aPrestamo, int lenPrestamos, int idCliente,int saldados)
{
	int i;
	int contadorDePrestamos=0;

	for(i=0; i< lenPrestamos; i++)
	{
		if(aPrestamo[i].idCliente == idCliente && aPrestamo[i].saldado==saldados && aPrestamo[i].isEmpty==0)
		{
			contadorDePrestamos++;
		}
	}
	return contadorDePrestamos;
}

int mostrarCantidadPrestamosMayoresAImporteSeleccionado(Prestamo* aPrestamo, int len, int importe)
{
	int respuesta=-1;
	int i;
	int cantidadDePrestamosMayoresAMilPesos=0;

	for(i=0; i< len; i++)
	{
		respuesta=0;
		if(aPrestamo[i].importe>1000 && aPrestamo[i].importe==importe && aPrestamo[i].isEmpty== 0)
		{
			cantidadDePrestamosMayoresAMilPesos++;
		}

	}
	printf("La cantidad de prestamos mayores a $1000 de importe $%d son: %d\n", importe, cantidadDePrestamosMayoresAMilPesos);
	return respuesta;
}


