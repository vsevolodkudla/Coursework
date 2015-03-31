//---------------------------------------------------------------------------

#ifndef OperationsH
#define OperationsH
#include "Unit1.h"
#include<math.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Derevo
{
        protected:
                Derevo *left,*righ;
                Derevo(Derevo *l,Derevo *r):left(l),righ(r){};
        public:
                ~Derevo()
                {
                        delete left;
                        delete righ;
                }
                virtual double Rezult(){}
                virtual void SetVar(AnsiString y,double x)
                {
                        if(left) left->SetVar(y,x);
                        if(righ) righ->SetVar(y,x);
                }
};
//----------------------------------------------------------------------
class Real:public Derevo
{
                double chuslo;
        public:
                Real(double t):Derevo(NULL,NULL),chuslo(t){}
                double Rezult()
                {
                        return chuslo;
                }
};
//----------------------------------------------------------------------
class Var:public Derevo
{
                AnsiString Name;
                double zminna;
        public:
                Var(AnsiString h,double t=0):Derevo(NULL,NULL),zminna(t),Name(h){};
                double Rezult()
                {
                        return zminna;
                }
                void SetVar(AnsiString tmp,double t)
                {
                        if(Name==tmp)
                                zminna=t;
                }
};
//----------------------------------------------------------------------
class Plus:public Derevo
{
        public:
                Plus(Derevo *l,Derevo *r):Derevo(l,r){};
                double Rezult()
                {
                        return left->Rezult()+righ->Rezult();
                }
};
//----------------------------------------------------------------------
class Minus:public Derevo
{
        public:
                Minus(Derevo *l,Derevo *r):Derevo(l,r){};
                double Rezult()
                {
                        return left->Rezult()-righ->Rezult();
                }
};
//----------------------------------------------------------------------
class Mult:public Derevo
{
        public:
                Mult(Derevo *l,Derevo *r):Derevo(l,r){};
                double Rezult()
                {
                        return left->Rezult()*righ->Rezult();
                }
};
//----------------------------------------------------------------------
class Div:public Derevo
{
        public:
                Div(Derevo *l,Derevo *r):Derevo(l,r){};
                double Rezult()
                {
                        if(!righ->Rezult())
                                throw 1;
                        else
                                return left->Rezult()/righ->Rezult();
                }
};
//----------------------------------------------------------------------
class Duzku:public Derevo
{
                AnsiString asfunc;
        public:
                Duzku(Derevo *l,AnsiString t):Derevo(l,NULL),asfunc(t){};
                double Rezult()
                {
                        if(asfunc=="()")
                                return left->Rezult();
                        if(asfunc=="sqrt")
                                if(left->Rezult()>=0)
                                        return sqrt(left->Rezult());
                                else
                                        throw 2;
                        if(asfunc=="sin")
                                return sin(left->Rezult());
                        if(asfunc=="cos")
                                return cos(left->Rezult());
                        if(asfunc=="tg")
                                return tan(left->Rezult());
                        if(asfunc=="ln")
                                return log(left->Rezult());
                        if(asfunc=="exp")
                                return exp(left->Rezult());
                        if(asfunc=="lg")
                                return log10(left->Rezult());
                        if(asfunc=="abs")
                                return fabs(left->Rezult());
                        if(asfunc=="arcsin")
                                return asin(left->Rezult());
                        if(asfunc=="arccos")
                                return acos(left->Rezult());
                        if(asfunc=="arctg")
                                return atan(left->Rezult());
                        if(asfunc=="ceil")
                                return ceil(left->Rezult());
                        if(asfunc=="floor")
                                return floor(left->Rezult());
                        if(asfunc=="sh")
                                return (exp(left->Rezult())-exp(-left->Rezult()))/2;
                        if(asfunc=="ch")
                                return (exp(left->Rezult())+exp(-left->Rezult()))/2;
                        if(asfunc=="th")
                                return (exp(2*left->Rezult())-1)/(exp(2*left->Rezult())+1);
                        if(asfunc=="cth")
                                return (exp(2*left->Rezult())+1)/(exp(2*left->Rezult())-1);
                        if(asfunc=="sech")
                                return 2/(exp(left->Rezult())-exp(-left->Rezult()));
                        if(asfunc=="csch")
                                return 2/(exp(left->Rezult())+exp(-left->Rezult()));
                }
};
//----------------------------------------------------------------------
class Pidnesen:public Derevo
{
        public:
                Pidnesen(Derevo *l,Derevo *r):Derevo(l,r){};
                double Rezult()
                {
                        return pow(left->Rezult(),righ->Rezult());
                }
};
//----------------------------------------------------------------------
struct Zminna
{
        AnsiString Name;
        double var;
        int n;
        Zminna *next;
};
//----------------------------------------------------------------------
struct VurazBloc
{
        AnsiString Vuraz,Name,Opus;
        int n;
        AnsiString *pMas;
        VurazBloc *next;
};
//----------------------------------------------------------------------
class Kategory
{
        public:
                AnsiString Name;
                VurazBloc *pStek;
                Kategory *next;
                Kategory(VurazBloc *t)
                {
                        pStek=t;
                        t->next=NULL;
                        next=NULL;
                };
                void SetName(AnsiString t)
                {
                        Name=t;
                };
                AnsiString GetName()
                {
                        return Name;
                };
                void SetNext(Kategory *p)
                {
                        next=p;
                };
                Kategory* GetNext()
                {
                        return next;
                };
                void SetVuraz(VurazBloc *t)
                {
                        VurazBloc *tmp=pStek;
                        while(tmp->next!=NULL &&
                                tmp->next->Name<t->Name)
                                tmp=tmp->next;
                        t->next=tmp->next;
                        tmp->next=t;
                        if(tmp->next==pStek)
                                pStek=tmp;
                };
                VurazBloc* GetVuraz()
                {
                        return pStek;
                };
};
//----------------------------------------------------------------------
int PosEnd(AnsiString asSt,AnsiString asT);
//----------------------------------------------------------------------
Derevo* Obchuslutu(AnsiString asText,Zminna*);
//----------------------------------------------------------------------
int Provirka(AnsiString r);
//----------------------------------------------------------------------
int Func(AnsiString Gt,AnsiString t);
//----------------------------------------------------------------------
//----------------------------------------------------------------------

#endif
