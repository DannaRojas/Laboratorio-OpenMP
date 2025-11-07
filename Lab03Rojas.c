/**************************************************
*       Pontificia Universidad Javeriana          *
*               ----------=----------             *
*                                                 *
* Autor: Danna Gabriela Rojas Bernal              *
* Fecha: 6 noviembre de 2025                        *
* Docente: J. Corredor
* Materia: Sistemas Operativos                             *
* Tema :Introducción a OpenMP
*Descripcion: 
***************************************************/
#include <omp.h> 
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    const int N = 1000;
    int a = 50;
    int b = 0;

    #pragma omp parallel for private(i) private(a)
    for (i = 0; i < N; i++){
        b = a + i; // Escritura concurrente en 'b'
    }

    // La 'a' original sigue siendo 50. 'b' puede no ser 1049 por la condición de carrera.
    printf("a = %d b = %d (Se espera a=50 b = 1049)\n", a, b);
return 0;
}
