/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Danna Gabriela Rojas Bernal              *
* Fecha: 6 noviembre de 2025                      *
* Docente: J. Corredor							  *
* Materia: Sistemas Operativos                    *
* Tema :Introducción a OpenMP					  *
* Descripcion: Uso de la directiva y funcion 	  *
* para hacer uso de OpenMP                        *
***************************************************/

//Libreria 
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

//programa principal 
int main(int argc, char *argv[]){
if (argc!=2){//verificacion que lleguen los argumentos 
	printf("Error: \n\t$. /ejecutable numHilos\n");
	exit(0);
}
	int numHilos= (int) atoi(argv[1]);

	// Se obtiene el número máximo de hilos (threads) que el sistema tiene disponibles por defecto
	int maxCores= omp_get_max_threads();
	printf("Número maximo de Cored del SO: %d \n", maxCores);
	// Se fijan el número de hilos deseado
	omp_set_num_threads(numHilos);//
	printf("Número de hilos fijados: %d \n", numHilos);

//región paralela OMP
#pragma omp parallel
{
	printf("Hilo ID en Región paralela: %d \n", omp_get_thread_num());
}
return 0;
}
//Analisis: puede colocar más hilos de los que tiene el procesor ya que el OpenMP crea hilos logicos
// por lo que el SO que varios hilos compartan los mismos núcleos

