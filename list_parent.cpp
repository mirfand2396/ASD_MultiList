#include "list_parent.h"

void createList(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */

    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void dealokasi(address_parent &P){
    delete P;
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P){
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }

}

void deleteFirst(List_parent &L, address_parent &P){
    if(first(L)==NULL){
        cout<<"Data is Empty"<<endl;
    }
    else{
        address_parent Q=first(L);
        while(next(Q)!=first(L)){
            Q=next(Q);
        }
        P=first(L);
        next(Q)=next(P);
        first(L)=next(first(L));
        next(P)=NULL;
    }
}
void deleteLast(List_parent &L, address_parent &P){
    if(first(L)==NULL){
        cout<<"Data is Empty"<<endl;
    }
    else{
        address_parent Q=first(L);
        while(next(next(Q))!=first(L)){
            Q=next(Q);
        }
        P=next(Q);
        next(Q)=first(L);
        next(P)=NULL;
    }
}

void deleteByFlightID(List_parent &L, address_parent Prec, address_parent &P){
    if(first(L)==NULL){
        cout<<"Data is Empty"<<endl;
    }
    else{
        address_parent Q=first(L);
        while(next(Q)!=Prec){
            Q=next(Q);
        }
        if(Q==first(L)){
            deleteFirst(L,P);
        }
        else if(next(next(Q))==first(L)){
            deleteLast(L,P);
        }
        else{
            P=Prec;
            next(Q)=next(P);
            next(P)=NULL;
        }
    }
}


void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<"  -----------------------------------------"<<endl;
            cout<<"   "<<info(P).flight_name<<"       "<<info(P).flight_id<<"           "<<info(P).destination<<endl;
            printInfo(child(P));
            cout<<"  -----------------------------------------"<<endl;
            P = next(P);
        } while((P)!=first(L));
    }
}

address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    do {
        if(info(P).flight_id == x.flight_id) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

address_parent findElmBefore(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nim = x.nim,
    * FS : mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    do {
        if(info(next(P)).flight_id == x.flight_id) {
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}
