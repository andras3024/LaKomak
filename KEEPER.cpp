#include "KEEPER.h"

// Első kör információi
void kezdesk(palya& p,kapu* kapuk, map <int, jatekos>& jatekosok)
{
    bool l = true;
    int i = 0;
    string dontes, uzenet;
    while (l)
    {
        getline(cin, uzenet);
        if (uzenet == ".")
        {
            l = false;
        }
        else
        {
            int m = 0;
            dontes = ujadat(uzenet, m);
            if (dontes == "SIZE")
            {
                int x = 0, y = 0;
                x = atoi(ujadat(uzenet, m).c_str());
                y = atoi(ujadat(uzenet, m).c_str());
                p.set(x, y);

            }
            else if (dontes == "GATE")
            {
                string seged;
                kapuk[i].a.x= atoi(ujadat(uzenet, m).c_str());
                kapuk[i].a.y = atoi(ujadat(uzenet, m).c_str());
                kapuk[i].b.x = atoi(ujadat(uzenet, m).c_str());
                kapuk[i].b.y = atoi(ujadat(uzenet, m).c_str());
                seged = ujadat(uzenet, m).c_str();
                seged.erase(0,1);
                kapuk[i].d = atoi(seged.c_str());
                i++;
            }
            else if (dontes == "ID")
            {
                int id;
                id = atoi(ujadat(uzenet, m).c_str());
                jatekos sajat;
                jatekosok[id] = &sajat;
                jatekosok[id].id = id;
            }
        }
    }

}
//Minden kör elején lefut és beölti az adatokat
void kork(int&tick, int *score, map <int, jatekos>& jatekosok,int&labdaid,int & tarsuzenet,bool & vanlabda)
{
    bool l = true;
    //bool u=true;
    string dontes, uzenet, seged2,tipkap,asd;
    int idkap;
    while (l)
    {
        getline(cin, uzenet);
        if (uzenet == ".")
        {
            l = false;
        }
        else
        {
            int m = 0;
            dontes = ujadat(uzenet, m);
            if (dontes == "TICK")
            {
                tick = atoi(ujadat(uzenet, m).c_str());
            }
            else if (dontes == "SCORE")
            {
                score[0] = atoi(ujadat(uzenet, m).c_str());
                score[1] = atoi(ujadat(uzenet, m).c_str());
            }
            else if (dontes == "MESSAGE")
            {

                asd=ujadat(uzenet,m);
                asd=ujadat(uzenet,m);
                if(asd=="I") {tarsuzenet=0;}
                if(asd=="I") {tarsuzenet=0;}
                else if(asd=="Send") {tarsuzenet=8;}
                else if(asd=="and") {tarsuzenet=8;}
                else if(asd=="Your") {if(tarsuzenet==-1) tarsuzenet=0; else tarsuzenet=0;}
                else if(asd=="When") {tarsuzenet=0;}
                else if(asd=="If") {tarsuzenet=0;}
                else if(asd=="Cross") {tarsuzenet=0;}
                else if(asd=="Cross") {tarsuzenet=0;}
                else if(asd=="I-I") {tarsuzenet=9;}
                else if(asd=="Ball,") {tarsuzenet=0;}
                else if(asd=="Bring") {tarsuzenet=0;}
                else if(asd== "Yololeio"){tarsuzenet=0;}
                else if(asd == "Catch"){tarsuzenet=3;}
                else if(asd == "The"){tarsuzenet=3;}
                /*else
                {
                    while (u)
                    {
                        cout<<uzenet<<tarsuzenet<<endl;
                    }

                }*/


            }
            else
            {
                idkap = atoi(dontes.c_str());
                if (jatekosok.find(idkap) == jatekosok.end())
                {
                    jatekos player;
                    jatekosok[idkap] = &player;
                    jatekosok[idkap].id = idkap;
                }
                tipkap = ujadat(uzenet, m).c_str();

                if (tipkap == "BALL")
                {
                    vanlabda = true;
                    labdaid = idkap;
                    jatekosok[idkap].tip = tipkap;
                    jatekosok[idkap].elozopoz.x=jatekosok[idkap].poz.x;
                    jatekosok[idkap].elozopoz.y=jatekosok[idkap].poz.y;
                    jatekosok[idkap].poz.x = atoi(ujadat(uzenet, m).c_str());
                    jatekosok[idkap].poz.y = atoi(ujadat(uzenet, m).c_str());
                    if(jatekosok[idkap].elozopoz.x==jatekosok[idkap].poz.x && jatekosok[idkap].elozopoz.y==jatekosok[idkap].poz.y)
                    {
                        jatekosok[idkap].mozog=false;
                    }
                    else jatekosok[idkap].mozog=true;
                }
                else
                {
                    jatekosok[idkap].tip = tipkap;
                    jatekosok[idkap].elozopoz.x=jatekosok[idkap].poz.x;
                    jatekosok[idkap].elozopoz.y=jatekosok[idkap].poz.y;
                    jatekosok[idkap].poz.x = atoi(ujadat(uzenet, m).c_str());
                    jatekosok[idkap].poz.y = atoi(ujadat(uzenet, m).c_str());
                    seged2= ujadat(uzenet, m).c_str();
                    seged2.erase(0, 1);
                    jatekosok[idkap].team = atoi(seged2.c_str()) ;
                    jatekosok[idkap].e = atoi(ujadat(uzenet, m).c_str());
                    if(jatekosok[idkap].elozopoz.x==jatekosok[idkap].poz.x && jatekosok[idkap].elozopoz.y==jatekosok[idkap].poz.y)
                    {
                        jatekosok[idkap].mozog=false;
                    }
                    else jatekosok[idkap].mozog=true;
                    if(jatekosok[idkap].poz.x==jatekosok[labdaid].poz.x && jatekosok[idkap].poz.y==jatekosok[labdaid].poz.y)
                    {
                        jatekosok[idkap].nalalabda=true;
                    }
                    else jatekosok[idkap].nalalabda=false;
                }
            }
        }

    }
}
//Megkeres egy adott típusú játékost, az átadott vektorba tölti be
void jatekoskeresok(map <int, jatekos>& jatekosok,string tipus,int csapat,vector<int>&vissza,int &sajatid)
{
    map <int, jatekos>::iterator it;
    for(it = jatekosok.begin(); it != jatekosok.end(); it++)
    {
            if(it->second.tip == tipus && it->second.team == csapat && it->second.id != sajatid)
            {
                vissza.push_back(it->first);

            }
    }
}
//Megkeres egy adott típusú játékost, egy id(int) értéket ad vissza
int ellensegkeresok(map <int, jatekos>& jatekosok,string tipus)
{
    map <int, jatekos>::iterator it;
    int id = 0;
    for(it = jatekosok.begin(); it != jatekosok.end(); it++)
    {
            if(it->second.tip == tipus)
            {
                id = it->first;

            }
    }
    return id;
}
//jatekosok[sajatid].nalalabda bool-t változtatja, attól függően egy helyen állunk-e a labdával vagy sem
//MÉG SOK ÉRTELME NINCS, NEM HASZNÁLOM SEHOL!
bool labdatartask(map<int, jatekos> &jatekosok, int &labdaid,int &sajatid)   // ez még csak kezdés, sok értelme még nincs
{
    if((jatekosok[sajatid].poz.x==jatekosok[labdaid].poz.x)&&(jatekosok[sajatid].poz.y==jatekosok[labdaid].poz.y))
        jatekosok[sajatid].nalalabda=true;
    else
        jatekosok[sajatid].nalalabda=false;

    return jatekosok[sajatid].nalalabda;
}
//Vizsgálja, hogy a kapufa mellet (kívülről) áll-e a KAPUSUNK [sajatid], ezt hasznájuk a beakadás ellen
bool kapumellett(map<int,jatekos> &jatekosok, kapu *kapuk,int &sajatid)
{
    if((jatekosok[sajatid].poz.x==kapuk->a.x) && (((abs(jatekosok[sajatid].poz.y-kapuk->a.y))==1) || ((abs(jatekosok[sajatid].poz.y-kapuk->b.y))==1)))
        return true;
    else
        return false;
}
//Vizsgálja, hogy a kapufa mellet (kívülről) áll-e az ELLENFÉL [ellenid], ezt hasznájuk a beakadás ellen
bool kapumellettell(map<int,jatekos> &jatekosok, kapu *kapuk,int &ellenid)
{
    if((jatekosok[ellenid].poz.x==kapuk->a.x) && (((abs(jatekosok[ellenid].poz.y-kapuk->a.y))==1) || ((abs(jatekosok[ellenid].poz.y-kapuk->b.y))==1)))
        return true;
    else
        return false;
}
// ha nem mozog rámegyek, ha mozog kapu előtt szögben védekezek (kapus mozgása labda nélkül támadáskor)
void ramozdulk(map<int, jatekos> &jatekosok, kapu *kapuk, int &labdaid,palya &p,int &regitick,int &sajatid)
{

     valasz mess;
     int ellenid, sebesseg=1,kapx,labdax;
     ellenid = ellensegkeresok(jatekosok,"ATTACKER");

     int sajatx,vedunkx,veszx;

     if(jatekosok[sajatid].team == 1) //Egyik térfélen vagyunkm beallitjuk a kapu előtti és veszélyes zónát
     {
         vedunkx = 1;
         veszx =6;

         //ellx = vedunkx-jatekosok[ellenid].poz.x;    //ellenség távolsága a védendő sortól
         sajatx =vedunkx-jatekosok[sajatid].poz.x;   //saját távolságunk a védendő sortól
         labdax = vedunkx-jatekosok[labdaid].poz.x;  //labda távolsága a védendő sortól
     }
     else                              // Másik térfélen vagyunk és beallitjuk a kapu eleőtti és veszélyes zónát
     {
         vedunkx = p.get_m()-2;
         veszx=6;

         //ellx = vedunkx-jatekosok[ellenid].poz.x;
         sajatx =vedunkx-jatekosok[sajatid].poz.x;
         labdax = vedunkx-jatekosok[labdaid].poz.x;
     }

     //EZEN KÉNE CSISZOLNI? FURCSA A SEBESSÉGES RÉSZ !!!

     if(regitick<4)            // regitick akkor növekszik, ha regota nem mozgot az ellenfel es a labda
     {

         if( sajatx>=labdax && sajatx > veszx){
         sebesseg = 2; //le kell hagynunk
         }
         if( abs(jatekosok[sajatid].poz.y-jatekosok[labdaid].poz.y)>2 && labdax < veszx){
             /*if(jatekosok[sajatid].e>10) //ujdonsag
                sebesseg = 3;
             else*/
                 sebesseg=2;
         }
         if( abs(jatekosok[sajatid].poz.y-jatekosok[labdaid].poz.y)>3&& labdax < veszx){
             if(jatekosok[sajatid].e>10)
                sebesseg = 3;
             else
                 sebesseg=2;
         }
         if (abs(jatekosok[sajatid].poz.y-jatekosok[labdaid].poz.y)>=2 && labdax < veszx)
         {
             if(jatekosok[sajatid].e>10)
                sebesseg = 3;
             else
                 sebesseg=2;
         }
     }
     if(!jatekosok[ellenid].mozog && regitick > 2 && jatekosok[sajatid].e == 20)
     {
         mess.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
     }
     else if(!jatekosok[ellenid].mozog && regitick > 2)
     {
         mess.print();
     }
     else  // különben beallunk a kapu elott arra a pontra, ami a legkozelebb van az ellenfélenk (mert az ellenfél arra halad)
     {
         int minimum=min(kapuk->a.y,kapuk->b.y)-1;
         int maximum=max(kapuk->a.y,kapuk->b.y)+1;
         int i=0, j=-1;
         double tav_min=1000;
         double tav = 0;

         for(i=minimum; i<maximum+1; i++)   // kapu melyik pontja van a legközelebb
         {
             tav=pow(jatekosok[labdaid].poz.y-i,2) + pow(jatekosok[labdaid].poz.x-kapuk->a.x,2);

             if(tav < tav_min)
             {
                 tav_min=tav;
                 j++;
             }
         }
         /*mozgasy = minimum+j;
         if(jatekosok[labdaid].poz.x == jatekosok[sajatid].poz.x && jatekosok[labdaid].elozopoz.x == jatekosok[sajatid].poz.x)// ez se segít egyenlőre
         {
            if(jatekosok[labdaid].poz.x-jatekosok[labdaid].elozopoz.x<0)
            {
                mozgasy = mozgasy-1;
            }
            else if(jatekosok[labdaid].poz.x-jatekosok[labdaid].elozopoz.x>0)
            {
                mozgasy = mozgasy+1;
            }
            else
            {
                mozgasy = mozgasy;
            }
         }*/
         //
         //X koordináta
         if(abs(jatekosok[labdaid].poz.x-kapuk->a.x) == 1)
         {
             if(jatekosok[sajatid].team == 1)
             {
                 kapx = kapuk->a.x+1;
             }
             else
             {
                 kapx = kapuk->a.x-1;
             }
         }
         else
         {
             if(jatekosok[sajatid].team == 1)
             {
                 kapx = kapuk->a.x+2;
             }
             else
             {
                 kapx = kapuk->a.x-2;
             }
         }
        if(kapumellett(jatekosok, kapuk,sajatid)){
             if(jatekosok[sajatid].team == 1)
             {
                 kapx = kapuk->a.x+2;
             }
             else{
                  kapx = kapuk->a.x-2;
             }
             mess.print(kapx,jatekosok[sajatid].poz.y,sebesseg);
         }
         else{
             mess.print(kapx,minimum+j,sebesseg);
         }

     }
}
//A kapus x mozgasánák koord.
int mozgasx (kapu *kapuk,jatekos &sajatj)
{
    int x;
    if(sajatj.team == 1)
    {
        x = kapuk->a.x+1;
        if(sajatj.poz.x == x)
        {
            x = kapuk->a.x+3;
        }
    }
    else{
        x = kapuk->a.x-1;
        if(sajatj.poz.x == x)
        {
            x = kapuk->a.x-3;
        }
    }
    return x;
}
// ha megszereztük a labdát --> eljuttatjuk a csapattársig
void passz2k(map<int, jatekos> &jatekosok,int& tarsid,int &labdaid,bool &passzoltam,int &teszt,int &uzenet,kapu *kapuk,int &sajatid)
{
    int celx,cely,s = 1,ellenid,kapx;
    valasz message;
    string tarsuzenet;
    p2d cel;
    ellenid = ellensegkeresok(jatekosok,"ATTACKER");
    bool labdaszerzes = false;
    if(jatekosok[sajatid] == jatekosok[labdaid]  && jatekosok[sajatid].elozopoz.x == jatekosok[labdaid].elozopoz.x && jatekosok[sajatid].elozopoz.y == jatekosok[labdaid].elozopoz.y )
    {
        labdaszerzes = false;
    }
    else if(jatekosok[sajatid] == jatekosok[labdaid] )
    {
        labdaszerzes = true;
    }
    // Cél koordináták
    if(tarsid !=0)
    {
        if(jatekosok[sajatid].poz.y!=jatekosok[tarsid].poz.y)
        {
            celx=jatekosok[sajatid].poz.x;
            cely=jatekosok[tarsid].poz.y;
        }
        else
        {
            celx=jatekosok[tarsid].poz.x;
            cely=jatekosok[tarsid].poz.y;
        }
    }
    //
    if(kapumellett(jatekosok, kapuk,sajatid))
    {
        if(jatekosok[sajatid].team == 1)
        {
           kapx = kapuk->a.x+1;
        }
        else{
           kapx = kapuk->a.x-1;
        }
        message.print(kapx,jatekosok[sajatid].poz.y,s,kapx,jatekosok[sajatid].poz.y,s);
    }
    else if(labdaszerzes && abs(jatekosok[sajatid].poz.x-kapuk->a.x)< 5)
    {
        message.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1);
    }
    else if(uzenet ==8)
    {
        tarsuzenet = "MESSAGE "+ to_string(tarsid) + " PLAYER " + to_string(jatekosok[sajatid].poz.x) +" "+ to_string(jatekosok[sajatid].poz.y)+" 1 BALL null null null";
        message.print(tarsuzenet);
    }
    else if(uzenet == 3 && jatekosok[tarsid].tavolsag(jatekosok[sajatid])<3) // nincs túl sok haszna
    {
        message.print();
    }
    else{
        tarsuzenet="MESSAGE "+ to_string(tarsid) + "PLAYER " + to_string(jatekosok[sajatid].poz.x) +" "+ to_string(jatekosok[sajatid].poz.y);
        if(tarsid==0 )
        {
            message.print();
        }
        else
        {
            if(jatekosok[sajatid] == jatekosok[labdaid] &&jatekosok[ellenid] == jatekosok[labdaid] && jatekosok[sajatid].e >= jatekosok[ellenid].e && jatekosok[sajatid].e <20)
            {
                message.print();
            }
            //Ne mozugjunk túl sokat el egymás mellett
            else if(jatekosok[sajatid].poz.x == jatekosok[tarsid].elozopoz.x && jatekosok[sajatid].poz.y == jatekosok[tarsid].elozopoz.y )
            {
                 message.print();
            }
            else if(jatekosok[tarsid].poz.x == jatekosok[sajatid].elozopoz.x && jatekosok[tarsid].poz.y == jatekosok[sajatid].elozopoz.y )
            {
                 message.print();
            }
            //
            else if( jatekosok[sajatid].e <= (jatekosok[ellenid].e+3) && jatekosok[sajatid].e <19 && jatekosok[ellenid].e<=20)
            {
                message.print();
            }
            else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 1 && !jatekosok[tarsid].mozog ){
                message.loves(celx,cely,1,tarsuzenet); passzoltam = true;
            }
            else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 2 && jatekosok[sajatid].e > 6 && !jatekosok[tarsid].mozog){
                if(abs(jatekosok[sajatid].poz.y-jatekosok[ellenid].poz.y)>2)
                {
                    s = 1;
                }
                else{
                    s=2;
                }
                message.loves(celx,cely,2,tarsuzenet); passzoltam = true;
            }
            else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 3 && jatekosok[sajatid].e > 7 && !jatekosok[tarsid].mozog){
               if(abs(jatekosok[sajatid].poz.y-jatekosok[ellenid].poz.y)>2)
               {
                   s = 1;
               }
               else{
                   s=2;
               }
                message.loves(celx,cely,s,tarsuzenet); passzoltam = true;
            }
            else{
                tarsuzenet="MESSAGE "+ to_string(tarsid) + "PLAYER " + to_string(jatekosok[sajatid].poz.x) +" "+ to_string(jatekosok[sajatid].poz.y);
                jatekosok[sajatid].poolba(celx,cely,s);
                cel = jatekosok[sajatid].pool.front();
                int ujcelx,ujcely;
                ujcelx = cel.x;
                ujcely = cel.y;
                teszt++;
                message.print(ujcelx,ujcely,1,ujcelx,ujcely,1,tarsuzenet);
            }
        }

    }
}



