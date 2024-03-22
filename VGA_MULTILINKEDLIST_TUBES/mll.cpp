#include "mll.h"

void connectGenre(listFilm &L1, listGenre L2, string namaFilm, string namaGenre){
    adrFilm pFilm = findNodeFilm(L1, namaFilm);
    adrGenre pGenre = findGenreFilm(L2, namaGenre);
    if (pFilm == NULL && pGenre == NULL){
        cout << "THERE IS NO FILM AND GENRE DATA" << endl;
    }else if(pFilm != NULL && pGenre == NULL){
        cout << "THERE IS NO GENRE DATA" << endl;
    }else if(pFilm == NULL && pGenre != NULL){
        cout << "THERE IS NO FILM DATA" << endl;
    }else{
        adrRelation R = new elmRelation;
        childGenre(R) = NULL;
        nextRelation(R) = NULL;
        if(genreFilm(pFilm)==NULL){
            genreFilm(pFilm)=R;
            childGenre(R) = pGenre;
        }else{
            adrRelation temp = genreFilm(pFilm);
            while(nextRelation(temp)!=NULL){
                temp=nextRelation(temp);
            }
            nextRelation(temp) = R;
            childGenre(R)=pGenre;
        }
    }
}

void printInfoFilmdanGenre(listFilm L1){
    adrFilm P = first(L1);
    if(first(L1)!=NULL){

        while(P != NULL) {
            cout << infoFilm(P).namaFilm << endl;
            cout << "----------------------------------------------" << endl;
            adrRelation R = genreFilm(P);
            while(R!=NULL){
                adrGenre S = childGenre(R);
                    if(S!=NULL){
                        cout << "-> " << infoGenre(S).namaGenre<< endl;
                    }
                R = nextRelation(R);
            }
            cout << "==============================================" << endl;
            P = nextFilm(P);
        }
    }else{
        cout << "         THERE IS NO FILM IN DATABASE" << endl;
        cout << "==============================================" << endl;
    }

}

void printInfoGenredanFilm(listGenre L2, listFilm L1, string namaGenre){
    adrGenre pGenre = findGenreFilm(L2, namaGenre);
    if(pGenre!=NULL){
        adrFilm pFilm = first(L1);
        if(first(L1)!=NULL){
            cout << infoGenre(pGenre).namaGenre << " : " << endl;
            cout << "----------------------------------------------"<<endl;
            while(pFilm!=NULL){
                adrRelation R = genreFilm(pFilm);
                if (R!=NULL){
                    while(R!=NULL){
                        if(infoGenre(childGenre(R)).namaGenre == namaGenre){
                            cout << infoFilm(pFilm).namaFilm << endl;
                        }
                        R = nextRelation(R);
                    }
                }
                pFilm = nextFilm(pFilm);
            }
        }else{
            cout << "          THERE IS NO FILM IN GENRE" << endl;
        }

    }else{
        cout << "The genre you are looking for doesn't exist" << endl;
    }
}

void hapusFilmdanGenrenya(listFilm &L1, adrFilm &p1Film, string namaFilm){
    adrFilm pFilm = findNodeFilm(L1, namaFilm);
    if (pFilm == NULL){
        cout << "THERE ARE NO MOVIES IN THE DATABASE" << endl;
    }else{
        adrRelation R = genreFilm(pFilm);
        while(R!=NULL){
            childGenre(R)=NULL;
            R = nextRelation(R);
        }
        genreFilm(pFilm) = NULL;
        if (first(L1) == pFilm){
            first(L1) = nextFilm(pFilm);
            nextFilm(pFilm) = NULL;
        } else if (next(pFilm) == NULL){
            adrFilm temp = first(L1);
            while(nextFilm(temp)!= NULL){
                temp = nextFilm(temp);
            }
            nextFilm(temp) = NULL;
        } else{
            adrFilm temp = first(L1);
            while(nextFilm(temp)!= pFilm){
                temp = nextFilm(temp);
            }
            nextFilm(temp) = nextFilm(pFilm);
            nextFilm(pFilm) = NULL;
        }
    }
}

int hitungbanyakGenrepadaFilm(listFilm L1, string namaFilm){
    adrFilm P = first(L1);
    int jumlah = 0;
    if(first(L1) == NULL){
        cout << "Film doesn't exists" << endl;
        return 0;
    }else{
        while(P != NULL) {
            if (infoFilm(P).namaFilm == namaFilm){
                adrRelation R = genreFilm(P);
                while(R!=NULL){
                    adrGenre S = childGenre(R);
                        if(S!=NULL){
                            jumlah++;
                        }
                    R = nextRelation(R);
                }
            }
            P = nextFilm(P);
        }
        return jumlah;
    }

}

int hitungbanyakFilmpadaGenre(listFilm L1, listGenre L2, string namaGenre){
    int jumlah = 0;
    adrGenre pGenre = findGenreFilm(L2, namaGenre);
    if(pGenre!=NULL){
        adrFilm pFilm = first(L1);
        while(pFilm!=NULL){
            adrRelation R = genreFilm(pFilm);
            while(R!=NULL){
                if (infoGenre(childGenre(R)).namaGenre==namaGenre){
                    jumlah++;
                }
                R = nextRelation(R);
            }
            pFilm = nextFilm(pFilm);
        }
    }
    return jumlah;
}

string cariFilmdenganGenreTerbanyak(listFilm L1){
    adrFilm pFilm = first(L1);
    int maximum = 0;
    adrFilm terbesar;

    if(first(L1) == NULL){
        return "There are no movies in the database";
    }else{
        while(pFilm != NULL){
            adrRelation r = genreFilm(pFilm);
            int jumlah = 0;
            while(r != NULL){
                jumlah++;
                if(jumlah >= maximum){
                    maximum = jumlah;
                    terbesar = pFilm;
                }
                r = nextRelation(r);
            }
            pFilm = nextFilm(pFilm);
        }
        cout << "Film with the most genres is ";
        return infoFilm(terbesar).namaFilm;
    }
}

string cariFilmdenganGenreTersedikit(listFilm L1){
    adrFilm P = first(L1);
    int jumlah1 = 0;
    if(P!=NULL) {
        adrRelation R = genreFilm(P);
        while(R!=NULL){
            adrGenre S = childGenre(R);
                if(S!=NULL){
                    jumlah1++;
                }
            R = nextRelation(R);
        }
    }
    adrFilm pFilm = first(L1);
    int minimum = jumlah1;
    adrFilm terkecil;

    if(first(L1) == NULL){
        return "There are no movies in the database";
    }else{
        while(pFilm != NULL){
            adrRelation r = genreFilm(pFilm);
            int jumlah = 0;
            while(r != NULL){
                jumlah++;
                r = nextRelation(r);
            }
            if(jumlah <= minimum){
                minimum = jumlah;
                terkecil = pFilm;
            }
            pFilm = nextFilm(pFilm);
        }
        cout <<"Film with the least genres is ";
        return infoFilm(terkecil).namaFilm;
    }
}
