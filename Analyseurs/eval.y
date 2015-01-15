/* -- eval.y --       
   Evaluation d'une expression       
   Partie analyseur grammatical.    

   Utilisation : bison eval.y */

%{
#include <stdio.h>

/* Pré-déclarations */
int yylex (void);
void yyerror (const char *);

/* Variable définie dans un autre fichier */
extern char* yytext;

extern Automate parsedAutomaton;

%}

%defines /* Génère le fichier en-tête eval.tab.h */

%start  element /* Axiome de la grammaire */

%union{
  Constraint c;
  Linear_Expression e;
  int v;
  char* str;
  NNC_Polyhedron P;
}


%token<v> ENTIER
%token<str> NOM
%token<str> VAR

%type<e> expr

%%

elements   : element              
           | elements element   
           ;

element   : etat
          | transition
          | taille
          ;

taille   : TAILLE ENTIER            {}              
         ;

etat     : ETAT NOM ENTIER           {}
         ;

transition  : TRANSITION OBRACE NOM NOM conditions assignements EBRACE  
  {

  }

            | TRANSITION OBRACE NOM NOM conditions EBRACE
  {

  }
            ;

conditions  : CONDITION contraintes   {}
            ;

contraintes : contrainte     {}
            | contraintes contrainte   {}
            ;

contrainte  : expr '=' expr ';'     {}
            | expr '<' expr ';'     {}
            | expr '>' expr ';'     {}
            | expr '<=' expr ';'     {}
            | expr '>=' expr ';'     {}
            ;

assignements : ASSIGNEMENTS formules  {}
             ;

formules  : formule
          | formules formule
          ;

expr      : expr '+' facteur
          | expr '-' facteur
          | facteur
          ;

facteur   : facteur '*' facteur
          | ENTIER
          | VAR
          ;





%%
#include <stdio.h>
#include "eval.tab.h"

void yyerror (const char * error) 
{
    fprintf (stderr, "Erreur: %s sur l'expression %s\n", error, yytext);
}

int main() {
    if ( yyparse() != 0 ) {
        fprintf(stderr,"Syntaxe incorrecte\n"); return 1; }
    else
        return 0;


  // open a file handle to a particular file:
  FILE *myfile = fopen("filepath", "r");
  // make sure it's valid:
  if (!myfile) {
    cout << "Cannot open file" << endl;
    return -1;
  }
  // set lex to read from it instead of defaulting to STDIN:
  yyin = myfile;
}
