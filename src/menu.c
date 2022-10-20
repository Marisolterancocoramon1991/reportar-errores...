/*
 * menu.c
 *
 *  Created on: 19 oct 2022
 *      Author: kervi
 */


#include <stdio.h>
#include <stdlib.h>
void muestraDelMenu(int acomuladorestransporte, int acomuladoreshospedaje,
		int acomuladorescomida, int arqueros, int defensores,
		int mediocampistas, int delanteros) {

	printf("             Menu principal\n\n\n");
	printf("* Costo de transporte -> $ %d\n"
			"* Costo de hospedaje -> $ %d\n"
			"* Costo de comida -> $ %d\n", acomuladorestransporte,
			acomuladoreshospedaje, acomuladorescomida);

	printf("\n2) Carga del jugador\n");
	printf("* Arqueros -> %d\n"
			"* Defensores -> -> %d\n"
			"* Mediocampistas -> %d\n"
			"* Delanteros -> %d\n", arqueros, defensores, mediocampistas,
			delanteros);

	printf("3) realizar todos los calculos\n");
	printf("4) informar todos los resultados \n");
	printf("5) salir \n");
}
