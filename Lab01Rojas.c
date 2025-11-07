/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Danna Gabriela Rojas Bernal              *
* Fecha: 6 noviembre de 2025                        *
* Docente: J. Corredor
* Materia: Sistemas Operativos                             *
* Tema :Introducción a OpenMP
*Descripcion: Uso de la directiva y funcion 
               para hacer uso de OpenMP              *
***************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]){
	int maxCores= omp_get_max_threads();
printf("Número maximo de Cored del SO: %d \n", maxCores);

//región paralela OMP

#pragma omp parallel
{
	printf("Hilo ID en Región paralela: %d \n", omp_get_thread_num());
}
return 0;
}


