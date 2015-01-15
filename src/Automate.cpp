/* 
 * File:   Automate.cpp
 * Author: Merwane
 * 
 * Created on 11 janvier 2015, 16:22
 */

#include "Automate.h"
#include <string>
#include <list>
#include <algorithm>
#include "EtatSymbolique.h"

Automate::Automate(std::list<Etat> etats, std::list<Transition> transitions , Etat etatInitial, std::list<Etat> etatsFinaux, int dimensions, std::list<Parma_Polyhedra_Library::Variable> variables) : 
etats(etats), transitions(transitions), etatInitial(etatInitial), etatsFinaux(etatsFinaux), dimensions(dimensions), variables(variables){
}

/* Automate Automate::chargerDepuisTexte(std::string texte){
//Algorithme qui charge le texte
}
 */


using namespace Parma_Polyhedra_Library;
/* Implémente l'algorithme de vérification d'accessibilité des états finaux.*/

bool Automate::verifieraccessibilite(std::list<EtatSymbolique> chemin){
    
    //Variables locales:

    std::list<EtatSymbolique> traites, aTraiter;
    bool atteignable, fini;

    //On crée l'horloge nulle: toutes variables à 0.
    Parma_Polyhedra_Library::Constraint_System cs;

    std::list<Variable>::iterator it;
        
    for(it=variables.begin(); it!=variables.end(); ++it){
        Constraint c(*it == 0);
        cs.insert(c);
    }
    
    NNC_Polyhedron horloge(cs);

    EtatSymbolique etatExamine(etatInitial, horloge, NULL);

    //Début: on met en pile l'état initial et on initialise les variables
    etatExamine.futur(variables);
    aTraiter.push_back(etatExamine);
    atteignable=false;
    
    //Traitement: On dépile, et tant que l'état examiné n'est pas final on empile ses successeurs possibles
    while( !aTraiter.empty() && !atteignable )
    {
        etatExamine=aTraiter.front();
        aTraiter.pop_front();

        //On regarde si l'état appartient à la liste des Etats finaux
        std::list<Etat>::iterator it;
        bool final=false;
        for (it=etatsFinaux.begin(); it!=etatsFinaux.end(); ++it){
            if(etatExamine.getEtat().equals(*it)){
                final=true;
            }           
        }    
        
        if (final){

            // On est parvenus à un état final, on enregistre le chemin en remontant de père en père jusqu'à l'état initial (le seul dont le père est nul)
            while(etatExamine.getPere()!=NULL){
                chemin.push_back(etatExamine);
                etatExamine=*etatExamine.getPere();
            }
            //On ajoute l'état initial au chemin
            chemin.push_back(etatExamine);
            atteignable=true;
        }
        else
        {
            //On teste si l'etat examiné a déjà été traité
            std::list<EtatSymbolique>::iterator it2;
            bool traite=false;
            for(it2=traites.begin(); it2!=traites.end(); ++it2){
                if (etatExamine.inclus(*it2)){
                    traite=true;
                }


            }
           
            if (traite){
                //Etat déjà traité, on l'ignore
            }
            else
            {
                traites.push_back(etatExamine);
                std::list<EtatSymbolique> successeurs = etatExamine.successeurs(variables);
                //Une façon non-élégante de copier les successeurs dans aTraiter (il paraît qu'il y a de nouveaux standards pour foreach, mais pas sûr qu'ils soient compatibles avec toutes les versions de compilateur) 
                std::list<EtatSymbolique>::iterator it3=aTraiter.end();
                 aTraiter.splice (it3, successeurs);
            }
        }
    }
    return atteignable;
}




 

