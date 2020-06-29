/*
 * 101-INF3105-30
 * TP1
 *
 * Classe OutilsTp1 - Implementation
 *
 * A utiliser pour remplir la grille (voir ExUtOutilsTp1.cpp pour un exemple d'utilisation).
 *
 * Louise Laforest
 * Janvier 2010
 *
 */

#include <iostream>
#include <cstdlib>
#include "OutilsTp1.hpp"

using namespace std;

/**
 * Constructeur
 */
OutilsTp1 :: OutilsTp1 ( int germe ) {
    nombres [ 0 ] =  -9;  nombres [ 1 ] =  -7;  nombres [ 2 ] =  -6;  nombres [ 3 ] =  -6;
    nombres [ 4 ] =  -5;  nombres [ 5 ] =  -5;  nombres [ 6 ] =  -4;  nombres [ 7 ] =  -4;
    nombres [ 8 ] =  -4;  nombres [ 9 ] =  -3;  nombres [ 10 ] = -3;  nombres [ 11 ] = -3;
    nombres [ 12 ] = -2;  nombres [ 13 ] = -2;  nombres [ 14 ] = -2;  nombres [ 15 ] = -2;
    nombres [ 16 ] = -1;  nombres [ 17 ] = -1;  nombres [ 18 ] = -1;  nombres [ 19 ] = -1;
    nombres [ 20 ] = -1;  nombres [ 21 ] =  0;  nombres [ 22 ] =  0;  nombres [ 23 ] =  0;
    nombres [ 24 ] =  0;  nombres [ 25 ] =  0;  nombres [ 26 ] =  0;  nombres [ 27 ] =  1;
    nombres [ 28 ] =  1;  nombres [ 29 ] =  1;  nombres [ 30 ] =  1;  nombres [ 31 ] =  1;
    nombres [ 32 ] =  2;  nombres [ 33 ] =  2;  nombres [ 34 ] =  2;  nombres [ 35 ] =  2;
    nombres [ 36 ] =  2;  nombres [ 37 ] =  2;  nombres [ 38 ] =  3;  nombres [ 39 ] =  3;
    nombres [ 40 ] =  3;  nombres [ 41 ] =  3;  nombres [ 42 ] =  3;  nombres [ 43 ] =  4;
    nombres [ 44 ] =  4;  nombres [ 45 ] =  4;  nombres [ 46 ] =  4;  nombres [ 47 ] =  5;
    nombres [ 48 ] =  5;  nombres [ 49 ] =  5;  nombres [ 50 ] =  5;  nombres [ 51 ] =  6;
    nombres [ 52 ] =  6;  nombres [ 53 ] =  6;  nombres [ 54 ] =  7;  nombres [ 55 ] =  7;
    nombres [ 56 ] =  7;  nombres [ 57 ] =  8;  nombres [ 58 ] =  8;  nombres [ 59 ] =  8;
    nombres [ 60 ] =  9;  nombres [ 61 ] = 10;  nombres [ 62 ] = 15;

    srand ( germe ); // le meme germe donne la meme sequence de nombres aleatoires

	prochain = 0;
	brasserNombres();
}

/**
 * Retourne un nombre aleatoire
 */
int OutilsTp1 :: donnerNombre() {
	int reponse = nombres [ prochain ];
	prochain = ( prochain + 1 ) % MAX_NOMBRES;
	return reponse;
}

/**
 * Retourne un nombre entier aleatoire entre min et max inclusivement
 */
int OutilsTp1 :: alea ( int min, int max ) {
    return (int) ( min + ( ((double) (rand() % RAND_MAX )) / RAND_MAX * ( max - min + 1 )));
}

/**
 * Permet de melanger le tableau de nombres
 */
void OutilsTp1 :: brasserNombres () {
    for ( int i = 0; i < MAX_NOMBRES - 1; ++i ) {
	    int indiceAleatoire = alea ( i, MAX_NOMBRES - 1 );
	    int temp = nombres[i];
		nombres[i] = nombres[indiceAleatoire];
		nombres[indiceAleatoire] = temp;
	}
}

