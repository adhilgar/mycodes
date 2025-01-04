

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//---------------------------------------------------------------------
//---------------------------------------------------------------------
//---------------------------------------------------------------------

int main(int argc, char** argv)
{
	int N0[4] = {20, 50, 100, 1000}; 	//numero de núcleos en cada caso
	double P0[4] = {0.5, 0.2, 0.1, 0.01}; 	//valor de la probabilidad p
	
	int ncasos = sizeof(N0)/sizeof(int);	//número de casos=4
	
	/*utilizamos *N para apuntar a la dirección en la que necesitemos
	reservar una cantidad de memoria de una longitud
	determinada mediante la función calloc*/
	
	int *N;								
	int k, j, i, m, longitud_N;
	
	//para la generación de números aleatorios entre cero y uno
	
	double U;
	srand48(time(NULL));
	
	//definimos el número de muestras
	
	long int M = pow(10, 6);
	
	//definimos el vector que almacenará las desintegraciones para cada simulación 
	//también definimos el número máximo de desintegraciones posibles
	
	int desintegraciones[M];
	int max_desintegraciones;
	max_desintegraciones = max(N0, ncasos);
	
	//matrices P y p con tantas filas como caso y tantas columnas como desintegraciones contando j=0

	int P[ncasos][max_desintegraciones+1];
	double p[ncasos][max_desintegraciones+1];
		
	//número de iteraciones que queramos realizar
	
	int niteraciones = 1;
	
	printf("\nDatos de partida:\n\n\tN0 = [%d, %d, %d, %d]\n\tP0 = [%f, %f, %f, %f]\n\tM = 10^6\n",
						N0[0], N0[1], N0[2], N0[3], P0[0], P0[1], P0[2], P0[3], M);
	
	// ################################################
	

	for (k=0; k<ncasos; k++)	//para cada caso
	{
		/*cada vector N tendrá la longitud del 
		 * del elemento de N0[k] correspondiente*/
		
		longitud_N = N0[k];
		
		/*mediante el puntero N, reservamos la cantidad
		 *  de memoria que necesitemos en cada caso, determinada
		 * en longitud, mediante la función calloc*/	
		
		N = (int *)calloc(longitud_N, sizeof(int)); 
		
		
		//para cada caso, repetimos 10^6 veces el proces0
		
		for(m=0; m<M; m++)
		{
			for(i=0; i<longitud_N; i++)
			{
				N[i] = 1;	//cada elemento del vector es igual a 1
			}
			
			for(j=0; j<niteraciones; j++)	//para cada iteración
			{
				for(i=0; i<longitud_N; i++)	//recorremos cada celda del vector
				{
					if(N[i]==1)	//si no se ha desintegrado
					{								
						U = drand48();			//generamos un número aleatorio entre 0 y 1
						if(U<=P0[k]){N[i] = 0;}	//aplicamos el algoritmo de la sección 8 del enunciado
						else {N[i] = 1;}					
					}
				}
			}
			
			desintegraciones[m] = cuentanumeros(N, longitud_N, 0); //contamos el número de ceros	
		}
		
		for(j=0; j<=max_desintegraciones; j++)
		{
			P[k][j] = cuentanumeros(desintegraciones, M, j);	//la matriz P cuenta el número de números de 0 a 10^6 en el vector desintegraciones
			p[k][j] = (double)P[k][j]/M;						//la matriz p es igual a P/M
		}	
		
		free(N); //antes de cerrar el bucle liberamos la memoria utilizada en N para volver a utilizarla en el siguiente caso
	}
	
	
	// ################################################
		
	//se crea y se guarda el archivo puntosmatriz.txt que guarda los valores de la matriz p para cada caso (del 0 al 3). 
		
	FILE * archivodatos = fopen("ejercicio1.txt", "w");		
	for (i=0;i<=25;i++)										//el límite en 25 es el óptimo para visualizar la gráfica con facilidad
		{
			fprintf(archivodatos, " %d %f %f %f %f \n", i, p[0][i], p[1][i], p[2][i], p[3][i]);
		}
	fclose(archivodatos);
	
	//llamamos a la función que nos crea el histograma

	histograma();
	
	return 0;
}
	

//---------------------------------------------------------------------

int cuentanumeros(int V[], int ncomponentes, int numero)
{
	int i, contador;
	
	contador = 0;
		
	for(i=0; i<ncomponentes; i++)
	{
		if(V[i]==numero){contador++;}
	}
			
	return contador;
}

//---------------------------------------------------------------------

int max(int V[], int componentes)
{
	int i;
	int maxvalor;
	
	maxvalor = V[0];
	
	for(i=1; i<componentes; i++)
	{
		if(V[i] > maxvalor){maxvalor = V[i];}
	}
	
	return maxvalor;
}

//---------------------------------------------------------------------

int histograma()
{
	#define NUM_COMANDOS 8
	
	int i;
		 
	/*lista de comandos para ejecutar y configurar la visualización que tendrán
	 * los puntos en la gráfica con gnuplot: datos a utilizar, estilo, color leyenda...*/


	char * comandosGNUplot[] = 
	{
		"set title 'Distribución de probabilidad - Ejercicio 1'", 
		"set ylabel 'p(x)'",
		"set xlabel 'x (numero de desintegraciones)'",
		"plot 'ejercicio1.txt' using 1:2 with lines title 'N0=20, p=0.5'",
		"replot 'ejercicio1.txt' using 1:3 with lines title 'N0=50, p=0.2'",
		"replot 'ejercicio1.txt' using 1:4 with lines title 'N0=100, p=0.1'",
		"replot 'ejercicio1.txt' using 1:5 with lines title 'N0=1000, p=0.01'",
 		"replot [0:25] (10**x/gamma(x+1))*exp(-10) with lines lc rgb 'red' title 'p(x)=(lambda^x/x!)*exp(-lambda)'"	
	};
							
	/*Se crea una archivo con la función 'pipe open' que utilizamos para
	 * crear un canal que ejecute gnuplot y envie el archivo txt correspondiente para que lo represente*/
	 
	FILE * p = popen("gnuplot -persist", "w");
	
	//ejecutamos los comandos en un bucle for
	
	for (i=0;i<NUM_COMANDOS;i++)
	{
		fprintf(p, "%s\n", comandosGNUplot[i]);
	}
 	
	return 0;
}
