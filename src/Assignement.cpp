/* 
 * File:   main.cpp
 * Author: geoffray
 *
 * Created on December 8, 2014, 9:43 AM
 */

#include "Assignement.h"
#include <ppl.hh>
#include <iostream>


using namespace Parma_Polyhedra_Library;
using namespace std;

Assignement::Assignement(Variable var, Linear_Expression expr) : variable(var), expression(expr)
{
}

Variable Assignement::getVariable(){
	return variable;
}


Linear_Expression Assignement::getExpression(){
	return expression;
}

void Assignement::print(){
    cout << "Assignment: x" << variable.space_dimension() << " = ";
    expression.print();
    
}

