#include<stdio.h>
#include<string.h>

int main()
{
 FILE *fp;
 char a[20];
 fp=fopen("My captain.txt","w");
 printf("Input to the reverse function : \n");
 gets(a);
 fprintf(fp,"%s",a);
 fclose(fp);
 char c[20];
 fp=fopen("My captain.txt","r");
 int i=0;
 c[0]=fgetc(fp);
 while(!feof(fp))
 {
     i=i+1;
     c[i]=fgetc(fp);
 }
 i=strlen(a)-1;
 while(i>=0)
 {
     printf("%c",c[i]);
     i=i-1;
 }

 fclose(fp);
}
