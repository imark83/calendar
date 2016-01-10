#include <stdio.h>

#define LUNES 0
#define MARTES 1
#define MIERCOLES 2
#define JUEVES 3
#define VIERNES 4
#define SABADO 5
#define DOMINGO 6

#define STARTS_ON    VIERNES

int main () {

	int k;        // contador para el mes
	int j;         // contador para el dia del mes
	int i;        // contador para el dia de la semana
	int nDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char *monthName[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

	i=STARTS_ON;    // inicializamos en el día que empieza el mes.

	printf ("\\documentclass{article}\n");

	printf ("\\usepackage[spanish]{babel}\n");
	printf ("\\usepackage[utf8x]{inputenc}\n");
	printf ("\\usepackage[T1]{fontenc}\n");

	printf ("\\usepackage[left=1cm,right=1cm,top=3cm,bottom=1cm]{geometry}\n");


	printf ("\\usepackage{array}\n");


	printf ("\\begin{document}\n");
	printf ("\\pagestyle{empty}\n");

	for (k=0; k<12; k++) {
		printf ("\\begin{center}\n");
		printf ("\\noindent\n");
		printf ("\\Huge\n");
		printf ("\\textbf{%s}\\\\\n", monthName[k]);
		printf ("\\vspace{1cm}\n");
		printf ("\\Large\n");
		printf ("\\begin{tabular}{|b{2.2cm}|b{2.2cm}|b{2.2cm}|b{2.2cm}|b{2.2cm}|b{2.2cm}|b{2.2cm}|}\n");
		printf ("\\hline\n");
		printf (" Lunes& Martes& Miércoles& Jueves& Viernes& Sábado& Domingo\\\\\n\\hline\n");
		for (j=0; j<i; j++) printf (" &");
		for (j=0; j<nDays[k]; j++) {
			printf ("\\hfill %i", j+1);
			i++;
			if (i==7) {
				printf ("\\\\[2.8cm]\n\\hline\n");
				i=0;
			}
			else {
				printf ("  &");
			}
		}
		if (i != 0) {
			for (j=i; j<6; j++) printf ("  &");
			printf ("\\\\[2.8cm]\n\\hline\n");
		}
		printf ("\\end{tabular}\n");
		printf ("\\end{center}\n");
		printf ("\\newpage\n");
	}
	printf ("\n\\end{document}\n");
}	
	
	
