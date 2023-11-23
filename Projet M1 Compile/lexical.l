
%{  
    #include "S.tab.h" //après le include, on fait le return des entités lexicales
	#include "ts.h"
	#include <ctype.h>
    extern nb_lignes ;
    extern nb_colonnes ;
	extern YYSTYPE yylval;

    /* explication INTEGER entre -32768 et 32767
    2 cas: soit positif sans signe ni parentheses,
           (+ ou - et integer)
    0 - matches zero.
    [1-9][0-9]{0,3} - matche les integers entre 1 et 9999, premier chiffre !=0.
    [12][0-9]{4} - matche les integers entre 10000 et 29999.
    3[01][0-9]{3} - matche les integers entre 30000 et 31999.
    32[0-6][0-9]{2} - matche les integers entre 32000 et 32699.
    327[0-5][0-9] - matche les integers entre 32700 et 32759.
    3276[0-7] - matche les integers entre 32760 et 32767.*/
    //INTEGER ((0|[1-9][0-9]{0,3}|[12][0-9]{4}|3[01][0-9]{3}|32[0-6][0-9]{2}|327[0-5][0-9]|3276[0-7])|"("[+-](0|[1-9][0-9]{0,3}|[12][0-9]{4}|3[01][0-9]{3}|32[0-6][0-9]{2}|327[0-5][0-9]|3276[0-7])")"|"["(0|[1-9][0-9]{0,3}|[12][0-9]{4}|3[01][0-9]{3}|32[0-6][0-9]{2}|327[0-5][0-9]|3276[0-7])"]")
    //FLOAT chiffre+ 1 au min  le point  chiffre* 0..n
%}

lettre [a-zA-Z]
lettreM [A-Z]
chiffre [0-9]
comment (%%({lettre}|{lettreM}|{chiffre}|"#"|"!"|"="|"+"|"-"|"*"|"/"|";"|" "|"'"|"."|"["|"]"|"("|")")*)
IDF ({lettre}({chiffre}|[a-z])*)
INTEGER ((0|[1-9][0-9]{0,3}|[12][0-9]{4}|3[01][0-9]{3}|32[0-6][0-9]{2}|327[0-5][0-9]|3276[0-7])|"("[+-](0|[1-9][0-9]{0,3}|[12][0-9]{4}|3[01][0-9]{3}|32[0-6][0-9]{2}|327[0-5][0-9]|3276[0-7])")")
FLOAT  ({chiffre}+"."{chiffre}*[1-9]|"("[+-]{chiffre}+"."{chiffre}*[1-9]")")

%%

"VAR"           {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf (" entite reconnue  %s \n", yytext); return dt_div;}
"CODE"      {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf (" entite reconnue %s  \n", yytext); return pr_div;}

{IDF}       {EntiteInsert(yytext,"IDF"," ",0,0);nb_colonnes= nb_colonnes + strlen(yytext);if(yyleng <=8) {printf("\n IDF reconnu %s \n",yytext);yylval.str = strdup(yytext);return idf;} else printf("IDF trop long \n");}
{comment}   {nb_colonnes= nb_colonnes + strlen(yytext);printf("\n commentaire reconnu : %s \n",yytext);/*return comment;*/}
{INTEGER}   {/*EntiteInsert(yytext,"CONST","integer",atoi(yytext), 0,1);*/nb_colonnes= nb_colonnes + strlen(yytext);printf("\n INTEGER reconnu : %s \n",yytext);yylval.str = strdup(yytext);return integer;}
{FLOAT}     {/*EntiteInsert(yytext,"CONST","float",atof(yytext), 0,1);*/nb_colonnes= nb_colonnes + strlen(yytext);printf("\n FLOAT reconnu : %s \n",yytext);yylval.str = strdup(yytext);return flt;}
\n          {nb_colonnes = 1;nb_lignes ++;}

"-"      {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur arithmetique - reconnu \n");return minus;}
"+"      {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur arithmetique + reconnu \n");return plus;}
"*"      {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur arithmetique * reconnu \n");return times;}
"/"      {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur arithmetique / reconnu \n");return divise;}

"&&"  {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur logique %s reconnu \n",yytext);return and;}
"||"   {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur logique %s reconnu \n",yytext);return or;}
"!"    {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur logique %s reconnu \n",yytext);return not;}
">"  {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur de comparaison %s reconnu \n",yytext);return G;}
"<"  {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur de comparaison %s reconnu \n",yytext);return L;}
"==" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur de comparaison %s reconnu \n",yytext);return EQ;}
">=" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur de comparaison %s reconnu \n",yytext);return GE;}
"<=" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur de comparaison %s reconnu \n",yytext);return LE;}
"!=" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Operateur de comparaison %s reconnu \n",yytext);return DI;}

"IF"      {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return IF;}
"ELSE"    {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return ELSE;}
"WHILE"   {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return WHILE;}
"FOR"    {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return FOR;}
"STRUCT"      {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return STRUCT;}

"INTEGER" {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return INTEGER;}
"FLOAT"  {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return FLOAT;}
CONST   {EntiteInsert(yytext,"Sep",0, 1,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("entite reconnue %s \n", yytext); return CONST;}

"="         {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n l'affectation = reconnu \n");return egl;}
","         {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("\n Separateur reconnu ,\n");  return vrg;}
";" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return pvg;}
":" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return Dpoints;}
"." {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return point;}
"(" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return Pouvr;}
")" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return Pferm;}
"{" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return accol;}
"}" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return accor;}
"[" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return baro;}
"]" {EntiteInsert(yytext,"Sep",0, 2,0);nb_colonnes= nb_colonnes + strlen(yytext);printf("Separateur reconnu %s\n", yytext); return barf;}

[" "]    {}
[\t]
.      {printf("\n line %d, colonne %d: entite %s qui a generee l'erreur \n",nb_lignes,nb_colonnes,yytext);nb_colonnes= nb_colonnes + strlen(yytext);}


%%
