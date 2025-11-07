/****************************************************
*       Pontificia Universidad Javeriana            *
*               ----------=----------               *
*                                                   *
* Autor: Danna Gabriela Rojas Bernal                *
* Fecha: 6 noviembre de 2025                        *
* Docente: J. Corredor								*
* Materia: Sistemas Operativos                      *
* Tema :Introducción a OpenMP						*
* Descripcion: Uso de la directiva y funcion 		*
* para hacer uso de OpenMP 							*
*    -Paralelismo para el calculo de la funcion seno*              
*****************************************************/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
//define funcion para obtener el minimo 
#define MIN(x,y) (((x) < (y)) ? (x):(y))

//se implementa la funcion sumatoria
double fsum(int i){
	int inicio=i *(i+1)/2;
	int fin= inicio + i ;  
	double valorSum=0;
	for (int j=inicio ; j<fin;j++){
	valorSum += sin(j);
	}
	return valorSum;
}
//programa principal
int main(int argc, char *argv[]){
	
	double resSumatoria=0;
	int rep = 30000;
	if (argc!=2){
	printf("Error: \n\t$. /ejecutable numHilos\n");
	exit(0);
	}
	int numHilos= (int) atoi(argv[1]);//conversion del argumento recibido
	
	int maxCores= omp_get_max_threads();// Se obtiene el número máximo de hilos soportados por el sistema
	printf("Número maximo de Cored del SO: %d \n", maxCores);
	
	// Se fijan el número de hilos deseado: numHilos
	omp_set_num_threads(numHilos);
	#pragma omp  master
	printf("Número de hilos fijados: %d \n", numHilos);

	//región paralela OMP
	#pragma omp parallel
{
	//segura que cada hilo tenga una copia privada de 'resSumatoria' y las combine al final

	#pragma omp parallel for reduction (+: resSumatoria)
	for(int i=0; i<rep; i++)
	resSumatoria +=fsum(i);

}
	printf("Resultado Sumatoria Funcion SENO: %0.2f \n", resSumatoria);
	return 0;
}


