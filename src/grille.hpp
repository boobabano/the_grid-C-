/*
 * Grille.hpp
 *
 *  Created on: 2010-02-04
 *      Author: bf891332
 */

#ifndef GRILLE_HPP_
#define GRILLE_HPP_

 class Grille {
 public :
        Grille();
        Grille(int germe, int dimension);
        Grille ( const Grille & g );
        ~Grille();
        int obtenirValeur (int ligne, int colonne);
        void modifierTableau (int ligne, int colonne, int valeur);
        int obtenirLigne();
        int obtenirColonne();
        void modifierLigne(int ligne);
        void modifierColonne(int colonne);
        void afficherGrille();
 private:
        int ** tableau;
        int germe;
        int dimension;
        int ligne;
        int colonne;
 };
#endif /* GRILLE_HPP_ */

