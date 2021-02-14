#include<stdio.h>

int main()
{
 FILE *fp;
 char ch;
 fp=fopen("fresh.txt","w");

 putc('a',fp);

 fprintf(fp,"This is awesome");

 fclose(fp);

 fp=fopen("fresh.txt","r");

 ch=getc(fp);
 while(ch!=EOF)
 {
     printf("%c",ch);
     ch=getc(fp);
 }

 fclose(fp);
}
