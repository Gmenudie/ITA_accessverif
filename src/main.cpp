/* 
 * File:   main.cpp
 * Author: geoffray
 *
 * Created on December 8, 2014, 9:43 AM
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
    bool ver=1;
    list<EtatSymbolique> chemin;
    Automate automate;
    
    

    automate.chargerDepuisTexte();
    automate.print();

    if(automate.verifieraccessibilite(chemin,ver)){
            cout << "--------- Final state accessible! --------\n\nHere is the path: \n" ;
            list<EtatSymbolique>::iterator it;
            for (it=chemin.begin(); it!=chemin.end(); ++it){
                it->print();
            }
                    
    }
    else {
            cout << "--------- No final state accessible! -----------\n";
    } 

  return 0;
}

