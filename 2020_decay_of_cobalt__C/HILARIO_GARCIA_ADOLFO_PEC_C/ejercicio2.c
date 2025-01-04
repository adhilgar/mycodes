#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv)
{
	int N0; //número de núcleos iniciales
	float p1, p2, p3, p4; //los cuatro elementos del vector P0
	int paso1, paso2, paso3, paso4; //los cuatro pasos de tiempo
	
	if (argc >=2){
		N0 = atoi(argv[1]);
	}else{
		N0 = 10000;
	}

	if (argc >=3){
		p1 = atof(argv[2]);
	}else{
		p1 = 0.5;
	}
		
	if (argc >=4){
		p2 = atof(argv[3]);
	}else{
		p2 = 0.1;
	}
	
	if (argc >=5){
		p3 = atof(argv[4]);
	}else{
		p3 = 0.01;
	}
	
	if (argc >=6){
		p4 = atof(argv[5]);
	}else{
		p4 = 0.001;
	}
	
	if (argc >=7){
		paso1 = atoi(argv[6]);
	}else{
		paso1 = 1;
	}

	if (argc >=8){
		paso2 = atoi(argv[7]);
	}else{
		paso2 = 1;
	}
		
	if (argc >=9){
		paso3 = atoi(argv[8]);
	}else{
		paso3 = 5;
	}
	
	if (argc >=10){
		paso4 = atoi(argv[9]);
	}else{
		paso4 = 10;
	}

	double P0[4]={p1, p2, p3, p4};	//valores de la probabilidad p
	
	int ncasos = sizeof(P0)/sizeof(double);
	
	int n[N0]; 		//vector a rellenar con unos
	
	int k, j, i; 	//para los bucles
	
	double U; 		//para la generacion aleatoria
	srand48(time(NULL));
	
	int paso[4] = {paso1, paso2, paso3, paso4}; 
	
	int nmax[ncasos];	//número máximo de j-iteraciones

	int N[ncasos][20000];	//matriz con el decrecimiento del número de núcleos para cada caso
	double t[ncasos][20000];	//matriz con el tiempo para cada caso
	
	double dt, lambda0; 	//para el paso del tiempo
	lambda0 = 0.13;
			
	FILE *archivodatos; //para guardar los datos en diferentes archivos

	char nombrebase[100] = "ejercicio2"; 
	char nombrearchivo[100] = "";

	
	printf("\nDatos de partida:\n\n\tN0 = %d\n\tp1 = %f\n\tp2 = %f\n\tp3 = %f\n\tp4 = %f\n",N0,p1,p2,p3,p4);
	printf("\n\tpaso1 = %d\n\tpaso2 = %d\n\tpaso3 = %d\n\tpaso4 = %d\n\n",paso1,paso2,paso3,paso4);
	
	
	//############################################# 
	
	for(k=0; k<ncasos; k++)
	{
		N[k][0] = N0;
	}
	
	for (k=0; k<ncasos; k++) 	//para cada caso
	{	
		for(i=0; i<N0; i++) 	//cada elemento del vector N es igual a 1
		{
			n[i] = 1;
		}
		
		j = 1;
		
		do{ 	
			for(i=0; i<N0; i++) 	//recorremos cada elemento del vector
			{
				if(n[i]==1) //si no se ha desintegrado
				{							
					U = drand48();		//generamos un numero aleatorio entre 0 y 1
					if(U<=P0[k]){n[i] = 0;}		//si ese numero es menor que p se convierte en cero
				}
			}				
				
			N[k][j] = cuentanumeros(n, N0, 1);

			j++;				
						
		} while(N[k][j-1]>0);	//repetimos el proceso mientras siga habiendo unos
		
		nmax[k] = j;			//nos guardamos el máximo de j-iteraciones		
				
		dt = P0[k]/lambda0; 	//el paso del tiempo es p partido lambda0
		
		for(i=0; i<nmax[k]; i++)
		{
			t[k][i] = dt*i;		//definimos el paso del tiempo
		}		 	
		
		sprintf(nombrearchivo,"%s",nombrebase);				//llamamos "puntosexponencial" a nombrebase
		sprintf(nombrearchivo,"%s_%d",nombrearchivo,k+1);	//le asignamos un número del 1 al 4 para cada caso
		sprintf(nombrearchivo,"%s.txt",nombrearchivo);		//le añadimos el ".txt"						

		archivodatos = fopen(nombrearchivo, "w"); //para escribir los archivos de datos con el paso de tiempo que necesitemos
		for (i=0;i<=nmax[k];i++)
		{
			if(i % paso[k]==0){fprintf(archivodatos,"%f %d \n",t[k][i], N[k][i]);}
		}
		fclose(archivodatos);	//si la división de la j-iteración por el paso es exacta, entonces se escribe	

		if (k==3){
			sprintf(nombrearchivo,"%s",nombrebase);				//si estamos en el cuarto caso, generamos un archivo extra para representar tiempos t>50 años
			sprintf(nombrearchivo,"%s_%d",nombrearchivo,k+1);	
			sprintf(nombrearchivo,"%s_50.txt",nombrearchivo);						

			archivodatos = fopen(nombrearchivo, "w");
			for (i=0;i<=nmax[k];i++)
			{
				fprintf(archivodatos,"%f %d \n",t[k][i], N[k][i]);
			}
			fclose(archivodatos);	//si la división de la j-iteración por el paso es exacta, entonces se escribe				
		}

	}
	
	//############################################# 
	
	graficaplot();
	
	graficaplot50();	//representa el cuarto caso y la solución analítica para t>50 años
	
	archivodatos = fopen("Nmax.txt", "w");		//guardamos nmax del cuarto caso en un archivo de datos que cargaremos en el ejercicio 3
	fprintf(archivodatos,"%d\n", max(nmax,4));
	fclose(archivodatos);
	
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

int graficaplot()
{
	#define NUM_COMANDOS 8
	int i;
			 
	/*lista de comandos para ejecutar y configurar la visualización que tendrán
	 * los puntos en la gráfica con gnuplot: datos a utilizar, estilo, color leyenda...*/
	 
	char * comandosGNUplot[] = 
	{
		"set title 'Decrecimiento exponencial de N'", 
		"set ylabel 'N(t)'",
		"set xlabel 't(años)'",
		"plot 'ejercicio2_1.txt' using 1:2 with lines title 'p=0.5'",
		"replot 'ejercicio2_2.txt' using 1:2 with lines title 'p=0.1'",
		"replot 'ejercicio2_3.txt' using 1:2 with lines title 'p=0.01'",
		"replot 'ejercicio2_4.txt' using 1:2 with lines title 'p=0.001'",
		"replot [0:70] 10**4*exp(-0.13*x) with lines lc rgb 'red' title 'N(t) = N0 exp(-lamda0*t)'"
	};

	/*Se crea una archivo con la función 'pipe open' que utilizamos para
	 * crear un canal que ejecute los comandos de gnuplot y enviarle "puntosexponencial[k+1].txt" para que lo represente*/
	 
	FILE * p = popen ("gnuplot -persist", "w");
	
	//ejecutamos los comandos en un bucle for
	
	for (i=0;i<NUM_COMANDOS;i++)
	{
		fprintf(p, "%s\n", comandosGNUplot[i]);
	}
 	
	return 0;
}	

//---------------------------------------------------------------------

int graficaplot50()
{
	#define NUM_COMANDOS 5
	int i;
			 
	/*lista de comandos para ejecutar y configurar la visualización que tendrán
	 * los puntos en la gráfica con gnuplot: datos a utilizar, estilo, color leyenda...*/
	 
	char * comandosGNUplot[] = 
	{
		"set title 'Decrecimiento exponencial de N'", 
		"set ylabel 'N(t)'",
		"set xlabel 't(años)'",
		"plot [50:100] 'ejercicio2_4_50.txt' using 1:2 with lines title 'p=0.001'",
		"replot [50:100] 10**4*exp(-0.13*x) with lines lc rgb 'red' title 'N(t) = N0 exp(-lamda0*t)'"
	};

	/*Se crea una archivo con la función 'pipe open' que utilizamos para
	 * crear un canal que ejecute los comandos de gnuplot y enviarle "puntosexponencial[k+1].txt" para que lo represente*/
	 
	FILE * p = popen ("gnuplot -persist", "w");
	
	//ejecutamos los comandos en un bucle for
	
	for (i=0;i<NUM_COMANDOS;i++)
	{
		fprintf(p, "%s\n", comandosGNUplot[i]);
	}
 	
	return 0;
}	


	
	
	
	
