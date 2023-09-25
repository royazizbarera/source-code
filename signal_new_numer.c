#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int signum);

int kolom = 0;
int num[5] = {0, 0, 0, 0, 0};

int main()
{
   signal(SIGINT, sighandler);
   printf("A\tB\tC\tD\tE\n");
   while (1)
   {
      switch (kolom)
      {
      case 0:
         printf("%d\t\t\t\t\n", num[kolom]);
         break;

      case 1:
         printf("\t%d\t\t\t\n", num[kolom]);
         break;
      case 2:
         printf("\t\t%d\t\t\n", num[kolom]);
         break;
      case 3:
         printf("\t\t\t%d\t\n", num[kolom]);
         break;
      case 4:
         printf("\t\t\t\t%d\n", num[kolom]);
         break;
      }

      if (num[kolom] == 9) {
         num[kolom] = 0;
      } else {
         num[kolom] += 1;
      }

      sleep(1);
   }
   return (0);
}

void sighandler(int signum)
{
   if (kolom == 4) {
      kolom = 0;
   } else {
      kolom += 1;
   }
   printf("Interupt\n", signum);
}