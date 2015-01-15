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

	list<Etat> etats;
	list<Transition> transitions;
	Etat etatInitial;
	list<Etat> etatsFinaux;
	int dimensions=2;
	list<Variable> variables;
	list<EtatSymbolique> chemin;


    for (int i=0; i!=dimensions; i++){
        Variable A(i);
        variables.push_back(A);            
    }

    Etat q0("q0", 0);
    Etat q1("q1", 0);
    Etat q2("q2", 1);

    etats.push_back(q0);
    etats.push_back(q1);
    etats.push_back(q2);
    
   

    etatInitial=q0;

    etatsFinaux.push_back(q2);

	Automate automate(etats , transitions ,  etatInitial,  etatsFinaux, dimensions, variables);

	if(automate.verifieraccessibilite(chemin)){
		cout << "Etat final accessible! Voilà le chemin!" ;
	}
	else {
		cout << "Aucun état final atteignable!";
	} 

  return 0;
}

