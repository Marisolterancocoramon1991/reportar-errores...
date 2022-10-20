/*
 * validaciones.c
 *
 *  Created on: 19 oct 2022
 *      Author: kervi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * el arrays de caracteres valorReemplazoResultado se verfica que venga distinto de NULO. Ademas, se compara si lo ingresado es del 0 al 9
 * retorna 1 en caso de exito y 0 en caso de falllar,
 */

int esNumero(char *valorReemplazoResultado) {
	int i = 0;
	int retorno = 0;
	if (valorReemplazoResultado != NULL) {
		while (valorReemplazoResultado[i] != '\0') {
			if (valorReemplazoResultado[i] > '0'
					|| valorReemplazoResultado[i] < '9') {

				retorno = 1;

			}
			i++;
		}

	}

	return retorno;
}

/*
 *\ aqui se ingresa el valor ingresado por el usuario se invoca a la funcion esNumero() y despues se le entrega el valor convertdo a entero
 *\ al puneto enter *resultado.
 *\ retorna i si tuvo exito de lo contrario 0.
 */

int recogerNumero(int *resultado) {
	int retorno = 0;
	char valorReemplazo[500];

	fgets(valorReemplazo, sizeof(valorReemplazo), stdin);
	valorReemplazo[strlen(valorReemplazo) - 1] = '\0';

	if (esNumero(valorReemplazo) == 1) {
		*resultado = atoi(valorReemplazo);
		retorno = 1;
	}
	return retorno;
}

/*
 *la funcion carga los elementos *resultado como punter a entero, mensaje[] como arrays de caracteres.
 *mensajeFalla[] este es otro array de caracteres y su funcion es avisar al usuario que el nuer ingresado no pertenece a los numeros
 *minimo y maximo. Ademas, busca que ningun elementoo haya llegado nulo.
 *por otra parte llama a la funcion recogerNumero()
 */
int get_UTN_ValidacionNumero(int *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones) {
	int valorReemplazo;
	int retorno = 0;

	if (resultado != NULL && mensaje != NULL && mensajeFalla != NULL
			&& numeroMinimo <= numeroMaximo && repeticiones >= 0) {

		while (repeticiones > 0) {
			printf("%s", mensaje);
			if (recogerNumero(&valorReemplazo) == 1) {

				if (valorReemplazo >= numeroMinimo
						&& valorReemplazo <= numeroMaximo) {

					repeticiones = -1;
					retorno = 1;
				} else {
					printf("%s. numero de intentos %d", mensajeFalla,
							repeticiones);
					repeticiones--;
				}

			}

		}
		if (repeticiones == 0) {
			retorno = -1;
		} else {
			retorno = 1;
			*resultado = valorReemplazo;
		}
	}

	return retorno;
}

