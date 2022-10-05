#include "libreria.h" //libreria creada
int main(int argc, char* argv[])
{
	struct recta r1; //estructura para la recta 1
	struct recta r2;//estructura para la recta 2
	double puntos[TAM];//arreglo para guardar los datos ingresados por el usuario
	char rec;
	int cont=0;//contador
	int pos=1;//contador 
	if (argc != 9) //validación cantidad de argumentos ingresados por el usuario 
	{
		printf("\nError en la catidad de argumentos ingresados \n");
	}
	else
	{
         	for (cont=0;cont<=TAM;cont++)
          {
                  puntos[cont] = atof(argv[pos]);  //conversión los datos ingresados de cadena de caracteres a punto flotante
                  pos++;
          }
          }
// invocación de funciones 
crear_punto(&puntos[0], &r1, &r2);
encontrar_recta(&r1,&r2);
imprimir_recta(r1,r2);
imprimir_punto(r1,r2);
rec=tipo_rectas(r1,r2);
interseccion(r1,r2,rec);
return 0;
}

