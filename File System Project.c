#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 10000

int check_condition(double a[]);

void display_caseID(double a[]);
void display_sex_status(double a[]);
void display_martial_status(double a[]);

int main()
{
    FILE *fp;
    char str[MAXCHAR];
    fp=fopen("USCensus1990.data.txt","r");
    printf("Case ID, Sex Status & Martial Status about people who are U.S citizen by naturalization as well as state government employees : \n");
    printf("\nCase ID                   Sex Status                    Martial Status\n");
    if (fp==NULL){
        printf("\nCould not open file");
        return 1;
    }

    fgets(str, MAXCHAR, fp);

     while (fgets(str, MAXCHAR, fp) != NULL){
        double arr[100];
        int k=0;
        char * token = strtok(str, ",");
        while( token != NULL) {
          arr[k++] = atof(token);
          token = strtok(NULL, ",");
       }

       if(check_condition(arr))
       {

           printf("\n");
           display_caseID(arr);
           printf("                     ");
           display_sex_status(arr);
           printf("                    ");
           display_martial_status(arr);
       }
     }

    fclose(fp);
    return 0;
}

int check_condition(double a[])
{
  if(a[5]==3 && a[6]==4)
      return(1);
  else
    return(0);
}

void display_caseID(double a[])
{
  if(a[0]<100000)
    printf("%.0f  ",a[0]);
  else if(a[0]<1000000)
    printf("%.0f ",a[0]);
  else
    printf("%.0f",a[0]);
}

void display_sex_status(double a[])
{
    if(a[56]==0)
        printf("Male  ");
    else if(a[56]==1)
        printf("Female");
}

void display_martial_status(double a[])
{
    if(a[29]==0)
        printf("Now Married,Except Separated");
    else if(a[29]==1)
        printf("Windowed");
    else if(a[29]==2)
        printf("Divorced");
    else if(a[29]==3)
        printf("Separated");
    else if(a[29]==4)
        printf("Never married/Under 15yrs old");
}
