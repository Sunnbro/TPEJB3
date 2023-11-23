#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include  "quad.h"

//cretion d'1 quadruplet
void createQuad(char *opt, char *opd1, char *opd2, char *res){
	QuadR[qc].opt=strdup(opt);
	QuadR[qc].opd1=strdup(opd1);
	QuadR[qc].opd2=strdup(opd2);
	QuadR[qc].res=strdup(res);
	qc++;
}

//convert interger to string
char* ToSTR(int i){
	char s[15];
	sprintf(s,"%d",i);
	return strdup(s);
}

//creation d'1 quad arithmeitque
void createQuadA(int type, char *cond1, char *cond2, char *res){
	char *TypeBR;
	switch(type){
		case 1 :{//1==> "==" (égale)
			TypeBR=strdup("BNE");
		}
		break;
		case 2 :{//2==> "!=" (different)
			TypeBR=strdup("BE");
		}
		break;
		case 3 :{//3==> ">=" higher Or Equal
			TypeBR=strdup("BL");
		}
		break;
		case 4 :{//4==> "<=" lower Or Equal
			TypeBR=strdup("BG");
		}
		break;
		case 5 :{//5==> "<" lower
			TypeBR=strdup("BGE");
		}
		break;
		case 6 :{//6==> ">" higher
			TypeBR=strdup("BLE");
		}
		break;
	}
	createQuad(TypeBR,"",cond1,cond2);
    
}

//creation d'1 quad logique
void createQuadL(int type, char *cond1, char *cond2, char *res){
	switch(type){
		case 1 :{//1==> not
			createQuad("BNZ","",cond1,"");
			
		}
		break;
		case 2 :{//2==> or
			createQuad("BNZ",ToSTR(qc+3),cond1,"");
			createQuad("BNZ",ToSTR(qc+2),cond2,"");
            createQuad("BR","","","");
			
		}
		break;
		case 3 :{//3==> and
			createQuad("BZ",ToSTR(qc+2),cond1,"");
			createQuad("BZ",ToSTR(qc+1),cond2,"");
			createQuad("BR","","","");
		}
		break;
	}
}
//les piles pour l'imbriquation

//empiler integer
void empiler_Int(pile **p,int donne){
	pile *new;
	char str[10];
	new=(pile*)malloc(sizeof(pile));
	sprintf(str,"%d",donne);
	new->donnee=strdup(str);
	//update chaining
	new->prc=*p;
	*p=new;
}

//get first ele on the  pile
char* first(pile*p){
	return p->donnee;
}

//depiler
char* depiler(pile**p){
	char *res;
	pile *H;
	H=*p;
	res=strdup(H->donnee);
	*p=H->prc;
	free(H);
	return res;
}


void displayQuad(){
	int i;
	printf("\n::::::::::::::::::::::::::::::: Quadruplets :::::::::::::::::::::::::::::::::::\n");
	printf("___________________________________________________________________\n");
	for(i=0;i<qc;i++){
		printf("\n|\t %d - ( %s  ,  %s  ,  %s  ,  %s )",i,QuadR[i].opt,QuadR[i].opd1,QuadR[i].opd2,QuadR[i].res);
	}
	printf("\n___________________________________________________________________\n");
}




void EliminationCodeInutile(quad * q){  //X=t3 ... dans les quads suivants yas pas un opd1 ou opd2 qui contient X donc affectation inutile n7iha 
int i=0;
int bol=0;
    for (i=0;i<qc;i++)
    { bol=0;
        if(q[i].opt[0] == '=')
        {
             int k;
                         for(k=i+1;k<qc;k++) //on va parcourir pour savoir ou se trouve le quad qui utilise la var 
                        { 
                    if(strcmp(q[i].res,q[k].opd1)==0 || strcmp(q[i].res,q[k].opd2)==0 || strcmp(q[i].res,q[k].res)==0){ //x=2     (+,2,3,X)  
                        bol=1; break;
                    } //si reutilise au moins une fois -> rien enlever     
                        }
            if(bol==0){//var non utilise apres la derniere affectation donc inutile
                            q[i].opt=strdup(""); //on supprime le quad 
                            q[i].opd1=strdup("");
                            q[i].opd2=strdup("");
                            q[i].res=strdup("");
                          /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */

            }
        }

    }   


}

void checkRedondance(quad * q) //Redondance  a=4*j  z=4*j
{
    int i=0;
    for (i=0;i<qc;i++)
    {
        if(q[i].opt[0]=='+' || q[i].opt[0]=='-' || q[i].opt[0]=='*' || q[i].opt[0]=='/') //verifier tout les quads arithmetiques
        {
            int k=0;
            for(k=i+1;k<qc;k++)
            {
            if(strcmp(q[i].opt,q[k].opt)==0 && strcmp(q[i].opd1,q[k].opd1)==0 && strcmp(q[i].opd2,q[k].opd2)==0) //pas besoin de comparer qc[].res
             //si c'est le meme quad = meme expression arithmetique exemple(ici 1 et 3):    
             // 1-(+,1,2,T1) 2-(=,T1,,A) 3-(+,1,2,T2) 4-(=,T2,,B)
                    {   
                        int jz;
                         for(jz=k+1;jz<qc;jz++) //on va parcourir pour savoir ou se trouve le quad qui utilise le 2eme quad identique 
                        { //(exemple d'en haut, on cherche le (4) qui utilise (3))
                            if(q[jz].opt[0] == '=' && strcmp(q[k].res,q[jz].opd1)==0){ //le quad(4) doit etre de la forme (=,T2,,res)
                            q[jz].opd1=strdup(q[i].res); //une fois trouve on remplace T2 par T1
                            q[k].opt=strdup(""); //on supprime le quad (3) : (+,1,2,T2)
                            q[k].opd1=strdup("");
                            q[k].opd2=strdup("");
                            q[k].res=strdup("");
                         /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */
                             }

                         }

                    }        
               }
        }
    }
}


void SimplificationAlgebrique(quad *q)
{
    int i=0;
    for (i=0;i<qc;i++)
    {
        if(q[i].opt[0]=='*') //exemple A*2 tweli A+A
        {
            if(q[i].opd1[0]=='2') // cas win 2*A -> tweli (+,A,A,X)
            {
                q[i].opt=strdup("+");
                q[i].opd1=strdup(q[i].opd2);
                q[i].opd2=strdup(q[i].opd2);
            }
            else if (q[i].opd2[0]=='2') // cas win A*2 0> tweli (+,A,A,X)
            {
                q[i].opt=strdup("+");
                q[i].opd1=strdup(q[i].opd1);
                q[i].opd2=strdup(q[i].opd1);
            }
        }
        if(q[i].opt[0]=='+'){ //calcul inutile : x=A+0  (+,A,0,T1) (=,T1,,B)
                    if(strcmp(q[i].opd1,"0")==0 ){     // cas win 0 ykon f 2eme champs (op1) (+,0,A,T1) 
                    int k=0;
                    for(k=i+1;k<qc;k++)
                    {   if(q[k].opt[0]=='=' && strcmp(q[i].res,q[k].opd1)==0){ //(=,T1,,B) yweli (=,A,,B)
                        q[k].opd1=strdup(q[i].opd2);
                        q[i].opt=strdup("");    //supprime loperation inutile 
                        q[i].opd1=strdup("");
                        q[i].opd2=strdup("");
                        q[i].res=strdup("");
                     /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */
                        }
                    }
                }
       		 else if(strcmp(q[i].opd2,"0")==0 ){ // cas win 0 ykon f 3eme champs (op1) (+,A,0,T1)
                    int k=0;
                    for(k=i+1;k<qc;k++)
                    {   if(q[k].opt[0]=='=' && strcmp(q[i].res,q[k].opd1)==0){ //(=,T1,,B) yweli (=,A,,B)
                        q[k].opd1=strdup(q[i].opd1);
                        q[i].opt=strdup("");    //supprime loperation inutile 
                        q[i].opd1=strdup("");
                        q[i].opd2=strdup("");
                        q[i].res=strdup("");
                     /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */
                        }
                    }
                }
        }

            
        
        if(q[i].opt[0]=='-'){ //calcul inutile : x=a-a (-,A,A,T1) (=,T1,,X)
            if(strcmp(q[i].opd1,q[i].opd2)==0){ //compare si op1 w op2 kifkif
                 int k=0;
                 for(k=i+1;k<qc;k++)
            {       if(q[k].opt[0]=='=' && strcmp(q[i].res,q[k].opd1)==0){ //compare si T1 existe f affectation lte7t
                    q[k].opd1=strdup("0");      // (=,T1,,X) -> tweli (=,0,,X)
                        q[i].opt=strdup("");    //supprime loperation inutile du moins
                        q[i].opd1=strdup("");
                        q[i].opd2=strdup("");
                        q[i].res=strdup("");
                     /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */
                        
            }
                           
           
                
            }
        }
    }
}
}

void chekPropCopie(quad * q) //propag express
{
    int i=0;
    for (i=0;i<qc;i++)
    {
        if(q[i].opt[0]=='=')
        {
            int k=0;
            for(k=i+1;k<qc;k++)
            {
                if(strcmp(q[i].opd1,q[k].res)==0 || strcmp(q[i].res,q[k].res)==0) // exmpl1: Y=1 X=Y+2; Y=3; break pcq on peut plus remplacer pcq les valeurs tbedlou
                    break;      // exmpl2: X=2; X=3; Y=X+2; break pcq on peut plus remplacer pcq les valeurs tbedlou (rana f le quad X=2 on va plutot l X=3 donc break)
                if(q[k].opt[0]=='+' || q[k].opt[0]=='*' || q[k].opt[0]=='-' || q[k].opt[0]=='/')
                {
                    if(strcmp(q[i].res,q[k].opd1)==0) // exmple: X=2; Y=X+1; ici X est opd1 dans le 2eme quad, donc on remplace w supprime le quad 1
                    {
                        q[k].opd1=strdup(q[i].opd1); //remplace par la 2 au lieu de X
                        q[i].opt=strdup("");    //supprime le quad 1 
                        q[i].opd1=strdup("");
                        q[i].opd2=strdup("");
                        q[i].res=strdup("");
                    /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */
                        
                    }
                    else if(strcmp(q[i].res,q[k].opd2)==0) //idem juste ici Y=1+X;
                    {
                        q[k].opd2=strdup(q[i].opd1);//remplace
                        q[i].opt=strdup("");    //supprime le quad 1
                        q[i].opd1=strdup("");
                        q[i].opd2=strdup("");
                        q[i].res=strdup("");
                     /*    int rs;
                        for ( rs = i; rs <qc ; rs++)
                        {  if(q[rs].opt[0]=='B'){ q[rs].opd1=ToSTR(atoi(q[rs].opd1)-1);}
                            
                        } */
                    }
                }
            }
        }
    }
}
