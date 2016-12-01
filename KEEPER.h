#ifndef KEEPER_H
#define KEEPER_H
#pragma once
#include <iostream>
#include <string>
#include "valasz.h"
#include "jatekos.h"
#include <map>
#include <vector>
#include <math.h>
#include "ATTACKER.h"
#include "DEFENDER.h"

using namespace std;


void kezdesk(palya& p, kapu* kap, map <int, jatekos>& jatekosok);
void kork(int&tick, int *score, map <int, jatekos>& jatekosok, int&labdaid, int &tarsuzenet, bool &vanlabda);
void jatekoskeresok(map <int, jatekos>& jatekosok, string tipus, int csapat, vector<int> &vissza, int &sajatid);
bool labdatartask(map<int, jatekos> &jatekosok, int &labdaid, int &sajatid);
void ramozdulk(map<int, jatekos> &jatekosok, kapu *kapuk, int &labdaid, palya &p, int &regitick, int &sajatid);
void passz2k(map<int, jatekos> &jatekosok, int& tarsid, int &labdaid, bool &passzoltam, int &teszt, int &uzenet, kapu *kapuk, int &sajatid);
void passz2kregi(map<int, jatekos> &jatekosok, palya &p, bool &passzoltam, int &labdaid, kapu *kapuk, p2d &passzhely);
int ellensegkeresok(map <int, jatekos>& jatekosok,string tipus);
bool kapumellett(map<int,jatekos> &jatekosok, kapu *kapuk, int &sajatid);
bool kapumellettell(map<int,jatekos> &jatekosok, kapu *kapuk,int &ellenid);
int mozgasx (kapu *kapuk, jatekos &sajatj);

#endif // KEEPER_H
