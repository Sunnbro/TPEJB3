
/****************CREATION DE LA TABLE DES SYMBOLES ******************/
/***Step 1: Definition des structures de données ***/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quad.h"


#ifndef TS_H
#define TS_H
#define TABLE_SIZE 15

typedef struct record {
    char name[20];
    char type[20];
    char code[20];
    char* value;
    int taillemax;
    float* tab; //va contenir les valeurs du tableau
    struct record *next;
} Record;

Record *table[TABLE_SIZE];

typedef struct // struct de la table des separateurs + mots cle
{ 
   int state; 
   char name[20];
   char type[20];
} elt;

elt tabs[250],tabm[250];
extern char sav[20];
char chaine1 [] = "vide"; //chaine est vide


//fonction de hachage
int hash(char* chaine){
 int i=0,cpt=0;
  while(chaine[i]!='\0'){ //Tq non fin de chaine - \0 est le caractere ou code ascii=0 ou fin de chaine
    cpt+=chaine[i]%TABLE_SIZE; //cpt recoit la somme du code ascii des chars de la chaine en entre
    i++;
  }
  cpt=cpt%TABLE_SIZE; //change % si trop grand
  return cpt;
}


/***Step 2: initialisation de l'état des cases des tables des symbloles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation()
{
  int i;
  for (i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
  

  for (i=0;i<250;i++)
    {tabs[i].state=0;
    tabm[i].state=0;}

}


/***Step 3: insertion des entititées lexicales dans les tables des symboles ***/




void insertTSidf(char *name, char *code, char *type, char *value, int taille_max) {
    int index = hash(name);
    Record *new_record = malloc(sizeof(Record));
    if (new_record == NULL) {
        printf("Erreur: mémoire insuffisante\n");
        free(new_record);
        return;
    }
    strncpy(new_record->name, name, 20);
    strncpy(new_record->type, type, 20);
    strncpy(new_record->code, code, 20);
    new_record->value=strdup(value);
    new_record->taillemax=taille_max;
    
    new_record->next = table[index];
    table[index] = new_record;
}

int searchTSidf(char *name) { //fonction recherche si idf existe return 1 sinn 0
    int index = hash(name);
    Record *record = table[index];
    while (record != NULL) {
        if (strcmp(record->name, name) == 0) {
            return 1;  // le nom est trouvé dans la table
        }
        record = record->next;
    }
    return 0;  // le nom n'est pas trouvé dans la table
}


//inserer SEP+mots cles
void insererTS2 (char name[], char code[],int y,int i) //go fct EntiteInsert
{
  switch (y)
 { 
   case 1:/*insertion dans la table des mots clés*/
       tabm[i].state=1;
       strcpy(tabm[i].name,name);
       strcpy(tabm[i].type,code);
       break; 
    
   case 2:/*insertion dans la table des séparateurs*/
      tabs[i].state=1;
      strcpy(tabs[i].name,name);
      strcpy(tabs[i].type,code);
      break;
 }

}

/***Step 4: La fonction EntiteInsert permet de verifier si l'entité existe dèja dans la table des symboles */
// si elle n'existe pas on insere (idfs et const seulement)
void EntiteInsert (char name[], char code[],char type[],int y,int z)	
{

int j,i;

switch(y) 
  {
   case 0:/*verifier si la case dans la tables des IDF et CONST est libre*/
              switch (z)
              {
              case 0: // les chiffres n'ont pas besoin du champ valeur
                if(searchTSidf(name) == 0 ) {
                insertTSidf(name, code, type ,chaine1,0);}
                break;
              
              case 1:if(searchTSidf(name) == 0 ) {
                insertTSidf(name, code, type , name,0);}
                break;
              }
               
        //else
          //printf("entité existe déjà\n");
        break;

   case 1:/*verifier si la case dans la tables des mots clés est libre*/
       /* &&    (strcmp(name,tab[i].name)!=0)   */
       for (i=0;((i<250)&&(tabm[i].state==1));i++); 
        if(i<250)
          insererTS2(name,code,1,i);
       
        break; 
    
   case 2:/*verifier si la case dans la tables des séparateurs est libre*/
         
         //&&(strcmp(name,tab[i].name)!=0)
         for (i=0;((i<250)&&(tabs[i].state==1));i++); 
        if(i<250)
         insererTS2(name,code,2,i); 
       
        break;


  }

}
 void insererTYPE(char name[], char type[])
	{ 
     int index = hash(name);
    Record *record1 = table[index];
    while (record1 != NULL) {
        if (strcmp(record1->name, name) == 0) {
          
            strncpy(record1->type, type, 20);
           
      // printf("INSEEERT SUCCESSFUUUUUUUUUUUUUUUUUUUUUll",name); 
      }
        record1 = record1->next;
    }
     
     
    
	}

void insererTaille(char name[],int type ,int taille)
	{ 
     int index = hash(name);
    Record *record6 = table[index];
    while (record6 != NULL) {
        if (strcmp(record6->name, name) == 0) {
          
            record6->taillemax=taille;
             
   
    record6->tab = malloc(taille * sizeof(float));
    
    if (record6->tab == NULL) {
        printf("Erreur: mémoire insuffisante\n");
        free(record6);
        return;
    }
    int jr;
    for(jr=0;jr<taille;jr++){
      record6->tab[jr]=0; 
    }


      // printf("INSEEERT SUCCESSFUUUUUUUUUUUUUUUUUUUUUll",name); 
      }
        record6 = record6->next;
    }
     
     
    
	}

 void insererVal(char name[], char* value)
	{ 
     int index = hash(name);
    Record *record2 = table[index];
    while (record2 != NULL) {
        if (strcmp(record2->name, name) == 0) {
          
              // le nom est trouvé dans la table
      // record2->value = value[0];
        record2->value=strdup(value);
       //printf("Insertion Reussie %s \n",name); 
      }
        record2 = record2->next;
    }
    
	}

  void insererValTab(char name[],char* indexo, char* value)
	{ 
     int index = hash(name);
    Record *record11 = table[index];
    while (record11 != NULL) {
        if (strcmp(record11->name, name) == 0) {
          int interi= atoi(indexo);
              // le nom est trouvé dans la table
      // record2->value = value[0];
       if (interi>record11->taillemax)
       {
       // printf("-----------%f -------------",flt);
      printf("index impossible %d-- taille max est depasse ",interi);
       }
      else  record11->tab[interi-1]=atof(value);
       //printf("Insertion Reussie %s \n",name); 
      }
        record11 = record11->next;
    }
     
     
    
	}
 
 int Validindex(char name[], char* ind)
	{ 
     int index1 = hash(name);
    Record *record4 = table[index1];
    while (record4 != NULL) {
        if (strcmp(record4->name, name) == 0) {
         
         
          int inter= atoi(ind);
              // le nom est trouvé dans la table
      // record2->value = value[0];
       if (inter>record4->taillemax)
       {
       // printf("-----------%f -------------",flt);
      return 0;
       }
      else  return 1;
       //printf("Insertion Reussie %s \n",name); 
      

      }
        record4 = record4->next;
    }
     
     
    
	}
 
 
 /* char* GetVal(char name[])
	{ 
     int index = hash(name);
    Record *record4 = table[index];
    while (record4 != NULL) {
        if (strcmp(record4->name, name) == 0) {
          
              // le nom est trouvé dans la table
      // record2->value = value[0];
       // record2->value=strdup(value);
       //printf("Insertion Reussie %s \n",name); 
        return record4->value;
      }
        record4 = record4->next;
    }
     
     
    
	}*/

int Existe(char name[]){ //pour double declaration
int index = hash(name);
    Record *record3 = table[index];
    while (record3 != NULL) {
        if (strcmp(record3->name, name) == 0) {
          if(strcmp(record3->type," ")==0){
            return 1; } // le nom est trouvé dans la table
        }
        record3 = record3->next;
    }
    return 0;


}


/***Step 5 L'affichage du contenue de la table des symboles ***/
void afficherTSidf(){
  
printf("\n \n/----------------------------------Table des symboles IDF-----------------------------------/\n");
printf("/----------------------------------Table des symboles IDF-----------------------------------/\n");
printf("________________________________________________________________________________________________________\n");
printf("\t \t | Nom_Entite |  Code_Entite | Type_Entite | Val_Entite | Taille_Max(tab) | vals tab\n");
printf("________________________________________________________________________________________________________\n");
int i;
for (i = 0; i < TABLE_SIZE; i++) {
       printf("\n hash value %d \n",i);
      Record *record = table[i];
while (record != NULL) {
   if(record->taillemax==0){  printf("\t \t |%10s |%15s | %12s | %8s | %4d\n ", record->name, record->code, record->type,record->value, record->taillemax);}
   else {printf("\t \t |%10s |%15s | %12s | %8s | %4d      | \t [ ", record->name, record->code, record->type, record->value, record->taillemax);
    int jk;
    for (jk = 0; jk < record->taillemax; jk++) {
        //if(strcmp(record->tab[jk],"r")==0)
        //printf("%c", record->tab[jk]);
        //if (jk < record->taillemax - 1) {
            printf("|%g| ",record->tab[jk]);
        //}
    }
    printf(" ]\n");}
    record = record->next;
}}
}

void afficherTSsuite()
{int i;
 

printf("\n \n/----------------------------------Table des Mots cles -----------------------------------/\n");
printf("/----------------------------------Table des Mots cles -----------------------------------/\n");
printf("________________________________\n");
printf("| Nom_Entite |  Code_Entite\n");
printf("________________________________\n");
for(i=0;i<250;i++)
{	
	
    if(tabm[i].state==1){
      
           printf("|%10s  |%10s        |\n",tabm[i].name,tabm[i].type);
         }
		
         
      }


printf("\n \n/----------------------------------Table des Separateurs -----------------------------------/\n");
printf("/----------------------------------Table des Separateurs -----------------------------------/\n");
printf("________________________________\n");
printf("| Nom_Entite |  Code_Entite\n");
printf("________________________________\n");
for(i=0;i<250;i++)
{	
	
    if(tabs[i].state==1){
      
           printf("|%10s  |%10s        |\n",tabs[i].name,tabs[i].type);
           //printf("\t|%10s |%15s\n",tabs[i].name,tabs[i].type);
         }
		
         
      }

}

int GetNature(char name[]) //retourne la nature (idf,CNST)
		{
		char* z= "CONST";
    int index = hash(name);
    Record *record4 = table[index];
    while (record4 != NULL) {
        if (strcmp(record4->name, name) == 0) {
            if(strcmp(record4->type,z)==0)return 0;  // le nom est trouvé dans la table
        }
        record4 = record4->next;
    }
    return 1;  // le nom n'est pas trouvé dans la table

	}  

char *GetType(char name[]) // retourne le type de l'idf ou la const
		{
		
    int index = hash(name);
    Record *record = table[index];
    while (record != NULL) {
        if (strcmp(record->name, name) == 0) {
            return record->type;  // le nom est trouvé dans la table
        }
        record = record->next;
    }
    return "";  // le nom n'est pas trouvé dans la table

	}  

void checkVarUse(quad * q)
{
    int bol=0;
    int i=1;
    printf("Partie Optimisation: Verification de l'utilisation des variables:\n\n");
     for(i=1;i<16;i++)
    {		Record *record = table[i];
            while (record != NULL) {
                //printf("\n parcours %d \n ",i);
            //pour chaque noued (var) on vas EntiteInsert si la var est utilise au minimum une fois dans les quads
                if(strcmp(record->code,"IDF")==0){ //on ne veut pas afficher les constantes
                    
                    bol=0;
                    int k =0 ;
               // if(record->taillemax!=0)//cas tableau par exmpl Nom[] fla table est enregistre haka : Nom mais fles quads on utilise Nom[3] etc
                    //donc on vas comparer brk les car de lidf du tab avec strlen
                 //   {   
                      int length =  strlen(record->name); //printf("\nLA TAILLE DU TAB EST =%d \n",length);
                      //int a = atoi(record->taillemax);
                          for(k=0;k<qc;k++)//parcourir tout les quads 
                              { if((strcmp(record->type,"STRUCT")==0)||(strcmp(record->value,"VarEnrg")==0)||(strcmp(record->value,"nomprog")==0)) {bol=1;break;} //si idf est un struct wla une var de struct wla nomprog go next
                                else if(strncmp(q[k].opd1,record->name,length)== 0 || strncmp(q[k].opd2,record->name,length)== 0 || strncmp(q[k].res,record->name,length)== 0)
                                {bol=1;break;}//bol =1 : trouve
                              } 
                 //    }
             /*     else 
                  { int length =  strlen(record->name);
                    for(k=0;k<qc;k++)//parcourir tout les quads
                              { 
                                if(strncmp(q[k].opd1,record->name,length)== 0 || strncmp(q[k].opd2,record->name,length)== 0 || strncmp(q[k].res,record->name,length)== 0)
                                {bol=1;break;}//bol =1 : trouve
                              } 
                           }
                           */
                        
                if(bol==0)//non trouve on affiche un msg d'erreur
                        {  if(record->taillemax!=0) printf("\tWarning : Tableau ( %s ) declare mais pas utilise\n",record->name);
                        else printf("\tWarning : IDF ( %s ) declare mais pas utilise\n",record->name);
                          }
                  }

            record = record->next;
        }
      }
}

void optimisation()
{
    
   
  checkVarUse(QuadR); //marche 
  chekPropCopie(QuadR);	// marche
  SimplificationAlgebrique(QuadR); //marche
  checkRedondance(QuadR); //marche
	EliminationCodeInutile(QuadR);//  marche
	/*int i=0;
    for(i=0;i<qc-1;i++) //cette boucle supprime tout les quads qui ont le champ opt =""
    {
        if(strcmp(QuadR[i].opt,"")==0)
        {
            int j = 0;
            for(j=i;j<qc-1;j++)
            {
                QuadR[j].opt=strdup(QuadR[j+1].opt);
                QuadR[j].opd1=strdup(QuadR[j+1].opd1);
                QuadR[j].opd2=strdup(QuadR[j+1].opd2);
                QuadR[j].res=strdup(QuadR[j+1].res);
            }
            qc--;
        }
    }*/
}

//--------------------PARTIE GENERATION DU CODE OBJET ----------------------------------------

int isFloat(const char* str) {
  // Check if the string contains a decimal point
  if (strchr(str, '.') != NULL) {
      return 1;
    }
  
else   return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
//-------------------------------------partie generation du code objet------------------------------------

FILE *Assembly;

int sauv_etiq[200];
int pos=0;
void ToAssembly(){
	
	Assembly=fopen("CodeObjet.asm","w+"); //ouvrir fichier en mode lecture + ecriture
	int i;
	//Nom du programme   Title : ....
   for (i = 0; i < TABLE_SIZE; i++) {
    Record *record = table[i];
    while (record != NULL) {
        if (strcmp(record->value,"nomprog") == 0) {
            	fprintf(Assembly,"\nTITLE : %s\n", record->name);  // le nom est trouvé dans la table
        }
        record = record->next;
    }
    }
	
	
	fprintf(Assembly,"\nPILE SEGMENT stack\n");// declarer la pile
	fprintf(Assembly,"\t\t100 DD dup (?)\n");
	fprintf(Assembly,"PILE ENDS\n"); //fin dec pile
	
	
	fprintf(Assembly,"\nDATA SEGMENT\n"); //debut du segment data
	
  //chaque variable on utilise un type de declaration // DW = int // DD = float // X+ dup() pour les tabs
  for (i = 0; i < TABLE_SIZE; i++) {//parcourir la liste des symboles
    Record *record = table[i];
    while (record != NULL) {
        if ((strcmp(record->code,"IDF") == 0)&&(strcmp(record->code,"CONST") != 0)&&(strcmp(record->value,"VarEnrg") != 0)) {
           if(record->taillemax==0) { //cas des vars simples , pas les tableaux
            if (strcmp(record->type,"integer") == 0) {fprintf(Assembly,"\t %s DW 0\n",record->name);} //cas integer
            else if(strcmp(record->type,"float") == 0){fprintf(Assembly,"\t %s DD 0.0\n",record->name);}//cas float
              else if(strcmp(record->type,"CONST") == 0){ //si c var est une const on verifie la val
                //isFloat retourne 1 si record->value est un float sinon 0 (la fonction recherche un point dans le string)
                if(isFloat(record->value)==1){fprintf(Assembly,"\t %s DD %s\n",record->name,record->value);}//float
                else fprintf(Assembly,"\t %s DW %s\n",record->name,record->value);}//integer
            }
            else{ //cas declaration tableau : 2 cas soit entier soit float
               if (strcmp(record->type,"integer") == 0) {fprintf(Assembly,"\t %s DW 0 DUP(%d)\n",record->name,record->taillemax);}
           else if (strcmp(record->type,"float") == 0) {fprintf(Assembly,"\t %s DD 0 DUP(%d)\n",record->name,record->taillemax);}   
            }
        }
       
        record = record->next;
    }
    }

	fprintf(Assembly,"DATA ENDS\n");  //partie data finie

		
	//CODE SEGMENT
	fprintf(Assembly,"\nCODE SEGMENT\n"); //debut code segment
		fprintf(Assembly,"BEGIN:\n"); //begin
		fprintf(Assembly,"\t\tASSUME SS: PILE, DS: DATA, CS: CODE\n"); //charger DATA
		
				fprintf(Assembly,"\t\t\tMov AX,DATA\n");
				fprintf(Assembly,"\t\t\tMov DX,AX\n\n");
				
				FromQuad(QuadR); //appeler FromQuad pour generer le code Assembleur depuis les quads

				
				
	fprintf(Assembly,"CODE ENDS\n"); // code ends 
	fprintf(Assembly,"END BEGIN\n"); //end begin
		
	fclose(Assembly); //fermer le fichier
}



void FromQuad(quad *q)
{
	int k=0;
	for(k=0;k<qc;k++)
	{
		if(q[k].opt[0]=='B') {sauv_etiq[pos]=atoi(q[k].opd1); pos++;}
	}
	char * operation = malloc(sizeof(char*));
    int i=0;
    for(i=0;i<qc;i++)
    {
		int ii=0;
		for(ii=0;ii<pos;ii++)
		{
			if(i==sauv_etiq[ii]){ fprintf(Assembly,"etiq [ %d ] : \n",i);}
		}
		
        if(strcmp(q[i].opt,"+")==0 || strcmp(q[i].opt,"-")==0 || strcmp(q[i].opt,"*")==0 || strcmp(q[i].opt,"/")==0)
		{
			switch(q[i].opt[0])
			{
				case '+' : strcpy(operation,"ADD");  //cas quad arithm (+,,,)
						   break; 
				case '-' : strcpy(operation,"SUB"); //cas quad arithm (-,,,)
						   break;
				case '*' : strcpy(operation,"MUL"); //cas quad arithm (*,,,)
						   break;
				case '/' : strcpy(operation,"DIV"); //cas quad arithm (/,,,)
						   break;
			}
			if((q[i].opd1[0]=='T') && (q[i].opd2[0]=='T')) //cas quad arithm (opr,T1,T2,res)
			{
				fprintf(Assembly,"\t\t\tPOP AX\n");
				fprintf(Assembly,"\t\t\tPOP BX\n");
				fprintf(Assembly,"\t\t\t%s AX,BX\n",operation);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
			else if(q[i].opd1[0]=='T')      //cas quad arithm (opr,T1,opd2,res)
			{
				fprintf(Assembly,"\t\t\tPOP AX\n");
				fprintf(Assembly,"\t\t\t%s AX,%s\n",operation,q[i].opd2);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
			else if(q[i].opd2[0]=='T')      //cas quad arithm (opr,opd1,T1,res)
			{
				fprintf(Assembly,"\t\t\tPOP AX\n");
				fprintf(Assembly,"\t\t\t%s AX,%s\n",operation,q[i].opd1);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
			else                            //cas quad arithm (opr,opd1,opd2,res)  PAS DE TEMPORAIRES
			{
				fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].opd1);
				fprintf(Assembly,"\t\t\t%s AX,%s\n",operation,q[i].opd2);
				fprintf(Assembly,"\t\t\tPUSH AX\n");
			}
		}
		
		else if(q[i].opt[0]=='=')//quad affectation (=,,,)
			{
				if(q[i].opd1[0]=='T')// cas: (=,T,,A)
				{
					fprintf(Assembly,"\t\t\tPOP AX\n");
					fprintf(Assembly,"\t\t\tMOV %s,AX\n",q[i].res);
				}
				else if(q[i].res[0]=='T')//cas: (=,A,,T2)
				{
					fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].opd1);
					fprintf(Assembly,"\t\t\tPUSH AX\n");
				}
				else //cas: (=,B,,A)
				{
					fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].opd1);
					fprintf(Assembly,"\t\t\tMOV %s,AX\n",q[i].res);
				}
			}
			else if( q[i].opt[0]=='B')// quads jumps 
			{
				
				if(strcmp(q[i].opt,"BNE")==0 || strcmp(q[i].opt,"BNZ")==0)// quad du not / or
				{
					strcpy(operation,"JNE"); //jump if not equal en assembleur
				} 
				else if (strcmp(q[i].opt,"BLE")==0)  // quad (BLE,,opd1,opd2)
				{
					strcpy(operation,"JLE");//jump if less or equal en assembleur
				}
				else if (strcmp(q[i].opt,"BGE")==0) // quad (BGE,,opd1,opd2)
				{
					strcpy(operation,"JGE"); //jump if greater or equal en assembleur
				}
				else if(strcmp(q[i].opt,"BG")==0) // quad (BG,,opd1,opd2)
				{
					strcpy(operation,"JG"); //jump if greater en assembleur
				}
				else if(strcmp(q[i].opt,"BL")==0)  // quad (BL,,opd1,opd2)
				{
					strcpy(operation,"JL"); //jump if less en assembleur
				}
				else if(strcmp(q[i].opt,"BE")==0 || strcmp(q[i].opt,"BZ")==0 ) // BZ car on vas comparer si equal a 0 et BE evident
				{   // quad (BE,,opd1,opd2)    // quad (BZ,,opd1,opd2)
					strcpy(operation,"JE"); //jump if equal en assembleur
				}
				
				if(q[i].opt[1] != 'R')//cas Quad n'est pas un BR
				{
					if(strcmp(q[i].opt,"BZ")==0) // les quads BZ on doit utiliser CMP pour comparer l'operande avec 0
					{
						if(q[i].opd2[0]=='T') fprintf(Assembly,"\t\t\tPOP AX\n"); // si opd1 est un T on doit POP AX
						else fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].opd2); //sinon on fait MOV AX,variable
						
						fprintf(Assembly,"\t\t\tCMP AX,0\n");           // CMP AX,0    // Ax contient var et on compare ici avec 0
						fprintf(Assembly,"\t\t\t%s etiq[ %s ]\n",operation,q[i].opd1);  // JLE(exmple) etiq[ 123 ] 
					}
					else if(strcmp(q[i].opt,"BNZ")==0)
					{
						if(q[i].opd2[0]=='T') fprintf(Assembly,"\t\t\tPOP AX\n"); // si opd1 est un T on doit POP AX
						else fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].opd2); //sinon on fait MOV AX,variable
						
						fprintf(Assembly,"\t\t\tCMP AX,0\n");         // CMP AX,0    // Ax contient var et on compare ici avec 0
						fprintf(Assembly,"\t\t\t%s etiq[ %s ]\n",operation,q[i].opd1); // JLE(exmple) etiq[ 123 ]
					}
					else //reste des jump BL,BG,BE,BNE,BGE,BLE
					{
						if(q[i].opd2[0]=='T') fprintf(Assembly,"\t\t\tPOP AX\n"); // si opd1 est un T on doit POP AX
						else fprintf(Assembly,"\t\t\tMOV AX,%s\n",q[i].opd2);   //sinon on fait MOV AX,variable

						if(q[i].res[0]=='T') fprintf(Assembly,"\t\t\tPOP BX\n"); // si res est un T on doit POP BX
						else fprintf(Assembly,"\t\t\tMOV BX,%s\n",q[i].res);     //sinon on fait MOV BX,variable

						
						fprintf(Assembly,"\t\t\tCMP AX,BX\n");                  // on compare entre AX et BX, CMP AX,BX 
						fprintf(Assembly,"\t\t\t%s etiq[ %s ]\n",operation,q[i].opd1);  //si AX>=BX  JGE etiq[num]
					}
					

				}
				else 
				{
					fprintf(Assembly,"\t\t\tJMP etiq[ %s ]\n",q[i].opd1); //cas quad BR (BR,etiq,,)
				}
			}

    }
}







#endif // TS_H
