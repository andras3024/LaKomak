#include "DEFENDER.h"


// Első kör információi
void kezdesd(palya& p,kapu* kapuk, map <int, jatekos>& jatekosok,int &sajatid)
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
                sajatid = id;
                jatekos sajat;
                jatekosok[id] = &sajat;
                jatekosok[id].id = id;
            }
        }
    }

}
//Minden kör elején lefut és betölti az adatokat
void kord(int&tick, int *score, map <int, jatekos>& jatekosok,int&labdaid,int & tarsuzenet,bool & vanlabda)
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
                else if(asd=="Send") {tarsuzenet=8;}
                else if(asd=="and") {tarsuzenet=8;}//jó hatású az = 8,csak még bugos akkor a szoftver,de nem mindig
                else if(asd=="Your") {if(tarsuzenet==-1) tarsuzenet=0; else tarsuzenet=0;}
                else if(asd=="When") {tarsuzenet=0;}
                else if(asd=="If") {tarsuzenet=0;}
                else if(asd=="Cross") {tarsuzenet=0;}
                else if(asd=="Cross") {tarsuzenet=0;}
                else if(asd=="I-I") {tarsuzenet=9;}
                else if(asd=="Ball,") {tarsuzenet=9;}
                else if(asd=="Bring") {tarsuzenet=0;}
                else{tarsuzenet=0;}
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
//Megkeres egy adott típusú játékost,az átadott vectorba tölti be
void jatekoskeresod(map <int, jatekos>& jatekosok,string tipus,int csapat,vector<int>&vissza,int &sajatid)
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
int ellensegkeresod(map <int, jatekos>& jatekosok,string tipus)
{
    map <int, jatekos>::iterator it;
    int id;
    for(it = jatekosok.begin(); it != jatekosok.end(); it++)
    {
            if(it->second.tip == tipus)
            {
                id = it->first;

            }
    }
    return id;
}
//előbb x mentém mozgás,majd y mentén
p2d ujkoord(map <int, jatekos>& jatekosok,int &tarsid,int &sajatid){
    p2d cel;
    if(jatekosok[sajatid].poz.x != jatekosok[tarsid].poz.x)
    {
        cel.x=jatekosok[tarsid].poz.x;
        cel.y=jatekosok[sajatid].poz.y;
    }
    else
    {
        cel.x=jatekosok[tarsid].poz.x;
        cel.y=jatekosok[tarsid].poz.y;
    }
    return cel;
}
// Akkor hívódik meg,amikor nálunk van a labda és nem állnak fent a mainben előtte lévő esetek egyike se fent
void passz2d(map<int, jatekos> &jatekosok,int& tarsid,int &labdaid,palya &p,bool &passzoltam,int &teszt,int &uzenet,int &regitick,int &sajatid)
{
	// Változók
    int celx,cely,s = 1,ellenid;
    valasz message;
    string tarsuzenet;
    p2d cel;
    int senergia = jatekosok[sajatid].e+2;
	// Ellenidba betöltjük az ATTACKER idját
    ellenid = ellensegkeresod(jatekosok,"ATTACKER");
	//Labdaszerzés azért nézzük,hogy az első labdaérintésünket megtudjuk különbeztetni a későbbi "labdavezetéstől"
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
    celx=jatekosok[tarsid].poz.x;
    cely=jatekosok[tarsid].poz.y;
    // Passznál ne az ellenségnek adjuk
    if(celx == jatekosok[ellenid].poz.x && cely == jatekosok[ellenid].poz.y)
    {
        if(jatekosok[sajatid].team == 1)
        {
            celx += 1;
        }
        else{
            celx -= 1;
        }
        if((p.get_m()-1)-jatekosok[ellenid].poz.y !=0)
        {
            cely +=1;
        }
        else{
            cely -=1;
        }
    }
	//Regitick vizsgálatok,a meccs beakadásának megakadályozásához
    if(regitick > 6)
    {
        tarsuzenet="MESSAGE "+ to_string(tarsid) + " I will pass you to the " + to_string(p.get_m()/2) +" "+ to_string(p.get_sz()/2);
        jatekosok[sajatid].poolba(celx,cely,s);
        cel = jatekosok[sajatid].pool.front();
        int ujcelx,ujcely;
        ujcelx = cel.x;
        ujcely = cel.y;
        teszt++;
        message.print(ujcelx,ujcely,s,ujcelx,ujcely,s,tarsuzenet);
    }
	//ez felesleges,mainbe benne van
    /*else if(regitick > 10)
    {
        if(jatekosok[sajatid].poz.x == p.get_m()/2 && jatekosok[sajatid].poz.y ==p.get_sz()/2 )
        {
            message.print((p.get_m()/2+1),(p.get_sz()/2+1),1,(p.get_m()/2+1),(p.get_sz()/2+1),1);
        }
        else{
         message.print(p.get_m()/2,p.get_sz()/2,1,p.get_m()/2,p.get_sz()/2,1);
        }
    }*/
	// Normál passzkeresés rész
    else{
        //Üzenet 
        tarsuzenet="MESSAGE "+ to_string(tarsid) + " I will pass you to the " + to_string(celx) +" "+ to_string(cely);
		//Ha egymáson állunk az ellenséggel
        if(jatekosok[sajatid] == jatekosok[labdaid] &&jatekosok[ellenid] == jatekosok[labdaid]&& jatekosok[sajatid].e >= jatekosok[ellenid].e && jatekosok[sajatid].e <20)
        {
			if(labdaszerzes)
			{
				message.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1,jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
			}
            else {message.print();}
        }
		// Első labdaérintésünk és nem léptünk be felette lévő ifbe,ez lefusson mindenképp,hoyg megállítsuk a labdát
		else if(labdaszerzes)
		{
			message.print(jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1,jatekosok[labdaid].poz.x,jatekosok[labdaid].poz.y,1);
		}
		// Labdavezetés közben,óvatósan vezessük,hogy az energiánk mindig több legyen az ellenségénél
        else if( senergia >= jatekosok[ellenid].e && jatekosok[sajatid].e <20)
        {
            message.print();
        }
		// Lövés funkciók 1,2,3 távolságra
        else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 1 ){
            message.loves(celx,cely,1,tarsuzenet); passzoltam = true;
        }
        else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 2 && jatekosok[sajatid].e > 6){
            if(abs(jatekosok[sajatid].poz.y-jatekosok[ellenid].poz.y)>2)
            {
                s=1;
            }
            else{
                s=2;
            }
            message.loves(celx,cely,s,tarsuzenet); passzoltam = true;
        }
        else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 3 && jatekosok[sajatid].e > 7){
           if(abs(jatekosok[sajatid].poz.y-jatekosok[ellenid].poz.y)>2)
           {
               s = 1;
           }
           else{
               s=3;
           }
            message.loves(celx,cely,s,tarsuzenet); passzoltam = true;
        }
		//Alapvető mozgás,teszt > 2 esetén,szükséges-e??
        //javítva,jobb lett-e?
        else if(jatekosok[sajatid].tavolsag(jatekosok[ellenid]) <= 2 && jatekosok[sajatid].tavolsag(jatekosok[tarsid]) > 4 ){
            p2d ujcel;
            ujcel = ujkoord(jatekosok,tarsid,sajatid);
            celx = ujcel.x;
            cely = ujcel.y;
            s = 1;
            tarsuzenet="MESSAGE "+ to_string(tarsid) + " I will pass you to the " + to_string(p.get_m()/2) +" "+ to_string(p.get_sz()/2);
            jatekosok[sajatid].poolba(celx,cely,s);
            cel = jatekosok[sajatid].pool.front();
            int ujcelx,ujcely;
            ujcelx = cel.x;
            ujcely = cel.y;
            teszt++;
            message.print(ujcelx,ujcely,s,ujcelx,ujcely,s);
        }
        //Alapvető mozgás teszt< 3 esetén,ugyanaz szinte mint felette,összevonni?
        /*else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) > 4 &&jatekosok[sajatid].e >= jatekosok[ellenid].e && teszt < 3)
        {
            tarsuzenet="MESSAGE "+ to_string(tarsid) + " I will pass you to the " + to_string(p.get_m()/2) +" "+ to_string(p.get_sz()/2);
            jatekosok[sajatid].poolba(celx,cely,s);
            cel = jatekosok[sajatid].pool.front();
            int ujcelx,ujcely;
            ujcelx = cel.x;
            ujcely = cel.y;
            teszt++;
            message.print(ujcelx,ujcely,1,ujcelx,ujcely,1,tarsuzenet);
        }*/
		//Alapvető mozgás,ebbe mikor megynk bele?
        else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) > 4 &&jatekosok[sajatid].e >= jatekosok[ellenid].e && jatekosok[ellenid].mozog)
        {
            p2d ujcel;
            ujcel = ujkoord(jatekosok,tarsid,sajatid);
            celx = ujcel.x;
            cely = ujcel.y;
            tarsuzenet="MESSAGE "+ to_string(tarsid) + " I will pass you to the " + to_string(p.get_m()/2) +" "+ to_string(p.get_sz()/2);
            jatekosok[sajatid].poolba(celx,cely,s);
            cel = jatekosok[sajatid].pool.front();
            int ujcelx,ujcely;
            ujcelx = cel.x;
            ujcely = cel.y;
            message.print(ujcelx,ujcely,1,ujcelx,ujcely,1);
        }
        //Passz
        else{
			//Mégegy megállás,ha nincs elég energiánk,ez is felesleges?
            if(jatekosok[sajatid].e < 20 && jatekosok[sajatid].e >= jatekosok[ellenid].e && jatekosok[sajatid] == jatekosok[ellenid]){
               message.print();
            }
			//Ha messzebre kéne lőnni,mint amennyi energiánk van,lehetne bevezetni egy saját energia csekket is
            else if(jatekosok[labdaid].labda_energia(celx,cely,s) > 20){
                jatekosok[sajatid].poolba(celx,cely,s);
                cel = jatekosok[sajatid].pool.front();
                int ujcelx,ujcely;
                ujcelx = cel.x;
                ujcely = cel.y;
                teszt = true;
                message.print(ujcelx,ujcely,1,ujcelx,ujcely,1);
            }
			//Lővés 2 távolságra,mégegy redundáns funkció??
            else if(jatekosok[sajatid].tavolsag(jatekosok[tarsid]) == 2)
            {
                message.loves(celx,cely,2,tarsuzenet);passzoltam = true;
            }
            /*else if(jatekosok[sajatid].tavolsag(jatekosok[ellenid]) == 3)
            {
                message.loves(celx,cely,3,tarsuzenet);passzoltam = true;
            }*/
			//Alapértelmezett lövések,else if és else ág feleselges?
            else if(jatekosok[sajatid] == jatekosok[ellenid]){
               message.loves(celx,cely,2,tarsuzenet); passzoltam = true;
            }
            else{
                if(jatekosok[sajatid].tavolsag(jatekosok[ellenid]) >2)
                {
                    s = 1;
                }
                else{
                    s=2;
                }
                message.loves(celx,cely,s,tarsuzenet); passzoltam = true;
            }
        }
    }
}
// A labdaszerzéskor hívódik meg,amikor nincs nálunk a labda
void vedunk(map<int, jatekos> &jatekosok,palya& p,int &labdaid,int &baratid,int &termin,int &termax,int &tarsuzenet,bool &passzoltam,int &teszt,int &regitick,int &sajatid){
	//Változók
    valasz message;
    int mozgasx,mozgasy,ellenid,seb = 1,tavx,ellx,pfele1,sajatx,labdax,labdatavx,bmozgasx,baratx,labdatavx1,eredetix;
    string baruz;
	//Ellenség idnek betöltése
    ellenid = ellensegkereso(jatekosok,"ATTACKER",sajatid);
    //Csapat alapján relatív x koordináták
    if(jatekosok[sajatid].team == 1)
    {
        mozgasx = 0;
        bmozgasx = 0;
        eredetix = 0;
        pfele1 = p.get_m()/2+1;
        ellx = jatekosok[ellenid].poz.x;
        tavx = jatekosok[ellenid].poz.x-1;
        sajatx = jatekosok[sajatid].poz.x;
        baratx = jatekosok[baratid].poz.x;
        labdax = jatekosok[labdaid].poz.x;
        labdatavx = jatekosok[labdaid].poz.x-2;
        labdatavx1 = jatekosok[labdaid].poz.x-1;
    }
    else
    {
        eredetix =  p.get_m()-1;
        mozgasx = p.get_m()-1;
        bmozgasx = p.get_m()-1;
        pfele1= p.get_m()/2-1;
        ellx = mozgasx-jatekosok[ellenid].poz.x;
        tavx = jatekosok[ellenid].poz.x+1;
        sajatx = mozgasx-jatekosok[sajatid].poz.x;
        baratx = mozgasx-jatekosok[sajatid].poz.x;
        labdax = mozgasx-jatekosok[labdaid].poz.x;
        labdatavx = jatekosok[labdaid].poz.x+2;
        labdatavx1 = jatekosok[labdaid].poz.x+1;
    }
    //Barátnál van a labda már
    if(nalalabda(jatekosok,labdaid,baratid))
    {
        if(sajatx > p.get_m()/2)
        {
             mozgasx =  p.get_m()/2;

        }
        else
        {
             mozgasx =  jatekosok[sajatid].poz.x;
        }
        mozgasy = (termin+termax)/2;
        passzoltam = false;
        teszt =0;
    }
    //Elenségnél van a labda
    else if(nalalabda(jatekosok,labdaid,ellenid) || !passzoltam)
    {
        passzoltam = false;
		//A mi térfelünkön van az labda,Y koordináta
        if(jatekosok[labdaid].poz.y>=termin && jatekosok[labdaid].poz.y <= termax)
        {
            mozgasy = jatekosok[labdaid].poz.y;
        }
		//A barátunk térefelén van az ellenfél,azonban a barátunk minket követ,vagy senkise mozog
        else if(((!jatekosok[baratid].mozog && !jatekosok[ellenid].mozog) || (!jatekosok[ellenid].mozog && tarsuzenet == 9)) && !jatekosok[labdaid].mozog && regitick > 3)
        {
            if(jatekosok[sajatid].e ==20){
                mozgasy = jatekosok[labdaid].poz.y;
            }
            else{
                mozgasy = jatekosok[sajatid].poz.y;
            }
        }
		//Egyéb esetben mozgás a mi térfelünk felére
        else
        {
            mozgasy = (termin+termax)/2;
        }
        //Sebesség beállítások,csak akkor,ha a mi térfelünkön van
        if(jatekosok[labdaid].poz.y>=termin && jatekosok[labdaid].poz.y <= termax){
            if((abs(jatekosok[sajatid].poz.y -jatekosok[labdaid].poz.y)) >=3 && labdax < ellx  )
			{
				seb = 2;
			}
            //sebességnél,még nincs vizsgálva,ha y-on nagyon messze vagyunk!!! ez már valami,de még lehet fejleszteni
            if((abs(jatekosok[sajatid].poz.y -jatekosok[labdaid].poz.y)) >=3 && labdax < 4)
            {
                seb = 3;
            }

            if( sajatx>ellx )
			{
				seb = 2;
			}
            if( sajatx>=ellx && ellx <3 )
            {
                seb = 2;
            }
			if( sajatx>=labdax )
			{
				seb = 2;
			}
            if( sajatx>=labdax  &&labdax<3 )
            {
                seb = 3;
            }
			if(ellx < (p.get_m()/2) && sajatx>ellx)
			{
				seb = 3;
			}
            /*if(sajatx > labdax && jatekosok[sajatid].e >= jatekosok[ellenid].e)
			{
				seb =2;
            }*/
        }
        //X koordináta,mi térfelünkön van a labda
        if(jatekosok[labdaid].poz.y>=termin && jatekosok[labdaid].poz.y <= termax && labdax<pfele1)
        {
			//Ellenségénl van a labda
            if(jatekosok[ellenid] == jatekosok[labdaid])
            {
                if(sajatx < ellx && jatekosok[ellenid].poz.y != jatekosok[sajatid].poz.y && jatekosok[sajatid].e >= jatekosok[ellenid].e && jatekosok[sajatid].e > 10)
                {
                    mozgasx = tavx;
                }
                if(sajatx < ellx && jatekosok[ellenid].poz.y != jatekosok[sajatid].poz.y && jatekosok[sajatid].e >= jatekosok[ellenid].e && jatekosok[sajatid].e <= 10)
                {
                    mozgasx = jatekosok[sajatid].poz.x;
                }
                else if(jatekosok[ellenid].poz.y == jatekosok[sajatid].poz.y && ellx > 6 && !jatekosok[ellenid].mozog )
                {
                    mozgasx = jatekosok[ellenid].poz.x;
                }
                else if(ellx <3 && !jatekosok[ellenid].mozog && jatekosok[sajatid].e >= jatekosok[ellenid].e && !jatekosok[sajatid].mozog && regitick >2)
                {
                    mozgasx = jatekosok[ellenid].poz.x;
                }
                else if(ellx <3)
                {
                    mozgasx = mozgasx;
                }
                else if(jatekosok[ellenid].mozog && jatekosok[ellenid].poz.y == jatekosok[sajatid].poz.y && jatekosok[sajatid].e >= jatekosok[ellenid].e )
                {
                    mozgasx = tavx;
                }
                else
                {
                    mozgasx = mozgasx;
                }
            }
			//Az ellenség elrúgta  a labdát,megpróbáljuk elkapni
            else
            {
                if(labdax > 3)
                {
                    mozgasx = labdatavx;
                }
                else
                {
                     mozgasx = mozgasx;
                }
            }
        }
		//Senkise mozog eset,x koordináta
        else if(((!jatekosok[baratid].mozog && !jatekosok[ellenid].mozog) || (!jatekosok[ellenid].mozog && tarsuzenet == 9)) && !jatekosok[labdaid].mozog && regitick > 3)
        {
            if(jatekosok[sajatid].e ==20){
            seb = 1;
            mozgasx = jatekosok[labdaid].poz.x;
            }
            else
            {
                seb = 1;
                mozgasx = jatekosok[sajatid].poz.x;
            }
        }
        /*else if(!jatekosok[baratid].mozog && !jatekosok[ellenid].mozog && !jatekosok[labdaid].mozog)
        {
            if(jatekosok[sajatid].e ==20){
            seb = 1;
            mozgasx = jatekosok[labdaid].poz.x;
            }
            else
            {
                seb = 1;
                mozgasx = jatekosok[sajatid].poz.x;
            }
        }
		//minket követ a barát,de nem mozog az ellenség,x koordináta
        else if(!jatekosok[ellenid].mozog && tarsuzenet == 9 && !jatekosok[labdaid].mozog)
        {
            if(jatekosok[sajatid].e ==20){
            seb = 1;
            mozgasx = jatekosok[labdaid].poz.x;
            }
            else
            {
                seb = 1;
                mozgasx = jatekosok[sajatid].poz.x;
            }
        }*/
        //Ha épp nem kell mennünk a labdára viselkedés
        else if(jatekosok[sajatid].e >19){
            seb = 1;
            mozgasx = p.get_m()/2;
        }
		//Minden más eset
        else{
            mozgasx = jatekosok[sajatid].poz.x;
        }
    }
    // Engem követ a barát,de már elpasszoltam,sprint a labda után?
    else if(passzoltam && tarsuzenet == 9)
    {
         if(jatekosok[ellenid].tavolsag(jatekosok[labdaid])<jatekosok[sajatid].tavolsag(jatekosok[labdaid]))
         {
                seb = 2;
         }
         mozgasx = jatekosok[labdaid].poz.x;
         mozgasy = jatekosok[labdaid].poz.y;
    }
	//Még egy eset,ha senki nem mozog
    /*else if(tarsuzenet == 9 && !jatekosok[labdaid].mozog && !jatekosok[ellenid].mozog)
    {
        mozgasx = jatekosok[labdaid].poz.x;
        mozgasy = jatekosok[labdaid].poz.y;
    }*/
    //Mozgas egy jó helyre
    else if(sajatx > p.get_m()/2)
    {
         mozgasx =  p.get_m()/2;
         mozgasy = (termin+termax)/2;
    }
    else
    {
         mozgasx =  jatekosok[sajatid].poz.x;
         mozgasy = (termin+termax)/2;
    }
	//Egy utolsó csekk,hogyha kevesebb az energián,mint az ellenfélnek,inkább hátráljunk
    if(jatekosok[labdaid].poz.y>=termin && jatekosok[labdaid].poz.y <= termax)
    {
        if(jatekosok[sajatid].e < (jatekosok[ellenid].e-2) && abs(jatekosok[ellenid].poz.x -jatekosok[sajatid].poz.x) <= 1 && jatekosok[sajatid].poz.x != eredetix)
        {
            mozgasx = eredetix;
        }
        if(jatekosok[sajatid].e < (jatekosok[ellenid].e-4) && abs(jatekosok[ellenid].poz.x -jatekosok[sajatid].poz.x) == 2 && regitick < 6)
        {
            mozgasx = eredetix;
        }
    }
	//Válasz küldés,különböző szituációkra
    if(!jatekosok[baratid].mozog||(tarsuzenet == 2 && ellx <= baratx) ) //A társunk nem akar magától mozogni eset
    {
        baruz = "MESSAGE "+ to_string(baratid) + " PLAYER " + to_string(bmozgasx) +" "+ to_string(jatekosok[labdaid].poz.y)+" 1 BALL " + to_string(bmozgasx) +" "+ to_string(jatekosok[labdaid].poz.y)+" 1";
        message.print(mozgasx,mozgasy,seb,baruz);
    }   
    /*else if(tarsuzenet == 8)//??
    {
        baruz = "MESSAGE "+ to_string(baratid) + " PLAYER " + to_string(bmozgasx) +" "+ to_string(jatekosok[labdaid].poz.y)+" "+"1"+" BALL " + to_string(bmozgasx) +" "+ to_string(jatekosok[labdaid].poz.y)+" "+"1";
        message.print(mozgasx,mozgasy,seb,baruz);
    }*/
	//Csak a mi mozgásunkra vonatkozó válasz
    else{
        baruz = "MESSAGE "+ to_string(baratid) + " PLAYER " + to_string(mozgasx) +" "+ to_string((p.get_sz()/2))+" 1 BALL null null null"; //biztos jóhatása van ennek?nincs
        message.print(mozgasx,mozgasy,seb);
    }

}
//Egy logikai értéket ad vissza,ami arról tajékoztat a beadott játékosnál van-e a labda
bool nalalabda(map<int, jatekos> &jatekosok,int &labdaid,int &id)
{
    if(jatekosok[id] == jatekosok[labdaid] )return true;
    else return false;
}

/*p2d legkozelebb(map<int, jatekos> &jatekosok,p2d &a,p2d &b,palya& p,int &ellid){
    int st,legkisebb;
    double tav;
    p2d legkozelebb;
    p2d pontok[p.sz];
    int tavolsagok[p.sz];
    if(a.y <= b.y){
        for(int j=0;j< b.y+1;j++)
        {
            pontok[j] = a;
            tav = sqrt(pow(pontok[j].x-jatekosok[ellid].poz.x,2)+pow(pontok[j].y+jatekosok[ellid].poz.y,2));
            st = ceil(tav/1); // 1 csak egy próba,lehet 2 és 3 is!!!!
            tavolsagok[j] = st;
            a.y +=1;
        }
        legkisebb = tavolsagok[0];
        legkozelebb = pontok[0];
        for (int i=1;  i < p.sz+1;i++){
            if ( tavolsagok[i] < legkisebb ){
                legkozelebb = pontok[i];
                legkisebb = tavolsagok[i];
            }
        }
        return legkozelebb;
    }
    else {
        for(int j=0;j< a.y+1;j++)
        {
            pontok[j] = b;
            tav = sqrt(pow(pontok[j].x-jatekosok[ellid].poz.x,2)+pow(pontok[j].y+jatekosok[ellid].poz.y,2));
            st = ceil(tav/1); // 1 csak egy próba,lehet 2 és 3 is!!!!
            tavolsagok[j] = st;
            b.y +=1;
        }
        legkisebb = tavolsagok[0];
        legkozelebb = pontok[0];
        for (int i=1;  i < p.sz+1;i++){
            if ( tavolsagok[i] < legkisebb ){
                legkozelebb = pontok[i] ;
                 legkisebb = tavolsagok[i];
            }
        }
        return legkozelebb;
    }


}*/


