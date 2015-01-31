
#include "EtatSymbolique.h"
#include <string>
#include <list>
#include <ppl.hh>

using namespace std;
using namespace Parma_Polyhedra_Library;

EtatSymbolique::EtatSymbolique(Etat* etat, NNC_Polyhedron horloge , EtatSymbolique* pere): etat(etat), horloge(horloge), pere(pere)
{}

Etat* EtatSymbolique::getEtat(){
	return etat; 
}

EtatSymbolique* EtatSymbolique::getPere(){
	return pere;
}

NNC_Polyhedron EtatSymbolique::getHorloge(){
	return horloge;
}

void EtatSymbolique::setHorloge(NNC_Polyhedron new_horloge){
	horloge = new_horloge;
}

void EtatSymbolique::print(){
    cout << "Symbolic ";
    etat->print();
    cout << "Clock associated: ";
    horloge.print();   
    cout << endl;
}

void EtatSymbolique::printWithTransitions(){
    cout << "Symbolic ";
    etat->printWithTransitions();
    cout << "Clock associated: ";
    horloge.print();   
    cout << endl;
}


bool EtatSymbolique::inclus(EtatSymbolique es){
	if (!etat->equals(*(es.getEtat()))){
		return false;
	}
	else {
		return es.getHorloge().contains(horloge);

	}
}

bool EtatSymbolique::hasPere(){
    return (pere!=NULL);
}

void EtatSymbolique::resetClocks(list<Variable> variables){
    std::list<Variable>::iterator it;
    for (it=variables.begin(); it!=variables.end(); ++it){
        if(it->id() > etat->getNiveau()){
            horloge.affine_image(*it, Linear_Expression(0));
        }
    }
}


void EtatSymbolique::futur(list<Variable> variables){
	Constraint_System cs;
	std::list<Variable>::iterator it;

	//Construit un polyedre avec 0 sur toutes les variables et 1 sur la variable à étendre
	for (it=variables.begin(); it!=variables.end(); ++it){
		if(it->id()==etat->getNiveau()){
			Constraint c(*it==1);
			cs.insert(c);
		}
		else{
			Constraint c(*it==0);
			cs.insert(c);
		}
	}
        
        NNC_Polyhedron p(cs);
        NNC_Polyhedron nhorloge(this->getHorloge());
        nhorloge.positive_time_elapse_assign(p);
	this->setHorloge(nhorloge);   
}

std::list<EtatSymbolique> EtatSymbolique::successeurs(std::list<Variable> variables){

	std::list<EtatSymbolique> successeurs;
	std::list<Transition> transitions = etat->getTransitions();
	std::list<Transition>::iterator it = transitions.begin();

	//On essaie de franchir chaque transition
	for(it = transitions.begin(); it != transitions.end(); ++it){
		NNC_Polyhedron new_horloge(it->getConditions());
		new_horloge.intersection_assign(horloge);   //Intersection entre l'horloge de l'Etat symbolique et le polyedre des conditions

		//Si l'intersection n'est pas nulle, on franchit la transition et on fait les assignements
		if(!new_horloge.is_empty()){
                    Etat* succ = it->getSuccesseur();

			EtatSymbolique successeur(succ, new_horloge, this);
			std::list<Assignement> assignements = it->getAssignements();
			std::list<Assignement>::iterator it2;

			for(it2 = assignements.begin(); it2!=assignements.end(); ++it2){
                            NNC_Polyhedron nhorloge(successeur.getHorloge());
                            nhorloge.affine_image(it2->getVariable(), it2-> getExpression());
                            successeur.setHorloge(nhorloge);
			}
                        
                        // Si la priorité de l'état successeur est inférieure à celle actuelle, il faut réinitialiser des horloges.
                        if(succ->getNiveau() < etat->getNiveau()){
                            successeur.resetClocks(variables);
                        }
                        
                        successeur.futur(variables);
			successeurs.push_back(successeur);
		}	
	}
        
	return successeurs;
}
