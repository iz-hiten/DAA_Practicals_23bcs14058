#include <iostream>
using namespace std;

struct DNode {
    int d;
    DNode *p, *n;
    DNode(int v) { d=v; p=n=NULL; }
};

class DList {
    DNode *h, *t;
public:
    DList() { h=t=NULL; }
    void insBeg(int v) {
        DNode *x=new DNode(v);
        if(!h) h=t=x;
        else { x->n=h; h->p=x; h=x; }
    }
    void insEnd(int v) {
        DNode *x=new DNode(v);
        if(!t) h=t=x;
        else { t->n=x; x->p=t; t=x; }
    }
    void delBeg() {
        if(!h) return;
        if(h==t) { delete h; h=t=NULL; }
        else { DNode* x=h; h=h->n; h->p=NULL; delete x; }
    }
    void delEnd() {
        if(!t) return;
        if(h==t) { delete t; h=t=NULL; }
        else { DNode* x=t; t=t->p; t->n=NULL; delete x; }
    }
    void show() {
        DNode *c=h;
        while(c) { cout<<c->d<<" "; c=c->n; }
        cout<<"\n";
    }
};

struct CNode {
    int d;
    CNode *n;
    CNode(int v) { d=v; n=NULL; }
};

class CList {
    CNode *l;
public:
    CList() { l=NULL; }
    void insBeg(int v) {
        CNode *x=new CNode(v);
        if(!l) { l=x; x->n=x; }
        else {
            CNode *c=l;
            while(c->n!=l) c=c->n;
            x->n=l; c->n=x; l=x;
        }
    }
    void insEnd(int v) {
        CNode *x=new CNode(v);
        if(!l) { l=x; x->n=x; }
        else {
            CNode *c=l;
            while(c->n!=l) c=c->n;
            c->n=x; x->n=l;
        }
    }
    void delBeg() {
        if(!l) return;
        if(l->n==l) { delete l; l=NULL; }
        else {
            CNode *c=l;
            while(c->n!=l) c=c->n;
            CNode *x=l; l=l->n; c->n=l; delete x;
        }
    }
    void delEnd() {
        if(!l) return;
        if(l->n==l) { delete l; l=NULL; }
        else {
            CNode *c=l;
            while(c->n->n!=l) c=c->n;
            delete c->n; c->n=l;
        }
    }
    void show() {
        if(!l) { cout<<"\n"; return; }
        CNode *c=l;
        do { cout<<c->d<<" "; c=c->n; } while(c!=l);
        cout<<"\n";
    }
};

int main() {
    DList d;
    d.insBeg(1); d.insEnd(2); d.insEnd(3);
    d.show();
    d.delBeg(); d.show();
    d.delEnd(); d.show();

    CList c;
    c.insBeg(1); c.insEnd(2); c.insEnd(3);
    c.show();
    c.delBeg(); c.show();
    c.delEnd(); c.show();
}
