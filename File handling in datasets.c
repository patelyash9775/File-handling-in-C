#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000

int found(double ar[], double key, int index);

int main()
{
    FILE *fp;
    char str[MAXCHAR];
    double id[20000];
    int y=0;
    printf("Id for the LONGITUDE greater than 8.4 and lesser than 9.4 :-  ");
    printf("\nYear of. Entry                    Sex Status                    Martial Status\n");
    printf("\n");
    fp = fopen("3D_spatial_network.txt", "r");
    if (fp == NULL){
        printf("\nCould not open file");
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL){
        double arr[4];
        int k=0;
        int x =0;
        char * token = strtok(str, ",");
        while( token != NULL ) {
          arr[k++] = atof(token);
          token = strtok(NULL, ",");
       }

        x = found(id,arr[0],y);



        if(x!=-1 && (arr[1]>8.4 && arr[1]<9.4)){
            id[y++] = arr[0];
            printf("%.0lf \n",arr[0]);
        }
    }
    fclose(fp);

    return 0;
}


int found(double ar[], double key, int index){
    for(int j=0;j<index;j++){
        if(ar[j]==key){
            return -1;
        }
    }
    return 0;
}
