/*
 * Joueur.cpp
 *
 *  Created on: 2010-02-09
 *      Author: bf891332
 */
#include "joueur.hpp"
#include <iostream>
#include <cstdlib>

/*
 * constructeur de joueur sans parametres
 */
 Joueur ::Joueur(){
	 this->nom = "Ordinateur";
     this->pointage = 0;
 }
/*
 * constructeur de jouer avec parametres
 */
 Joueur::Joueur(string nom, int pointage){
	 this->nom = nom;
	 this->pointage = pointage;

 }
/*
 * Getters
 */
 string Joueur :: obtenirNom() const {
     return nom;
 }

 int Joueur:: obtenirPointage() const {
     return pointage;
 }
 /*
  * Setters
  */

 void Joueur :: modifierNom( string nom){
	    this->nom = nom;
 }
 void Joueur :: modifierPointage(int pointage){
	    this->pointage = pointage;
 }


