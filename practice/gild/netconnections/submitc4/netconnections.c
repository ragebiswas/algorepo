#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* Disjoint Set */
int *set = 0;
int f(int n) /* Set Find */
{
   if(set[n] < 0) return n;
   else return set[n] = f(set[n]);
}
void u(int n1, int n2) /* Set Union */
{
   n1 = f(n1); n2 = f(n2);
   if(set[n2] < set[n1]) set[n1] = n2;
   else {
      if(set[n1] == set[n2]) set[n1]--;
      set[n2] = n1;
   }
}
int main(int argc, char **argv)
{
   char c; int i, num, p1, p2, y = 0, n = 0;
   FILE *fp = fopen(argv[1], "r");
   fscanf(fp, "%d", &num);
   set = malloc((num+1) * sizeof(int));
   for(i = 0; i<num+1; i++) set[i] = -1;
   while(!feof(fp))
   {
      if(!fscanf(fp, "%c%d%d", &c, &p1, &p2)) break;
      switch(c) {
         case 'c': if(f(p1) != f(p2)) u(p1, p2); break;
         case 'q': (f(p1) == f(p2)) ? y++ : n++; break;
      }
   }
   printf("%d,%d\n", y, n);
   fclose(fp); free(set); 
   return 0;
}
      
  