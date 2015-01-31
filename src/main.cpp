/* 
 * File:   main.cpp
 * Author: geoffray
 *
 * Created on December 8, 2014
 */

#include <iostream>
#include <cstdlib>
#include <ppl.hh>
#include "Etat.h"
#include "Automate.h"


using namespace std;
using namespace Parma_Polyhedra_Library;
using namespace Parma_Polyhedra_Library::IO_Operators;


/*
 * 
 */
int main(int argc, char** argv) {
    
    //Déclarations de variables.
    list<EtatSymbolique> chemin;
    Automate automate;
    
    // On propose les deux modes d'affichage au lecteur
    int choix=2;
    cout << "\nChoose your mode\n [0] Normal    [1] Verbose\n";
    cin >> choix;
    while (choix!=0 && choix!=1){
        cout << "Incorrect choice! \n";
        cout << "Choose your mode\n [0] Normal    [1] Verbose\n";    
        cin >> choix;
            
    }
    
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //On charge le texte
    automate.chargerDepuisTexte();
    
    if (choix){
        automate.print();
    }

    if(automate.verifieraccessibilite(chemin,choix)){
            cout << "\n\n--------- Final state accessible! --------\n\nHere is the path: \n" ;
            list<EtatSymbolique>::iterator it;
            for (it=chemin.begin(); it!=chemin.end(); ++it){
                it->print();
                cout << endl;
            }
                    
    }
    else {
            cout << "\n\n--------- No final state accessible! -----------\n";
    } 

  return 0;
}

