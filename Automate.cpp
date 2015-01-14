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
#include <algorithme>
#include "EtatSymbolique.h"

Automate::Automate(std::list<Etat> etats, std::list<Transition> transitions , Etat etatInitial, std::list<Etat> etatsFinaux, int dimensions) : 
etats(etats), transitions(transitions), etatInitial(etatInitial), etatsFinaux(etatsFinaux), dimensions(dimensions){
}

/* Automate Automate::chargerDepuisTexte(std::string texte){
//Algorithme qui charge le texte
}
 */



/* Implémente l'algorithme de vérification d'accessibilité des états finaux.*/

std::list<Etat> Automate::verifieraccessibilite(){
    
    //Variables locales:

    std::list<EtatSymbolique> traites, chemin, aTraiter;
    bool atteignable, fini;
    EtatSymbolique etatExamine(etatInitial, Parma_Polyhedra_Library::NNC_Polyhedron horloge(), NULL);

    //Début: on met en pile l'état initial et on initialise les variables
    aTraiter.push_back(etatExamine.futur());
    atteignable=false;
    
    //Traitement: On dépile, et tant que l'état examiné n'est pas final on empile ses successeurs possibles
    while( !aTraite.empty() && !atteignable )
    {
        etatExamine=aTraiter.front();
        aTraiter.pop();

        //Méthode pas fantastique pour trouver si un élément appartient à une liste. Il y a peut-être mieux mais nous sommes débutants
        std::list<Etat>::iterator it;
        it = find (etatsFinaux.begin(), etatsFinaux.end() etatExamine.getEtat());
        
        if (it != etatsFinaux.end()){

            // On est parvenus à un état final, on enregistre le chemin en remontant de père en père jusqu'à l'état initial (le seul dont le père est nul)
            while(etatExamine.pere!=NULL){
                chemin.push_back(etatExamine);
                etatExamine=*etatExamine.getPere();
            }
            atteignable=true;
        }
        else
        {
            std::list<Etat>::iterator it2;
            it2 = find (traites.begin(), traites.end() etatExamine);
            if (it2 != traites.end()){
                //Etat déjà traité, on l'ignore
            }
            else
            {
                traites.push_back(etatExamine);
                std::list<EtatSymbolique> successeurs = etatExamine.successeurs();
                //Une façon non-élégante de copier les successeurs dans aTraiter (il paraît qu'il y a de nouveaux standards pour foreach, mais pas sûr qu'ils soient compatibles avec toutes les versions de compilateur) 
                std::list<EtatSymbolique>::iterator it3=aTraiter.end();
                 aTraiter.splice (it2, successeurs);
            }
        }
    }
    return chemin;
}




 


