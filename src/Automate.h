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



class Automate {
public:
   Automate(std::list<Etat> etats , Etat* etatInitial,  std::list<Etat> etatsFinaux, int dimensions, std::list<Parma_Polyhedra_Library::Variable> variables);
   Automate();
 
 int  getDimensions();  
   
 void setDimensions(int dim);
 void setVariables(std::list<Parma_Polyhedra_Library::Variable> vars);
 
 void addEtat(Etat et);
 void addEtatInitial(Etat et);
 void addEtatFinal(Etat et);
 
 void addTransition(Transition* transition, std::string nompred, std::string nomsuccs );
 
 void print();
 
 void chargerDepuisTexte();
 bool verifieraccessibilite(std::list<EtatSymbolique> &chemin, bool ver);
    
private:
std::list<Etat> etats;
Etat* etatInitial;
std::list<Etat> etatsFinaux;
int dimensions;
std::list<Parma_Polyhedra_Library::Variable> variables;

};


#endif	


 
