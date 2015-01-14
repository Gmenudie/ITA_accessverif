
#include "Etat.h"
#include <string>
#include <list>



Etat::Etat (std::string nom, int niveau, std::list<Transition> transitions):nom(nom), niveau(niveau), transitions(transitions)
{

}

int Etat::getNiveau(){
	return niveau;
}

std::list<Transition> Etat::getTransitions(){
	return transitions; 
}

