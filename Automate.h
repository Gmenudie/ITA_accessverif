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


class Automate {
public:
   Automate(std::list<Etat> etats ,std::list<Transition> transitions , Etat etatInitial,  std::list<Etat> etatsFinaux, int dimensions);
 //  Automate chargerDepuisTexte(std::string texte);
 std::list<Etat> verifieraccessibilite();
    
private:
std::list<Etat> etats;
std::list<Transition> transitions;
Etat etatInitial;
std::list<Etat> etatsFinaux;
int dimensions;

};


#endif	


 
