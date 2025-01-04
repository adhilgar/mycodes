#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char** argv)
{	
	int N0;  //número de núcleos inicial
	double P0;	//probabilidad de desintegración
	int m1, m2;	//muestras
	int paso;	//paso: recomiendo 50

	if (argc >=2){
		N0 = atoi(argv[1]);
	}else{
		N0 = 1000;
	}

	if(argc >=3){
		P0 = atof(argv[2]);
	}else{
		P0 = 0.001;
	}
		
	if (argc >=4){
		m1 = atoi(argv[3]);
	}else{
		m1 = 1;
	}
	
	if (argc >=5){
		m2 = atoi(argv[4]);
	}else{
		m2 = 100;
	}
	
	if (argc >=6){
		paso = atoi(argv[5]);
	}else{
		paso = 50;
	}
	
	printf("\nDatos de partida:\n\n\tN0 = %d\n\tP0 = %f\n\tpaso = %d\n\tm1 = %d\n\tm2 = %d\n\n",N0,P0,paso,m1,m2);
	
	int M[2]={m1, m2}; //cada caso viene determinado por el numero de muestras
	int ncasos = sizeof(M)/sizeof(int); 
	
	int n[N0]; 	//matriz a rellenar con unos
	
	
	int nmax;	//número máximo de iteraciones		
	
	// ------------------------------------------	
	
	FILE * archivoNmax = fopen("Nmax.txt", "r");	//el valor nmax lo cargamos del archivo de datos del ejercicio 2	
	if(archivoNmax==NULL)
	{
		nmax=10000;
	}
	else
	{
		fscanf(archivoNmax,"%d",&nmax);
		fclose(archivoNmax);
	}
	
	// ------------------------------------------
	
	int k, j, j2, i, m;	//contadores	
						//k-simulaciones, j-iteraciones, j2-paso-iteraciones, i-elementos del vector, m-casos
	
	double U;  //para la generación de números aleatorios
	srand48(time(NULL)); 
	
	int N[nmax][max(M, ncasos)];	//matriz con el número de nucleos restantes para cada m-caso
	double t[nmax][ncasos];			//matriz con el tiempo para cada m-caso
	double F[nmax][ncasos];			//FDA para cada m-caso y con nmax j-filas
	
	double dt, lambda0; 	//t = j x dt
	lambda0 = 0.13;
	dt = P0/lambda0;
	
	//#########################################
	
	for (m=0; m<ncasos; m++) 	
	{		
		for(k=0; k<M[m]; k++)
		{
			N[0][k] = N0;		//el primer elemento de la matriz N debe ser N0 
		}
	
		for(k=0; k<M[m]; k++)  //para el caso 1 entra una vez, para el caso 2 entra 100 veces
		{
			for(i=0; i<N0; i++) 	
			{
				n[i] = 1;		//cada elemento del vector n es un uno, se inicia el algoritmo ya descrito en los ej. 1 y 2.
			}
			
			j = 1;
			
			do{				
				for(i=0; i<N0; i++) 	
				{
					if(n[i]==1) 		
					{							
						U = drand48();		
						if(U<=P0){n[i] = 0;}	
					}
				}
								
				N[j][k] = cuentanumeros(n, N0, 1);

				j++;
							
			} while(j<=nmax);
		}
		
		j2 = 0;
		
		for(j=0;j<nmax;j++)
		{
			if(j % paso==0)	//para que se añada a la matriz, la iteración j debe poder dividirse con resto 0 por el paso.
			{				
				F[j2][m] = (double)((N0-(double)(sumatorio(N[j], M[m])/M[m]))/N0);//definimos la FDA (utilizamos la función sumatorio que suma los elementos de un vector)
				t[j2][m] = (double)dt*j2*paso; //definimos el paso del tiempo
				j2++;
			}
		}
	}
	
	//escribimos un archivo de datos para cada caso con los elementos de las matrices correspondientes
		
	FILE *archivodatos;

	archivodatos = fopen("ejercicio3_caso1.txt", "w");		
	for (j=0;j<nmax/paso;j++)
	{
		fprintf(archivodatos,"%f, %f \n", 
			t[j][0], F[j][0]);
	}
	fclose(archivodatos);
	
	archivodatos = fopen("ejercicio3_caso2.txt", "w");
	for (j=0;j<nmax/paso;j++)
	{
		fprintf(archivodatos,"%f %f \n", 
			t[j][1], F[j][1]);
	}
	fclose(archivodatos);

	graficaplot();	//generamos la gráfica mediante la función graficaplot
	
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

int sumatorio(int V[], int ncomponentes)
{

	int j, suma;
	
	suma=0;

	for (j=0; j<ncomponentes; j++)	
	{
		suma += V[j];
	}
	
	return suma;
}



//---------------------------------------------------------------------

int graficaplot()
{
	#define NUM_COMANDOS 5
	int i;

	// #############
			 
	/*lista de comandos para ejecutar y configurar la visualización que tendrán
	 * los puntos en la gráfica con gnuplot: datos a utilizar, estilo, color leyenda...*/

	char * comandosGNUplot1[] = 
	{
		"set title 'Función de distribución acumulada'", 
		"set ylabel 'F(t)'",
		"set xlabel 't (años)'",
		"plot 'ejercicio3_caso1.txt' using 1:2 with points title 'M=1'",
		"replot [0:80] 1-exp(-0.13*x) with lines lc rgb 'red' title 'F(t) = 1-exp(-lambda0*x)'"
	};

	/*Se crea una archivo con la función 'pipe open' que utilizamos para
	 * crear un canal que ejecute gnuplot y envie el archivo txt correspondiente para que lo represente*/
	 
	FILE *p = popen ("gnuplot -persist", "w");
	
	for (i=0;i<NUM_COMANDOS;i++)
	{
		fprintf(p, "%s\n", comandosGNUplot1[i]);
	}
	pclose(p);

	// #############
 
	char * comandosGNUplot2[] =
	{
		"set title 'Función de distribución acumulada'", 
		"set ylabel 'F(t)'",
		"set xlabel 't (años)'",
		"plot 'ejercicio3_caso2.txt' using 1:2 with points title 'M=100'",
		"replot [0:80] 1-exp(-0.13*x) with lines lc rgb 'red' title 'F(t) = 1-exp(-lambda0*x)'"
	};
	 
	p = popen ("gnuplot -persist", "w");
	
	for (i=0;i<NUM_COMANDOS;i++)
	{
		fprintf(p, "%s\n", comandosGNUplot2[i]);
	}
	pclose(p);	

	// #############

	return 0;
}
