%{
  #include <stddef.h>
  #include "quad.h"
  
  int nb_lignes=1, nb_colonnes=1;
	char sauvType[25];
  int sauvdeb;
  char sauvStruct[25];
  int cptTemp=1;
  
    %}

%union {
         int rxtype;
         char* str;
         struct{
                char* vlr; 
                char* type;
           }Strutype;
}

%token dt_div pr_div 
%token IF ELSE FOR STRUCT WHILE 
%token <str>idf     <str>integer <str>flt 
%token <str>minus   <str>plus    <str>times   <str>divise 
%token <str>G       <str>L       <str>EQ      <str>GE     <str>LE    <str>DI 
%token <str>egl     <str>and     <str>or      <str>not 
%token <str>INTEGER <str>FLOAT   <str>CONST   <str>point 
%token <str>vrg     <str>pvg     <str>Dpoints <str>Pouvr  <str>Pferm <str>accol     <str>accor 
%token <str>baro    <str>barf     

%type <Strutype>val expressionArith terme facteur ExpCondition FORA FORB for_boucle
%type <rxtype>TYPE

//associativite gauche +prio
%left or and not 
%left G L EQ GE LE DI
%left plus minus
%left divise times
%left Pouvr Pferm 


%start S 
%%
S :  /*prog_id*/ idf {insererVal($1,"nomprog");} accol dt_div accol dec accor pr_div accol list_inst accor accor 
{ printf(" Le programme est correcte syntaxiquement \n"); YYACCEPT; }
;

TYPE : FLOAT {$$=2; strcpy(sauvType, "float");}
     | INTEGER{$$=0; strcpy(sauvType, "integer");} 
     ;

dec : dec_var dec | dec_cst dec | def_struc dec | dec_struc dec
	 | 
;
dec_var : TYPE list_variables pvg 
  /*tab*/|TYPE idf baro integer barf pvg { if(Existe($2)!=0)   { 
                                if(atoi($4)>0){insererTYPE($2,sauvType);insererTaille($2,$1,atoi($4));}
                                 
                                else{printf("\n Taille Tableau incorrecte: doit etre superieure a 0 \n");}
  }else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$2,nb_lignes,nb_colonnes);
                              }
;
list_variables : idf { if(Existe($1)!=0)   { insererTYPE($1,sauvType);  }
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
                              }
               | idf vrg list_variables  { if(Existe($1)!=0)   { insererTYPE($1,sauvType);}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
                              }
;
	

dec_cst : CONST ent pvg  
;
ent : idf egl val /*Const X =5;*/{ if(Existe($1)!=0)   { insererTYPE($1,"CONST");
                                           //float ab;
                                          // ab = $3.vlr[0];
                                        //  if($3.vlr == NULL){
                                          //printf("\n ici C'EST NULLL ici \n");
                                         // }
                                          //insererVal($1,"RAS");
                                          insererVal($1,$3.vlr);
                                           
                                           //float flt;
                                           //flt=atof($3.vlr);
                                          // insererVal($1,flt);
                                            }
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
                              } 
    | idf /*Const X;*/{ if(Existe($1)!=0)   { insererTYPE($1,"CONST");insererVal($1,"RAS");}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
                              }
;
//defintion struct
def_struc: STRUCT accol defst accor idf pvg {if(Existe($5)!=0){insererTYPE($5,"STRUCT");}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$5,nb_lignes,nb_colonnes);
                              };
    ;
defst:TYPE idf pvg  {if(Existe($2)!=0)   {  insererTYPE($2,sauvType); insererVal($2,"VarEnrg");}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$2,nb_lignes,nb_colonnes);
                              } 
        defst// suite lfo9 !
        
        |TYPE idf pvg { if(Existe($2)!=0)   { insererTYPE($2,sauvType); insererVal($2,"VarEnrg");}//printf(" JE SUIS UN %s !!!",sauvType);}
                                else
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$2,nb_lignes,nb_colonnes);
                              }
    
      ; 

      //declaration struct
dec_struc: STRUCT idf  {if(Existe($2)==0) { //verifie si idf est bien declare
                                strcpy(sauvStruct,$2);
                                
                              }
                                else{
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n",$2,nb_lignes,nb_colonnes);
                              }
                              } decst pvg 
;
decst:idf vrg decst {if(Existe($1)!=0) { 
  //printf("JE SUIS ICIIIIIIIIIIIIIIII \n");
 
  
  insererTYPE($1,sauvStruct);}
else{
                                 printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
}
                              }
    | idf {if(Existe($1)!=0) { insererTYPE($1,sauvStruct);}
else{
                                printf(" \n Erreur semantique: Double declaration  de %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
}
                              }
;



list_inst : INST list_inst |
;
INST :
     IF_STATEMENT
    |Affectation 
	  | WHILE_STATEMENT
	 | for_boucle
   
   
	;


Affectation:  idf egl expressionArith pvg  {//verifier que c declare 
                                if(Existe($1)!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", $1, nb_lignes, nb_colonnes);

                                else //verifier que ce n'est pas une constante
                                  {if(GetNature($1)==0)
                                        printf(" \n Erreur semantique: Impossible de modifier la Constante %s a la ligne %d et a la colonne %d \n",$1,nb_lignes,nb_colonnes);
                                     else{ 
                                      printf("\n \n -------------TYPE VAR IDF1: %s----------    .%s. \n \n",$1,GetType($1));
                                     printf("\n \n -------------TYPE VAR IDF2: ----------    .%s. \n \n",$3.type);
                                
                                if(strcmp($3.type, "") != 0 && strcmp(GetType($1), "") != 0 )
                                
                                      {
                                        if(strcmp(GetType($1),$3.type)!=0)//si les 2 types differents
                                      { printf("\n Erreur semantique : Incompatibilite des types \n");

           
                                            }
                                        else{
                                          insererVal($1,$3.vlr);
                                          //inserer val pcq les types sont compatibles
                                          //inserer($1,$3.vlr);                                          

                                        }    }
                             // 


                                     }    }
                       createQuad("=",$3.vlr,"",$1);
                      }
             
  
               |idf baro integer barf egl expressionArith pvg {if(Existe($1)!=0){
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", $1, nb_lignes, nb_colonnes);

               }
               else{
               // printf("\n \n -------------TYPE VAR IDF1: %s----------    .%s. \n \n",$1,GetType($1));
                                
                             if(strcmp($6.type, "") != 0 && strcmp(GetType($1), "") != 0 )
                             {//printf("les deux arguments de l'affectation sont des string || 3.type= %s et 1= %s !",$3.type,GetType($1));
                             if(strcmp(GetType($1),$6.type)!=0)

        { printf("\n Erreur semantique : Incompatibilite des types \n");

           
        }
        else{
          if(Validindex($1,$3)==0){
                                printf(" \n Index Incorrect non compris entre 0 et la taille du tableau \n");
                              }
                            else{insererValTab($1,$3,$6.vlr);
                             char* format = "[%s]";
                             char suffix[strlen(format) + strlen($3) - 1]; // alloue de la memoire pour la chaîne suffixe
                             sprintf(suffix, format, $3);
                             char* result = malloc(strlen($1) + strlen(suffix) + 1);
                              strcpy(result, $1);
                              strcat(result, suffix);
                              $1=result;
                              //insererValTab($1,$3,$6.vlr);
                              createQuad("=",$6.vlr,"",$1);}


}}
               }
                              } //integer>0 car tab


// STRUCTURRRE AFFECTATION
    | idf point idf egl expressionArith pvg  {//verifier que c declare 
                                if(Existe($1)!=0 || Existe($3)!=0 || Existe(GetType($1))!=0 ) //exmple: Nri type Nomstr
                                  printf("\n Erreur semantique : IDF NON DECLARE a la ligne %d et à la colonne %d \n",  nb_lignes, nb_colonnes);

                                else //struct existe 
                                  {
                                      printf("\n \n -------------TYPE VAR IDF1: %s----------    .%s. \n \n",$3,GetType($3));
                                     printf("\n \n -------------TYPE VAR IDF2: ----------    .%s. \n \n",$5.type);
                                
                                if(strcmp($5.type, "") != 0 && strcmp(GetType($3), "") != 0 )
                                
                                      {
                                        if(strcmp(GetType($3),$5.type)!=0)//si les 2 types differents
                                      { printf("\n Erreur semantique : Incompatibilite des types \n");

           
                                            }
                                        else{
                                          char enrg[10];
                                          sprintf(enrg,"%s.%s",$1,$3);
                                          EntiteInsert(enrg,"IDF",GetType($3),0,0);
                                          insererVal(enrg,$5.vlr);
                                          //inserer val pcq les types sont compatibles
                                          //inserer($1,$3.vlr);                                          
                                          createQuad("=",$5.vlr,"",enrg);
                                        }    }
                             // 


                                         }
                       
                      }
    ;

/*==========================Expression Arithmetique===============================================*/
expressionArith:expressionArith plus terme {if($1.type=="integer" && $3.type=="integer")//si l'un des 2 est un float donc res est float 
              {$$.type="integer";}
              else if($1.type=="float" || $3.type=="float") $$.type="float";
              $1.vlr=strdup($$.vlr);          //(terme plus terme)=(+,$1.vlr,$3.vlr,$$.vlr)    terme($$.vlr=T1) plus terme ($$.vlr=3)   (+,$1.vlr,$3.vlr,$$.vlr)          
              sprintf($$.vlr,"T%d",cptTemp);
                                          createQuad("+",$1.vlr,$3.vlr,$$.vlr);
                                          cptTemp++;
                      }//expressionArith  
            |
            expressionArith minus terme {if($1.type=="integer" && $3.type=="integer")//si l'un des 2 est un float donc res est float 
              {$$.type="integer";}
              else if($1.type=="float" || $3.type=="float") $$.type="float";
              $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
                                          createQuad("-",$1.vlr,$3.vlr,$$.vlr);
                                          cptTemp++;
                      }//expressionArith  
            //expressionArith
            |
            terme {$$.type=$1.type;
            $$.vlr=$1.vlr;}
            ;

terme:      terme times facteur {if($1.type=="integer" && $3.type=="integer")//si l'un des 2 est un float donc res est float 
              {$$.type="integer";}
              else if($1.type=="float" || $3.type=="float") $$.type="float";
             
              $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
                                          createQuad("*",$1.vlr,$3.vlr,$$.vlr);
                                          cptTemp++;
            }
            |
            terme divise facteur  {if($1.type=="integer" && $3.type=="integer")//si l'un des 2 est un float donc res est float 
              {$$.type="integer";}
              else if($1.type=="float" || $3.type=="float") $$.type="float";
             if(strcmp($3.vlr,"0")==0){ printf("\n Erreur semantique : Division par 0 \n");
}
             
              $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
                                          createQuad("/",$1.vlr,$3.vlr,$$.vlr);
                                          cptTemp++;
            }
            
           | facteur{ $$.type=$1.type;
                      $$.vlr=$1.vlr;}
           ;

facteur:    idf baro integer barf //t[5] valeur d'une case tableau
                                 /*                   { */{if(Existe($1)!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", $1, nb_lignes, nb_colonnes);

                             else{//verifier que l'index compris dans la taille du tab
                              if(Validindex($1,$3)==0){
                                printf(" \n Index Incorrect non compris entre 0 et la taille du tableau \n");
                              }
                              $$.type=GetType($1);
                             char* format = "[%s]";
                             char suffix[strlen(format) + strlen($3) - 1]; // alloue de la memoire pour la chaîne suffixe
                             sprintf(suffix, format, $3);
                             char* result = malloc(strlen($1) + strlen(suffix) + 1);
                              strcpy(result, $1);
                              strcat(result, suffix);
                              $$.vlr=result;}
                             
                              }
            |
            idf 
                 /*                   { */{if(Existe($1)!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", $1, nb_lignes, nb_colonnes);

                              
                    else{
                    
                    //  printf("\n \n -------------TYPE VAR IDF2: %s----------    .%s. \n \n",$1,GetType($1));
                      if(strcmp(GetType($1),"integer")==0||strcmp(GetType($1),"float")==0){
                        $$.vlr=strdup($1);//strdup(GetVal($1)); //get val retourne la valeur de l'idf2  idf=idf2
                        $$.type=GetType($1); 
                      }
                    }
                    }
                    
            |
            idf point idf  {//verifier que c declare 
                                if(Existe($1)!=0 || Existe($3)!=0 || Existe(GetType($1))!=0 ) //exmple: Nri type Nomstr
                                  printf("\n Erreur semantique : IDF NON DECLARE a la ligne %d et à la colonne %d \n",  nb_lignes, nb_colonnes);

                                else{
                                  if(strcmp(GetType($3),"integer")==0||strcmp(GetType($3),"float")==0){
                        char enrg[10];
                        sprintf(enrg,"%s.%s",$1,$3);
                        $$.vlr=strdup(enrg);//strdup(GetVal($1)); //get val retourne la valeur de l'idf2  idf=idf2
                        $$.type=GetType($3); 
                      }

                                }
                                }
            |
            val {
                     //if(strcmp($1.type,"integer")==0)printf("comparaison marche avec string strcmp");
                    // printf("\n \n -------------TYPE VALEUR IDF2: ------------    .%s. \n \n",$1.type);
                     // if(strcmp(GetType($1),"integer")==0||strcmp(GetType($1),"float")==0){
                     $$.vlr=strdup($1.vlr); 
                     
                       $$.type=$1.type; 
                      
                    }

            | Pouvr expressionArith Pferm{$$.type=$2.type; $$.vlr=strdup($2.vlr);}; 
;


/////////////////////////////////expression conditionelle////////////////////

ExpCondition: ExpCondition or ExpCondition //moins prio

{
             $1.vlr=strdup($$.vlr);
            sprintf($$.vlr,"T%d",cptTemp);
            createQuadL(2,$1.vlr,$3.vlr,$$.vlr);
            cptTemp++;
            } 
            | ExpCondition and ExpCondition

            {
              $1.vlr=strdup($$.vlr);
            sprintf($$.vlr,"T%d",cptTemp);
            createQuadL(3,$1.vlr,$3.vlr,$$.vlr);
            cptTemp++;
            }
            | not ExpCondition {//$2.vlr=strdup($$.vlr);
            sprintf($$.vlr,"T%d",cptTemp);
            createQuadL(1,$2.vlr,"",$$.vlr);
            cptTemp++;}

            | ExpCondition G expressionArith //+ prio que or and not
 {
                $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
              createQuadA(6,$1.vlr,$3.vlr,$$.vlr);
              cptTemp++;
            }

            | ExpCondition L expressionArith
{
                $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
              createQuadA(5,$1.vlr,$3.vlr,$$.vlr);
              cptTemp++;
            }
            | ExpCondition EQ expressionArith

{
                $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
              createQuadA(1,$1.vlr,$3.vlr,$$.vlr);
              cptTemp++;
            }

            | ExpCondition GE expressionArith
            {
              $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
              createQuadA(3,$1.vlr,$3.vlr,$$.vlr);
              cptTemp++;
            }
            | ExpCondition LE expressionArith
             {
                $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
              createQuadA(4,$1.vlr,$3.vlr,$$.vlr);
              cptTemp++;
            }

            | ExpCondition DI expressionArith
            {
                $1.vlr=strdup($$.vlr);
              sprintf($$.vlr,"T%d",cptTemp);
              createQuadA(2,$1.vlr,$3.vlr,$$.vlr);
              cptTemp++;
            }

            | expressionArith
            {$$.vlr=strdup($1.vlr);}
            ;



val :  flt {$$.type = (char *) malloc(sizeof(char) * 7); // 7 = longueur maximale de "float" + 1 pour le caractère nul
        strcpy($$.type, "float");
        $$.vlr = (char *) malloc(sizeof(char) * 8);
        strcpy($$.vlr, $1);
        }
   | integer {$$.type = (char *) malloc(sizeof(char) * 8); // 8 = longueur maximale de "integer" + 1 pour le caractère nul
        strcpy($$.type, "integer");
        $$.vlr = (char *) malloc(sizeof(char) * 8);
        strcpy($$.vlr, $1);
        }
;


IF_STATEMENT :IF Pouvr ExpCondition Pferm { 
          empiler_Int(&pile2,qc-1);
                                     // pile 2 fiha les sauvdeb, apres ndirlo update f fin du THEN
                                    

          }
              accol list_inst accor elsebloc;

elsebloc:ELSE accol{
            QuadR[atoi(depiler(&pile2))].opd1=ToSTR(qc+1); //update quad cond li yb3et lel ELSE (qc raho f pile2)
            empiler_Int(&pile1,qc);
            createQuad("BR","","","");// creer quad BR vide pour fin ta3 THEN, il faut empiler bach nwlilo
            } list_inst {
           
            QuadR[atoi(depiler(&pile1))].opd1=ToSTR(qc); //update du quad BR hada Quad FIN 
            }
            accor;

WHILE_STATEMENT : WHILE {empiler_Int(&pile1,qc);} //sauv le qc pour retour du while pour retester condition 
                  Pouvr ExpCondition { empiler_Int(&pile2,qc-1); }//qc li lazemlo update hada yro7 l la fin exple (BLE,fin) 
                  Pferm accol list_inst 
                  accor {createQuad("BR",depiler(&pile1),"",""); //quad br pour retour a la cond debut
                         
                      /*   int qtemp=atoi(depiler(&pile2)); //exception condition AND et OR car ya 2 quads win mise a jour des opt1
                          if(strcmp(QuadR[qtemp].opt,"BZ")==0 && !strcmp(QuadR[qtemp+1].opt,"BZ")==0)
                          {QuadR[qtemp-1].opd1=ToSTR(qc);
                           QuadR[qtemp].opd1=ToSTR(qc); }

                         //else if(strcmp(QuadR[qtemp].opt,"BNZ")==0 && !strcmp(QuadR[qtemp+1].opt,"BNZ")==0){}
                         else{ */
                          QuadR[atoi(depiler(&pile2))].opd1=ToSTR(qc);}
                  
                  
                  
                  
                  ;

for_boucle : FORA Dpoints integer 
              { empiler_Int(&pile1,qc); //Les BR fla fin ywlo hna pour incrementer
                createQuad("+",$3,"",$1.vlr);
                empiler_Int(&pile3,qc);
              createQuadA(4,$1.vlr,"","");}//creer quad increment (le PAS)
             FORB// {                createQuadA(4,$1.vlr,$4.vlr,"");}
              
              Pferm {empiler_Int(&pile2,qc-1);
                
               
              }
               accol
              list_inst {createQuad("BR",depiler(&pile1),"","");   // creer quad bach nwelo l avant l'incrementation (debuter nouvelle iteration)
              QuadR[atoi(depiler(&pile2))].opd1=ToSTR(qc);  //  mise a jour 2eme arg (opd1) fl BR li yb3et l la fin ki tkoun la condition non satisfaite
                          }
              accor 
		;

FORA:FOR Pouvr idf Dpoints integer 
              { if(Existe($3)!=0)
                                  printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", $3, nb_lignes, nb_colonnes);

                              
                    else{
                createQuad("=",$5,"",$3);
              createQuad("BR",ToSTR(qc+2),"","");
              $$.vlr=strdup($3);
              } }//creer quad affectation + BR pour sauter la 1ere incrementation
              ;
FORB:  Dpoints idf  {//$$.vlr=strdup($2);
 if(Existe($2)!=0)
                    printf("\n Erreur semantique : IDF NON DECLARE de %s à la ligne %d et à la colonne %d \n", $2, nb_lignes, nb_colonnes);
                    else{
QuadR[atoi(depiler(&pile3))].res=strdup($2);}};
%%

int main ()
{
   initialisation();
   yyparse(); 
   afficherTSidf();//AFFICHAGE TS IDF+CST
   printf("\n -----------------------Quadruples Avant Optimisation-------------------------- \n");
   displayQuad();//affichage quads avant optimisation
   optimisation();// optimisation des quads
   printf("\n -----------------------Quadruples Apres Optimisation-------------------------- \n");
   displayQuad(); //affichage quads apres optimisation
   //afficherTSsuite();//AFFICHAGE TS Mots cles+ Seps
   ToAssembly();//generer fichier ASM 
   return 0;
}
yywrap () {}
int yyerror ( char*  msg )  
{
   printf ("Erreur Syntaxique a ligne %d a colonne %d \n", nb_lignes,nb_colonnes);
}
