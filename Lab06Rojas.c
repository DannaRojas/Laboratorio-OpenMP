/*****************************************************
*       Pontificia Universidad Javeriana             *
*               ----------=----------                *
*                                                    *
* Autor: Danna Gabriela Rojas Bernal                 *
* Fecha: 6 noviembre de 2025                         *
* Docente: J. Corredor							     *
* Materia: Sistemas Operativos                       *
* Tema :Introducción a OpenMP					     *
*Descripcion: Uso de la directiva y funcion 	     *
*para hacer uso de OpenMP 							 *
*	 -Paralelismo para el calculo de la funcion seno *
******************************************************/

//librerias
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>//manejo del tiempo
#define MIN(x,y) (((x) < (y)) ? (x):(y))//obtener el minimo 

struct timeval inicio, fin;//varibales para medir el tiempo

//funcion que guarda el tiempo de inicio la ejecucion 
void InicioMuestra(){
	gettimeofday(&inicio, (void *)0);
}

//funcion que calcula el tiempo trancurrido 
void FinMuestra(){
	gettimeofday(&fin, (void*)0);
	fin.tv_usec -= inicio.tv_usec;
	fin.tv_sec -= inicio.tv_sec;
	double tiempo = (double) (fin.tv_sec*1000000 + fin.tv_usec);
	printf("%9.0f microSeg \n", tiempo);
}
//funcion que calcula la sumatoria 
double fsum(int i ){
//se implementa la funcion sumatoria
	int inicio= i *(i+1)/2;
	int fin= inicio + i ;  
	double valorSum=0;
	for (int j=inicio ; j<fin;j++){
	valorSum += sin(j);
	}
	return valorSum;
}
//progrma principal 
int main(int argc, char *argv[]){

		double resSumatoria=0;
        
        if (argc!=3){
        printf("Error: \n\t$. /ejecutable numHilos numRep\n");
        exit(0);
        }
        int numHilos= (int) atoi(argv[1]);
	    int numRep=(int)atoi(argv[2]);
	    Obtiene el número máximo de hilos disponibles en el SO
        int maxCores= omp_get_max_threads();
        printf("Número maximo de Cored del SO: %d \n", maxCores);

        // Se fijan el número de hilos deseado: numHilos
        omp_set_num_threads(numHilos);
        #pragma omp  master
        printf("Número de hilos fijados: %d \n", numHilos);
	
	//Inicia la medición del tiempo de ejecución
	InicioMuestra();
        //región paralela OMP
        #pragma omp parallel
{
	//Al final las suma para evitar condiciones de carrera 
        #pragma omp parallel for reduction (+: resSumatoria)
        for(int i=0; i<numRep; i++)
        resSumatoria +=fsum(i);

}
	// Finaliza la medición del tiempo de ejecución
	FinMuestra(); 
       printf("Resultado Sumatoria Funcion SENO: %0.2f \n", resSumatoria);
        return 0;
}

