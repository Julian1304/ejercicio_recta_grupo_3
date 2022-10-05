#ifndef LIBRERIA_H 
#define LIBRERIA_H

// directivas de procesamiento
#include<stdio.h>
#include<stdlib.h>
#define TAM 7

struct punto  //estructura punto
{
	double x;
	double y;
};

struct recta //estructura recta
{
	double m;
	double b;
	struct punto p1,p2;
};

// prototipos
void crear_punto(double* puntos,struct recta *r1,struct recta *r2);
void encontrar_recta(struct recta *r1,struct recta *r2);
void imprimir_recta(struct recta r1,struct recta r2);
void imprimir_punto(struct recta r1,struct recta r2);
char tipo_rectas(struct recta r1,struct recta r2);
void interseccion(struct recta r1,struct recta r2,char rec);

#endif


