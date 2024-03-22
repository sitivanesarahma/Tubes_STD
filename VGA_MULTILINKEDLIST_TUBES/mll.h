#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>

using namespace std;

#define first(L) ((L).first)
#define infoFilm(P) (P)->infoFilm
#define infoGenre(P) (P)->infoGenre
#define nextFilm(P) (P)->nextFilm
#define genreFilm(P) (P) -> genreFilm
#define nextGenre(P) (P)->nextGenre
#define childGenre(P) (P) -> childGenre
#define nextRelation(P) (P)->nextRelation


struct dataFilm{
    string idFilm;
    string namaFilm;
    string tanggalRilis;
    string director;
    string durasi;
};
typedef dataFilm infotypeFilm;

struct dataGenre{
    string namaGenre;
};
typedef dataGenre infotypeGenre;

typedef struct elmFilm *adrFilm;
typedef struct elmRelation *adrRelation;
typedef struct elmGenre *adrGenre;

struct elmFilm{
    infotypeFilm infoFilm;
    adrFilm nextFilm;
    adrRelation genreFilm;
};

struct listFilm{
    adrFilm first;
};

struct elmGenre{
    infotypeGenre infoGenre;
    adrGenre nextGenre;
};

struct listGenre{
    adrGenre first;
};

struct elmRelation{
    adrGenre childGenre;
    adrRelation nextRelation;
};

struct list_relation{
    adrRelation first;
};

//film.cpp
void createListFilm(listFilm &L1);
adrFilm newnodeFilm(infotypeFilm film);
infotypeFilm datainfoFilm(string idFilm, string namaFilm, string tanggalRilis, string director, string durasi);
void addnodeFilm(listFilm &L1, adrFilm pFilm);
adrFilm findNodeFilm(listFilm L1, string namaFilm);
void printInfoParent(listFilm L1);
void printInfoGenre(listGenre L2);
void DisplayJudulFilm(listFilm L1);
int hitungbanyakFilm(listFilm L1);

//genre.cpp
void createListGenre(listGenre &L2);
adrGenre newnodeGenre(infotypeGenre genre);
infotypeGenre datainfoGenre(string namaGenre);
void addnodeGenre(listFilm &L1, listGenre L2, string namaFilm, string namaGenre);
adrGenre findGenreFilm(listGenre L2, string namaGenre);
void daftarGenre(listGenre &L2);
int hitungbanyakGenre(listGenre L1);

//mll.cpp
void connectGenre(listFilm &L1, listGenre L2, string namaFilm, string namaGenre);
void hapusFilmdanGenrenya(listFilm &L1, adrFilm &p1Film, string namaFilm);
void printInfoFilmdanGenre(listFilm L1);
void printInfoGenredanFilm(listGenre L2, listFilm L1, string namaGenre);
int hitungbanyakGenrepadaFilm(listFilm L1, string namaGenre);
int hitungbanyakFilmpadaGenre(listFilm L1, listGenre L2, string namaGenre);
string cariFilmdenganGenreTerbanyak(listFilm L1);
string cariFilmdenganGenreTersedikit(listFilm L1);


#endif // MLL_H_INCLUDED
