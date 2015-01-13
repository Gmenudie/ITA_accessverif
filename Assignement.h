/* 
 * File:   Assignement.h
 * Author: geoffray
 *
 * Created on January 11, 2015, 4:10 PM
 */

#ifndef ASSIGNEMENT_H
#define	ASSIGNEMENT_H
#include<ppl.hh>

class Assignement
{
private:
    Parma_Polyhedra_Library::Variable variable;
    Parma_Polyhedra_Library::Linear_Expression expression;
    
public:
    Assignement(Parma_Polyhedra_Library::Variable var, Parma_Polyhedra_Library::Linear_Expression expr);    
};

#endif	/* ASSIGNEMENT_H */

