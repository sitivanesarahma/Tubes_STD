#include <iostream>
#include <conio.h>
#include <string>

#include "mll.h"
using namespace std;

int main()
{

    int input, n,j,k;
    string idFilm,namaFilm,tanggalRilis,director,durasi;
    string judulFilm, Genre, cariGenre, namaGenre,Film;

    adrFilm pFilm;

    listFilm L1;
    listGenre L2;

    createListFilm(L1);
    createListGenre(L2);
    daftarGenre(L2);

    char ulang;

    do{
        system("cls");
        cout << "================ DATABASE FILM ===============" << endl;
        cout << "==============================================" << endl;
        cout << "|| 1. INPUT FILM                            ||" << endl;
        cout << "|| 2. ADD RELATION FILM TO GENRE            ||" << endl;
        cout << "|| 3. SHOW ALL FILM                         ||" << endl;
        cout << "|| 4. SHOW ALL GENRE                        ||" << endl;
        cout << "|| 5. SHOW GENRE WITH FILM                  ||" << endl;
        cout << "|| 6. SHOW ALL FILM WITH GENRE              ||" << endl;
        cout << "|| 7. FILM WITH THE MOST GENRES             ||" << endl;
        cout << "|| 8. FILM WITH THE LEAST GENRE             ||" << endl;
        cout << "|| 9. COUNT GENRE IN FILM                   ||" << endl;
        cout << "|| 10. COUNT FILM IN GENRE                  ||" << endl;
        cout << "|| 11. DELETE DATA                          ||" << endl;
        cout << "|| 12. EXIT                                 ||" << endl;
        cout << "==============================================" << endl;
        cout << endl;
        cout << "ENTER YOUR CHOICE (1-12) : "; cin >> input;


        switch(input){
            case 1:
                cout << endl << "ENTER THE NUMBER OF FILM : "; cin >> n; getchar();
                int i;
                i = 1;
                if(n == 0){
                    cout << "==================================" << endl;
                    cout << endl << "ENTER NUMBER MORE THAN 0" << endl;
                    cout << endl << "ENTER THE NUMBER OF FILM : "; cin >> n; getchar();
                    do{
                    cout << "Film ID        : "; cin >> idFilm; getchar();
                    cout << "Title          : "; getline(cin,namaFilm);
                    cout << "Release Date   : "; getline(cin,tanggalRilis);
                    cout << "Director       : "; getline(cin,director);
                    cout << "Duration       : "; getline(cin,durasi);

                    infotypeFilm data;
                    data = datainfoFilm(idFilm,namaFilm,tanggalRilis,director,durasi);
                    pFilm = newnodeFilm(data);
                    addnodeFilm(L1, pFilm);
                    cout << endl;
                    i++;
                    }while(i<=n && i>0);
                }else{
                    do{
                    cout << "Film ID        : "; cin >> idFilm; getchar();
                    cout << "Title          : "; getline(cin,namaFilm);
                    cout << "Release Date   : "; getline(cin,tanggalRilis);
                    cout << "Director       : "; getline(cin,director);
                    cout << "Duration       : "; getline(cin,durasi);

                    infotypeFilm data;
                    data = datainfoFilm(idFilm,namaFilm,tanggalRilis,director,durasi);
                    pFilm = newnodeFilm(data);
                    addnodeFilm(L1, pFilm);
                    cout << endl;
                    i++;
                    }while(i<=n && i>0);
                }
                getch();
                break;
            case 2:
                {
                    cout << endl;
                    cout << "===== FILM LIST =====" << endl;
                    DisplayJudulFilm(L1);
                    cout << endl;
                    cout << "===== GENRE LIST =====" << endl;
                    cout << "Genre : " << endl;
                    printInfoGenre(L2);
                    cout << endl;

                    cout << "Number of Film   : "; cin >> j;getchar();
                    k = 0;
                    while(k<j){
                        cout << "TITLE            : ";getline(cin,judulFilm);
                        int b = 0;
                        int a;
                        cout << "Number of Genres : "; cin >> a;
                        while(b < a){
                            cout << "GENRE            : "; cin >> Genre; getchar();
                            connectGenre(L1,L2,judulFilm,Genre);
                            b++;
                        }
                        cout << endl;
                        k++;
                    }
                    getch();
                    break;
                }

            case 3:
                printInfoParent(L1);
                getch();
                break;
            case 4:
                cout << "===== GENRE LIST =====" <<endl;
                printInfoGenre(L2);
                getch();
                break;
            case 5:
                cout << endl << "ENTER THE GENRE : ";
                cin >> cariGenre;
                cout << endl << "============== GENRE WITH FILM ===============" << endl;
                cout << endl <<"==============================================" << endl;
                printInfoGenredanFilm(L2,L1,cariGenre);
                cout << "==============================================" << endl;
                getch();
                break;
            case 6:
                cout << endl << "============ ALL FILM WITH GENRE =============" << endl;
                cout << endl << "==============================================" << endl;
                printInfoFilmdanGenre(L1);
                //cout << "==============================================" << endl;
                getch();
                break;
            case 7:
                cout << cariFilmdenganGenreTerbanyak(L1);
                getch();
                break;
            case 8:
                cout << cariFilmdenganGenreTersedikit(L1);
                getch();
                break;
            case 9:
                cout << "================ GENRE LIST ==================" << endl;
                printInfoGenre(L2);
                cout << "==============================================" << endl;
                cout << endl << "ENTER THE GENRE THAT YOU WANT TO COUNT : "; cin >> namaGenre;
                cout << endl;
                cout << "Number of Film from " << namaGenre <<" : ";
                cout << hitungbanyakFilmpadaGenre(L1,L2,namaGenre);
                cout << endl << "==============================================" << endl;
                cout << endl;
                getch();
                break;
            case 10:
                if(first(L1) == NULL){
                    cout << endl << "==============================================" << endl;
                    cout << "||           FILM DOESN'T EXISTS            ||" << endl;
                    cout << "==============================================" << endl;
                }else{
                    cout << endl << "ENTER THE FILM THAT YOU WANT TO COUNT :  "<<endl;getchar();
                    cout << "-> " ;getline(cin,Film);
                    cout << endl<< "==============================================" << endl;
                    cout << "Number of Genres from "<< endl<<Film <<" : ";
                    cout << hitungbanyakGenrepadaFilm(L1,Film);
                    cout << endl<< "==============================================" << endl << endl;
                }
                getch();
                break;
            case 11:
                cout <<endl<< "ENTER THE TITLE OF FILM YOU WANT TO DELETE : "<<endl;cout << "-> "; getchar(); getline(cin,namaFilm);
                cout << endl;
                cout << "==============================================" << endl;
                hapusFilmdanGenrenya(L1,pFilm,namaFilm);
                cout << "          THE FILM HAS BEEN DELETED           " << endl;
                cout << "==============================================" << endl;
                getch();
                break;
            case 12:
                cout << endl<< "==============================================" << endl;
                cout << "      YOU HAVE BEEN EXITED FROM THE MENU" << endl;
                cout << "==============================================" << endl;
                exit(0);
                getch();
                break;
        }
    }while(ulang != 12);

    cout << endl;
    return 0;
}
