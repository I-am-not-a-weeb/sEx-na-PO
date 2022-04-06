#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <math.h> /// ewentualna

using namespace std;

class Punkt
{
    int x, y;
public:
    Punkt()
    {
        x = 0; y = 0;
    }
    Punkt(int xx, int yy)
    {
        x = xx; y = yy;
    }
    Punkt(const Punkt& p)
    {
        x = p.x; y = p.y;
    }
    void Move(int dx, int dy)
    {
        x += dx; y += dy;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    string toString()
    {

    }
};
/*class Wektor
{
    int dx, dy;
public:
    Wektor(Punkt zp, Punkt dop) // zp - z punktu, dop - do punktu 
    {
        dx = dop.getX() - zp.getX();
        dy = dop.getY() - zp.getY();
    }
    Wektor()
    {
        ///nieuzywany
    }
    Punkt WektoryzacjaP(Punkt a)
    {
        return Punkt(a.getX() + dx, a.getY() + dy);
    }
};
*/
class Linia
{
    Punkt p1, p2;
public:
    Linia()                     ///bezsens ale dziala
    {
        p1 = Punkt(); p2 = Punkt();
    }
    Linia(Punkt fp1, Punkt fp2)
    {
        p1 = fp1; p2 = fp2;

    }
    Linia(const Linia& lin)
    {
        p1 = lin.p1;
        p2 = lin.p2;
    }
    void Move(int dx, int dy)
    {
        p1.Move(dx, dy);
        p2.Move(dx, dy);
    }
    Punkt getP1()
    {
        return p1;
    }
    Punkt getP2()
    {
        return p2;
    }
    string toString()
    {

    }
};
class Trojkat
{
    Linia lin1, lin2, lin3;
    Punkt Q;            /// srodek ciezkosci  trojkata, implementacja nie jest oparta na jego zmianie (jeszcze)
    //Wektor wp1, wp2, wp3;
public:
    Trojkat()           /// konstruktor domyslny
    {

    }
    Trojkat(Punkt fp1, Punkt fp2, Punkt fp3)            /// konstruktor tworzacy trojkat z trzech punktow, tymczasowa implementacja
    {
        lin1 = Linia(fp1, fp2); lin2 = Linia(fp2, fp3); lin3 = Linia(fp3, fp1);
        Q = Punkt((fp1.getX() + fp2.getX() + fp3.getX()) / 3, (fp1.getY() + fp2.getY() + fp3.getY()) / 3);
  /*    wp1 = Wektor(Q, fp1);
        wp2 = Wektor(Q, fp2);
        wp3 = Wektor(Q, fp3);*/
    }
    Trojkat(const Trojkat& old_tro)
    {
        lin1 = old_tro.lin1;
        lin2 = old_tro.lin2;
        lin3 = old_tro.lin3;
        Q = old_tro.Q;
    }
    void przesun(int dx, int dy)
    {
        Q = Punkt(Q.getX() + dx, Q.getY() + dy);
        lin1 = Linia(Punkt(lin1.getP1().getX() + dx,lin1.getP1().getY() + dy), Punkt(lin1.getP2().getX() + dx,lin1.getP2().getY()+dy));
        lin2 = Linia(Punkt(lin2.getP1().getX() + dx, lin2.getP1().getY() + dy), Punkt(lin2.getP2().getX() + dx, lin2.getP2().getY() + dy));
        lin3 = Linia(Punkt(lin3.getP1().getX() + dx, lin3.getP1().getY() + dy), Punkt(lin3.getP2().getX() + dx, lin3.getP2().getY() + dy));
    }
    string toString()
    {

    }
    int wypiszQx()
    {
        return Q.getX();
    }
    int wypiszQy()
    {
        return Q.getY();
    }
    int wypiszlinp1x(Linia lin)                     /// tymczasowe / test.pocz
    {
        return lin.getP1().getX();
    }
    int wypiszlinp2x(Linia lin)
    {
        return lin.getP2().getX();
    }
    int wypiszlinp1y(Linia lin)
    {
        return lin.getP1().getY();
    }
    int wypiszlinp2y(Linia lin)
    {
        return lin.getP2().getY();
    }                                               /// tymczasowe / test.kon
};
class Czworokat
{   
    Linia lin1, lin2, lin3, lin4;
    Punkt Q;
public:
    Czworokat()
    {

    }
    Czworokat(Punkt fp1, Punkt fp2, Punkt fp3, Punkt fp4)   ///konieczne wpisanie w kolejnosci tworzenia linii obwodu
    {
        lin1 = Linia(fp1, fp2); 
        lin2 = Linia(fp2, fp3); 
        lin3 = Linia(fp3, fp4);
        lin4 = Linia(fp4, fp1);
        Q = Punkt((fp1.getX() + fp2.getX() + fp3.getX() + fp4.getX()) / 4, (fp1.getY() + fp2.getY() + fp3.getY() + fp4.getY()) / 3);
    }
    Czworokat(const Czworokat &old_czwo)
    {

    }
    void przesun(int dx,int dy)
    {
        lin1 = Linia(Punkt(lin1.getP1().getX() + dx, lin1.getP1().getY() + dy), Punkt(lin1.getP2().getX() + dx, lin1.getP2().getY() + dy));
        lin2 = Linia(Punkt(lin2.getP1().getX() + dx, lin2.getP1().getY() + dy), Punkt(lin2.getP2().getX() + dx, lin2.getP2().getY() + dy));
        lin3 = Linia(Punkt(lin3.getP1().getX() + dx, lin3.getP1().getY() + dy), Punkt(lin3.getP2().getX() + dx, lin3.getP2().getY() + dy));
        lin4 = Linia(Punkt(lin4.getP1().getX() + dx, lin4.getP1().getY() + dy), Punkt(lin4.getP2().getX() + dx, lin4.getP2().getY() + dy));
    }
    string toString()
    {

    }
};
class Obraz
{
    Trojkat trojkaty;
    Czworokat czworokaty;
public:
    Obraz()
    {

    }

};
int main()
{
    Punkt a(-3, 2);
    Punkt b(-8, 5);
    Punkt c(-1, 5);
    Trojkat abc(a, b, c);
    cout << "Q abc = " << abc.wypiszQx() << " , " << abc.wypiszQy() << endl;
    abc.przesun(1, 1);
    cout << "Q efg = " << abc.wypiszQx() << " , " << abc.wypiszQy() << endl;
}

