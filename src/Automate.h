/* 
 * File:   Automate.h
 * Author: Merwane
 *
 * Created on 11 janvier 2015, 16:22
 */

#ifndef AUTOMATE_H
#define	AUTOMATE_H
#include <list>
#include <iostream>
#include <string>
#include <ppl.hh>
#include "Etat.h"
#include "Transition.h"
#include "EtatSymbolique.h"

 using namespace std;
using namespace Parma_Polyhedra_Library;

class Automate {
public:
   Automate(std::list<Etat> etats ,std::list<Transition> transitions , Etat etatInitial,  std::list<Etat> etatsFinaux, int dimensions, std::list<Parma_Polyhedra_Library::Variable> variables);
   Automate();
 void setDimensions(int dim);
 void setVariables(std::list<Parma_Polyhedra_Library::Variable> vars);
 
 void addEtat(Etat et);
 void addEtatInitial(Etat et);
 void addEtatFinal(Etat et);
 
 void addTransition(Transition* transition, string nompred, string nomsuccs );
 
 void chargerDepuisTexte(std::string texte);
 bool verifieraccessibilite(std::list<EtatSymbolique> chemin);
    
private:
std::list<Etat> etats;
std::list<Transition> transitions;
Etat etatInitial;
std::list<Etat> etatsFinaux;
int dimensions;
std::list<Parma_Polyhedra_Library::Variable> variables;

};


#endif	


 
