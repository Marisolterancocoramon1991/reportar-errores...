/*
 * validaciones.h
 *
 *  Created on: 20 oct 2022
 *      Author: kervi
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int get_UTN_ValidacionNumero(int *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones);
int recogerNumero(int *resultado);

int esNumero(char *valorReemplazoResultado);


#endif /* VALIDACIONES_H_ */
