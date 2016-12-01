//#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include "DEFENDER.h"
#include "KEEPER.h"
#include "ATTACKER.h"
#include "jatekos.h"
#include "valasz.h"

#include <fstream>

using namespace std;

int  s=1,tick = 0,labdaid,tarsuzenet=-1,sajatcsap,sajatid=0,ellenid = 0;
int *score = new int[2];
int tipid [2][4];
int bid =0;
int termin,termax;
p2d passzhely;
palya p;
kapu *kapuk = new kapu[1];
map <int, jatekos> jatekosok;
vector<int> vissza;
vector<int> legkozelebbipont;
valasz message;
bool vanlabda = false,visszamozgok = false,kijon=false;
char selector;

int akttick=0,eset=-1,masodikeset=-10,ellensegid,csakegyszer=0,lepunk=0,keset=-1;
string tarsnak,aka,oss,xxx;
bool labdaszerzes=true,xy=false,ujkor=false,beall=false,teszteltunk=false;
bool passzoltam = false;
int tesztd=0;
int regitick = 0,regiticksajat = 0;
int terminbar,termaxbar,fobaratid,balljbex;
string baalljbe;
bool jobb;
jatekos sajjatekos;

int main()
{
    kezdesd(p, kapuk, jatekosok,sajatid);
    kord(tick,score,jatekosok,labdaid,tarsuzenet,vanlabda);
    message.print();
    selector = jatekosok[sajatid].tip[0];
    sajatcsap = jatekosok[sajatid].team;

    switch(selector){
    case 'D':
       while (tick<500)
        {
			//Kör futtatás és emberek idjának kinyerése
            kord(tick,score,jatekosok,labdaid,tarsuzenet,vanlabda);      
            jatekoskeresod(jatekosok,"DEFENDER",sajatcsap,vissza,sajatid);
            ellenid = ellensegkeresod(jatekosok,"ATTACKER");
            fobaratid = ellensegkeresod(jatekosok,"DEFENDER");

            //Bool és térfél beállítás
			if(jatekosok[ellenid] == jatekosok[labdaid])
			{

				passzoltam = false;
			}
            //térféllel lehet játszani,nagyon nagy pont különbségeket jelent,de néha nagyon kicsi eredmény,miért? -> próbálgatni
            if(jatekosok[sajatid].poz.y > (p.get_sz()/2) && tick <3)
            {
                termin = p.get_sz()/2;
                termax = p.get_sz()-1;
                jobb = true;
            }
            else if(tick < 3)
            {
                termin = 0;
                termax = p.get_sz()/2;
                jobb = false;
            }
            if(jatekosok[sajatid].e > 14 && jatekosok[fobaratid].poz.y !=  jatekosok[labdaid].poz.y  )
            {
                if(jobb){
                    termin = p.get_sz()/2-3;
                    termax = p.get_sz()-1;
                }
                else{
                    termin = 0;
                    termax = p.get_sz()/2+3;
                }
            }
            else if(jatekosok[sajatid].e > 10 &&  jatekosok[fobaratid].poz.y !=  jatekosok[labdaid].poz.y )
            {
                if(jobb){
                    termin = p.get_sz()/2-1;
                    termax = p.get_sz()-1;
                }
                else{
                    termin = 0;
                    termax = p.get_sz()/2+1;
                }
            }
            else
            {
                if(jobb){
                    termin = p.get_sz()/2;
                    termax = p.get_sz()-1;
                }
                else{
                    termin = 0;
                    termax = p.get_sz()/2;
                }
            }
			//Regitick
            if(!jatekosok[labdaid].mozog && !jatekosok[ellenid].mozog && jatekosok[sajatid].mozog )
            {
                regitick = regitick;
            }
            else if(!jatekosok[labdaid].mozog && !jatekosok[ellenid].mozog){
                regitick++;
            }
            else
            {
                regitick = 0;
            }
			//Regitick saját magunkra nézve
			if(!jatekosok[sajatid].mozog)
            {
                regiticksajat++;
				
            }
            else
            {
                regiticksajat = 0;
            }
            //Teendők
            //Bartának írni,hova menjen ->ezt fejleszteni kell,nem jó így

            if(regiticksajat > 11 && jatekosok[labdaid].poz.y>=termin && jatekosok[labdaid].poz.y <= termax)
			{
				jatekosok.clear();
				regiticksajat = 0;
				message.print();
			}
            else if(regitick > 9)
            {
                if(jatekosok[sajatid].poz.x != jatekosok[labdaid].poz.x || jatekosok[sajatid].poz.y != jatekosok[labdaid].poz.y )
				{
					message.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
				}
                else if(jatekosok[sajatid].e >= jatekosok[ellenid].e){
                    if(jatekosok[sajatid].poz.y > p.get_sz()/2){
                        p2d cel;
                        int kx =0;
                        int ky =0;
                        jatekosok[sajatid].poolba(kx,ky,s);
                        cel = jatekosok[sajatid].pool.front();
                        int ujcelx,ujcely;
                        ujcelx = cel.x;
                        ujcely = cel.y;
                        if(tarsuzenet == 9)
                        {
                           message.print(ujcelx,ujcely,1);
                        }
                        else{
                           message.print(ujcelx,ujcely,1,ujcelx,ujcely,1);
                        }
                        passzoltam = false;
					}
					else{
						p2d cel;
                        int kx =6;
                        int ky =10;
                        jatekosok[sajatid].poolba(kx,ky,s);
                        cel = jatekosok[sajatid].pool.front();
                        int ujcelx,ujcely;
                        ujcelx = cel.x;
                        ujcely = cel.y;
                        if(tarsuzenet == 9)
                        {
                           message.print(ujcelx,ujcely,1);
                        }
                        else{
                           message.print(ujcelx,ujcely,1,ujcelx,ujcely,1);
                        }
                        passzoltam = false;
					}
				}
				else{
					message.print();
				}
                
            }
            else if(tarsuzenet == 8 && (jatekosok[labdaid].poz.y<termin ||jatekosok[labdaid].poz.y > termax) && !passzoltam)
            {
                if(jatekosok[sajatid].team == 1)
                {
                    balljbex = 0;
                }
                else
                {
                    balljbex = p.get_m()-1;
                }
                baalljbe = "MESSAGE "+to_string(fobaratid) + " PLAYER " + to_string(balljbex) +" "+ to_string(jatekosok[labdaid].poz.y)+" 2 BALL null null null";
                //baalljbe = "MESSAGE "+to_string(fobaratid) + " PLAYER " + to_string(balljbex) +" "+ to_string(jatekosok[labdaid].poz.y)+" 1 BALL " + to_string(balljbex) +" "+ to_string(jatekosok[labdaid].poz.y)+" 1";
                message.print(baalljbe);
            }
            else if(jatekosok[sajatid] == jatekosok[labdaid] &&jatekosok[fobaratid] == jatekosok[labdaid] && jatekosok[ellenid] == jatekosok[labdaid] && jatekosok[fobaratid].e >=jatekosok[ellenid].e )
            {
                if(jatekosok[sajatid].poz.x == p.get_m()/2 && jatekosok[sajatid].poz.y ==p.get_sz()/2 )
                {
                    p2d cel;
                    int kx =(p.get_m()/2+1);
                    int ky =(p.get_sz()/2+1) ;
                    jatekosok[sajatid].poolba(kx,ky,s);
                    cel = jatekosok[sajatid].pool.front();
                    int ujcelx,ujcely;
                    ujcelx = cel.x;
                    ujcely = cel.y;
                    message.print(ujcelx,ujcely,1);
                    passzoltam = false;
                }
                else{
                    p2d cel;
                    int kx =(p.get_m()/2);
                    int ky =(p.get_sz()/2) ;
                    jatekosok[sajatid].poolba(kx,ky,s);
                    cel = jatekosok[sajatid].pool.front();
                    int ujcelx,ujcely;
                    ujcelx = cel.x;
                    ujcely = cel.y;
                    message.print(ujcelx,ujcely,1);
                    passzoltam = false;
                }
            }
            else if(regitick > 6 &&jatekosok[sajatid] == jatekosok[labdaid] )
            {
                p2d cel;
                int kx =(p.get_m()/2+1);
                int ky =(p.get_sz()/2+1) ;
                jatekosok[sajatid].poolba(kx,ky,s);
                cel = jatekosok[sajatid].pool.front();
                int ujcelx,ujcely;
                ujcelx = cel.x;
                ujcely = cel.y;
                message.print(ujcelx,ujcely,1,ujcelx,ujcely,1);
            }
            else if(jatekosok[sajatid] == jatekosok[labdaid] &&jatekosok[fobaratid] == jatekosok[labdaid] && jatekosok[ellenid] == jatekosok[labdaid] && jatekosok[fobaratid].e < jatekosok[ellenid].e)
            {
                 message.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1);passzoltam = false;
            }
            /*else if(regitick > 6)
            {
                 message.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
            }*/
            else if(jatekosok[sajatid] == jatekosok[labdaid])
            {
                 passz2d(jatekosok,vissza[0],labdaid,p,passzoltam,tesztd,tarsuzenet,regitick,sajatid);
            }
            else if (vanlabda) {
                 vedunk(jatekosok,p,labdaid,vissza[0],termin,termax,tarsuzenet,passzoltam,tesztd,regitick,sajatid);
            }
            else{
                message.print();passzoltam = false; 
            }
            tarsuzenet =0;
        }
        break;
    case 'A':
        while (tick<500)
        {
            kor(tick,akttick, score, jatekosok, labdaid,tarsuzenet);
            if(((jatekosok[ellensegid]==jatekosok[labdaid] && jatekosok[sajatid]!=jatekosok[labdaid])|| (jatekosok[ellensegid]==jatekosok[labdaid] && jatekosok[sajatid]==jatekosok[labdaid] && jatekosok[sajatid].e<=jatekosok[ellensegid].e) || gol(kapuk,jatekosok,labdaid) || akttick==27) && tick>5)
            {
                labdaszerzes=true;
                tarsuzenet=-1;
                lepunk=0;
                eset=1;
                csakegyszer=0;
                ujkor=true;
                beall=false;
                teszteltunk=false;
                kijon=false;
                while (!jatekosok[sajatid].poolcel.empty())
                {
                    jatekosok[sajatid].poolcel.pop();
                }
                while (!jatekosok[labdaid].poolcel.empty())
                {
                    jatekosok[labdaid].poolcel.pop();
                }
                if(akttick==27) {akttick=0;}
                else {akttick=-1;}
                vissza.erase(vissza.begin(),vissza.end());
                int torlendoid=0;
                torlendoid=ellensegkereso(jatekosok,"ATTACKER", sajatid);
                if(torlendoid != 0){jatekosok.erase(torlendoid);}
                torlendoid=ellensegkereso(jatekosok,"ATTACKER",sajatid);
                if(torlendoid != 0){jatekosok.erase(torlendoid);}
                torlendoid=ellensegkereso(jatekosok,"ATTACKER",sajatid);
                if(torlendoid != 0){jatekosok.erase(torlendoid);}
            }
            kozelitunk(jatekosok , kapuk , labdaid ,tick,vissza,tarsuzenet,legkozelebbipont,labdaszerzes,eset,ujkor,ellensegid,keset,beall,teszteltunk,lepunk,akttick,kijon,sajatid);
        }
        break;
    case 'K':
        while (tick<500)
        {
           kork(tick, score, jatekosok, labdaid,tarsuzenet,vanlabda);
           bid = ellensegkeresok(jatekosok,"DEFENDER");
           ellenid = ellensegkeresod(jatekosok,"ATTACKER");
           sajjatekos = jatekosok[sajatid];
           //Regitick
           if(!jatekosok[labdaid].mozog && !jatekosok[ellenid].mozog && jatekosok[labdaid]==jatekosok[ellenid])
           {
               regitick++;
           }
           else
           {
               regitick = 0;
           }
           //bool állítások
           if(bid == 0 || (jatekosok[labdaid] == jatekosok[ellenid]))
           {
               visszamozgok = false;
               passzoltam = false;
           }
           if(jatekosok[bid] == jatekosok[labdaid] && jatekosok[sajatid] != jatekosok[labdaid])
           {
               jatekosok.erase(bid);
           }
           //különleges eset,ha beszorulunk a kapu sarkába
           if(kapumellettell(jatekosok,kapuk,ellenid) && jatekosok[labdaid]==jatekosok[ellenid]){
               if(jatekosok[labdaid]==jatekosok[sajatid] && jatekosok[sajatid].e >= jatekosok[ellenid].e)
               {
                   int celx;
                   if(jatekosok[sajatid].team == 1)
                   {
                       celx =jatekosok[sajatid].poz.x+1;
                    }
                   else{
                       celx = jatekosok[sajatid].poz.x-1;
                   }
                   message.print(celx,jatekosok[sajatid].poz.y,1,celx,jatekosok[sajatid].poz.y,1);
               }
               else if(jatekosok[labdaid]==jatekosok[sajatid])
                   {
                       message.print();
                   }
               else
                     {
                         if(jatekosok[sajatid].poz.y == jatekosok[ellenid].poz.y)
                       {
                           message.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
                       }
                       else{
                           message.print(jatekosok[sajatid].poz.x,jatekosok[labdaid].poz.y,1);
                       }
                   }
           }
           //Egy helyen állunk
           else if(jatekosok[bid] == jatekosok[labdaid] && bid !=0 && jatekosok[sajatid] == jatekosok[labdaid])
           {
               int x,y;
               if(jatekosok[bid].e < jatekosok[ellenid].e )
               {
                   message.print();
               }
               else
               {
                   y = (kapuk->a.y+kapuk->b.y)/2;
                   x = mozgasx(kapuk,sajjatekos);
                   message.print(x,y,1);
                   jatekosok.erase(bid);
               }
           }
           //ha nálunk van a labda
           else if (jatekosok[sajatid] == jatekosok[labdaid])
           {
               passz2k(jatekosok,bid,labdaid,passzoltam,tesztd,tarsuzenet,kapuk,sajatid);
           }
           //ha ellenségnél van a labda
           else if(!passzoltam)
           {
               ramozdulk(jatekosok,kapuk,labdaid,p,regitick,sajatid);
           }
           //Többi esetben megyünk a kapu elé
           else{
               int x,y;
               y = (kapuk->a.y+kapuk->b.y)/2;
               if(jatekosok[sajatid].team == 1)
               {
                   x = kapuk->a.x+2;
               }
               else{
                   x = kapuk->a.x-2;
               }
               message.print(x,y,1);
           }
        }
        break;
    default:
        break;
    }
    ofstream myfile;
    myfile.open ("example.txt", fstream::app);
    myfile << sajatcsap<<" "<<score[0]<<" "<<score[1]  << "\n";
    myfile.close();
    return 0;
}
