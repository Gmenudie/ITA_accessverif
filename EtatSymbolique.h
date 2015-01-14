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
    EtatSymbolique(Etat etat, Parma_Polyhedra_Library::NNC_Polyhedron horloge , EtatSymbolique* pere);
    Parma_Polyhedra_Library::NNC_Polyhedron futur();
	std::list<EtatSymbolique> successeurs();
    
	//Getters
    Etat getEtat();
    EtatSymbolique* getPere();
    Parma_Polyhedra_Library::NNC_Polyhedron getHorloge();
    
    //Setters
    void setHorloge(Parma_Polyhedra_Library::NNC_Polyhedron);
   
private:
Etat etat;
Parma_Polyhedra_Library::NNC_Polyhedron horloge ;
EtatSymbolique* pere;
};

#endif	