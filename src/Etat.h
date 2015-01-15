#ifndef ETAT_H
#define	ETAT_H
#include <list>
#include <string>
#include "Transition.h"



class Etat {
public:
    Etat(std::string nom, int niveau, std::list<Transition> transitions);
    Etat();
    Etat(std::string nom, int niveau);

    int getNiveau();
    std::string getNom();
    std::list<Transition> getTransitions();
    bool equals(Etat et);
    
private:
std::string nom;
int niveau;
std::list<Transition> transitions;
};


#endif
    
