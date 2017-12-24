#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DOCSIZE 1000
#define DOCAMOUNT 20
struct Docs {
   char document[DOCSIZE];
   int   realSize;
   char **kshingles;
   int shingleSize;
};

int main() {
	struct Docs dataset[DOCAMOUNT];
	readDataset(dataset);
    int choice;
    int k;
    do {
		do{
            printf("\n 1.K shingle and Jaccard Similarity Calculation");
            printf("\n 2.Exit");
            printf("\n Your Choice : ");
            scanf("%d",&choice);
            if(choice<1||choice>2)
                printf("Invalid Choice");
		}while(choice<1 || choice > 2);
        switch(choice){
        case 1:
            printf("\n Enter k for shingling : ");
            scanf("%d",&k);
            kshingle(dataset,k);
            break;
        default:
            printf("\n End of Program");
        }
	} while (choice != 2);
}
void kshingle(struct Docs dataset[DOCAMOUNT], int k){
    int maxKshingle = dataset[0].realSize - k + 1;
    //printf("real size : %d \t\n",dataset[0].realSize);
    int i = 0;
    dataset[0].kshingles = malloc(maxKshingle * sizeof(char*));
    for(i = 0; i < maxKshingle;i++){
            dataset[0].kshingles[i] = malloc((k +1)* sizeof(char));
    }
    memmove(dataset[0].kshingles[0],dataset[0].document,k);
    dataset[0].kshingles[0][k] = '\0';
    printf("%s \n", dataset[0].kshingles[0]);
    printf("%s \a", dataset[0].document);
}
void readDataset(struct Docs dataset[DOCAMOUNT]){

    char filename[10] = "0.txt";
    int i,j = 0;
    char x = 'c';
    for(i=0;i<DOCAMOUNT;i++){
        if(i<9){
        filename[0] = i + 1 + '0';
        }else if(i<19){
        strcpy(filename,"10.txt");
        filename[1] = (i + 1)%10 + '0';
        }
        else{
        strcpy(filename,"20.txt");
        filename[1] = (i + 1)%10 + '0';
        }
        j = 0;
        FILE *fp;
        int c;
        fp = fopen(filename,"r");
        if(!fp){
		printf("\nError while trying to open document %s! \n",filename);
		return 0;
		exit(0);
	}
	do{
		c = getc(fp);
		if(c != NULL){
        if(c>64 && c<90){
            putchar(c + 'a'-'A');
            dataset[i].document[j++] = c + 'a'-'A';
        }
        else if(c>96 && c<123){
            putchar(c);
            dataset[i].document[j++] = c;
        }
        else if(c == 32){
                if(dataset[i].document[j-1]!=32){
                putchar(c);
                dataset[i].document[j++] = c;
                }
        }
		}
	}while(!feof(fp));
	fclose(fp);
	dataset[i].realSize = j;
	printf("\n DOCUMENT : %s read successfully \n",filename);
    }
}
