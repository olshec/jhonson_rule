/*
 * pr1.c
 *
 *  Created on: Sep 26, 2019
 *      Author: --
 */

#include <stdio.h>;

struct TimeWork{
	int washTime;
	int dryTime;
};

int cmpfunc (const void * a, const void * b) {
   return ( (*(struct TimeWork*)a).washTime - (*(struct TimeWork*)b).washTime );
}

int main(){

	struct TimeWork tm[5];
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
	   for( n = 0 ; n < 5; n++ ) {
	      printf("%d ", tm[n].washTime);
	   }

	   qsort(tm, 5, sizeof(struct TimeWork), cmpfunc);

	   printf("\nAfter sorting the list is: \n");
	   for( n = 0 ; n < 5; n++ ) {
	      printf("%d ", tm[n].washTime);
	   }

	//printf("%s","hw");


}
