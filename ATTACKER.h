#ifndef FELDOLGOZAS_H
#define FELDOLGOZAS_H

#pragma once
#include <iostream>
#include <string>
#include "valasz.h"
#include "jatekos.h"
#include <map>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

string ujadat(string s, int& kezd);
void kezdes(palya& p, kapu* kap, map <int, jatekos>& jatekosok);
void kor(int&tick, int &akttick, int *score, map <int, jatekos>& jatekosok, int&labdaid, int &tarsuzenet);
void csapattarskereso(map <int, jatekos>& jatekosok, string tipus, int csapat, vector<int> &vissza, int &sajatid);
void kozelitunk(map <int, jatekos>& jatekosok, kapu* kapuk, int& labdaid, int &tick, vector<int> vissza, int &tarsuzenet, vector<int> legkozelebbipont, bool &labdaszerzes, int &eset, bool &ujkor, int &ellensegid, int &keset, bool &beall, bool &teszteltunk, int &lepunk, int &akttick, bool &kijon, int &sajatid);
int kaputav(kapu* kapuk, map <int, jatekos>& jatekosok, vector<int> &legkozelebbipont, int &sajatid);
bool gol (kapu* kapuk, map <int, jatekos>& jatekosok, int &labdaid);
int esetvalaszto(int& tarsuzenet);
void poolbairas(map <int, jatekos>& jatekosok, int &jatekosid, int &jat_x, int &jat_y, int &jat_s, queue<int> &pool);
int masodikesetvalaszto(kapu* kapuk, map <int, jatekos>& jatekosok, vector<int> &legkozelebbipont, int &ellensegid, int &labdaid);
int ellensegkereso(map <int, jatekos>& jatekosok, string tipus, int &sajatid);
void loves(map <int, jatekos>& jatekosok, kapu* kapuk, int &akttick, int &sajatid);
int kaputav(kapu* kapuk, int a, int b);
void helykereses(map <int, jatekos>& jatekosok, kapu* kapuk, int &sajatid);
bool beallt(map <int, jatekos>& jatekosok, kapu* kapuk, int &sajatid);
void teszt(map <int, jatekos>& jatekosok, kapu* kapuk, int &ellensegid, int &sajatid);
int kapusverzio(map <int, jatekos>& jatekosok, kapu* kapuk, int &ellenid, int &sajatid); bool kpozmaradt(map <int, jatekos>& jatekosok,int &ellenid);
int tav2p(int x1,int y1,int x2,int y2);
int melyikpoll(map <int, jatekos>& jatekosok, int &labdaid, int &cst);
bool elinduljunk(map <int, jatekos>& jatekosok, kapu* kapuk, int &cst, int &akttick, int &sajatid);
bool felenkjon(map <int, jatekos>& jatekosok, int &ellensegid, int &sajatid);
void hajonfelenk(map <int, jatekos>& jatekosok, int &ellensegid, kapu* kapu, vector<int> legkozelebbipont, int &sajatid);
void vegtelenciklus(string asdasd);


//void passz2(map<int, jatekos> &jatekosok, int tarsid );
//void helykereses2(map <int, jatekos>& jatekosok,kapu* kapuk,int &ellensegid);
// FELDOLGOZAS_Hvoid helykereses3(map <int, jatekos>& jatekosok,kapu* kapuk,int &ellensegid);




#endif
