/*
 * 101-INF3105-30
 * TP1
 *
 * Classe OutilsTp1 - Specifications
 *
 * A utiliser pour remplir la grille (voir ExUtOutilsTp1.cpp pour un exemple d'utilisation).
 *
 * Louise Laforest
 * Janvier 2010
 *
 */

#ifndef OUTILS_TP1_HPP
#define OUTILS_TP1_HPP


class OutilsTp1 {

    public :
        static const int MAX_NOMBRES = 63;     // Longueur de la sequence aleatoire

        /**
         * Retourne un nombre entier aleatoire entre min et max inclusivement
         */
        static int alea ( int min, int max );

        /**
         * Constructeur
         */
        OutilsTp1 ( int germe = 0 );

        /**
         * Retourne un nombre aleatoire
         */
        int donnerNombre();

    private :
        int prochain;                   // position du prochain nombre a retourner
        int nombres [ MAX_NOMBRES ];    // tableau des nombres aleatoires

        void brasserNombres ();         // permet de melanger le tableau de nombres

}; // OutilsTp1

#endif // OUTILS_TP1_HPP

