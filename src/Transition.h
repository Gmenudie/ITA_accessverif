/* 
 * File:   Transition.h
 * Author: Merwane
 *
 * Created on 11 janvier 2015, 16:43
 */

#ifndef TRANSITION_H
#define	TRANSITION_H

#include <list>
#include <string>
#include <ppl.hh>
#include "Assignement.h"

class Etat;

class Transition {
public:
    Transition(Parma_Polyhedra_Library::NNC_Polyhedron cond, Etat* pred, Etat* succ, std::list<Assignement> ass); 

    Parma_Polyhedra_Library::NNC_Polyhedron getConditions(); 
    Etat* getSuccesseur(); 
    std::list<Assignement> getAssignements();
    
    void setPredecesseur(Etat* pred);
    void setSuccesseur(Etat* succs);
    void setConditions(Parma_Polyhedra_Library::NNC_Polyhedron cond);
    void setAssignements(std::list<Assignement> assi);
   
    
private:
Parma_Polyhedra_Library::NNC_Polyhedron conditions;
Etat* predecesseur;
Etat* successeur;
std::list<Assignement> assignements;
};

#endif	/* ASSIGNEMENT_H */
                 
    

