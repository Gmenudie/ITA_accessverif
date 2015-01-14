#ifndef ETAT_H
#define	ETAT_H
#include <list>
#include <string>


class Transition;

class Etat {
public:
    Etat(std::string nom, int niveau, std::list<Transition> transitions);

    int getNiveau();
    std::list<Transition> getTransitions();
    
private:
std::string nom;
int niveau;
std::list<Transition> transitions;
};


#endif
    
