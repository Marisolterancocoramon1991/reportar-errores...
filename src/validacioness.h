/*
 * validacioness.h
 *
 *  Created on: 19 oct 2022
 *      Author: kervi
 */

#ifndef VALIDACIONESS_H_
#define VALIDACIONESS_H_

int get_UTN_ValidacionNumero(int *resultado, char mensaje[],
		char mensajeFalla[], int numeroMinimo, int numeroMaximo,
		int repeticiones);
int recogerNumero(int *resultado);

int esNumero(char *valorReemplazoResultado);


#endif /* VALIDACIONESS_H_ */
