#include "mll.h"

void createListFilm(listFilm &L1){
    first(L1) = NULL;
}

adrFilm newnodeFilm(infotypeFilm film){
    adrFilm pFilm = new elmFilm;
    infoFilm(pFilm) = film;
    nextFilm(pFilm) = NULL;
    genreFilm(pFilm) = NULL;
    return pFilm;
}

infotypeFilm datainfoFilm(string idFilm, string namaFilm, string tanggalRilis, string director, string durasi){
    infotypeFilm data;
    data.idFilm = idFilm;
    data.namaFilm = namaFilm;
    data.tanggalRilis = tanggalRilis;
    data.director = director;
    data.durasi = durasi;
    return data;
}

void addnodeFilm(listFilm &L1, adrFilm pFilm){
    if(first(L1)==NULL){
        first(L1) = pFilm;
    }else{
        adrFilm qFilm = first(L1);
        while(nextFilm(qFilm)!=NULL){
            qFilm = nextFilm(qFilm);
        }
        nextFilm(qFilm) = pFilm;
    }
}

adrFilm findNodeFilm(listFilm L1, string namaFilm){
    if(first(L1)==NULL){
        return NULL;
    }else{
        adrFilm pFilm = first(L1);
        while(pFilm!=NULL&&infoFilm(pFilm).namaFilm!=namaFilm){
            pFilm = nextFilm(pFilm);
        }
        return pFilm;
    }
}

void printInfoParent(listFilm L1) {
    adrFilm P = first(L1);
    if(first(L1)!=NULL) {
        while(P!=NULL){
            cout << "==============================================" << endl;
            cout << infoFilm(P).namaFilm                             << endl;
            cout << "==============================================" << endl;
            cout << "ID FILM        : " << infoFilm(P).idFilm        << endl;
            cout << "Release Date   : " << infoFilm(P).tanggalRilis  << endl;
            cout << "Director       : " << infoFilm(P).director      << endl;
            cout << "Duration       : " << infoFilm(P).durasi        << endl;
            cout << "==============================================" << endl;
            P = nextFilm(P);
        }
    }
}

void DisplayJudulFilm(listFilm L1){
    adrFilm p;
    p = first(L1);
    if (first(L1) == NULL){
        cout << "TIDAK ADA DATA" << endl;
    }else{
        cout << "Judul Film : " << endl;
        while(p != NULL){
        cout <<"-> "<<infoFilm(p).namaFilm<<endl;
        p = nextFilm(p);
        }
    }
}

int hitungbanyakFilm(listFilm L1){
    adrFilm pFilm = first(L1);
    int i = 0;
    while (pFilm != NULL){
        i++;
        pFilm = nextFilm(pFilm);
    }
    return i;
}

