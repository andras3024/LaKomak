#include "ATTACKER.h"

string ujadat(string s, int& kezd) // de String^ még nem
{
    string csk = " ";
    string st = s.substr(kezd, s.length() - kezd); // kezd-töl a végéig
    int i = st.find_first_of(csk); // van-e benne elválasztó ?
    kezd = kezd + i + 1; // legközelebb csak a fennmaradó részben keresünk
    if (i == -1) // nincs több elválasztó
        return st; // mehet az utolsó string vissza
    return st.substr(0, i); // egyébként csak az elsö elválasztóig.
}
void kezdes(palya& p,kapu* kapuk, map <int, jatekos>& jatekosok)
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
            //else { cout << "nem jo formatum" << endl; }
        }
    }

}
void kor(int &tick,int &akttick, int *score, map <int, jatekos>& jatekosok,int&labdaid,int & tarsuzenet)
{
    bool l = true;
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
                akttick++;
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
                else if(asd=="Send") {tarsuzenet=1;}
                else if(asd=="and") {tarsuzenet=1;}
                else if(asd=="Your") {tarsuzenet=0;}
                else if(asd=="When") {tarsuzenet=2;}
                else if(asd=="If") {tarsuzenet=2;}
                else if(asd=="Cross") {tarsuzenet=2;}
                /*else
                {
                    while (xy)
                    {
                        cout<<tick<<uzenet<<endl;
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
                    labdaid = idkap;
                    jatekosok[labdaid].tip = tipkap;
                    jatekosok[labdaid].elozopoz.x=jatekosok[labdaid].poz.x;
                    jatekosok[labdaid].elozopoz.y=jatekosok[labdaid].poz.y;
                    jatekosok[labdaid].poz.x = atoi(ujadat(uzenet, m).c_str());
                    jatekosok[labdaid].poz.y = atoi(ujadat(uzenet, m).c_str());
                    if(jatekosok[labdaid].elozopoz.x==jatekosok[labdaid].poz.x && jatekosok[labdaid].elozopoz.y==jatekosok[labdaid].poz.y)
                    {
                        jatekosok[labdaid].mozog=false;
                    }
                    else jatekosok[labdaid].mozog=true;
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
void csapattarskereso(map <int, jatekos>& jatekosok,string tipus,int csapat,vector<int>&vissza, int &sajatid)
{
    map <int, jatekos>::iterator it;
    for(it = jatekosok.begin(); it != jatekosok.end(); it++)
    {
            if(it->second.tip == tipus && it->second.team == csapat && it->first!=sajatid)
            {
                vissza.push_back(it->first);

            }
    }

}
void kozelitunk(map <int, jatekos>& jatekosok, kapu* kapuk, int &labdaid, int&tick, vector<int> vissza, int& tarsuzenet, vector<int> legkozelebbipont, bool &labdaszerzes, int&eset, bool &ujkor,int &ellensegid, int &keset,bool &beall,bool &teszteltunk, int &lepunk,int &akttick,bool &kijon, int &sajatid)
{
    int id=sajatid,ellensegtav,melyik,cst;
    valasz mess;
    p2d lovescel,megyunk;
    bool asd=true;
    csapattarskereso(jatekosok,"ATTACKER",jatekosok[id].team,vissza,sajatid);
    ellensegid=ellensegkereso(jatekosok,"KEEPER",sajatid);
    cst=ellensegkereso(jatekosok,"ATTACKER",sajatid);
    legkozelebbipont.erase(legkozelebbipont.begin(),legkozelebbipont.end());
    kaputav(kapuk,jatekosok,legkozelebbipont,sajatid);

    if(vissza.empty() && !ujkor) {eset=1;}
    if(tick==4)                 //a ötödik körben kapom az elso uzenetet ezert a negyedikben megállok h ha odapasszolja nekem akkor ne kelljen visszamenni
    {
        mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1);
        eset=-2;
    }
    if(tick==5 || ujkor)        //jon az uzi vagy uj korvan
    {
        eset=esetvalaszto(tarsuzenet);
        if(tarsuzenet!=-1) {ujkor=false;}
    }
    if(jatekosok[id]==jatekosok[labdaid] && !ujkor){labdaszerzes=false;}
    beall=beallt(jatekosok, kapuk,sajatid);
    if(labdaszerzes)
    {
        switch (eset)
        {
        case 1:         //amíg nem kapunk üzenetet megyunk a kapu kozepe felé ésa kaputol ot tavolsagra
            if(jatekosok[sajatid].team==1)
            {
                mess.print(kapuk->a.x-5,(kapuk->a.y+kapuk->b.y)/2,1);
            }
            else if (jatekosok[sajatid].team==2)
            {
                mess.print(kapuk->a.x+5,(kapuk->a.y+kapuk->b.y)/2,1);
            }
            break;
        case 2:     //megállunk és várjuk a labdát
            mess.print(jatekosok[id].elozopoz.x,jatekosok[id].elozopoz.y,1);
            jatekosok[cst].poolba1(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
            jatekosok[cst].poolba2(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
            jatekosok[cst].poolba3(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
            eset=5;
            break;
        case 3:    //oda passzol ahova mondjuk

            ellensegtav=ellensegkereso(jatekosok,"ATTACKER",sajatid);
            if(jatekosok[sajatid].team==2)
            {
                {mess.print(kapuk->a.x+5,(kapuk->a.y+kapuk->b.y)/2,1,"MESSAGE "+to_string(ellensegtav) +" PLAYER "+to_string(jatekosok[ellensegtav].poz.x)+" "+ to_string(jatekosok[ellensegtav].poz.y)+" 1 BALL "+to_string(kapuk->a.x+5)+" "+to_string((kapuk->a.y+kapuk->b.y)/2)+" "+to_string(1));}
                jatekosok[cst].poolba1(kapuk->a.x+5,(kapuk->a.y+kapuk->b.y)/2);
                jatekosok[cst].poolba2(kapuk->a.x+5,(kapuk->a.y+kapuk->b.y)/2);
                jatekosok[cst].poolba3(kapuk->a.x+5,(kapuk->a.y+kapuk->b.y)/2);

            }
            else if(jatekosok[sajatid].team==1)
            {
                {mess.print(kapuk->a.x-5,(kapuk->a.y+kapuk->b.y)/2,1,"MESSAGE "+to_string(ellensegtav) +" PLAYER "+to_string(jatekosok[ellensegtav].poz.x)+" "+ to_string(jatekosok[ellensegtav].poz.y)+" 1 BALL " +to_string(kapuk->a.x-5)+" "+to_string((kapuk->a.y+kapuk->b.y)/2)+" "+to_string(1));}
                jatekosok[cst].poolba1(kapuk->a.x-5,(kapuk->a.y+kapuk->b.y)/2);
                jatekosok[cst].poolba2(kapuk->a.x-5,(kapuk->a.y+kapuk->b.y)/2);
                jatekosok[cst].poolba3(kapuk->a.x-5,(kapuk->a.y+kapuk->b.y)/2);
            }
            eset=5;
            break;
        case 4:     // el kell menjek a labdáért de nem biztos, hogy lesz elég energiám
            asd=elinduljunk(jatekosok,kapuk,cst,akttick,sajatid);
            if(asd)
            {
                mess.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
                jatekosok[cst].poolba1(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
                jatekosok[cst].poolba2(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
                jatekosok[cst].poolba3(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
                eset=5;
            }
            else {mess.print();eset=7;}
            break;
        case 5:     //várok de ha elindul felém akkor megelozom
            if((jatekosok[ellensegid].poz.x != jatekosok[ellensegid].elozopoz.x  && felenkjon(jatekosok,ellensegid,sajatid)) || jatekosok[sajatid]==jatekosok[ellensegid])
            {
                mess.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);

                if(!jatekosok[cst].pool1.empty()) {jatekosok[cst].pool1.pop();}
                if(!jatekosok[cst].pool2.empty()) {jatekosok[cst].pool2.pop();}
                if(!jatekosok[cst].pool3.empty()) {jatekosok[cst].pool3.pop();}
                eset=6;
            }
            else if(!jatekosok[cst].pool1.empty() || !jatekosok[cst].pool2.empty() || !jatekosok[cst].pool3.empty())
            {
                 if(!jatekosok[cst].pool1.empty()) {jatekosok[cst].pool1.pop();}
                 if(!jatekosok[cst].pool2.empty()) {jatekosok[cst].pool2.pop();}
                 if(!jatekosok[cst].pool3.empty()) {jatekosok[cst].pool3.pop();}
                 mess.print();
            }
            else {mess.print();}
            break;
        case 6:
            melyik=0;
            melyik=melyikpoll(jatekosok,labdaid,cst);
            if(melyik==0) {mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1);}
            else if(melyik==1 && jatekosok[cst].pool1.size()>2)
            {
                while(jatekosok[cst].pool1.size()!=2) {jatekosok[cst].pool1.pop();}
                megyunk=jatekosok[cst].pool1.front();
                mess.print(megyunk.x,megyunk.y,2);
                eset=7;
            }
            else if(melyik==2 && jatekosok[cst].pool1.size()>2)
            {
                while(jatekosok[cst].pool2.size()!=2) {jatekosok[cst].pool2.pop();}
                megyunk=jatekosok[cst].pool2.front();
                mess.print(megyunk.x,megyunk.y,2);
                eset=7;
            }
            else if(melyik==3 && jatekosok[cst].pool1.size()>2)
            {
                while(jatekosok[cst].pool3.size()!=2) {jatekosok[cst].pool3.pop();}
                megyunk=jatekosok[cst].pool3.front();
                mess.print(megyunk.x,megyunk.y,2);
                eset=7;
            }
            else {mess.print();}
            kijon=true;
            break;
        case 7:
            mess.print();
            break;
        case -1:
            mess.print();
        default:
            break;
        }


    }
    else if(!jatekosok[labdaid].poolcel.empty() && jatekosok[sajatid]!=jatekosok[labdaid]) {mess.print();}  //elrugtam a labdát és várok
    else if(beall && jatekosok[ellensegid].poz.x !=jatekosok[ellensegid].elozopoz.x && teszteltunk)     // kijott a apus el kell lőni
    {
        int aaa=kaputav(kapuk,jatekosok,legkozelebbipont,sajatid);
        if(jatekosok[sajatid].e>=aaa*3) {mess.loves(kapuk->a.x,jatekosok[sajatid].poz.y,3);}
        else {mess.print();}
    }
    else if(kijon && !labdaszerzes)         //kijött a kapus el kell lőni
    {
        vector<int> asdasdasd;
        int aa=kaputav(kapuk,jatekosok,asdasdasd,sajatid);
        if(jatekosok[sajatid].poz.y !=jatekosok[ellensegid].poz.y && aa<=jatekosok[sajatid].e*3)
        {
            mess.loves(asdasdasd[0],asdasdasd[1],3);
        }
        else if(aa>jatekosok[sajatid].e*3 && jatekosok[sajatid].e>jatekosok[sajatid].e){mess.print();}
        else if (jatekosok[sajatid].poz.y ==jatekosok[ellensegid].poz.y)
        {
            if(jatekosok[sajatid].poz.y+1<=max(kapuk->a.y,kapuk->b.y)){mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y+1,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y+1,1);}
            else {mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y-1,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y-1,1);}
        }
        else{mess.print();}
    }
    else if(lepunk>2 )      //megvan h mozog a kapus energiát gyüjtünk és lövünk
    {
        switch (keset)
        {
        case 1:            // 1 = kapus egy helyben áll

            if(jatekosok[sajatid].e>13 || akttick<21)
            {
                if(jatekosok[sajatid].poz.y !=jatekosok[ellensegid].poz.y )
                {
                    lovescel.x=kapuk->a.x;
                    lovescel.y=jatekosok[sajatid].poz.y;
                    mess.loves(lovescel.x,lovescel.y,1);
                    jatekosok[labdaid].poolcel.push(lovescel);
                }
                else teszt(jatekosok,kapuk,ellensegid,sajatid);
            }
            else {mess.print();}
            break;
        case 2:             //2 = követi csak az y koordintád
            loves(jatekosok,kapuk,akttick,sajatid);
            break;
        case 3:             //3 = kimozdul rád az y-od mentén
            mess.print();
            break;
        case 4:             //4 = ide-oda mozog
            if(jatekosok[sajatid].poz.y !=jatekosok[ellensegid].poz.y+4 && jatekosok[sajatid].poz.y !=jatekosok[ellensegid].poz.y-4 &&jatekosok[sajatid].e>15 && akttick<23 )
            {
                lovescel.x=kapuk->a.x;
                lovescel.y=jatekosok[sajatid].poz.y;
                mess.loves(lovescel.x,lovescel.y,1);
                jatekosok[labdaid].poolcel.push(lovescel);
            }
            else if(akttick==22)
            {
                lovescel.x=kapuk->a.x;
                lovescel.y=jatekosok[sajatid].poz.y;
                mess.loves(lovescel.x,lovescel.y,1);
                jatekosok[labdaid].poolcel.push(lovescel);
            }
            else {mess.print();}
            break;
        case 5:
            mess.print();
            break;
        default:
            while(beall)
            {
                cout<<jatekosok[sajatid].e<<endl;
            }
            break;
        }
    }
    else if(!labdaszerzes && !beall)    //megvana alabda visszük a a legközelebbi, a kaputól 5 egység távol lévő helyre
    {
        int kapuu;
        //kapuu=kaputav(kapuk,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y);
        kapuu=tav2p(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,legkozelebbipont[0],legkozelebbipont[1]);
        if(jatekosok[sajatid].poolcel.empty()){helykereses(jatekosok,kapuk,sajatid);}
        else if( jatekosok[sajatid]!=jatekosok[labdaid]){mess.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);labdaszerzes=true;eset=7;}
        else if(abs(jatekosok[sajatid].poz.x-jatekosok[ellensegid].poz.x)<4 && kapuu==7 && lepunk==0) { mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,1);lepunk=1;}
        else if(abs(jatekosok[sajatid].poz.x-jatekosok[ellensegid].poz.x)>=4 && lepunk>0 && jatekosok[sajatid].e>17)
        {
            if(jatekosok[sajatid].team==2) {mess.print(jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y,1);}
            else mess.print(jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y,1);
            lepunk=-2;
        }
        else if(abs(jatekosok[sajatid].poz.x-jatekosok[ellensegid].poz.x)<4 && lepunk==-2)
        {

            if(jatekosok[sajatid].poz.y+1<=max(kapuk->a.y,kapuk->b.y)){mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y+1,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y+1,1);}
            else {mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y-1,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y-1,1);}
            lepunk=-4;
        }
        else if(lepunk==-4)
        {
            vector<int> asdasdasd;
            kaputav(kapuk,jatekosok,asdasdasd,sajatid);
            if(jatekosok[sajatid].e>=kapuu*3){mess.loves(asdasdasd[0],asdasdasd[1],3);}
            else if (kapuu>6) {mess.print();lepunk=-2;}
            else if(jatekosok[sajatid].e>jatekosok[ellensegid].e && jatekosok[sajatid].e<19) {mess.print();}
            else if(jatekosok[sajatid].e<jatekosok[ellensegid].e && jatekosok[sajatid].e>=kapuu*2 ) {mess.loves(asdasdasd[0],asdasdasd[1],2);}
            else {mess.print();}
        }
        else mess.print();

    }
    else if (!labdaszerzes && beall && lepunk<3)    //tesztelünk, hogy a kapus h viselkedik
    {
        legkozelebbipont.erase(legkozelebbipont.begin(),legkozelebbipont.end());
        kaputav(kapuk,jatekosok,legkozelebbipont,sajatid);
        if(jatekosok[sajatid]!=jatekosok[labdaid]){mess.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);labdaszerzes=true;eset=7;}
        else if(!teszteltunk && jatekosok[sajatid].e>5) {teszt(jatekosok,kapuk,ellensegid,sajatid);teszteltunk=true;lepunk++;}
        else if(lepunk==1 && jatekosok[sajatid].elozopoz.x==jatekosok[ellensegid].poz.x && jatekosok[sajatid].elozopoz.y==jatekosok[ellensegid].poz.y) {mess.loves(legkozelebbipont[0],legkozelebbipont[1],3);lepunk=3;keset=5;}
        else if(lepunk==1) {mess.print();lepunk++;}
        else if(teszteltunk && lepunk==2) {lepunk++;keset=kapusverzio(jatekosok,kapuk,ellensegid,sajatid);mess.print();}
        else mess.print();
    }
}
int esetvalaszto(int& tarsuzenet )
{
    int eset;
    if(tarsuzenet==0)
    {
        eset=2;
    }
    else if (tarsuzenet==1){eset=3;} //case 3
    else if(tarsuzenet==2){eset=4;}
    else if(tarsuzenet==-1){eset=1;}
    return eset;
}
int kaputav( kapu* kapuk, map <int, jatekos>& jatekosok,vector<int> &legkozelebbipont, int &sajatid)
{    
    int id=sajatid,legkisebb=100,a,b;
    for(int i=0;i<(max(kapuk->a.y,kapuk->b.y)-min(kapuk->a.y,kapuk->b.y));i++)
    {
        int akt=ceil(sqrt(pow(kapuk->a.x-jatekosok[id].poz.x,2)+pow(min(kapuk->a.y,kapuk->b.y)+i-jatekosok[id].poz.y,2)));
        if(akt<legkisebb)
        {
            legkisebb=akt;
            a=kapuk->a.x;
            b=kapuk->a.y+i;
        }
    }
    legkozelebbipont.push_back(a);
    legkozelebbipont.push_back(b);
    return legkisebb;
}
int kaputav(kapu* kapuk,int a,int b)
{
    int legkisebb=100;
    for(int i=0;i<(max(kapuk->a.y,kapuk->b.y)-min(kapuk->a.y,kapuk->b.y));i++)
    {
        int akt=ceil(sqrt(pow(kapuk->a.x-a,2)+pow(min(kapuk->a.y,kapuk->b.y)+i-b,2)));
        if(akt<legkisebb)
        {
            legkisebb=akt;
        }
    }
    return legkisebb;
}
bool gol (kapu* kapuk, map <int, jatekos>& jatekosok, int &labdaid)
{
    for(int i=0;i<(max(kapuk->a.y,kapuk->b.y)-min(kapuk->a.y,kapuk->b.y))+1;i++)
    {
        if(jatekosok[labdaid].poz.x==kapuk->a.x && jatekosok[labdaid].poz.y==min(kapuk->a.y,kapuk->b.y)+i)
        {
            return true;
        }
    }
    return false;
}
int ellensegkereso(map <int, jatekos>& jatekosok,string tipus, int &sajatid)
{
    map <int, jatekos>::iterator it;
    int id=0;
    for(it = jatekosok.begin(); it != jatekosok.end(); it++)
    {
            if(it->second.tip == tipus && it->first != sajatid)
            {
                id = it->first;

            }
    }
    return id;
}
void loves(map <int, jatekos>& jatekosok,kapu* kapuk, int &akttick, int &sajatid)
{
    valasz mess;
    int id=sajatid,cst;
    vector<int> legkozelebbipont;
    int akttav =kaputav(kapuk,jatekosok,legkozelebbipont,sajatid);
    p2d akt;
    cst=ellensegkereso(jatekosok,"ATTACKER",sajatid);
    if(akttick<22 && jatekosok[sajatid].e>13 && akttav==5)
    {
        if(jatekosok[id].poz.y+2<=max(kapuk->a.y,kapuk->b.y) )      //ha csak fölfelé tudok
        {
            if(jatekosok[id].team==1)
            {
                akt.x=jatekosok[id].poz.x+1;
                akt.y=jatekosok[id].poz.y+1;
                mess.print(akt.x,akt.y,2,akt.x,akt.y,2);
                jatekosok[id].poolcel.push(akt);
            }
            else
            {
                akt.x=jatekosok[id].poz.x-1;
                akt.y=jatekosok[id].poz.y+1;
                mess.print(akt.x,akt.y,2,akt.x,akt.y,2);
                jatekosok[id].poolcel.push(akt);
            }
        }
        else if(jatekosok[id].poz.y-2>=min(kapuk->a.y,kapuk->b.y))      // ha csak lefelé tudok
        {
            if(jatekosok[id].team==1)
            {
                akt.x=jatekosok[id].poz.x+1;
                akt.y=jatekosok[id].poz.y-1;
                mess.print(akt.x,akt.y,2,akt.x,akt.y,2);
                jatekosok[id].poolcel.push(akt);
            }
            else
            {
                akt.x=jatekosok[id].poz.x-1;
                akt.y=jatekosok[id].poz.y-1;
                mess.print(akt.x,akt.y,2,akt.x,akt.y,2);
                jatekosok[id].poolcel.push(akt);
            }

        }


    }
    else if( akttav==4 && jatekosok[sajatid].e>18 && akttick<22 )
    {
        if(jatekosok[sajatid].poz.y+2<=max(kapuk->a.y,kapuk->b.y) && jatekosok[cst].poz.y !=(jatekosok[sajatid].poz.y+1))
        {
            if(abs(jatekosok[cst].poz.y-jatekosok[sajatid].poz.y)<=1 &&abs(jatekosok[cst].poz.x-jatekosok[sajatid].poz.x)<=1)
            {mess.print();}
            else {mess.loves(legkozelebbipont[0],legkozelebbipont[1]+2,3);}
        }
        else if (jatekosok[sajatid].poz.y-2>=min(kapuk->a.y,kapuk->b.y) && jatekosok[cst].poz.y !=(jatekosok[sajatid].poz.y-1))
        {
            if(abs(jatekosok[cst].poz.y-jatekosok[sajatid].poz.y)<=1 &&abs(jatekosok[cst].poz.x-jatekosok[sajatid].poz.x)<=1)
            {mess.print();}
            else {mess.loves(legkozelebbipont[0],legkozelebbipont[1]-2,3);}
        }
        else {mess.print();}
    }
    else if(akttick==22)
    {
        if(legkozelebbipont[1]+2<=max(kapuk->a.y,kapuk->b.y))
        {
            mess.loves(legkozelebbipont[0],legkozelebbipont[1]+2,3);
        }
        else if (legkozelebbipont[1]-2>=min(kapuk->a.y,kapuk->b.y))
        {
            mess.loves(legkozelebbipont[0],legkozelebbipont[1]-2,3);
        }
    }
    else mess.print();
}
void helykereses(map <int, jatekos>& jatekosok,kapu* kapuk, int &sajatid)
{
    valasz mess;
    double akthosszd,minhossz=100;
    int yy,xx;
        for(int j=min(kapuk->a.y,kapuk->b.y);j<max(kapuk->a.y,kapuk->b.y)+1;j++)
        {
            if(jatekosok[sajatid].team==1)
            {
            akthosszd=sqrt(pow(jatekosok[sajatid].poz.x-(kapuk->a.x-5),2)+pow(jatekosok[sajatid].poz.y-j,2));
            if(akthosszd<minhossz){minhossz=akthosszd;yy=j;xx=kapuk->a.x-5;}
            }
            else
            {
                akthosszd=sqrt(pow(jatekosok[sajatid].poz.x-(kapuk->a.x+5),2)+pow(jatekosok[sajatid].poz.y-j,2));
                if(akthosszd<minhossz){minhossz=akthosszd;yy=j;xx=kapuk->a.x+5;}
            }
        }
     mess.print(xx,yy,1,xx,yy,1);
     p2d pont;
     pont.x=xx;
     pont.y=yy;
     jatekosok[sajatid].poolcel.push(pont);
}
int helykeresesponttol(map <int, jatekos>& jatekosok,kapu* kapuk, int &x, int &y, int &sajatid)
{
    double akthosszd,minhossz=100;
        for(int j=min(kapuk->a.y,kapuk->b.y);j<max(kapuk->a.y,kapuk->b.y)+1;j++)
        {
            if(jatekosok[sajatid].team==1)
            {
            akthosszd=sqrt(pow(x-(kapuk->a.x-5),2)+pow(y-j,2));
            if(akthosszd<minhossz){minhossz=akthosszd;}
            }
            else
            {
                akthosszd=sqrt(pow(x-(kapuk->a.x+5),2)+pow(y-j,2));
                if(akthosszd<minhossz){minhossz=akthosszd;}
            }
        }
        return ceil(minhossz);
}
bool beallt(map <int, jatekos>& jatekosok,kapu* kapuk, int &sajatid)
{
    if(jatekosok[sajatid].team==1)
    {
        if(jatekosok[sajatid].poz.x==kapuk->a.x-5 && jatekosok[sajatid].poz.y<=max(kapuk->a.y,kapuk->b.y) && jatekosok[sajatid].poz.y>=min(kapuk->a.y,kapuk->b.y) )
        {return true;}
        else {return false;}
    }
    else
    {
        if(jatekosok[sajatid].poz.x==kapuk->a.x+5 && jatekosok[sajatid].poz.y<=max(kapuk->a.y,kapuk->b.y) && jatekosok[sajatid].poz.y>=min(kapuk->a.y,kapuk->b.y))
        {return true;}
        else {return false;}
    }
}
void teszt(map <int, jatekos>& jatekosok,kapu* kapuk,int &ellensegid, int &sajatid)
{
    valasz mess;
    if(max(kapuk->a.y,kapuk->b.y)-jatekosok[sajatid].poz.y>jatekosok[sajatid].poz.y-min(kapuk->a.y,kapuk->b.y))
    {
        if(!(jatekosok[sajatid].poz.x ==jatekosok[ellensegid].poz.x &&jatekosok[sajatid].poz.y+1 ==jatekosok[ellensegid].poz.y))
        {
            mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y+1,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y+1,1);
        }
        else {mess.loves(kapuk->a.x,jatekosok[sajatid].poz.y,1);}
    }
    else
    {
        if(!(jatekosok[sajatid].poz.x ==jatekosok[ellensegid].poz.x &&jatekosok[sajatid].poz.y-1 ==jatekosok[ellensegid].poz.y))
        {
            mess.print(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y-1,1,jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y-1,1);
        }
        else {mess.loves(kapuk->a.x,jatekosok[sajatid].poz.y,1);}
    }
}
int kapusverzio(map <int, jatekos>& jatekosok,kapu* kapuk,int &ellenid, int &sajatid)
{
    int eset;// 1 = kapus egy helyben áll,2 = követi csak az y koordintád,3 = kimozdul rád az y-od mentén,4 = ide-oda mozog

    if(kpozmaradt(jatekosok,ellenid))
    {
        eset = 1;
    }
    else if(!kpozmaradt(jatekosok,ellenid) && jatekosok[ellenid].poz.y==jatekosok[sajatid].poz.y )
    {
        eset = 2;
    }
    else if(!kpozmaradt(jatekosok,ellenid) && jatekosok[ellenid].poz.y==jatekosok[sajatid].poz.y && (jatekosok[ellenid].poz.x !=(kapuk->a.x+1) || jatekosok[ellenid].poz.x !=(kapuk->a.x-1) ))
    {
        eset = 3;
    }
    else
    {
        eset = 4;
    }
    return eset;
}
bool kpozmaradt(map <int, jatekos>& jatekosok,int &ellenid)
{
    if(jatekosok[ellenid].poz.x==jatekosok[ellenid].elozopoz.x &&jatekosok[ellenid].poz.y==jatekosok[ellenid].elozopoz.y )return true;
    else return false;
}
int tav2p(int x1,int y1,int x2,int y2)
{
    int asd= sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    return asd;
}
int melyikpoll(map <int, jatekos>& jatekosok, int &labdaid,int &cst)
{
    int egy=0,ketto=0,harom=0,vissza=0;
    p2d poz1,poz2,poz3;
    if(!jatekosok[cst].pool1.empty())
    {
        poz1=jatekosok[cst].pool1.front();
        if(poz1.x==jatekosok[labdaid].poz.x && poz1.y==jatekosok[labdaid].poz.y)
        {
            egy=1;
            jatekosok[cst].pool1.pop();
        }
        else
        {
            while(!jatekosok[cst].pool1.empty())
            {jatekosok[cst].pool1.pop();}
        }
    }
    if(!jatekosok[cst].pool2.empty())
    {
        poz2=jatekosok[cst].pool2.front();
        if(poz2.x==jatekosok[labdaid].poz.x && poz2.y==jatekosok[labdaid].poz.y)
        {
            ketto=2;
            jatekosok[cst].pool2.pop();
        }
        else
        {
            while(!jatekosok[cst].pool2.empty())
            {jatekosok[cst].pool2.pop();}
        }
    }
    if(!jatekosok[cst].pool3.empty())
    {
        poz3=jatekosok[cst].pool3.front();
        if(poz3.x==jatekosok[labdaid].poz.x && poz3.y==jatekosok[labdaid].poz.y)
        {
            harom=3;
            jatekosok[cst].pool3.pop();
        }
        else
        {
            while(!jatekosok[cst].pool3.empty())
            {jatekosok[cst].pool3.pop();}
        }
    }
    if((egy==1 && ketto==2) || (egy==1 && harom==3) || (ketto==2 && harom==3))
    {
        vissza=0;
    }
    else
    {
        if(egy==1) {vissza= 1;}
        else if(ketto==2) {vissza= 2;}
        else if(harom==3) {vissza= 3;}
    }
    return  vissza;
}
bool elinduljunk(map <int, jatekos>& jatekosok,kapu* kapuk,int &cst,int &akttick, int &sajatid)
{
    int tick1,tick2,maradek,maradekenergia;
    bool vissza=false;
    tick1=jatekosok[sajatid].tavolsag(jatekosok[cst]);
    tick2=helykeresesponttol(jatekosok,kapuk,jatekosok[cst].poz.x,jatekosok[cst].poz.y,sajatid);
    maradek=22-akttick-tick1-tick2;
    maradekenergia=jatekosok[sajatid].e-2*tick2;
    if(maradek>4 && maradekenergia>1) {vissza=true;}
    return vissza;
}
bool felenkjon(map <int, jatekos>& jatekosok, int &ellensegid, int &sajatid)
{
    bool vissza;
    if(jatekosok[sajatid].team==1)
    {
        if(jatekosok[ellensegid].poz.x-jatekosok[sajatid].poz.x<jatekosok[ellensegid].elozopoz.x-jatekosok[sajatid].poz.x){vissza=true;}
        else {vissza=false;}
    }
    else
    {
        if(abs(jatekosok[ellensegid].poz.x-jatekosok[sajatid].poz.x)<abs(jatekosok[ellensegid].elozopoz.x-jatekosok[sajatid].poz.x))
        {
            vissza=true;
        }
        else {vissza=false;}
    }
    return vissza;
}
void hajonfelenk(map <int, jatekos>& jatekosok, int &ellensegid,kapu* kapuk, vector<int> legkozelebbipont, int &sajatid)
{
    valasz mess;
    int a=0;
    a=tav2p(jatekosok[sajatid].poz.x,jatekosok[sajatid].poz.y,legkozelebbipont[0],legkozelebbipont[1]);
    if(jatekosok[sajatid].e>(3*a)) {mess.loves(legkozelebbipont[0],legkozelebbipont[1]+1,3);}
    else if(jatekosok[sajatid].e<=jatekosok[ellensegid].e) {mess.print();}
    else if(jatekosok[sajatid].e>(jatekosok[ellensegid].e+2))
    {
        if(jatekosok[sajatid].team==2){mess.print(jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y,1);}
        else mess.print(jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y,1);
    }
    else if(jatekosok[sajatid].e>(jatekosok[ellensegid].e+6))
    {
        if(jatekosok[sajatid].poz.y+1<max(kapuk->a.y,kapuk->b.y))
        {
            if(jatekosok[sajatid].team==2){mess.print(jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y+1,1,jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y+1,1);}
            else mess.print(jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y+1,1,jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y+1,1);
        }
        else
        {

            if(jatekosok[sajatid].team==2){mess.print(jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y-1,1,jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y-1,1);}
            else mess.print(jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y-1,1,jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y-1,1);
        }
    }
    else if(jatekosok[sajatid].e>jatekosok[ellensegid].e && jatekosok[ellensegid].e<17){mess.print();}
    else if(jatekosok[sajatid].e>jatekosok[ellensegid].e && jatekosok[ellensegid].e<17 && jatekosok[sajatid].e>18)
    {
        if(jatekosok[sajatid].team==2){mess.print(jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x-1,jatekosok[sajatid].poz.y,1);}
        else mess.print(jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y,1,jatekosok[sajatid].poz.x+1,jatekosok[sajatid].poz.y,1);
    }
    else if(jatekosok[sajatid].e>jatekosok[ellensegid].e && jatekosok[ellensegid].e>17) {mess.loves(legkozelebbipont[0],legkozelebbipont[1],2);}
    else {mess.print();}
}
void vegtelenciklus(string asdasd)
{
    while (1)
    {
        cout<<asdasd<<endl;
    }
}
