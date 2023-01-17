#include<iostream>
#include<conio.h>
using namespace std;

int pow(int e,int n)
{
    if(n==1||e==0) return e;
    else return e*pow(e,n-1);
     
}
class fraction
{
    public: 
    int num,dem;
    fraction(int x=0,int y=1)
    {
        num=x;dem=y;
    }
    fraction operator+(fraction);
    fraction operator/(fraction);
    fraction operator*(fraction);
    fraction operator^(int);
    fraction operator-(fraction);
    void operator=(fraction);
    void afficher_fraction();
};

fraction fraction::operator+(fraction e)
{
    fraction r;
    r.dem=dem*e.dem;
    r.num=(num*e.dem)+(e.num*dem);
    return r;
}

fraction fraction::operator/(fraction e)
{
    fraction r;
    r.num=num*e.dem;
    r.dem=dem*e.num;
    return r;
}

fraction fraction::operator*(fraction e)
{
    fraction r(num*e.num,dem*e.dem);
    return r;
}
fraction fraction::operator-(fraction e)
{
    fraction r((num*e.dem)-(e.num*dem),dem*e.dem);
    return r;
}

fraction fraction::operator^(int n)
{
    num=pow(num,n);
    dem=pow(dem,n);
    return *this;
}

void fraction::afficher_fraction(){
    cout<<num;
    cout<<"/";
    cout<<dem;
}

void fraction::operator=(fraction r)
{
num=r.num;
dem=r.dem;
}
