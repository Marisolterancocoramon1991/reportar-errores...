/*
 ============================================================================
 Name        : primer_tp_prueba_errores.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargaCostoMantenimiento.h"
#include "validacioness.h"
#include "menu.h"
#define JUGADORES 22 //aplicar la cantidad de interacciones  por jugador .
#define CIEN 100  //division para el porcentaje de jugadores por confederacion.

int main(void) {

	setbuf(stdout, NULL);

	int numeroCamiseta;
	int posicion;
	int i;
	float promedioJugadoreConfederacionAFC;
	float promedioJugadoreConfederacionCAF;
	float promedioJugadoreConfederacionCONCACAF;
	float promedioJugadoreConfederacionCONEBOL;
	float promedioJugadoreConfederacionUEFA;
	float promedioJugadoreConfederacionOFC;
	int confederacion;
	int eleccion;
	int costoDeCampania;
	int porcentajeAumento;
	int costoDeCampaniaAumento;
	int transporte;
	int hospedaje;
	int comida;
	int acomuladorestransporte = 0;
	int acomuladoreshospedaje = 0;
	int acomuladorescomida = 0;
	int arqueros = 0;
	int defensores = 0;
	int mediocampistas = 0;
	int delanteros = 0;
	int confederacionAFC = 0;
	int confederacionCAF = 0;
	int confederacionCONCACAF = 0;
	int confederacionCONMEBOL = 0;
	int confederacionUEFA = 0;
	int confederacionOFC = 0;
	int bandera = 0;
	int banderaDosInteraccionMenu = 0;
	int banderaTresInteracccionMenu = 0;

	for (i = 0; i < JUGADORES; i++) {

		do {

			transporte = 0; //inicializo estas variables aqui para cumplirr con el formato y de siempre al usuario 0.
			hospedaje = 0; // pongo al principio del bucle para que se mas facil interpretar lo que se quiere hacer con las variable.
			comida = 0;
			muestraDelMenu(transporte, hospedaje, comida, arqueros, defensores,
					mediocampistas, delanteros);

			if (banderaTresInteracccionMenu == 2
					&& banderaDosInteraccionMenu == 2) {

				get_UTN_ValidacionNumero(&eleccion,
						"\n  ingrese seccion del menu para salir 5\n",
						"¡Error!  ingrese seccion del menu valida\n", 5, 5, 15);

				banderaTresInteracccionMenu = 0;
				banderaDosInteraccionMenu = 0;
			} else {

				get_UTN_ValidacionNumero(&eleccion,
						"\n  ingrese seccion del menu\n",
						"¡Error!  ingrese seccion del menu valida\n", 1, 4, 15);
			}

			switch (eleccion) {
			case 1:

				cargarCostoMantenimiento(&transporte, &hospedaje, &comida);
				acomuladorestransporte += transporte;
				acomuladoreshospedaje += hospedaje;
				acomuladorescomida += comida;
				muestraDelMenu(acomuladorestransporte, acomuladoreshospedaje,
						acomuladorescomida, arqueros, defensores,
						mediocampistas, delanteros);

				banderaDosInteraccionMenu = 1;

				break;

			case 2:
				get_UTN_ValidacionNumero(&numeroCamiseta,
						"\ningresar número de camiseta\n",
						"ha ingresadao un caracter o un nuero fallido\n", 1, 50,
						15);
				banderaTresInteracccionMenu = 1;

				do {

					get_UTN_ValidacionNumero(&posicion,
							"\nposiciones para portero 1, defensores 2, mediocapista 3 y cuatro delanteros 4\n",
							"ha ingresadao un caracter o un numero fallido\n",
							1, 4, 15);
					switch (posicion) {
					case 1:

						if (arqueros < 2) {
							arqueros++;
							bandera = 1;
						}

						break;

					case 2:
						if (defensores < 8) {

							defensores++;
							bandera = 1;
						}

						break;
					case 3:
						if (mediocampistas < 8) {

							mediocampistas++;
							bandera = 1;
						}

						break;
					case 4:
						if (delanteros < 4) {

							delanteros++;
							bandera = 1;
						}

						break;
					case 5:
						printf(
								"\n Muchas gracias por su interaccion; usted es el jugador con el numero de camiseta %d, "
										"y es el numero %d en ingresar sus datos  \n",
								numeroCamiseta, i);

						break;

					}

				} while (bandera == 0);
				bandera = 0;

				get_UTN_ValidacionNumero(&confederacion,
						"\n  AFC en Asia 1; CAF en África 2; CONCACAF en zona del Norte 3; CONMEBOL en Sudamérica  4;\n"
								"UEFA en Europa 5; OFC en Oceanía 6;",
						" Ha ingresado un caracter o un numero fallido\n", 1, 6,
						15);
				switch (confederacion) {
				case 1:
					confederacionAFC++;

					break;

				case 2:
					confederacionCAF++;
					break;
				case 3:
					confederacionCONCACAF++;
					break;
				case 4:
					confederacionCONMEBOL++;
					break;
				case 5:
					confederacionUEFA++;
					break;
				case 6:
					confederacionOFC++;
					break;
				}

				break;

			case 3:

				if (banderaTresInteracccionMenu == 1
						&& banderaDosInteraccionMenu == 1) {

					banderaTresInteracccionMenu = 2;

					promedioJugadoreConfederacionAFC =
							(float) (CIEN / JUGADORES) * confederacionAFC;
					promedioJugadoreConfederacionCAF =
							(float) (CIEN / JUGADORES) * confederacionCAF;
					promedioJugadoreConfederacionCONCACAF = (float) (CIEN
							/ JUGADORES) * confederacionCONCACAF;
					promedioJugadoreConfederacionCONEBOL = (float) (CIEN
							/ JUGADORES) * confederacionCONMEBOL;
					promedioJugadoreConfederacionUEFA = (float) (CIEN
							/ JUGADORES) * confederacionUEFA;
					promedioJugadoreConfederacionOFC =
							(float) (CIEN / JUGADORES) * confederacionOFC;

				} else {
					get_UTN_ValidacionNumero(&eleccion,
							"\n  ¡error! Debe ingresar primero los costos y los datos del jugador\n",
							"¡Error! vuelva ha intentarlo, debe ingresar costos y dats del jugador\n",
							1, 2, 15);

				}
				break;

			case 4:
				if (banderaTresInteracccionMenu == 2
						&& banderaDosInteraccionMenu == 1) {

					banderaDosInteraccionMenu = 2;

					printf(
							"\n               Informar de todos los resultados\n");
					printf("Porcentaje  AFC %.2f\n",
							promedioJugadoreConfederacionAFC);
					printf("\nPorcentaje CAF %.2f\n",
							promedioJugadoreConfederacionCAF);
					printf("\nPorcentaje CONCACAF %.2f\n",
							promedioJugadoreConfederacionCONCACAF);
					printf("\n Porcentaje CONEBOL %.2f \n",
							promedioJugadoreConfederacionCONEBOL);
					printf("\n Porcentaje UEFA %.2f \n",
							promedioJugadoreConfederacionUEFA);
					printf("\n Porcentaje OFC %.2f\n",
							promedioJugadoreConfederacionOFC);
					printf(
							"\nValor de gasto se anuncia al finalizar la interaccion\n");

				} else {
					get_UTN_ValidacionNumero(&eleccion,
							"\n  ¡error! Debe ingresar primero los costos y los datos del jugador\n"
									"o debe realizar todos los calculos en la seccion 3 del menu",
							"¡Error! vuelva ha intentarlo, debe ingresar costos y dats del jugador\n",
							1, 3, 15);

				}

				break;

			}

		} while (eleccion != 5);

		printf(
				"\nel numero de camiseta del jugador %d, numero de ticket del jugador %d\n",
				numeroCamiseta, i);

	}

	if (confederacionUEFA > confederacionAFC
			&& confederacionUEFA > confederacionCAF
			&& confederacionUEFA > confederacionCONCACAF
			&& confederacionUEFA > confederacionCONMEBOL
			&& confederacionUEFA > confederacionOFC) {

		costoDeCampania = acomuladorestransporte + acomuladoreshospedaje
				+ acomuladorescomida;
		porcentajeAumento = costoDeCampania * 0.35;
		costoDeCampaniaAumento = costoDeCampania + porcentajeAumento;


	} else {

		costoDeCampaniaAumento = 0;
		porcentajeAumento = 0;

	}
	muestraDelMenu(acomuladorestransporte, acomuladoreshospedaje,
			acomuladorescomida, arqueros, defensores, mediocampistas,
			delanteros);
	printf("\n               Informar de todos los resultados\n");
	printf("Porcentaje  AFC %.2f\n", promedioJugadoreConfederacionAFC);
	printf("\nPorcentaje CAF %.2f\n", promedioJugadoreConfederacionCAF);
	printf("\nPorcentaje CONCACAF %.2f\n",
			promedioJugadoreConfederacionCONCACAF);
	printf("\n Porcentaje CONEBOL %.2f \n",
			promedioJugadoreConfederacionCONEBOL);
	printf("\n Porcentaje UEFA %.2f \n", promedioJugadoreConfederacionUEFA);
	printf("\n Porcentaje OFC %.2f\n", promedioJugadoreConfederacionOFC);
	printf("el costo de manimiento era %d y recibio el aumento %d"
			"su nuevo valor es %d\n", costoDeCampania, porcentajeAumento,
			costoDeCampaniaAumento);

	return EXIT_SUCCESS;
}
