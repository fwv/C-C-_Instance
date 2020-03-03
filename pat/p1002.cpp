#include<iostream>
#include<stdio.h>
using namespace std;
/**
 * 1002 A+B for Polynomials (25 分)
 * This time, you are supposed to find A+B where A and B are two polynomials.
 * 
 */
int p1002() {
	int a, k = 0;
	float b;
	float f[1001];
	for (int i = 0; i < 1001; i++) {
		f[i] = 0;
	}

	scanf("%d", &k);
	while (k--) {
		scanf("%d %f", &a, &b);
		if (b) {
			f[a] += b;
		}
	}

	scanf("%d", &k);
	while (k--) {
		scanf("%d %f", &a, &b);
		if (b) {
			f[a] += b;
		}
	}
	k = 0;
	for (int i = 0; i < 1001; i++) {
		if (f[i]) {
			k++;
		}
	}
	printf("%d", k);
	if (k) {
		printf(" ");
	}
	if (k) {
		for (int i = 1000; i >= 0; i--) {
			if (f[i]) {
				printf("%d %0.1f", i, f[i]);
				k--;
				if (k) {
					printf(" ");
				}
			}

		}
	}
	return 0;
}                       