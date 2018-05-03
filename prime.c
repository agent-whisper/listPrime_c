/*
	Program menampilkan bilangan prima berdasarkan batasan dari pengguna
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE (int) 1
#define FALSE (int) 0


void requestInteger(char* tag, int* container) {
	printf("Masukkan nilai %s (bilangan bulat): ", tag);
	scanf("%d", container);
}

/* Membuat sekuens bilangan prima menggunakan algoritma Sieve_of_Eratosthenes */
void initSieve(int sieveSize, int* container) {
	// Inisialisasi semua container dengan TRUE kecuali 0 dan 1
	container[0] = FALSE;
	container[1] = FALSE;

	for (int i = 2; i < sieveSize; i++) {
		container[i] = TRUE;
	}

	/* 	Algoritma Sieve_of_Eratosthenes menghasilkan array yang berisi TRUE jika
		indeksnya adalah bilangan prima */
	for (int i = 2; i < sqrt(sieveSize); i++) {
		if (container[i] == TRUE) {
			for (int j = i * i; j < sieveSize; j += i) {
				container[j] = FALSE;
			}
		}
	}
}

/*	Menampilkan isi primeArray sesuai dengan nilai batas yang dimasukkan */
void printSieve(int* primeArray, int lowerLimit, int upperLimit) {
	int startIdx = lowerLimit;
	if (startIdx < 0) {
		startIdx = 2;
	}

	for (int i = startIdx; i < upperLimit; i++) {
		if (primeArray[i] == TRUE) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

void main() {
	int lowerLimit, upperLimit;
	int *primeSieve;

	requestInteger("batas bawah", &lowerLimit);
	requestInteger("batas atas", &upperLimit);
	
	// Buat array container sebesar upperLimit
	primeSieve = malloc(upperLimit * sizeof(int));

	initSieve(upperLimit, primeSieve);

	printSieve(primeSieve, lowerLimit, upperLimit);

	if (primeSieve != NULL) {
		free(primeSieve);
	}

	printf("\n");
}