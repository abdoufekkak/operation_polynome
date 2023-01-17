#include"monom.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct polynome
{
    node anode;
    struct polynome *next;
}polynome;

polynome* newpolynome ( node mo)
 {
 polynome* p ;
 p = (polynome*) malloc( sizeof( polynome));
 if( p != NULL ){
 p->anode.coeff.num=mo.coeff.num;
 p->anode.coeff.dem=mo.coeff.dem;  
 p->anode.degre=mo.degre;
 p->next= NULL ;
 }
 return p ;
 }

void ajouter(polynome **P,node d)
{    polynome *dd=newpolynome(d);
     polynome *current;
    if(*P==NULL){
        *P=dd;
        }
    else
        {
        current =*P;
while(current->next != NULL)
{
	 current=current->next;   
        }
        current->next =dd;
}}

polynome * derive(polynome *P)
{   polynome *cu =P,*pr;
	while(cu!=NULL)
	{   fraction q=cu->anode.coeff;
	     node dP(cu->anode.degre,q);
	     ajouter(&pr,dP.derivate());
		cu=cu->next;
	}
    return pr;}
polynome * integrer(polynome *P)
{
	if(P==NULL){
		return NULL;
	}
	else{
	polynome*dp =newpolynome(P->anode.integrate());
 dp->next=integrer(P->next);
 return dp ;
 }	
	}
fraction eval(polynome*P ,fraction r)
{
fraction S;
polynome*f=P;
while ( f!= NULL ){
 S=S+f->anode.evaluaton_node(r);
 f= f->next ;
}
 return S ;
}

void affiche_polynome(polynome *k){
	polynome *f;
	k->anode.afficher_node();
	f=k->next;
	while(f!=NULL){
		
		if(f->anode.coeff.num>0 &&f->anode.degre!=-1){
		cout<<"+";
		f->anode.afficher_node();
		}
		else if(f->anode.coeff.num<0 &&f->anode.degre!=-1){
			f->anode.afficher_node();
		}
		f=f->next;	
	}

}

polynome *addition(polynome *p1,polynome *p2){
	polynome *tmp,*cu=p1,*k,*aa;
	polynome *coco=p2;
	fraction s,r;
	polynome *pr=NULL;
	while(cu!=NULL)
	{   fraction q=cu->anode.coeff;
	     node f(cu->anode.degre,q);
	     ajouter(&pr,f);
		cu=cu->next;
	}
	while(coco!=NULL)
	{   fraction q=coco->anode.coeff;
	     node f(coco->anode.degre,q);
	     ajouter(&pr,f);
		coco=coco->next;
	}	
   for(tmp=pr;tmp!=NULL;tmp=tmp->next){
	fraction s;
for(cu=tmp->next;cu!=NULL;cu=cu->next){
	if((cu->anode.degre==tmp->anode.degre)&& cu->anode.degre!=-1 ){
	s=s+cu->anode.coeff;
		cu->anode.degre=-1;	
		cu->anode.coeff.num=0;
	}	
}
 tmp->anode.coeff=tmp->anode.coeff+s;
}
return pr;
}
polynome *SUTT(polynome *p1,polynome *p2){
	polynome *tmp;
	for(tmp=p2;tmp!=NULL;tmp=tmp->next){
		tmp->anode.coeff.num=-(tmp->anode.coeff.num);}
	polynome *Q=addition(p1,p2);
	for(tmp=p2;tmp!=NULL;tmp=tmp->next){
		tmp->anode.coeff.num=-(tmp->anode.coeff.num);}
 return Q;
}

polynome* multipq(polynome *p,polynome *q ){
  polynome *tmp1,*tmp3,*res;
  bool prems ;
  prems =true;
  res = NULL;
  tmp3 =q;
  while(p!=NULL){
    tmp1=NULL;
    q=tmp3;
    while(q!=NULL){
    	fraction f(p->anode.coeff * q->anode.coeff);
    	node d(p->anode.degre + q->anode.degre,f);
    	ajouter(&tmp1,d);
      q= q->next;
}
    if(prems!=true){
 res=addition(tmp1,res);}
    else{
      res=tmp1;
}
    prems=false;
    p=p->next;
}

  return  res;}
polynome*poww(polynome *p,int n){
	if (n==0){
		fraction r;
		node d(0,r);
		polynome *p=newpolynome(d);
		return p;
	}
	else{
	if (n==1){
		return p;
		  }
	else return multipq(p,poww(p,n-1));}}
void affectation(polynome **p,polynome *q){
polynome*cu=q;	
*p=NULL;
	polynome *pr=NULL;
	while(cu!=NULL)
	{   fraction Q=cu->anode.coeff;
	     node f(cu->anode.degre,Q);
	     ajouter(&pr,f);
		cu=cu->next;
	}
*p=pr;
		
}



