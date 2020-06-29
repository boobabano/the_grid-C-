/* ex.cpp
 *
 *  Created on: 2010-02-04
 *      Author: bf891332
 */

/*
 * ex.cpp
 *
 *  Created on: 2010-02-04
 *      Author: bf891332
 */

#include <iostream> // pour pouvoir utiliser cout
#include <iomanip>  // pour pouvoir utiliser setw
#include <cstdlib>
#include "OutilsTp1.hpp"
#include "Grille.hpp"
#include "Joueur.hpp"
#include <string>

using namespace std;

  static const int VALEUR_VIDE = 99;
 /*
  * methode permattant de saisir le germe pour initialiser
  * la procedure aléatoire elle retourne un int qui est le germe
  * */
  int saisirGerme();
  /*
   * methode permettant de valider l'entrée de caractères
   * different des entiers elle prend en paramètres la
   * variable entière a valider et retourne un int
   */
  int validerInteger(int & variable);
  /*
   * methode permettant de valider la dimension de la
   * grille de jeu elle retourne la taille de la grille
   */
  int validerTailleGrille();
  /*
   * methode permettant de saisir le nom du joueur
   * elle prend en paramètres le nom et la chaine de
   * caractères qui va avec.elle retourne le nom du joueur
   */
  string saisirNom(string nom ,string message);
  /*
   * methode permettant de d'afficher le menu de jeu
   * elle ne retourne rien et prend en paramètre le
   * nom du joueur
   */
  void afficherMenu(string nom);
  /*
   * methode permettant de valider le choix de jeu
   * elle retourne le choix
   */
  int validerChoix();
  /*
   * methode permettant de valider la reponse du
   * joueur a savoir si il doit commencer ou non
   * elle retourne la reponse dans une string
   * et prend en parametre une string qui va contenir
   * la reponse du joueur
   */
  string validerReponse(string reponse);
  /*
   * methode qui permet a l'ordinateur de jouer sur la colonne
   * elle prend en paramètre la dimension de la grille, la grille
   * le numero de ligne saisi par le joueur ,le joueur lui meme
   * et un pointeur qui determine la fin du jeu cette methode
   * retourne le numero de colonne joué par l'ordinateur
   */
  int jouerOrdinateurC(int dimension,Grille  &uneGrille,int noLigne, Joueur &Joueur2,int *finJeu);
  /*
   * methode qui permet a l'ordinateur de jouer sur la ligne
   * elle prend en paramètre la dimension de la grille, la grille
   * le numero de colonne saisi par le joueur ,le joueur lui meme
   * et un pointeur qui determine la fin du jeu cette methode
   * retourne le numero de ligne joué par l'ordinateur
   */
  int jouerOrdinateurL(int dimension,Grille &uneGrille,int noColonne,Joueur Joueur1, Joueur &Joueur2,int *finJeu);
  /*
   * nethode qui permet au jouer de jouer sur la colonne,cette
   * methode prend en paramètre la dimension de la grille, la
   * grille, le joueur1,le joueur2 ,le numero de la ligne saisie
   * par l'autre joueur, la reponse pour decider lequel des joueurs
   * va commencer la colonne, le choix , et un pointeur pour determiner
   * la fin de jeu,elle retourne le numero de ligne saisi par le joueur
   */
  int  jouerColonne(int dimensionSaisie,Grille  &uneGrille, Joueur &Joueur1,Joueur &Joueur2, string reponse,
	int noLigne,int *finJeu, int choix);
  /*
     * methode qui permet au jouer de jouer sur la ligne,cette
     * methode prend en paramètre la dimension de la grille, la
     * grille, le joueur1,le joueur2 ,le numero de la colonne saisie
     * par l'autre joueur, la reponse pour decider lequel des joueurs
     * va commencer la ligne, le choix , et un pointeur pour determiner
     * la fin de jeu, elle retourne le numero de colonne saisi par le joueur
     */
  int  jouerLigne(int dimensionSaisie,Grille  &uneGrille, Joueur &Joueur1,Joueur &Joueur2, string reponse,
	int noColonne,int *finJeu,int choix);
     /*
      * cette methode permet de lancer le jeu contre l'ordinateur, en alternant l'ordinateur et le
      * joueur elle contient les appels de methodes ordinateurC,ordinateurL,jouerLigne et jouerColonne
      * elle prend en paramètres la grille, la dimension de la grille, le joueur1, le joueur2,la reponse
      * et le choix ,cette methode est void donc ne retourne rien
      */
  void jouerContreOrdinateur(Grille  &uneGrille,Joueur &Joueur1,Joueur &Joueur2,int dimension,string reponse,int choix);
     /*cette methode permet de lancer le jeu a 2 joueurs en faisant appel aux methodes JouerLIgne et jouerColonne
      * elle prend en paramètres la grille ,le joueur1, le joueur2, la dimension de la grille, la reponse et le choix
      * elle ne retourne aucune valeur
     */
  void multiJoueurs(Grille  &uneGrille,Joueur &Joueur1,Joueur &Joueur2,int dimension,string reponse,int choix);
     /*cette methode permet d'afficher les statistiques des joueur lorsque le jeu est terminé, elle prend en paramètres
      * le joueur1 , le joueur2 et le choix
      * cette methode ne retourne rien
      */
  void affichageStatistiques(Joueur &Joueur1, Joueur & Joueur2,int choix);


  int main(){
    int germe = 0;
	string nom="";
	string reponse="";
	string nom2="";
	int pointage =0 ;
	string message="";

              int germeSaisi =  saisirGerme();//appel de la methode saisir germe
              validerInteger(germe);// appel de la methode validerInteger
              int dimensionSaisie = validerTailleGrille();//appel de la methode validerTailleGrille

              string nomSaisi = saisirNom(nom,"veuillez entrer votre nom:");// appel de la methode saisirNom
              Joueur Joueur1(nomSaisi,pointage);//appel du constructeur joueur pour creer le joueur1
              afficherMenu(nomSaisi);// appel de la methode afficherMenu
              int choixSaisi = validerChoix();// appel de la methode validerChoix
              string reponseSaisie= validerReponse(reponse);// appel de la methode validerReponse


            if(choixSaisi == 1){

               string nomSecond = saisirNom(nom,"veuillez entrer le nom de l'autre joueur");// appel de la methode saisirNom
               Joueur Joueur2 (nomSecond,pointage);//appel du constructeur joueur pour creer le joueur2
               Grille  uneGrille (germeSaisi,dimensionSaisie);// appel au constructeur de Grille
               uneGrille.modifierTableau(0,0,VALEUR_VIDE);// initialisation de la premiere case du tableau a VALEUR_VIDE
               uneGrille.afficherGrille();// appel a la methode affichergrille
               multiJoueurs(uneGrille,Joueur1,Joueur2,dimensionSaisie,reponseSaisie,choixSaisi);// appel de la methode multiJoueurs

               affichageStatistiques(Joueur1,Joueur2,choixSaisi);// appel de la methode affichageStatistiques
               uneGrille.~Grille(); // appel du destructeur de grille a la fin du jeu
			}else {
			   Joueur Joueur2;// creation d'un joueur sans parametre par default qui est l'ordinateur
               Grille  uneGrille (germeSaisi,dimensionSaisie);// appel au constructeur de grille
               uneGrille.modifierTableau(0,0,VALEUR_VIDE);//initialisation de la premiere case du tableau a VALEUR_VIDE
               uneGrille.afficherGrille();// appel a la methode affichergrille

               jouerContreOrdinateur(uneGrille,Joueur1,Joueur2,dimensionSaisie,reponseSaisie,choixSaisi);// appel a lla methode jouerContreOrdinateur

               affichageStatistiques(Joueur1,Joueur2,choixSaisi);// appel de la methode affichageStatistiques
               uneGrille.~Grille();// appel du destructeur de grille a la fin du jeu
				}




}//main




   int saisirGerme(){
	   int germe = 0;
	   cout<<"Debut du programme" <<endl;
	   cout<<"Veuillez entrer un nombre pour initialiser la procédure aléatoire:" << endl;
	   cin>> germe ;
	  return germe;
    }

   int validerInteger(int & variable){
       cin.clear();
       cin.ignore(numeric_limits<int>::max(), '\n');

      while (!cin || cin.gcount() != 1) {
        cout << "entree invalide, recommencez : ";
        cin>> variable ;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');

       }
       cin.clear();
     return variable;
   }
    int validerTailleGrille(){
      int dimension = 0;
	    do{
	  	   cout<< "veuillez entrer la dimension de la grille entre 2 et 8 inclusivement"<< endl;
	  	   cin>>dimension;
	  	   dimension = validerInteger(dimension);
	  	   if(dimension < 2 || dimension > 8){
	  		  cout<< "la taille de la grille est inclusivement entre 2 et 8"<<endl;
	  	     }
	      }while(dimension < 2 || dimension > 8);

	  return dimension;
        }
     string saisirNom(string nom ,string message){
    	  cout<< message << endl;
    	  cin>> nom;

    	  return nom;
      }

      void afficherMenu(string nom){
    	  cout<< nom + " ,choisissez l'une des options suivantes:"<< endl;
    	  cout<<"1-Jeu a deux joueurs."<<endl;
    	  cout<<"2-Jeu avec l'ordinateur."<<endl;
      }
       int validerChoix(){
    	   int choix=0;
    	   do{
    	   	  cout<<"votre choix:"<< endl;
    	   	  cin>>choix;
    	   	  choix = validerInteger(choix);
    	   	  if(choix != 1 && choix!= 2){
    	   		  cout<<"votre choix est incorrect"<< endl;
    	   	    }
    	   	 }while(choix != 1 && choix!= 2);
	  return choix;
      }
       string validerReponse(string reponse){

    	   do{
    	   	  cout<<"voulez vous commencer (Oui ou Non):"<<endl;
    	   	  cin>> reponse;

    	   	  if((reponse.compare("oui")!= 0) && (reponse.compare("non")!=0)){

    	   		   cout<<" votre reponse est incorrecte"<<endl;
    	   	    }
    	   }while((reponse.compare("oui")!= 0) && (reponse.compare("non")!=0));

    	   return reponse;
       }

       int jouerOrdinateurC(int dimension,Grille  &uneGrille,int noLigne, Joueur &Joueur2,
    		   int *finJeu){
           int pointage;
           int temp,temp1;
           int max ;
           int max1 = -10;
           int tab[dimension];
           int noColonne;
           int nbre;
           bool verif1 = false;
           int nombre;

           for(int j = 0 ; j < dimension && !verif1; j++){
           //verification pour la colonne
                nombre = uneGrille.obtenirValeur(noLigne,j);
              if(nombre != VALEUR_VIDE){
                   verif1 = true;
                 }
           	}
           if(verif1){
             for(int j = 0; j < dimension;++j) {
                for(int i = 0; i < dimension;++i) {
                   if(uneGrille.obtenirValeur(i,j) != 99 && i != noLigne) {
                       max = uneGrille.obtenirValeur(i,j);
                       if(max > max1) {
                          max1 = max;
                       }
                   }
                 }//fin for de i
                 temp = uneGrille.obtenirValeur(noLigne,j);
                 if(temp != 99) {
					 temp1 = temp - max1;
					 tab[j] = temp1;
				  }else{
				     tab[j] = temp;
				  }
                 max1 = -10;

              }//fin for j
              max = -10;
              noColonne = 0;
              for(int i = 0;i < dimension;++i) {
            	  if(tab[i] != 99 && tab[i] > max ) {
                      max = tab[i];
                      noColonne = i;
                 }
              }

              nbre = uneGrille.obtenirValeur(noLigne,noColonne);
              pointage = Joueur2.obtenirPointage() + nbre;

              Joueur2.modifierPointage(pointage);
              uneGrille.modifierTableau(noLigne,noColonne,99);

              uneGrille.afficherGrille();


              cout << "Ordinateur" << endl;
              cout << pointage << endl;
              }
              else{
                 *finJeu = 1;
               }
              return noColonne;
       }

       int jouerOrdinateurL(int dimension,Grille &uneGrille,int noColonne,Joueur Joueur1,
    		   Joueur &Joueur2,int *finJeu){
                 int pointage;
                 int temp,temp1;
                 int max ;
                 int max1 = -10;
                 int tab[dimension];
                 int noLigne;
                 int nbre;
                 bool verif1 = false;
                 int nombre;

                for(int i = 0 ; i<dimension && !verif1; i++){
                //verification pour la ligne
                nombre = uneGrille.obtenirValeur(i,noColonne);
               if(nombre != VALEUR_VIDE){
                   verif1 = true;
                 	}
                 }

                if(verif1){

                 for(int i = 0; i < dimension;++i){
                    for(int j = 0; j < dimension;++j) {
                        if(uneGrille.obtenirValeur(i,j) != 99 && i != noColonne) {
                             max = uneGrille.obtenirValeur(i,j);
                             if(max > max1) {
                                max1 = max;
                             }
                         }
                       }//fin for de i
                       temp = uneGrille.obtenirValeur(i,noColonne);
                       if(temp != VALEUR_VIDE) {
      					 temp1 = temp - max1;
      					 tab[i] = temp1;
      				  }else{
      				     tab[i] = temp;
      				  }
                       max1 = -10;

                    }//fin for j
                    max = -10;
                    noLigne = 0;
                    for(int j = 0;j < dimension;++j) {
                  	   if(tab[j] != VALEUR_VIDE && tab[j] > max ) {
                          max = tab[j];
                          noLigne = j;
                       }
                    }

                    nbre = uneGrille.obtenirValeur(noLigne,noColonne);
                    pointage = Joueur2.obtenirPointage() + nbre;
                    Joueur2.modifierPointage(pointage);
                    uneGrille.modifierTableau(noLigne,noColonne,VALEUR_VIDE);
                    uneGrille.afficherGrille();
                    cout << "Ordinateur" << endl;
                    cout << pointage << endl;

                }
                else{
                	*finJeu = 1;
                }
                return noLigne;
             }
       int  jouerColonne(int dimensionSaisie,Grille  &uneGrille, Joueur &Joueur1,Joueur &Joueur2, string reponse,
    	int noLigne,int *finJeu, int choix){
       	 int pointage = 0;
         int temp=0;
       	 int noColonne = 0;
       	 int nbre = 0;
       	 int nombre;
         bool verif1 = false;
         string valeur = "";

         if(reponse.compare("non")==0  && choix == 1) {
             valeur = Joueur2.obtenirNom();
          }
           else {
              valeur = Joueur1.obtenirNom();
          }
          for(int j = 0 ; j < dimensionSaisie && !verif1; j++){    //verification pour la colonne
            	nombre = uneGrille.obtenirValeur(noLigne,j);
            	if(nombre != VALEUR_VIDE){
            	   verif1 = true;
            	}
		   }
           if (verif1) {
              do {
                  cout<< valeur + " , >> veuillez entrer le numero de la colonne de la case choisie:";
                  cin>>noColonne;
                  validerInteger(noColonne);

                  if(noColonne > dimensionSaisie-1 || noColonne < 0 ||
                		  uneGrille.obtenirValeur(noLigne,noColonne) == VALEUR_VIDE){
                      cout<<"erreur choix invalide "<< endl;
                  }
            	}while(noColonne > dimensionSaisie-1 || noColonne < 0 ||
            			uneGrille.obtenirValeur(noLigne,noColonne) == VALEUR_VIDE);


				if(reponse.compare("non")==0  && choix == 1){
				   nbre = Joueur2.obtenirPointage();
				}
				else{
				   nbre = Joueur1.obtenirPointage();
				}

				temp = pointage;
				pointage  = uneGrille.obtenirValeur(noLigne,noColonne) + nbre;
				uneGrille.modifierColonne(noColonne);
				if ((pointage != VALEUR_VIDE) && (reponse.compare("non")==0 )  && (choix == 1)){
                    Joueur2.modifierPointage(pointage);

				}
				 else if(pointage != VALEUR_VIDE){
                      Joueur1.modifierPointage(pointage);

				 }
                 uneGrille.modifierTableau(noLigne,noColonne,VALEUR_VIDE);
                 uneGrille.afficherGrille();
                 if(reponse.compare("non")==0  && choix == 1) {
                    cout<< valeur << endl;
                    cout<< Joueur2.obtenirPointage() << endl;

                  }
                  else {
                      cout<< valeur << endl;
                      cout<< Joueur1.obtenirPointage() << endl;

                  }
            }else {
            	*finJeu = 1;
            }

           return noColonne;
         }


    int  jouerLigne(int dimensionSaisie,Grille  &uneGrille, Joueur &Joueur1,Joueur &Joueur2,
    		string reponse,int noColonne,int *finJeu,int choix){
           string valeur = "";
    	   int noLigne =0;
    	   int pointage2 = 0;

    	   int nbre = 0;
    	   int nombre;
    	   bool verif1 = false;
		if(reponse.compare("non")==0 || choix == 2) {
		   valeur = Joueur1.obtenirNom();
		 }
		else {
		   valeur = Joueur2.obtenirNom();
		 }

	     for(int i = 0 ; i < dimensionSaisie && !verif1; i++) { //verification pour la ligne
			nombre = uneGrille.obtenirValeur(i,noColonne);
		    if(nombre != VALEUR_VIDE){
				verif1 = true;

			}
		  }

		  if(verif1) {

			do{
				do{
					cout<< valeur + " , >> veuillez entrer le numero de la ligne de la case choisie:";
					cin>>noLigne;
					validerInteger(noLigne);

					if(noLigne > dimensionSaisie-1 || noLigne < 0  ||
							(uneGrille.obtenirValeur(noLigne,noColonne)== VALEUR_VIDE )){
						cout<<"erreur choix invalide "<< endl;

										}
					}while(noLigne > dimensionSaisie-1 || noLigne < 0 ||
							(uneGrille.obtenirValeur(noLigne,noColonne)== VALEUR_VIDE ));


					if(reponse.compare("non")==0 || choix == 2){
						nbre = Joueur1.obtenirPointage();
					}
					else{
						nbre = Joueur2.obtenirPointage();
					}
						pointage2 = uneGrille.obtenirValeur(noLigne,noColonne)+ nbre;
						uneGrille.modifierLigne(noLigne);
					if ((pointage2 != VALEUR_VIDE && (reponse.compare("non")==0))  || (choix == 2)){
						Joueur1.modifierPointage(pointage2);
					}
					else{
						Joueur2.modifierPointage(pointage2);
					}
					if( pointage2 == VALEUR_VIDE){
						cout<<"erreur choix invalide "<< endl;
					}

					}while( pointage2 == VALEUR_VIDE);

					uneGrille.modifierTableau(noLigne,noColonne,VALEUR_VIDE);
					uneGrille.afficherGrille();

					if(reponse.compare("non")==0 || choix == 2) {
		               valeur = Joueur1.obtenirNom();
		               cout<< valeur <<endl;
		               cout<< Joueur1.obtenirPointage() << endl;
		               cout<<endl;
					  }
				     else {
					   cout<< valeur <<endl;
					   cout<< Joueur2.obtenirPointage() << endl;
					   cout<<endl;
				     }
			}else {
				*finJeu = 1;
			}

		     return noLigne;
		   }
     void jouerContreOrdinateur(Grille  &uneGrille,Joueur &Joueur1,Joueur &Joueur2,
       int dimension,string reponse,int choix){
        int colonneSaisie =0;
        int ligneSaisie = 0;
        int finJeu = 0;

        do{
        	if(!finJeu)
        		  if(reponse.compare("non")== 0){
                  colonneSaisie  = jouerOrdinateurC(dimension,uneGrille,ligneSaisie,Joueur1,&finJeu);
        	      ligneSaisie = jouerLigne(dimension,uneGrille,Joueur1,Joueur2,reponse,colonneSaisie,
        	    		  &finJeu,choix);
        		  }
        		  else{
        			colonneSaisie =jouerColonne(dimension,uneGrille,Joueur1,Joueur2,reponse,ligneSaisie,
        					&finJeu,choix);

        			ligneSaisie = jouerOrdinateurL(dimension,uneGrille,colonneSaisie,Joueur1,Joueur2,
        					&finJeu);
        		  }
        	     }while(!finJeu);
           }

     void multiJoueurs(Grille  &uneGrille,Joueur &Joueur1,Joueur &Joueur2,int dimension,
    		 string reponse,int choix){
      int finJeu = 0;
      int colonneSaisie =0;
      int ligneSaisie = 0;
      do{
        if(!finJeu)
        	colonneSaisie =jouerColonne(dimension,uneGrille,Joueur1,Joueur2,reponse,
        			ligneSaisie,&finJeu,choix);
        	if(!finJeu)
        	  ligneSaisie = jouerLigne(dimension,uneGrille,Joueur1,Joueur2,reponse,
        			  colonneSaisie,&finJeu,choix);
        }while(!finJeu);

    }

    void affichageStatistiques(Joueur &Joueur1, Joueur & Joueur2,int choix){

    	cout<<endl;
    	cout<<endl;
    	cout<<"La partie est terminée voici les resultats:"<< endl;

        if(choix == 1)
    	  cout<< (Joueur1.obtenirNom() + " a :");
    	  cout<< Joueur1.obtenirPointage()<<  " points " << endl;
    	  cout<< (Joueur2.obtenirNom() + " a :");
    	  cout<< Joueur2.obtenirPointage()<< " points "<< endl;
    	  cout<<endl;
    	  cout<<endl;
    	  if(Joueur1.obtenirPointage() > Joueur2.obtenirPointage()){
    	      cout<<"le gagnant est " + Joueur1.obtenirNom() << endl;
    	    }
    	  else{
    	     cout<<"le gagnant est " + Joueur2.obtenirNom()<< endl;
    	    }

    	   cout<<"Fin du programme";


       /*if(choix == 2) {
    	        cout<< (Joueur1.obtenirNom() + " a :");
    	    	cout<< Joueur1.obtenirPointage()<<  " points " << endl;
    	    	cout<< (Joueur2.obtenirNom() + " a :");
    	    	cout<< Joueur2.obtenirPointage()<< " points "<< endl;
    	    	cout<<endl;
    	    	cout<<endl;
        }*/
    }

   /* void validerPriorite(){


    }*/

