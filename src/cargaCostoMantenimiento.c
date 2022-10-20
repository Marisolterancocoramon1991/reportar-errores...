/*
 * cargaCostoMantenimiento.c
 *
 *  Created on: 19 oct 2022
 *      Author: kervi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacioness.h"

int cargarCostoMantenimiento(int *transporte, int *hospedaje, int *comida) {

	int eleccion;
	int bandera = 1;
	int retorno = 0;
	*transporte = 0;
	*hospedaje = 0;
	*comida = 0;

	while (*transporte == 0 || *hospedaje == 0 || *comida == 0) {

		retorno = 1;

		if (bandera == 1) {

			get_UTN_ValidacionNumero(&eleccion,
					"\n Elegir que elementos cargar  transporte 1, hospedaje 2 comida 3 \n",
					"\n ¡Error! Elegir que elementos cargar  transporte 1, hospedaje 2 comida 3 \n\n",
					1, 3, 15);

			bandera = 0;
		}
		switch (eleccion) {
		case 1:

			if (*transporte == 0) {

				if (*hospedaje == 0 && *comida == 0) {

					get_UTN_ValidacionNumero(&*transporte,
							"\nMonto a gastar en transporte\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  hospedaje 2 comida 3 \n",
							"\n ¡Error! elegir elemento de carga hospedaje 2 comida 3 \n ",
							2, 3, 15);

				} else if (*hospedaje == 0 && *comida > 1) {

					get_UTN_ValidacionNumero(&*transporte,
							"\nMonto a gastar en transporte\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  hospedaje 2 \n",
							"\n ¡Error! elegir elemento de carga hospedaje 2 \n ",
							2, 2, 15);

				} else if (*hospedaje > 1 && *comida == 0) {
					get_UTN_ValidacionNumero(&*transporte,
							"\nMonto a gastar en transporte\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  comida 3 \n",
							"\n ¡Error! elegir elemento de carga comida 3 \n ",
							3, 3, 15);

				} else {
					get_UTN_ValidacionNumero(&*transporte,
							"\nMonto a gastar en transporte\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);
				}

			}
			break;

		case 2:
			if (*hospedaje == 0) {
				if (*transporte == 0 && *comida == 0) {

					get_UTN_ValidacionNumero(&*hospedaje,
							"\nMonto a gastar en hosedaje\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

					do {
						get_UTN_ValidacionNumero(&eleccion,
								"\n Elegir que elementos cargar transporte 1 y commida 3 \n",
								"\n ¡Error! elegir elemento de transporte 1 y commida 3 \n ",
								1, 3, 15);
					} while (eleccion == 2);

				} else if (*transporte == 0 && *comida > 1) {
					get_UTN_ValidacionNumero(&*hospedaje,
							"\nMonto a gastar en hosedaje\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  transorte 1 \n",
							"\n ¡Error! elegir elemento de carga transprte 1  \n ",
							1, 1, 15);

				} else if (*transporte > 1 && *comida == 0) {

					get_UTN_ValidacionNumero(&*hospedaje,
							"\nMonto a gastar en hosedaje\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);
					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  comida 3 \n",
							"\n ¡Error! elegir elemento de carga comida 3 \n ",
							3, 3, 15);

				} else {
					get_UTN_ValidacionNumero(&*hospedaje,
							"\nMonto a gastar en hosedaje\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

				}

			}

			break;

		case 3:
			if (*comida == 0) {
				if (*transporte == 0 && *hospedaje == 0) {

					get_UTN_ValidacionNumero(&*comida,
							"\nMonto a gastar en comida\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);

					do {
						get_UTN_ValidacionNumero(&eleccion,
								"\n Elegir que elementos cargar  transporte 1 y hospedaje 2 \n",
								"\n ¡Error! elegir elemento de carga  transporte 1 y hospedaje 2  \n ",
								1, 3, 15);

					} while (eleccion == 3);

				} else if (*transporte > 1 && *hospedaje == 0) {
					get_UTN_ValidacionNumero(&*comida,
							"\nMonto a gastar en comida\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);
					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  hospedaje 2 \n",
							"\n ¡Error! elegir elemento de carga hospedaje 2  \n ",
							2, 2, 15);

				} else if (*transporte == 0 && *hospedaje > 1) {
					get_UTN_ValidacionNumero(&*comida,
							"\nMonto a gastar en comida\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);
					get_UTN_ValidacionNumero(&eleccion,
							"\n Elegir que elementos cargar  hospedaje 1 \n",
							"\n ¡Error! elegir elemento de carga hospedaje 1  \n ",
							1, 1, 15);

				} else {
					get_UTN_ValidacionNumero(&*comida,
							"\nMonto a gastar en comida\n",
							"\n ¡Error! el gasto no fue ingresado correctamente",
							1, 10000, 15);
				}
			}

			break;

		}

	}

	return retorno;
}


