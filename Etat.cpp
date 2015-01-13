
#include "Etat.h"
#include <string>
#include <list>

using namespace std;


Etat::Etat (string nom, int niveau, list<Transition*> transitions):nom(nom), niveau(niveau), transitions(transitions)
{

}

