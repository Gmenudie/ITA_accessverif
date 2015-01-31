#include "Etat.h"
#include <string>
#include <list>

using namespace std;



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

void Etat::addTransition(Transition transition){
    transitions.push_back(transition);
}

bool Etat::equals(Etat et){
    return (this->nom==et.getNom() && this->niveau == et.getNiveau());
}

void Etat::print(){
   
    cout << "State " + this->getNom() + " , level " << this->getNiveau() << "\n";
}
    
void Etat::printWithTransitions(){
   
    list<Transition>::iterator it;
    cout << "State " + this->getNom() + " , level " << this->getNiveau() << "\n";
    
    for (it=transitions.begin(); it!=transitions.end(); ++it ){
       it->print();
    }
}
