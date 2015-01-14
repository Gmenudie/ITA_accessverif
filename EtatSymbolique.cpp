
#include "EtatSymbolique.h"
#include <string>
#include <list>
#include <ppl.hh>

using namespace std;
using namespace Parma_Polyhedra_Library;

EtatSymbolique::EtatSymbolique(Etat etat, NNC_Polyhedron horloge , EtatSymbolique* pere): etat(etat), horloge(horloge), pere(pere)
{}

Etat EtatSymbolique::getEtat(){
	return etat; 
}

EtatSymbolique* EtatSymbolique::getPere(){
	return pere;
}

NNC_Polyhedron getHorloge(){
	return horloge
}

void setHorloge(NNC_Polyhedron new_horloge){
	horloge = new_horloge;
}

//Doit avoir acces à list<Variable> variables (à mettre en place !!!)
NNC_Polyhedron EtatSymbolique::futur(){
	Constraint_System cs;
	NNC_Polyhedron futur=horloge;
	std::list<Variable>::iterator it;
	for (it=variables.begin(); it!=variables.end(); ++it){
		if(it->id()==getEtat().getNiveau()){
			Constraint c(*it==1);
			cs.insert(c);
		}
		else{
			Constraint c(*it==0);
			cs.insert(c);
		}
	}

	futur.positive_time_elapse_assign(NNC_Polyhedron p(cs));
	return futur;    
}

std::list<EtatSymbolique> EtatSymbolique::successeurs(){

	std::list<EtatSymbolique> successeurs;
	std::list<Transition> transitions = etat.getTransitions();
	std::list<Transition>::iterator it = transitions.begin();

	for(it = transitions.begin(); it != transitions.end(); ++it){
		NNC_Polyhedron new_horloge = it->getConditions();
		new_horloge.intersection_assign(horloge);

		if(!new_horloge.is_empty()){

			EtatSymbolique successeur(it->getSuccesseur(), new_horloge, this);
			std::list<Assignement> assignements = it->getAssignements();
			std::list<Assignement>::iterator it2;

			for(it2 = assignements.begin(); it2!=assignements.end(); ++it2){
				successeur.setHorloge(successeur.getHorloge.affine_image(it2->getVariable(), it2-> getExpression()));
			}
			successeurs.push_back(successeur.futur());
		}	
	}
	return successeurs;
}
