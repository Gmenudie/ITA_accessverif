
#include "Etat.h"
#include <string>
#include <list>



Etat::Etat (std::string nom, int niveau, std::list<Transition> transitions):nom(nom), niveau(niveau), transitions(transitions)
{

}

Etat::Etat(){
    nom="Default name";
    niveau=0;
   
}

Etat::Etat(std::string name, int niv){
    nom=name;
    niveau=niv;   
}

int Etat::getNiveau(){
	return niveau;
}

std::string Etat::getNom(){
	return nom;
}

std::list<Transition> Etat::getTransitions(){
	return transitions; 
}

bool Etat::equals(Etat et){
    return (this->nom==et.getNom() && this->niveau == et.getNiveau());
}

