#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include"polynom.h"
#include <ctype.h>

using namespace std;

void removetoile(char *str)
{
int count = 0;
 
    for (int i = 0; str[i]; i++)
        if (str[i] != '*')
            str[count++] = str[i]; 
    str[count] = '\0';
}
void removeSpaces(char *str)
{
   
    int count = 0;
 

    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];
                                
    str[count] = '\0';
}
bool cherche(char*str,char c){
	for(int i=0;i<strlen(str);i++){
		if(str[i]==c) return  true;
	}
	 return false;
}
void ordre(char t[]){	
for(int i=0;i<strlen(t);i++){
if((t[i]=='-')&& t[i+1]!='+'&&t[i-1]!='+'&& i-1!=-1){ 
for(int a=strlen(t);a>=i;a--){
	t[a+1]=t[a];	
}
t[i]='+';
}	}
for(int i=0;i<strlen(t);i++){
if((((t[i]=='+')&& t[i+1]=='X')||(t[i]=='-')&& t[i+1]=='X')&&strlen(t)>1){ 
for(int a=strlen(t);a>=i;a--){
	t[a+1]=t[a];	
}
t[i+1]='1';}
else if(t[0]=='X'){
for(int a=strlen(t);a>=i;a--){
	t[a+1]=t[a];
}
t[0]='1';
}}
for(int i=0;i<strlen(t);i++){	
	if((t[i]=='+')&& t[i-1]=='-'&& i!=0){
		char c ;
		c=t[i];
		t[i]=t[i-1];
		t[i-1]=c;
}}
removeSpaces(t);
	if(t[0]=='+'){
		t[0]=' ';}
	removeSpaces(t);}
 
polynome* bbbb( char str[]){
	int x,d,i,j,s=0,E,q[100],p=0,D=0,a,taille,d1,d2,d3;
	char y,z,v,s1,s2,s3;
	char *c1,*b2,*f1;
    polynome *f=NULL; 
	ordre(str);
	 for(i=0;i<=strlen(str);i++){
	 	p++;
	  if((str[i]=='+' xor str[i]=='\0')){ 
	 char *k=(char*) malloc(30 *sizeof(char));
	  for(j=0;j<p-1;j++){
	  	k[p-2-j]=str[i-j-1];
	  }
//	cas1
	   if(cherche(k,'/')==true &&(cherche(k,'X')==true) &&(cherche(k,'^')==true))
	{
	 sscanf(k,"%ld/%dX^%d",&d1,&d2,&d3); //3/1Y^4
	 fraction d(d1,d2);
     node h(d3,d);
     ajouter(&f,h);
	 delete(k);
	 

	 p=0;}
//cas 2
	 else if( cherche(k,'/')==true &&(cherche(k,'X')==false) &&(cherche(k,'^')==false)   ){
	 	{
	 sscanf(k,"%ld/%d",&d1,&d2); //   2/3
	 fraction d(d1,d2);
     node h(0,d);
     ajouter(&f,h);
	 delete(k);
	 p=0;}
	 }
//	 cas 3
     else if( cherche(k,'/')==false &&(cherche(k,'X')==false) &&(cherche(k,'^')==false)   )
	 	{
	 sscanf(k,"%ld",&d1); //3
	 fraction d(d1);
     node h(0,d);
     ajouter(&f,h);
	 delete(k);
	 p=0;}
	 

//	CAS 4
else if( cherche(k,'/')==false &&(cherche(k,'X')==true) &&(cherche(k,'^')==true)   )
	 	{
	 sscanf(k,"%ldX^%d",&d1,&d2); //3X^4
	 fraction d(d1);
     node h(d2,d);
     ajouter(&f,h);
	 delete(k);
	 p=0;}
//CAS 5
else if(cherche(k,'/')==false &&(cherche(k,'X')==true) &&(cherche(k,'^')==false)){//2y
	  sscanf(k,"%ldX",&d1);
	 fraction d(d1);
     node h(1,d); 
     ajouter(&f,h);
	 delete(k);
	 p=0;
}
//CAS 6
else if(cherche(k,'/')==true &&(cherche(k,'X')==true) &&(cherche(k,'^')==false)){
	sscanf(k,"%ld/%dX",&d1,&d2);
	 fraction d(d1,d2);
     node h(1,d); 
     ajouter(&f,h);
	 delete(k);
	 p=0;
}
}
}
return f; 
}
	void intro(){
  system("cls");
  system("color F0");
  cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
  cout<<"|                                                                                                                     |"<<endl;
  cout<<"|                                                                                                                     |"<<endl;
  cout<<"|                                                         BIENVENUE                                                   |"<<endl;
  cout<<"|                                             REALISE PAR :                                                           |"<<endl;
  cout<<"|                                   ABDOU && SALMA                                                                    |"<<endl;
  cout<<"|---------------------------------------------------------------------------------------------------------------------|"<<endl;
  getch();
  system("cls");
}

int Menu()
{
	
	
		system("cls"); //efface l'écran
		printf("             ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n");
		printf("             º                                                      º\n");
		printf("             º                    Menu Principal                    º\n");
		printf("             º                                                      º\n");
		printf("             ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n");
		printf("\n                1- Saisir un Polynome:LET P='Polynome a saisir'");
		printf("\n                2- modifier un Polynome:SET P='polynome a modifier' ");
		printf("\n                3- Afficher le Polynome:DISPLAY P OU DISPLAY Q");
		printf("\n                4- Addition de deux polynomes : ADD P,Q OU ADD Q,P");
		printf("\n                5- Soustraction de deux polynomes : SUB P,Q OU SUB Q,P");
		printf("\n                6- Multiplication de deux polynomes :MUL P,Q OU MUL Q,P");
        printf("\n                7- Puissance n eme d’un polynome : POW P, 3");
        printf("\n                8- Affectation d’un polynome a un autre : AFFECT P, Q");
        printf("\n                9- Derivee d’un polynome : DER P");
        printf("\n                10-Integration d’un polynome : INT P");
        printf("\n                11-Evaluation d’un polynome : EVAL P for X=5");
		printf("\n                12- Arret du programme : EXIT\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n:");
		getch();
		system("cls");}
bool utilisateur(char t[]){
	int i,j,k;
	bool f;
//CAS 1
if(cherche(t,'/')==true &&(cherche(t,'X')==true) &&(cherche(t,'^')==true))
{      int g=0;
	if(t[0]=='-'){
		g++;}
		for(i=g;t[i]!='/';i++){
			f=f&& t[i]-'0'<=9 && t[i]-'0'>=0;
		}
		for(j=i+1;t[j]!='X';j++){
		f=f&& t[j]-'0'<=9 && t[j]-'0'>=0;
		}
		f=f&&t[j]=='X';
		j=j+1;
		f=f&&t[j]=='^';
	for(k=j+1;k<strlen(t);k++){
			f=f&& t[k]-'0'<=9 &&t[k]-'0'>=0;
	}}
//CAS 2;
else if(cherche(t,'/')==true &&(cherche(t,'X')==false) &&(cherche(t,'^')==false)){//3/2
	 int g=0;
	if(t[0]=='-'){
		g++;
			}
	for(i=g;t[i]!='/';i++){
			f=f&& t[i]-'0'<=9 && t[i]-'0'>=0;
		}
		for(j=i+1;j<strlen(t);j++){
		f=f&& t[j]-'0'<=9 && t[j]-'0'>=0;
		}
}
//CAS3
else if(cherche(t,'/')==false &&(cherche(t,'X')==false) &&(cherche(t,'^')==false)){//3
	int g=0;
	if(t[0]=='-'){
		g++;
			}
	for(i=g;i<strlen(t);i++){
			f=f&& t[i]-'0'<=9 && t[i]-'0'>=0;
		}
}
//CAS4
else if(cherche(t,'/')==false &&(cherche(t,'X')==true) &&(cherche(t,'^')==true)){//3x^2
	    int g=0;
	if(t[0]=='-'){
		g++;
			}
		for(i=g;t[i]!='X';i++){
			f=f&& t[i]-'0'<=9 && t[i]-'0'>=0;
		}
		f=f&& t[i]=='X';
		i=i+1;
		f=f&&t[i]=='^';
	for(k=i+1;k<strlen(t);k++){
			f=f&& t[k]-'0'<=9 && t[k]-'0'>=0;
		}

}
//CAS 5
else if(cherche(t,'/')==false &&(cherche(t,'X')==true) &&(cherche(t,'^')==false)){//2x
   int g=0;
	if(t[0]=='-'){
		g++;
			}
		for(i=g;i<strlen(t)-1;i++){
			f=f&& t[i]-'0'<=9 && t[i]-'0'>=0;
		}
}
//CAS 6
else if(cherche(t,'/')==true &&(cherche(t,'X')==true) &&(cherche(t,'^')==false)) {//a/bx
       int g=0;
	if(t[0]=='-'){
		g++;}
		for(i=0;t[i]!='/';i++){
			f=f&& t[i]-'0'<=9 && t[i]-'0'>=0;
		}
		for(j=i+1;j<strlen(t)-1;j++){
		f=f&& t[j]-'0'<=9 && t[j]-'0'>=0;
		}	
}
return f;
}
bool cccc(char*t){
	 system("cls");
	char f[30];
	int i=0;
	bool s=true;
	char ff[2]=" ";
	strcpy(f,t);
	int j=strlen(t);
int k=0;
while(i<strlen(f)){	
strtok(t,"+");
while(f[i]!='+'||i==strlen(f)-1){
i++;
}
puts(ff);
s=s&&utilisateur(t);
strcpy(t,f+i+1);
i++;
}
 system("cls");
return s;
}

int main(){
	char ff[30];
	 intro();
	 Menu();
	char cmQ;
	char q1,q2,q3,q4;
	int x,d,i,j,s=0,E,q[30],p=0,D=0,a,taille,d1,d2,d3,cmp;
	char y,z,v,s1,s2,s3;
	char *c1,*b2,*str,*f1;
    polynome *Q=NULL; 
    polynome *P=NULL;
    polynome *PQ=NULL;

    while(1){
    f1=new char[200];
    c1=new char[200];
    cout<<">>> ";
    gets(c1);
    char f2[30];
    strcpy(f1,c1);
    strcpy(f2,c1);
   char*b3=new char[10];
   b2=new char[200];
   b2=strtok(f1," ");
   if(!strcmp(b2,"LET")){
   	system("cls");
   removeSpaces(c1);
   removetoile(c1);
    str=new char[200];
       str=strchr(c1,'=');
        str=str+1;
		ordre(str);
    strcpy(ff,str);

if(cccc(ff)==false){
	goto ligne;}
    if(P==NULL){
        q1=c1[3];
       P=bbbb(str);
    cout<<"bien insere le:"<<q1;}
	else if(c1[3]!=q1 && Q==NULL){
			q2=c1[3];
		Q=bbbb(str);
		cout<<"bien insere le:"<<q2;
	}
	else  {cout<<"erreur";}
	delete f1;
	delete c1;
	cout<<endl;
	getch();
	system("cls");
	}
else if(!strcmp(b2,"DISPLAY")){
	system("cls");
	removeSpaces(c1);
	if(c1[7]==q1 && P!=NULL){
	cout<<q1<<"=";
	affiche_polynome(P);}
	else if(c1[7]==q2 && Q!=NULL){
	cout<<q2<<"=";
	affiche_polynome(Q);}
	else {
	cout<<"impossible";}
	cout<<endl;
	delete f1;
	delete c1;
	getch();
	system("cls");
}
else if(!strcmp(b2,"SET")){
	system("cls");
	removeSpaces(c1);
	removetoile(c1);
    str=new char[200];
       str=strchr(c1,'=');
        str=str+1; 
        strcpy(ff,str);
if(cccc(ff)==false){
	goto ligne;}
	if(c1[3]==q1 && P!=NULL){
		delete P;
		P=bbbb(str);
		cout<<"bien modifie le "<<q1;}
	else if(c1[3]==q2 &&Q!=NULL){
	delete Q;
	Q=bbbb(str);
cout<<"bien modifie le "<<q2;}
else cout<<"impossible";
delete f1;
delete c1;
getch();
system("cls");
cout<<endl;
}
else if(!strcmp(b2,"ADD")){
	system("cls");
	removeSpaces(c1);
	if(((c1[3]==q2 &&c1[4]==','&&c1[5]==q1)||(c1[3]==q1 &&c1[4]==','&&c1[5]==q2)) &&P!=NULL&&Q!=NULL){
	affiche_polynome(addition(P,Q)); 
	}
	else cout<<"vous n'avez pas inserer l'un des polynome";
cout<<endl;
getch();
system("cls");
}
else if(!strcmp(b2,"SUB")){
system("cls");
	removeSpaces(c1);
	if(c1[3]==q1&&c1[4]==','&&c1[5]==q2 &&P!=NULL&&Q!=NULL){
	affiche_polynome(SUTT(P,Q)); 
	}
	else if(c1[3]==q2 &&c1[4]==','&&c1[5]==q1 &&P!=NULL&&Q!=NULL){
		affiche_polynome(SUTT(Q,P));
	}
	else cout<<"vous n'avez pas inserer l'un des polynome";
cout<<endl;
getch();
system("cls");
}
else if(!strcmp(b2,"MUL")){
system("cls");
	removeSpaces(c1);
	if(((c1[3]==q1 &&c1[4]==','&&c1[5]==q2)||(c1[3]==q2 &&c1[4]==','&&c1[5]==q1))&&P!=NULL&&Q!=NULL){
		affiche_polynome(multipq(P,Q)); 
	}
	else cout<<"vous n'avez pas inserer l'un des polynome";
cout<<endl;
getch();
system("cls");
}
else if(!strcmp(b2,"POW")){
system("cls");
			removeSpaces(c1); 
	if(c1[3]==q1&& P!=NULL && c1[4]==','&& c1[5]-'0'>=0&&c1[5]-'0'<=9){
		affiche_polynome(poww(P,c1[5]-'0'));}
	else if(P==NULL &&c1[5]-'0'>=0&&c1[5]-'0'<=9){
		cout<<"vous n'avez pas inserier le polynome"<<c1[3];
	}
	else if(c1[3]==q1&& P!=NULL && c1[4]==','&& (c1[5]-'0'<0||c1[5]-'0'>9))
	{
	 cout<<"erreur du puissance";
	}
	else if(c1[3]!=q1&& P==NULL && c1[4]==','&& (c1[5]-'0'<0||c1[5]-'0'>9))
	{
		cout<<"erreur sur la polynome end la puissance";
	}
else if(c1[3]==q2&& Q!=NULL && c1[4]==','&& c1[5]-'0'>=0&&c1[5]-'0'<=9){
		affiche_polynome(poww(Q,c1[5]-'0'));}
	else if(Q==NULL &&c1[5]-'0'>=0&&c1[5]-'0'<=9){
		cout<<"vous n'avez pas inserie le polynome"<<c1[3];
	}
	else if(c1[3]==q2&& Q!=NULL && c1[4]==','&& (c1[5]-'0'<0||c1[5]-'0'>9))
	{
	 cout<<"erreur du puissance";
	}
	else if(c1[3]!=q1&& Q==NULL && c1[4]==','&& (c1[5]-'0'<0||c1[5]-'0'>9))
	{
		cout<<"erreur sur la polynome end la puissance";
}
cout<<endl;
getch();
system("cls");
 } 
 else if(!strcmp(b2,"AFFECT")){
system("cls");
 	 removeSpaces(c1);//AFFECTP,Q
 	if(c1[6]==q1&&c1[7]==','&&c1[8]==q2  ){
 		affectation(&Q,P);
 		cout<<"l affectation a était effectué avec succès.";
	 }
	 else if(c1[6]==q2&&c1[7]==','&&c1[8]==q1){
	 	 		affectation(&P,Q);
	 	 		cout<<"l affectation a était effectué avec succès.";
	 }
	 else cout<<"cette operation est impossible";
	 cout<<endl;
	 getch();
system("cls");
 }
 else if(!strcmp(b2,"DER")){
system("cls");
	removeSpaces(c1);
	if(c1[3]==q1&& P!=NULL){
		affiche_polynome(derive(P));}
	else if(c1[3]==q2 &&Q!=NULL){
	 affiche_polynome(derive(Q));
	}
	else cout<<"vous n'avez pas inserer le polynome ";
cout<<endl;
	 getch();
system("cls");
}
else if(!strcmp(b2,"INT")){
system("cls");
	removeSpaces(c1);
	if(c1[3]==q1&& P!=NULL){
		affiche_polynome(integrer(P));}
	else if(c1[3]==q2 &&Q!=NULL){
	 affiche_polynome(integrer(Q));
	}
	else cout<<"vous n'avez pas inserer le polynome ";
cout<<endl;
getch();
system("cls");
}
else if(!strcmp(b2,"EVAL")){
system("cls");	
	removeSpaces(c1);
	int d;
	sscanf(c1,"EVALPforX=%d",&d);
	if(c1[4]==q1 && P!=NULL &&(d>=0||d<0)){
		fraction r(d);
		eval(P,r).afficher_fraction();
	}
	else if(c1[4]==q2 && Q!=NULL &&(d>=0||d<0)){
		fraction r(d);
		eval(Q,r).afficher_fraction();
	}
	else if(P==NULL||Q==NULL){
	 cout<<"vous n'avez pas inserer le polynome ";}
	 else cout<<"rien a evaluer";
	 
cout<<endl;
system("cls");
}
else if(!strcmp(b2,"EXIT")){
	return 0;
}
else{ ligne:
cout<<"cette commande n'existe pas"<<endl;
}
}
}





