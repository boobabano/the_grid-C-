/*
 * Grille.cpp
 *
 *  Created on: 2010-02-04
 *      Author: bf891332
 */
#include <iomanip>
#include "OutilsTp1.hpp"
#include "Grille.hpp"
 #include <iostream>
 #include <cstdlib>

 using namespace std;
/*
 * constructeur de grille
 */
 Grille::Grille(int germe, int dimension){
	 this->dimension = dimension;
	 this->germe = germe;
     this->ligne = 0;
     this->colonne = 0;

	tableau = new int *[dimension];
	 for(int i =0 ; i< dimension ; i++){
	   tableau[i]= new int [dimension];
	 }

	 OutilsTp1 outil ( germe );
	 for ( int i = 0; i < dimension; ++i ) {
	     for ( int j = 0 ; j < dimension; ++j ) {
	 		  tableau[i][j] = outil.donnerNombre();
	 		  	          		}
  }
 }

 /*
  * affichage de la grille
  */
  void Grille :: afficherGrille (){


		     if(dimension == 2){
		     cout<<"           0         1"<< endl;
		     cout<<"      +---------+----------+" <<endl;
		     }
		     else if (dimension == 3){
		     cout<<"            0          1          2"<< endl;
		     cout<<"      +----------+----------+-----------+" <<endl;
		     }
		     else if (dimension == 4){
		     cout<<"            0            1          2            3  "<< endl;
		   	 cout<<"      +-----------+-----------+-----------+------------+" <<endl;
		     }
		     else if (dimension == 5){
		     cout<<"             0            1            2            3            4  "<< endl;
		   	 cout<<"      +------------+------------+------------+------------+-------------+" <<endl;
		     }
		     else if (dimension == 6){
		     cout<<"             0             1             2             3              4             5 "<< endl;
		   	 cout<<"      +-------------+-------------+-------------+-------------+-------------+--------------+" <<endl;
		     }
		     else if (dimension == 7){
		     cout<<"              0              1              2             3               4               5              6 "<< endl;
		   	 cout<<"      +--------------+--------------+--------------+--------------+--------------+--------------+---------------+" <<endl;
		     }
		     else{
		     cout<<"               0              1               2                3               4               5              6             7"<< endl;
		     cout<<"      +---------------+---------------+---------------+---------------+---------------+---------------+---------------+----------------+" <<endl;

		     }

		     for ( int i = 0; i < dimension; ++i ) {
		     	for ( int j = 0 ; j < dimension; ++j ) {

		     	  cout << "      | ";
                   if(ligne == i && colonne == j){

                    	cout << setw(dimension) << "@@" << setw(dimension) ;
                      }
                    else if (tableau[i][j]== 99){
		     	          cout << setw(dimension) << " " << setw(dimension) ;
		     	          }
                    else{
		     	          cout << setw (dimension)<< tableau[i][j];
                         }
		     	          		}
		     	          	 	cout << "       |" << endl;
		     	          	 	if (dimension == 8){
		     	          	 	cout << "      +" << "---------------+---------------+---------------+---------------+---------------+---------------+---------------+----------------" << "+";
		     	          	 	}
		     	          	 	else if(dimension == 7){
		     	          	 	cout << "      +" << "--------------+--------------+--------------+--------------+--------------+--------------+---------------" << "+";
		     	          	 	}
		     	          	 	else if(dimension == 6){
		     	          	 	cout << "      +" << "-------------+-------------+-------------+-------------+-------------+--------------" << "+";
		     	          	 	}
		     	          	 	else if(dimension == 5){
		     	          	    cout << "      +" << "------------+------------+------------+------------+-------------" << "+";
		     	          	 	}
		     	          	 	else if(dimension == 4){
		     	          	 	cout << "      +" << "-----------+-----------+-----------+------------" << "+";
		     	          	 	}
		     	          	 	else if(dimension == 3){
		     	          	 	cout << "      +" << "----------+----------+-----------" << "+";
		     	          	 	}
		     	          	 	else {
		     	          	 	cout << "      +" << "---------+----------" << "+";
		     	          	 	}

		     	          		cout << endl;
		     	          	}

 }
  /*
   * Getters
   */

 int Grille :: obtenirValeur (int ligne, int colonne){
	 return tableau[ligne][colonne];
 }

 int Grille :: obtenirLigne(){
	 return this->ligne;
 }
 int Grille :: obtenirColonne(){
	 return this->colonne;
 }
 /*
  * Setters
  */
 void Grille :: modifierLigne(int ligne){
	 this->ligne = ligne ;
 }
 void Grille :: modifierColonne(int colonne){
	 this->colonne = colonne;
 }
 void  Grille :: modifierTableau (int ligne, int colonne, int valeur){
 	 tableau[ligne][colonne] = valeur;
  }
 /*
  * Destructeur de grille
  */
 Grille :: ~Grille(){
 for (int i = 0; i<dimension ; i++){
	 delete[] tableau [i];
   }
    delete tableau;
 }


/*
 * constructeur de copies
 */

 Grille :: Grille( const Grille & g){
 this ->germe = g.germe;
 this ->dimension = g.dimension;
     for(int i = 0; i < dimension; ++i) {
         for(int j = 0; j < dimension; ++j ) {
           tableau[i][j] = g.tableau[i][j];
        }//fin for(j)
 } //fin for(i)


 }



