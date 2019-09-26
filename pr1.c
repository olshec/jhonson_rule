/*
 * pr1.c
 *
 *  Created on: Sep 26, 2019
 *      Author: --
 */

#include <stdio.h>;

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct TimeWork{
	int washTime;
	int dryTime;
};

int cmpfunc (const void * a, const void * b) {
   int t1=MIN((*(struct TimeWork*)a).washTime,
		   (*(struct TimeWork*)a).dryTime);
   int t2=MIN((*(struct TimeWork*)b).washTime,
   		   (*(struct TimeWork*)b).dryTime);
   return ( t1 - t2 );
}

int main(){
	int countBaskets = 5;
	struct TimeWork tm[countBaskets];
	tm[0].washTime=32;
	tm[0].dryTime=42;

	tm[1].washTime=47;
	tm[1].dryTime=15;

	tm[2].washTime=22;
	tm[2].dryTime=50;

	tm[3].washTime=58;
	tm[3].dryTime=40;

	tm[4].washTime=31;
	tm[4].dryTime=28;





	int n;
	printf("Before sorting the list is: \n");
	   for( n = 0 ; n < countBaskets; n++ ) {
	      printf("%d : %d \n", tm[n].washTime, tm[n].dryTime);
	   }

	   qsort(tm, countBaskets, sizeof(struct TimeWork), cmpfunc);

	   printf("\nAfter sorting the list is: \n");
	   for( n = 0 ; n < countBaskets; n++ ) {
		  printf("%d : %d \n", tm[n].washTime, tm[n].dryTime);
	   }

	   struct TimeWork mas1[countBaskets];
	   struct TimeWork mas2[countBaskets];

	   int countBasketsHead = 0;
	   int countBasketsTail = 0;

	   for(n = 0 ; n < countBaskets; n++){
		   if(tm[n].washTime<=tm[n].dryTime)
		   {
			   mas1[countBasketsHead++]=tm[n];
		   }
		   else
		   {
			   mas2[countBasketsTail++]=tm[n];
		   }
	   }

	   while(countBasketsHead < countBaskets){
		   mas1[countBasketsHead++]=mas2[--countBasketsTail];
	   }

	   printf("\nResult mas: \n");
	   	   for( n = 0 ; n < countBaskets; n++ ) {
	   		  printf("%d : %d \n", mas1[n].washTime, mas1[n].dryTime);
	   	   }

}
