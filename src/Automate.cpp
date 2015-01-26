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
#include <stdio.h>
#include "EtatSymbolique.h"

int yyparse(Automate* automate);
extern FILE * yyin;
using namespace Parma_Polyhedra_Library;
using namespace std;

Automate::Automate(){
   
   
}
Automate::Automate(std::list<Etat> etats, Etat* etatInitial, std::list<Etat> etatsFinaux, int dimensions, std::list<Parma_Polyhedra_Library::Variable> variables) : 
etats(etats), etatInitial(etatInitial), etatsFinaux(etatsFinaux), dimensions(dimensions), variables(variables){
}

int Automate::getDimensions(){
    return dimensions;
}

void Automate::setDimensions(int dim){
    dimensions=dim;
}
void Automate::setVariables(std::list<Parma_Polyhedra_Library::Variable> vars){
    variables=vars;
}

void Automate::addEtat(Etat et){
    etats.push_back(et);
}

void Automate::addEtatInitial(Etat et){
    etats.push_back(et);
    etatInitial= &(etats.back());
}

void Automate::addEtatFinal(Etat et){
    etats.push_back(et);
    etatsFinaux.push_back(et);
}

void Automate::addTransition(Transition* transition, string nompred, string nomsuccs ){
    
    list<Etat>::iterator it;
    int nbmatch=0; //Enregistre le nombre d'états qu'on a trouvé (doit être 2) afin de sortir de la boucle de façon anticipée
    Etat* pred;
    Etat* succs;
    
    cout << "Début de la recherche de " << nompred << " et " << nomsuccs << endl  ;
    for(it=etats.begin(); it!=etats.end(); ++it){
        if (it->getNom()==nompred){
           cout << "Trouvé état predecesseur\n";
            pred=&(*it);
            transition->setPredecesseur(pred);
            nbmatch+=1;
            cout << "Set.\n";
        }
        if (it->getNom()==nomsuccs){
            cout << "Trouvé état successeur\n";
            succs=&(*it);
            transition->setSuccesseur(succs);
            nbmatch+=1;
            cout << "Set.\n";
        }
        if(nbmatch==2){
            cout << "Fini\n";
            break;
        }
        cout << "Niveau " << it->getNiveau();
        cout << "Etat "<< it->getNom() << " ne convient pas. Etat suivant\n";
    }
    
    //Ce n'est vraiment pas top de faire ça ici (car il faut s'assurer que la transition est complète, ce qui est le cas) mais je ne vois pas de meilleur moyen de procéder
    cout << "Rajout de la transition aux etats concernés";
    pred->addTransition(*transition);
}

void Automate::print(){
    list<Etat>::iterator it;
     
    cout <<  "----- Here is the automaton -----\n\n" ;    
    cout << "Initial state: " ; 
    etatInitial->print();
    
    for(it = etats.begin(); it!= etats.end(); ++it){
       it->print();
    }
    for(it = etatsFinaux.begin(); it!= etatsFinaux.end(); ++it){
       cout << "Final state: " + it->getNom() + " , level " << it->getNiveau() << "\n\n"; 
    }
    cout <<  "-----------------\n";
  
}



 
 

 void Automate::chargerDepuisTexte(){
    //Algorithme qui charge le texte
    string filepath;
     
    cin >> filepath;

    //Ouvre le fichier
    cout << "\nPlease enter path to file to load: \n";
    FILE *myfile = fopen(filepath.c_str(), "r");
     
    while (!myfile){
        cout << "Cannot open file " << filepath << endl;
        cout << "Please enter path to file to load: \n";
        cin >> filepath;
        cout << endl;
        myfile = fopen(filepath.c_str(), "r");
    }

        yyin = myfile;
        if ( yyparse(this) != 0 ) {
            fprintf(stderr,"Syntaxe incorrecte\n");  
        }
}





/* Implémente l'algorithme de vérification d'accessibilité des états finaux.*/

bool Automate::verifieraccessibilite(list<EtatSymbolique> &chemin, bool ver){
    
    //Variables locales:
    if(ver)
    {
        cout << "----- Start verification ------\n\n";
    }
    std::list<EtatSymbolique> traites;
    list<EtatSymbolique*> aTraiter;
    list<EtatSymbolique> temp;
    bool atteignable, fini;

    //On crée l'horloge nulle: toutes variables à 0.
    Parma_Polyhedra_Library::Constraint_System cs;

    std::list<Variable>::iterator it;
        
    for(it=variables.begin(); it!=variables.end(); ++it){
        Constraint c(*it == 0);
        cs.insert(c);
    }
    
    NNC_Polyhedron horloge(cs);

    EtatSymbolique etatSymboliqueInitial(etatInitial, horloge, NULL);
    
    if(ver){
        cout << "First element is ";
        etatSymboliqueInitial.print();
        cout << endl;
    }

    //Début: on met en pile l'état initial et on initialise les variables
    etatSymboliqueInitial.futur(variables);
    if(ver){
        cout << "After future element is ";
        etatSymboliqueInitial.print();
        cout << endl;
    }
    temp.push_back(etatSymboliqueInitial);
    EtatSymbolique * etatExamine = &temp.back();
    aTraiter.push_back(etatExamine);
    atteignable=false;
    
    //Traitement: On dépile, et tant que l'état examiné n'est pas final on empile ses successeurs possibles
    while( !aTraiter.empty() && !atteignable )
    {

        
        etatExamine=aTraiter.back();
        aTraiter.pop_back();
        
        if(ver){
            cout << "Now analysing ";
            etatExamine->print();
            cout << "Adresse ";
            cout << etatExamine;
            cout << endl;
        }

        //On regarde si l'état appartient à la liste des Etats finaux
        std::list<Etat>::iterator it;
        bool final=false;
        for (it=etatsFinaux.begin(); it!=etatsFinaux.end(); ++it){
            if(etatExamine->getEtat()->equals(*it)){
                if(ver){
                    cout << "Final state found! \n";
                    etatExamine->print();
                    cout << endl;
                }
                final=true;
            }           
        }    
        
        if (final){

            // On est parvenus à un état final, on enregistre le chemin en remontant de père en père jusqu'à l'état initial (le seul dont le père est nul)
            while(etatExamine->hasPere()){
                chemin.push_back(*etatExamine);
                cout << "Adding to the path: \n";
                etatExamine->print();
                EtatSymbolique * pere= etatExamine->getPere();
                cout << "Le père est: \n";
                pere->print();
                cout << "adresse " << pere << endl ; 
                etatExamine = pere;
            }
            //On ajoute l'état initial au chemin
            chemin.push_back(*etatExamine);
            atteignable=true;
        }
        else
        {
            if(ver){
                    cout << "This state is not a final state \n";
                }
            traites.push_back(*etatExamine);
            std::list<EtatSymbolique> successeurs = etatExamine->successeurs(variables);

            //On ajoute à aTraiter les successeurs non déjà traités

            std::list<EtatSymbolique>::iterator it2;
            std::list<EtatSymbolique>::iterator it3;
            bool traite=false;
            for (it3=successeurs.begin(); it3!=successeurs.end();++it3)
            {
                cout << "Successeur récupéré \n";
                it3->print();
                cout << "Dont le pere est \n";
                it3->getPere()->print();
                for(it2=traites.begin(); it2!=traites.end(); ++it2){
                    if (it3->inclus(*it2)){
                        traite=true;
                        break;
                    }
                }
                if(traite){
                    //Etat traité, on ne fait rien et on remet traité à false pour le successeur suivant
                    traite=false;
                }
                else{
                    //Etat non traité, on le rajoute à aTraiter
                    temp.push_back(EtatSymbolique(it3->getEtat(), it3->getHorloge(), it3->getPere()));
                    aTraiter.push_back(&temp.back());
                   
                }
            }                          
        }
    }
    return atteignable;
}




 


