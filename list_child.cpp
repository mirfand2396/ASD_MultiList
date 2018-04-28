#include "list_child.h"

void createList(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child x) {
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address_child &P){
    delete P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P){
    address_child Q;
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        prev(P)=last(L);
        next(last(L))=P;
        last(L)=P;
    }
}

void deleteFirst(List_child &L, address_child &P){
    if(first(L)==NULL){
        cout<<"Data is Empty"<<endl;
    }
    else{
        P=first(L);
        first(L)=next(first(L));
        next(P)=NULL;
        prev(first(L))=NULL;
    }
}

void deleteLast(List_child &L, address_child &P){
    if(first(L)==NULL){
        cout<<"Data is Empty"<<endl;
    }
    else{
        P=last(L);
        last(L)=prev(last(L));
        prev(P)=NULL;
        next(last(L))=NULL;
    }
}

void printInfo(List_child L) {
    address_child P = first(L);
    while(P !=NULL) {
    cout<<"    "<<info(P).pass_id<<"        "<<info(P).pass_name<<"          "<<endl;
        P = next(P);
    }
}


address_child findElm(List_child L, infotype_child x) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).pass_id==x.pass_id) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}
