#ifndef DEFENDER_H
#define DEFENDER_H
#pragma once
#include <iostream>
#include <string>
#include "valasz.h"
#include "jatekos.h"
#include <map>
#include <vector>
#include <math.h>
#include "ATTACKER.h"


using namespace std;


void kezdesd(palya& p, kapu* kap, map <int, jatekos>& jatekosok, int &sajatid);
void kord(int&tick, int *score, map <int, jatekos>& jatekosok, int&labdaid, int &tarsuzenet, bool &vanlabda);
void jatekoskeresod(map <int, jatekos>& jatekosok, string tipus, int csapat, vector<int> &vissza, int &sajatid);
void passz2d(map<int, jatekos> &jatekosok, int& tarsid, int &labdaid, palya &p, bool &passzoltam, int &teszt, int &uzenet, int &regitick, int &sajatid);
void vedunk(map<int, jatekos> &jatekosok, palya &p, int &labdaid, int &baratid, int &termin, int &termax, int &tarsuzenet, bool &passzoltam, int &teszt, int &regitick, int &sajatid);
bool nalalabda(map<int, jatekos> &jatekosok,int &labdaid,int &baratid);
int ellensegkeresod(map <int, jatekos>& jatekosok,string tipus);
//p2d legkozelebb(map<int, jatekos> &jatekosok, p2d &a, p2d &b, palya &p, int &ellid);

#endif //DEFENDER_H
