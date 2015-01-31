/* -- eval.l --       
   Evaluation d'une expression       
   Partie analyseur lexical.    

   Utilisation : flex eval.l */

%{
#include "eval.tab.hpp" /* Généré par bison grâce à l'option %defines */
#include <iostream>
#include <string.h> 
%}

%option noinput
%option nounput
%option noyywrap

BLANC [ \n\t]

%%

MAX_LEVEL  		return MAX_LEVEL;
STATE			return STATE;
INITIAL			return INI;
FINAL			return FINAL;
TRANSITION		return TRANSITION;
GUARD			return GUARD;
ASSIGNMENT		return ASSIGNMENT;
[\-+*=<>;]      return yytext[0];
LEVEL			return LEVEL;
[0-9]+      	{yylval.i = atoi(yytext); return ENTIER;}
q[0-9]+			{yylval.str = strdup(yytext); return NOM;}
x[0-9]+			{yylval.i = atoi(yytext+1); return VAR;}
\{				return OBRACE;
\} 				return EBRACE;
"<="			return MINEQUAL;
">="			return SUPEQUAL;

{BLANC}+    	;
.           	fprintf(stderr, "Caractere (%c) non reconnu\n", yytext[0]); /* tout le reste (les règles sont évaluées de haut en bas */

%%

