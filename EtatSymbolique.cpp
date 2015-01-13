
#include "EtatSymbolique.h"
#include <string>
#include <list>
#include <ppl.hh>
using namespace std;
using namespace Parma_Polyhedra_Library;
EtatSymbolique::EtatSymbolique(Etat* etat, NNC_Polyhedron horloge , EtatSymbolique* pere): etat(etat), horloge(horloge), pere(pere)
{}
/*EtatSymbolique::futur()
{
    
}
EtatSymbolique::successeurs()
{


}*/
