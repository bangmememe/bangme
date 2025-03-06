#include <stdio.h>

int main()
{
   int celsius;
   // celsius = 15;
   printf("Input celsius temp: ?");
   scanf("%d", &celsius);
   printf("celsius temp : %d \n", celsius);

   double fahr;
   fahr = celsius * 9 / 5 + 32;
   
   printf("fahr temp : %f \n", fahr);

   return 0;
}