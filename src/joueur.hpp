/*
* joueur.hpp
*
*  Created on: 2010-02-09
*      Author: bf891332
*/

#ifndef JOUEUR_HPP_
#define JOUEUR_HPP_

#include <string>

using namespace std;

class Joueur {
public :
    Joueur();
    Joueur(string nom, int pointage);
    string obtenirNom()const;
    int obtenirPointage() const;
    void modifierNom(string nom);
    void modifierPointage(int pointage);


  private:
    string nom;
    int pointage;

};

#endif /* JOUEUR_HPP_ */

