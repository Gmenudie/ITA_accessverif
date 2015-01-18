/* 
 * File:   Transition.cpp
 * Author: Merwane
 *
 * Created on 11 janvier 2015, 16:43
 */



#include <list>
#include <iostream>
#include <string>
#include <ppl.hh>
#include "Transition.h"
#include "Etat.h"

using namespace Parma_Polyhedra_Library;
using namespace std;
        
Transition::Transition(){
    conditions =NNC_Polyhedron();
    predecesseur =new Etat;
    successeur = new Etat;
    assignements = list<Assignement>();
}

Transition::Transition(NNC_Polyhedron cond, Etat* pred, Etat* succ, list<Assignement> ass): 
conditions(cond), predecesseur(pred), successeur(succ), assignements(ass)
{}

Parma_Polyhedra_Library::NNC_Polyhedron Transition::getConditions(){
	return conditions;
} 

Etat* Transition::getSuccesseur(){
	return successeur;
}

std::list<Assignement> Transition::getAssignements(){
	return assignements;
}

void Transition::setPredecesseur(Etat* pred){
        predecesseur = pred;
    }

void Transition::setSuccesseur(Etat* succs){
    successeur = succs;
}

void Transition::setConditions(NNC_Polyhedron cond){
        conditions=cond;
    }

void Transition::setAssignements(list<Assignement> assi){
        assignements=assi;
    }

        
                 
    


