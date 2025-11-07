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

    #pragma omp parallel for private(i) private(a) private(b)
    for (i = 0; i < N; i++){
        b = a + i; // Cada hilo calcula su propio b, sin afectar el b global
    }

    // Como b era privado, el b original sigue en 0. No se obtiene 1049.
    printf("a = %d b = %d (Se espera a=50 b = 1049)\n", a, b);
	return 0;
}
