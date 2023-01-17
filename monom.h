#include<iostream>
#include"rationnell.h"
using namespace std;
class node
{
    public:
     int degre;
    fraction coeff;
    node(){
        degre=0;
    }
    node( int x,fraction y){
        coeff=y; degre=x;
    }
    node derivate();
    node integrate();
    node operator+(node);
    node operator-(node);
    node operator*(node);
    void operator^(int);
    void afficher_node();
    void modifier_node(node);
    void operator=(node);
    fraction evaluaton_node(fraction);
};

node node::derivate()
{    if(degre!=0){
    node r(degre-1,coeff*(degre));
    return r;}
    else if(degre==0) {
    	fraction q;
       node r;
       return r;
	}
}

node node::integrate()
{
   node r;
    r.degre=degre+1;
    fraction x(r.degre);
    r.coeff=coeff/x;
    return r;
}

node node::operator+(node anode)
{
    node r;
    r.coeff=coeff+anode.coeff;
    return r;
}
node node::operator-(node anode)
{
    node r;
    r.coeff=coeff-anode.coeff;
    return r;
}

node node::operator*(node anode)
{
    node r;
    r.degre=anode.degre + degre;
    r.coeff=coeff*anode.coeff;
    return r;
}


void node::afficher_node()
{    if(coeff.dem!=1){
    coeff.afficher_fraction();}
    else cout<<coeff.num; 
    if(degre!=0){
    cout<<"X^"<<degre;}
}

void node::operator=(node anode)
{
degre=anode.degre;
coeff=anode.coeff;
}


fraction node::evaluaton_node(fraction e)
{
    fraction r;
    r=coeff*(e^degre);
    return r;
}

void node::operator^(int e)
{
    coeff=coeff^(e);
    degre=degre*e;
}
