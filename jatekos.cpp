#include "jatekos.h"

void palya::set(int m,int sz){ this->m = m; this->sz = sz; }
int palya::get_m() { return m; }
int palya::get_sz() { return sz; }
void p2d::kiir() { std::cout << "x: " << x << " y: " << y<<std::endl; }
p2d jatekos::get_poz() { return poz; }
void jatekos::set_poz(int&x,int& y) { poz.x = x; poz.y = y; }
int jatekos::get_e() { return e; }
void jatekos::set_e(int& e) { this->e += e; }
int jatekos::labda_energia(int &cel_x, int &cel_y, int &sp){
    int e;
    e = ceil(sqrt(pow((cel_x - this->poz.x),2)+pow((cel_y- this->poz.y),2))*sp);
    return e;
}
int jatekos::jatekos_energia(int &cel_x1, int &cel_y1, int &sp1)
{
    double d;
    p2d kovlep,pozicio;
    double st,i;


    double cel_x = (double)cel_x1;
    double cel_y = (double)cel_y1;
    double sp = (double)sp1;
    double pozix =this->poz.x;
    double poziy =this->poz.y;

    d = sqrt(pow((cel_x- pozix),2)+pow((cel_y-poziy),2));
    st = ceil(d/sp);
    for(i = 1;i<st+1;i++)
    {
        pozicio.x = round(pozix+(cel_x- pozix)*(i/st));
        pozicio.y = round(poziy+(cel_y-poziy)*(i/st));
        this->pool.push(pozicio);
    }
    kovlep = pool.front();
    pool.pop();
    e = ceil(sqrt(pow((kovlep.x-pozix),2)+pow((kovlep.y-poziy),2)));
    return e;

}
void jatekos::poolba(int &cel_x1, int &cel_y1, int &sp1)
{
    clear();
    double d;
    p2d pozicio;
    double st,i;

    double cel_x = (double)cel_x1;
    double cel_y = (double)cel_y1;
    double sp = (double)sp1;
    double pozix =this->poz.x;
    double poziy =this->poz.y;

    d = sqrt(pow((cel_x- pozix),2)+pow((cel_y-poziy),2));
    st = ceil(d/sp);
    for(i = 1;i<st+1;i++)
    {
        pozicio.x = round(pozix+(cel_x- pozix)*(i/st));
        pozicio.y = round(poziy+(cel_y-poziy)*(i/st));
        this->pool.push(pozicio);
    }
}
void jatekos::poolba1(int cel_x1, int cel_y1)
{
    clear();
    double d;
    p2d pozicio;
    double st,i;

    double cel_x = (double)cel_x1;
    double cel_y = (double)cel_y1;
    double sp = 1;
    double pozix =this->poz.x;
    double poziy =this->poz.y;

    d = sqrt(pow((cel_x- pozix),2)+pow((cel_y-poziy),2));
    st = ceil(d/sp);
    for(i = 1;i<st+1;i++)
    {
        pozicio.x = round(pozix+(cel_x- pozix)*(i/st));
        pozicio.y = round(poziy+(cel_y-poziy)*(i/st));
        this->pool.push(pozicio);
    }
}
void jatekos::poolba2(int cel_x1, int cel_y1)
{
    clear();
    double d;
    p2d pozicio;
    double st,i;

    double cel_x = (double)cel_x1;
    double cel_y = (double)cel_y1;
    double sp = 2;
    double pozix =this->poz.x;
    double poziy =this->poz.y;

    d = sqrt(pow((cel_x- pozix),2)+pow((cel_y-poziy),2));
    st = ceil(d/sp);
    for(i = 1;i<st+1;i++)
    {
        pozicio.x = round(pozix+(cel_x- pozix)*(i/st));
        pozicio.y = round(poziy+(cel_y-poziy)*(i/st));
        this->pool.push(pozicio);
    }
}
void jatekos::poolba3(int cel_x1, int cel_y1)
{
    clear();
    double d;
    p2d pozicio;
    double st,i;

    double cel_x = (double)cel_x1;
    double cel_y = (double)cel_y1;
    double sp = 3;
    double pozix =this->poz.x;
    double poziy =this->poz.y;

    d = sqrt(pow((cel_x- pozix),2)+pow((cel_y-poziy),2));
    st = ceil(d/sp);
    for(i = 1;i<st+1;i++)
    {
        pozicio.x = round(pozix+(cel_x- pozix)*(i/st));
        pozicio.y = round(poziy+(cel_y-poziy)*(i/st));
        this->pool.push(pozicio);
    }
}
void jatekos::clear()
{
   std::queue<p2d> empty;
   std::swap(this->pool, empty );
}
bool jatekos::operator == (const jatekos &p2)
{
    if(poz.x == p2.poz.x && poz.y == p2.poz.y)
    {
    return true;
    }
    else{
        return false;
    }
}
bool jatekos::operator != (const jatekos &p2){
    if(poz.x != p2.poz.x || poz.y != p2.poz.y)
    {
    return true;
    }
    else{
        return false;
    }
}
int jatekos::tavolsag(jatekos &barat){
    double d;
    int st,sp=1;
    d = sqrt(pow((barat.poz.x-this->poz.x),2)+pow((barat.poz.y-this->poz.y),2));
    st = ceil(d/sp);
    return st;
}
void jatekos::poolcelba(int celx, int cely) { p2d celpoz; celpoz.x=celx; celpoz.y=cely; this->poolcel.push(celpoz); }
