 #include "valasz.h"

valasz::valasz()
{

}

void valasz::print(int px, int py, int ps, int bx, int by, int bs, string mess)
{
    cout << "PLAYER " << px << " " << py << " " << ps << endl;
    cout << "BALL " << bx << " " << by << " " << bs << endl;
    cout <<mess<< endl;
    cout << "."<<endl;
}
void valasz::print(int px, int py, int ps,string mess)
{
    cout << "PLAYER " << px << " " << py << " " << ps << endl;
    cout <<mess<<endl;
    cout << "."<<endl;
}
void valasz::print(string mess){
    cout <<mess<<endl;
    cout << "."<<endl;
}
void valasz::print(int px, int py, int ps)
{
    cout << "PLAYER " << px << " " << py << " " << ps << endl;
    cout << "."<<endl;
}
void valasz::loves(int bx, int by, int bs)
{
    cout << "BALL " << bx << " " << by << " " << bs << endl;
    cout << "."<<endl;
}
void valasz::loves(int bx, int by, int bs,string mess)
{
    cout << "BALL " << bx << " " << by << " " << bs << endl;
    cout <<mess<<endl;
    cout << "."<<endl;
}
void valasz::print(int px, int py, int ps, int bx, int by, int bs)
{
    cout << "PLAYER " << px << " " << py << " " << ps << endl;
    cout << "BALL " << bx << " " << by << " " << bs << endl;
    cout << "."<<endl;
}
void valasz::print() {
    cout << "."<<endl;
}

