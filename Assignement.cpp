/* 
 * File:   main.cpp
 * Author: geoffray
 *
 * Created on December 8, 2014, 9:43 AM
 */

#include "Assignement.h"
#include <ppl.hh>


using namespace Parma_Polyhedra_Library;

Assignement::Assignement(Variable var, Linear_Expression expr) : variable(var), expression(expr)
{
}

Variable getVariable(){
	return variable;
}


Linear_Expression getExpression(){
	return expression;
}

