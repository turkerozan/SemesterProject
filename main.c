#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	FILE *fp;
	char *filename = "veriseti";
	char *c =(char*) malloc(36*sizeof(char));
	fp = fopen(filename,"rb");
	if(!fp){
		printf("Error while trying to open document! \n");
		return 0;
	}
	do{
		fscanf(fp,"%35s%*c",c);
		printf("%s \t \n",c);
	}while(!feof(fp));
	fclose(fp);
	return 0;


}
