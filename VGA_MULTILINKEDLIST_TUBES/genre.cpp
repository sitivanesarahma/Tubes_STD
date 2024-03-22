#include "mll.h"

void createListGenre(listGenre &L2){
    first(L2) = NULL;
}

adrGenre newnodeGenre(infotypeGenre genre){
    adrGenre pGenre = new elmGenre;
    infoGenre(pGenre) = genre;
    nextGenre(pGenre) = NULL;
    return pGenre;
}

infotypeGenre datainfoGenre(string namaGenre){
    infotypeGenre data2;
    data2.namaGenre = namaGenre;
    return data2;
}

adrGenre findGenreFilm(listGenre L2, string namaGenre){
    if(first(L2)==NULL){
        return NULL;
    }else{
        adrGenre pGenre = first(L2);
        while(pGenre!=NULL&&infoGenre(pGenre).namaGenre!=namaGenre){
            pGenre = nextGenre(pGenre);
        }
        return pGenre;
    }
}

void addnodeGenre(listGenre &L2, adrGenre pGenre){
    if(first(L2)==NULL){
        first(L2) = pGenre;
    }else{
        adrGenre qGenre = first(L2);
        while(nextGenre(qGenre)!=NULL){
            qGenre = nextGenre(qGenre);
        }
        nextGenre(qGenre) = pGenre;
    }
}

void printInfoGenre(listGenre L2) {
    adrGenre P = first(L2);
    while(P !=NULL) {
        cout<<"-> "<<infoGenre(P).namaGenre<<endl;
        P = nextGenre(P);
    }
}

void daftarGenre(listGenre &L2){
    adrGenre pGenre;
    infotypeGenre data2;

    data2 = datainfoGenre("Horror");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Romance");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Action");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Drama");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Thriller");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Sci-fi");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Documentary");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Fantasy");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Adventure");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Fiction");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Non-Fiction");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Comedy");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Mystery");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);

    data2 = datainfoGenre("Drama");
    pGenre = newnodeGenre(data2);
    addnodeGenre(L2, pGenre);
}

int hitungbanyakGenre(listGenre L2){
    adrGenre pGenre = first(L2);
    int jumlah = 0;
    while(pGenre != NULL){
        jumlah++;
        pGenre = nextGenre(pGenre);
    }
    return jumlah++;
}

