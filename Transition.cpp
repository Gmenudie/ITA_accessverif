/* 
 * File:   Transition.cpp
 * Author: Merwane
 *
 * Created on 11 janvier 2015, 16:43
 */



#include <list>
#include <iostream>
#include <string>
#include <ppl.hh>
#include "Transition.h"

using namespace Parma_Polyhedra_Library;
using namespace std;

Transition::Transition(NNC_Polyhedron cond, Etat* pred, Etat* succ, list<Assignement> ass): 
conditions(cond), predecesseur(pred), successeur(succ), assignements(ass)
{}
   

        
                 
    


