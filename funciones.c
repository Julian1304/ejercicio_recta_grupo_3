#include "libreria.h"
void crear_punto(double *puntos,struct recta *r1,struct recta *r2) //se asignan los puntos ingresados por el ussuario a la estructura de cada recta
{
	(r1)->p1.x=puntos[0];
	(r1)->p1.y=puntos[1];
	(r1)->p2.x=puntos[2];
	(r1)->p2.y=puntos[3];
	(r2)->p1.x=puntos[4];
	(r2)->p1.y=puntos[5];
	(r2)->p2.x=puntos[6];
	(r2)->p2.y=puntos[7];
}

	

void encontrar_recta(struct recta *r1,struct recta *r2)
{
	(r1)->m=((r1 -> p2.y) -(r1 -> p1.y))/((r1 -> p2.x) -(r1 -> p1.x)); //calcula la pendiente de la recta 1
	(r1) -> b=(r1 -> p2.y) - ((r1 -> m) *( r1 -> p2.x)); //calcula punto de corte de la recta 1

	(r2) -> m=((r2 -> p2.y) -(r2->p1.y))/((r2->p2.x)-(r2->p1.x)); //calcula la pendiente de la recta 2
	(r2) -> b=(r2->p2.y) - ((r2->m)*(r2->p2.x));//calcula punto de corte de la recta 2

}

void imprimir_recta(struct recta r1,struct recta r2)
{
	if ((r1.p1.x) - (r1.p2.x) !=0 && (r2.p1.x) - (r2.p2.x) !=0 ) // imprime las rectas cuando no son ni verticales ni horizontales
	{
	printf("\n la ecuación de la primera recta es y=%.2fx+%.2f \n",r1.m,r1.b); 
	printf("\n la ecuación de la segunda recta es y=%.2fx+%.2f \n",r2.m,r2.b);
	}
	else if ((r1.p1.x) - (r1.p2.x)==0 && (r2.p1.x) - (r2.p2.x) !=0 ) // imprime las rectas cuando r1 es vertical
	{
		printf("\n la ecuación de la primera recta es x=%.2f \n",r1.p1.x);
       		printf("\n la ecuación de la segunda recta es y=%.2fx+%.2f \n",r2.m,r2.b);
	}
	else if ((r1.p1.x) - (r1.p2.x)!=0 && (r2.p1.x) - (r2.p2.x) ==0 ) //imprime las rectas cuando r2 es vertical
	{
		printf("\n la ecuación de la primera recta es y=%.2fx+%.2f \n",r1.m,r1.b);
        	printf("\n la ecuación de la segunda recta es x=%.2f \n",r2.p2.x);
	}
	else									//imprime las rectas cuando ambas son verticales 
	{
		printf("\n la ecuación de la primera recta es x=%.2f \n",r1.p1.x);
	        printf("\n la ecuación de la segunda recta es x=%.2f \n",r2.p1.x);
	}

}


void imprimir_punto(struct recta r1, struct recta r2)
{
	printf("\n El ususrio ingreso las coordenadas P1(%.2f,%.2f) y P2(%.2f,%.2f) para la recta 1\n",r1.p1.x,r1.p1.y,r1.p2.x,r1.p2.y); //imprime las dos coordenadas del recta 1
	printf("\n El ususrio ingreso las coordenadas P1(%.2f,%.2f) y P2(%.2f,%.2f) para la recta 2\n",r2.p1.x,r2.p1.y,r2.p2.x,r2.p2.y);//imprime las dos cordenasas de la recta 2
}


char tipo_rectas(struct recta r1, struct recta r2)
{
	char rec;
	if (r1.m==r2.m)
	{
		rec=0;// son paralelas
		printf("\nlas rectas r1 y r2 son paralelas \n");
	
	}
	else if(r1.m*r2.m==-1)
	{
		rec=-1; //son perpendiculares}
		printf("\n las rectas son perpendiculares \n");
	}
	else if ((r1.p1.x) - (r1.p2.x) ==0 && (r2.p1.x) - (r2.p2.x) ==0 )
	{
		rec=-2; //si no son paralelas ni perpendiculares
		printf("\nlas rectas son paralelas y son rectas verticales \n");
	}
	else if (((r1.p1.x) - (r1.p2.x) ==0 && r2.m==0)||((r2.p1.x) - (r2.p2.x) ==0 && r1.m==0))
	{
		rec=2; // si son perpendiculares y una de ellas es vertical 
		printf("\n las rectas son perpendiculares y una de ellas es una recta vertical\n");
	}	

	else if ((r1.p1.x) - (r1.p2.x) !=0 && (r2.p1.x) - (r2.p2.x) !=0 )
	{
		rec=1; //ninguna
		printf("\n las rectas no son ni perpendiculares ni paralelas \n");
	}
	else
	{
		rec=3; //hay una recta vertical pero no son paralelas ni perpendiculares 
		printf("\n las rectas no son ni perpendiculares ni paralelas y una de ellas es vertical \n");
	}
return rec;
}

void interseccion(struct recta r1, struct recta r2,char rec)
{
	float x; //coordenada x del punto de intersección
	float y;//coordenada y del punto de intersección

	if (rec==-1 || rec ==1)//encuentra el punto de intersección de las rectas, pero ninguna de las rectas son verticales

	{
		x=((r2).b - (r1).b)/((r1).m - (r2).m); 
       		y=((r1.m)*x)+r1.b;
		

		printf("\nsu intersección esta en el punto (%.2f,%.2f)\n",x,y);
	}
	else if (rec==2) //punto de intersecci�n rectas perpendiculares si existe una recta vertical 
	{
		if (r1.m==0) //evalua si la recta r1 es horizontal
		{ 
			x=r2.p1.x;
			y=r1.p1.y;
			printf("\nsu intersección esta en el punto (%.2f,%.2f)\n",x,y);
		}
		else if(r2.m==0) //evalua si la recta r2 es horizontal
		{
			x=r1.p1.x;
			y=r2.p1.y;
			printf("\nsu intersección esta en el punto (%.2f,%.2f)\n",x,y);
		}
	}

	else if (rec=3) //punto de intersección si hay una recta vertical pero las rectas no son perpendiculares
	{	
		if ((r1.p1.x) - (r1.p2.x) ==0) //evalua si la recta r1 es vertical 
		{
			x=r1.p1.x;
			y=((r2.m)*x)+r2.b;
			printf("\nsu intersección esta en el punto (%.2f,%.2f)\n",x,y);
		}
		else
		{	
			x=r2.p1.x; //la recta r2 es vertical 
                        y=((r1.m)*x)+r1.b;
                        printf("\nsu intersección esta en el punto (%.2f,%.2f)\n",x,y);
		}
	}
	else
	{
		printf("\n no hay punto de intersección\n"); //las rectas son paralelas y no hay punto de corte
	}
	}

