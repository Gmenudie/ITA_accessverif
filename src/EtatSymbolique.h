/* 
 * File:   EtatSymbolique.h
 * Author: Merwane
 *
 * Created on 11 janvier 2015, 16:46
 */

#ifndef ETATSYMBOLIQUE_H
#define	ETATSYMBOLIQUE_H
#include <list>
#include <string>
#include <ppl.hh>
#include "Etat.h"

class EtatSymbolique{
public :    
    EtatSymbolique(Etat* etat, Parma_Polyhedra_Library::NNC_Polyhedron horloge , EtatSymbolique* pere);
    void futur(std::list<Parma_Polyhedra_Library::Variable> variables);
	std::list<EtatSymbolique> successeurs(std::list<Parma_Polyhedra_Library::Variable> variables);
	bool inclus(EtatSymbolique es);
        bool hasPere();
        void resetClocks(std::list<Parma_Polyhedra_Library::Variable> variables);
    
    //Getters
    Etat* getEtat();
    EtatSymbolique* getPere();
    Parma_Polyhedra_Library::NNC_Polyhedron getHorloge();
    
    //Setters
    void setHorloge(Parma_Polyhedra_Library::NNC_Polyhedron);
    
    void print();
    void printWithTransitions();
   
private:
Etat* etat;
Parma_Polyhedra_Library::NNC_Polyhedron horloge ;
EtatSymbolique* pere;
};

#endif	