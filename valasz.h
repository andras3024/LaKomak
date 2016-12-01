#ifndef valasz_H
#define valasz_H
#pragma once
#include <iostream>
#include <string>

using namespace std;
class valasz
{
public:
    valasz();
    void print(int px, int py, int ps, int bx, int by, int bs, string mess);
    void print(int px, int py, int ps,string mess);
    void print(string mess);
    void print(int px, int py, int ps);
    void loves(int bx, int by, int bs);
    void loves(int bx, int by, int bs,string mess);
    void print(int px, int py, int ps, int bx, int by, int bs);
    void print();
};

#endif // valasz_H
