#ifndef JATEKOS_H
#define JATEKOS_H
#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

struct p2d {
    int x;
    int y;
    void kiir();
};
class palya {
    public:
    int m, sz;
    palya(){}
    palya(int m, int sz) { this->m = m; this->sz = sz; }
    void set(int m, int sz);
    int get_m();
    int get_sz();
};
class kapu {
public:
    p2d a, b;
    int d;
    kapu() {}
    kapu(p2d& a, p2d& b, int& d) { this->a = a; this->b = b; this->d = d; }
};
class jatekos {
public:
    p2d poz;
    p2d elozopoz;
    int e;
    int team;
    std::string tip;
    int id;
    bool mozog;
    bool nalalabda;
    queue <p2d> pool;    
    queue <p2d> pool1;
    queue <p2d> pool2;
    queue <p2d> pool3;
    queue <p2d> poolcel;

    jatekos(){ this->e = 20; }
    jatekos(int x, int y) { poz.x = x; poz.y = y; this->e = 20; }
    jatekos(const jatekos* j) { poz = j->poz; }
    jatekos(const jatekos& j) { poz = j.poz; }
    int labda_energia(int& cel_x,int& cel_y,int& st);
    int jatekos_energia(int &cel_x1, int &cel_y1, int &sp1);
    p2d get_poz();
    int get_e();
    void clear();
    void set_e(int& e);
    void set_poz(int&x, int& y);
    void poolba(int &cel_x, int &cel_y, int &sp);
    void poolba1(int cel_x1, int cel_y1);
    void poolba2(int cel_x1, int cel_y1);
    void poolba3(int cel_x1, int cel_y1);
    bool operator == (const jatekos &p2);
    bool operator != (const jatekos &p2);
    int tavolsag(jatekos &barat);
    void poolcelba(int celx, int cely);
};

#endif // JATEKOS_H
