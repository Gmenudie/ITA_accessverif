/* -- eval.l --       
   Evaluation d'une expression       
   Partie analyseur lexical.    

   Utilisation : flex eval.l */

%{
#include "eval.tab.hpp" /* Généré par bison grâce à l'option %defines */

%}

%option noinput
%option nounput
%option noyywrap

BLANC [ \n\t]

%%

TAILLE  		return TAILLE;
ETAT			return ETAT;
INITIAL			return INITIAL;
FINAL			return FINAL;
TRANSITION		return TRANSITION;
CONDITIONS		return CONDITIONS;
ASSIGNEMENTS	return ASSIGNEMENTS;

[0-9]+      	yylval.i = atoi(yytext); return ENTIER;
q[0-9]+			yylval.str = yytext; return NOM;
x[0-9]+			yylval.i = atoi(yytext+1); return VAR;
\{				return OBRACE;
\} 				return EBRACE;
"<="			return MINEQUAL;
">="			return SUPEQUAL;

{BLANC}+    	;
.           	fprintf(stderr, "Caractere (%c) non reconnu\n", yytext[0]); /* tout le reste (les règles sont évaluées de haut en bas */

%%

