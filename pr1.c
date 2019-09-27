/*
 * pr1.c
 *
 *  Created on: Sep 26, 2019
 *      Author: --
 */

#include <stdio.h>;

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

struct TimeWork {
	int index;
	int washTime;
	int dryTime;
};

int cmpfunc(const void *a, const void *b) {
	int t1 = MIN((*(struct TimeWork* )a).washTime,
			(*(struct TimeWork* )a).dryTime);
	int t2 = MIN((*(struct TimeWork* )b).washTime,
			(*(struct TimeWork* )b).dryTime);
	return (t1 - t2);
}

int main() {

	int countBaskets;

	FILE *Fout;
	FILE *Fin;
	Fin = fopen("lab2.a.dat.txt", "r");
	if (!Fin) {
		printf("File not found!\n");
		return 0;
	}

	fscanf(Fin, "%d", &countBaskets);
	if (countBaskets <= 0) {
		printf("File lab2.a.dat.txt not found!\n");
		return 0;
	}
	struct TimeWork tm[countBaskets];
	int n;
	for (n = 0; n < countBaskets; n++) {
		fscanf(Fin, "%d %d", &tm[n].washTime, &tm[n].dryTime);
		tm[n].index=n;
	}
	fclose(Fin);

	printf("Before sorting the list is: \n");
	for (n = 0; n < countBaskets; n++) {
		printf("%d : %d \n", tm[n].washTime, tm[n].dryTime);
	}

	qsort(tm, countBaskets, sizeof(struct TimeWork), cmpfunc);

	printf("\nAfter sorting the list is: \n");
	for (n = 0; n < countBaskets; n++) {
		printf("%d : %d \n", tm[n].washTime, tm[n].dryTime);
	}

	struct TimeWork mas1[countBaskets];
	struct TimeWork mas2[countBaskets];

	int countBasketsHead = 0;
	int countBasketsTail = 0;

	for (n = 0; n < countBaskets; n++) {
		if (tm[n].washTime <= tm[n].dryTime) {
			mas1[countBasketsHead++] = tm[n];
		} else {
			mas2[countBasketsTail++] = tm[n];
		}
	}

	while (countBasketsHead < countBaskets) {
		mas1[countBasketsHead++] = mas2[--countBasketsTail];
	}

	printf("\nResult mas: \n");
	for (n = 0; n < countBaskets; n++) {
		printf("%d %d  %d \n", mas1[n].index, mas1[n].washTime,
				mas1[n].dryTime);
	}

	int washTymeStart = 0;
	int washTyme = mas1[0].washTime;
	int washTymeEnd = washTymeStart + washTyme;

	int dryTymeStart = mas1[0].washTime;
	int dryTyme = mas1[0].dryTime;
	int dryTymeEnd = dryTymeStart + dryTyme;

	Fout = fopen("lab2.a.out.txt", "w");
	if (!Fout) {
		printf("File lab2.a.out.txt cannot be open!\n");
		return 0;
	}

	printf("\nResult matrix: \n");
	if (countBaskets == 1) {
		printf("%d %d  %d %d %d\n", mas1[0].index, mas1[0].washTime,
				mas1[0].dryTime, washTymeStart, dryTymeStart);
		printf("makespan is: %d\n", dryTymeEnd);

		fprintf( Fout, "%d %d  %d %d %d\n", mas1[0].index, mas1[0].washTime,
				mas1[0].dryTime, washTymeStart, dryTymeStart );
		fprintf( Fout, "makespan is: %d\n", dryTymeEnd );

	} else {
		printf("%d %d  %d %d %d\n", mas1[0].index, mas1[0].washTime,
				mas1[0].dryTime, washTymeStart, dryTymeStart);
		fprintf( Fout, "%d %d  %d %d %d\n", mas1[0].index, mas1[0].washTime,
						mas1[0].dryTime, washTymeStart, dryTymeStart );
		for (n = 1; n < countBaskets; n++) {
			int washTymeStart = washTymeEnd;
			washTyme = mas1[n].washTime;
			washTymeEnd = washTymeStart + washTyme;

			if (washTymeEnd > dryTymeEnd) {
				printf("dryer gap from %d to %d\n", dryTymeEnd, washTymeEnd);
				fprintf( Fout, "dryer gap from %d to %d\n", dryTymeEnd, washTymeEnd );
				dryTymeStart = washTymeEnd;
				dryTyme = mas1[n].dryTime;
				dryTymeEnd = dryTymeStart + dryTyme;
			} else {
				dryTymeStart = dryTymeEnd;
				dryTyme = mas1[n].dryTime;
				dryTymeEnd = dryTymeStart + dryTyme;
			}
			printf("%d %d  %d %d %d\n", mas1[n].index, mas1[n].washTime,
					mas1[n].dryTime, washTymeStart, dryTymeStart);
			fprintf( Fout, "%d %d  %d %d %d\n", mas1[n].index, mas1[n].washTime,
					mas1[n].dryTime, washTymeStart, dryTymeStart );
		}
		printf("makespan is: %d\n", dryTymeEnd);
		fprintf( Fout, "makespan is: %d\n", dryTymeEnd );

	}
	fclose(Fout);

}
