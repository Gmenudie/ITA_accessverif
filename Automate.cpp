/* 
 * File:   Automate.cpp
 * Author: Merwane
 * 
 * Created on 11 janvier 2015, 16:22
 */

#include "Automate.h"
#include <string>
#include <list>
#include <queue>
#include "EtatSymbolique.h"

Automate::Automate(std::list<Etat*> listeetats, std::list<Transition*>listetransitions , Etat* Etatinitial, Etat* Etatfinal, int dimensions) : 
listeetats(listeetats), listetransitions(listetransitions), Etatinitial(Etatinitial), Etatfinal(Etatfinal), dimensions(dimensions){
}

/* Automate Automate::chargerDepuisTexte(std::string texte){
//Algorithme qui charge le texte
}
 */



/* Implémente l'algorithme de vérification d'accessibilité des états finaux.

Automate::verifieraccessibilite(){
    
    //Variables locales:
    
std::queue<EtatSymbolique> aTraiter;
std::list<EtatSymbolique> traites, chemin;
bool atteignable, fini;
EtatSymbolique etatExamine(etatInitial, Polyedre horloge_nulle);

//Début: on met en pile l'état initial et on initialise les variables
aTraiter.push(etatExamine.futur())
atteignable <- faux
Traitement:
On dépile, et tant que l'état examiné n'est pas final on empile ses successeurs possibles
Tant que ( !pilevide & !atteignable )
etatExamine <- pile.dépile()
Si (etatExamine appartient à etatFinal )
On est parvenus à un état final, on enregistre le chemin en remontant de père en père jusqu'à
l'état initial (le seul dont le père est nul)
Tant que (etatExamine.pere non nul)
chemin.add(etatExamine)
etatExamine=etatExamine.pere
Fin Tant que
atteignable <- vrai
Sinon Si (etatExamine appartient à traites)
L'état a déjà été traité, on l'ignore
Sinon
L'état n'est pas final, on ajoute ses successeurs à la pile
traites.add(etatExamine)
Pour tout successeur dans etatExamine.successeurs()
pile.empile(succeur.futur())
Fin Pour
Fin Si
Fin Tant que
Renvoyer atteignable, chemin

}
*/



 


