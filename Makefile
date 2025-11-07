#############################################
#
#	Makefile
#Autor: Danna Gabriela Rojas Bernal 
#Materia: Ssitemas Operativos
#Fichero: Automatización de Compilación
###############################################

GCC = gcc
FLAGS = -lm -fopenmp

PROGRAMAS= Lab01Rojas Lab02Rojas Lab03Rojas Lab04Rojas Lab05Rojas Lab06Rojas

Lab01Rojas:
	$(GCC) $@.c -o $@ $(FLAGS)

Lab02Rojas:
	$(GCC) $@.c -o $@ $(FLAGS)

Lab03Rojas:
	$(GCC) $@.c -o $@ $(FLAGS)

Lab04Rojas:
	$(GCC) $@.c -o $@ $(FLAGS)

Lab05Rojas:
	$(GCC) $@.c -o $@ $(FLAGS)

Lab06Rojas:
	$(GCC) $@.c -o $@ $(FLAGS)

clean:
	$(RM) $(PROGRAMAS)
