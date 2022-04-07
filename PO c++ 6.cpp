#include <iostream>
#include <Windows.h>
#include <cstdio>
#include <math.h> /// ewentualna
#include <conio.h>
#include <sstream>

using namespace std;
                            /// wersja NOT FOOL PROOF, trzeba wpisywać dobre wartosci, 
                            ///tak samo jak przy instalacji programow, nie chcemy zainstalowac niechcianych dodatkow ;)
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
        ostringstream out;
        out << "(" << x << "," << y << ") ";
            return out.str();
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
        ostringstream out;
        out << p1.toString();
        return out.str();
    }
};
class Trojkat
{
    Linia lin1, lin2, lin3;
    Punkt Q;                            /// srodek ciezkosci  trojkata, implementacja nie jest oparta na jego zmianie (jeszcze)
    //Wektor wp1, wp2, wp3;
public:
    Trojkat()                           /// konstruktor domyslny
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
        lin1.Move(dx, dy);
        lin2.Move(dx, dy);
        lin3.Move(dx, dy);
    }
    string toString()
    {
        ostringstream out;
        out << lin1.toString() << lin2.toString() << lin3.toString();
        return out.str();
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
    Czworokat(const Czworokat& old_czwo)
    {
        lin1 = old_czwo.lin1;
        lin2 = old_czwo.lin2;
        lin3 = old_czwo.lin3;
        lin4 = old_czwo.lin4;
    }
    void przesun(int dx,int dy)
    {
        lin1.Move(dx, dy);
        lin2.Move(dx, dy);
        lin3.Move(dx, dy);
        lin4.Move(dx, dy);
    }
    string toString()
    {
        ostringstream out;
        out << lin1.toString() << lin2.toString() << lin3.toString() << lin4.toString();
        return out.str();
    }
};
class Obraz
{
    int t = 0; int c = 0;
    Trojkat* trojkaty,* ttrojkaty;
    Czworokat* czworokaty,* tczworokaty;
public:
    Obraz()
    {
        trojkaty = new Trojkat[t];
        czworokaty = new Czworokat[c];
    }
    void dodajTrojkat(Trojkat ftroj)
    {
        t++;
            ttrojkaty = new Trojkat[t];
            for (int i = 0; i < t; i++)
            {
                ttrojkaty[i] = trojkaty[i];
            }
            delete[] trojkaty;
            trojkaty = new Trojkat[t];                                                          ///wypierdala wyjatki ze o ja pierdole
            for (int i = 0; i < t; i++)
            {
                trojkaty[i] = ttrojkaty[i];
            }
        trojkaty[t-1] = ftroj;
        delete[] ttrojkaty;
        cout << endl << "Dodano trojkat nr " << t-1 << endl;
    }
    void dodajCzworokat(Czworokat fczwor)
    {
        c++;
        tczworokaty = new Czworokat[c];
        for (int i = 0; i < c; i++)
        {
            tczworokaty[i] = czworokaty[i];
        }
        ///tczworokaty = czworokaty;
        delete[] czworokaty;
        czworokaty = new Czworokat[c];
        for (int i = 0; i < c; i++)
        {
            czworokaty[i] = tczworokaty[i];
        }
        ///czworokaty = tczworokaty;
        czworokaty[c-1] = fczwor;
        delete[] tczworokaty;
        cout << endl << "Dodano czworokat nr " << c-1 << endl;
    }
    void przesunTrojkat(int dx, int dy, int nr)
    {
        trojkaty[nr].przesun(dx, dy);
        cout << endl << "Przesunieto trojkat nr " << nr << " o dx = " << dx << " i dy = " << dy << endl;
    }
    void przesunCzworokat(int dx, int dy,int nr)
    {
        czworokaty[nr].przesun(dx, dy);
        cout << endl << "Przesunieto czworokat nr " << nr << " o dx = " << dx << " i dy = " << dy << endl;
    }
    string sListTrojkaty()
    {
        ostringstream out;
        for (int i = 0; i < t; i++)
        {
            out << "Trojkat nr "<< i << ": " << trojkaty[i].toString() << endl;
        }
        return out.str();
    }
    string sListCzworokaty()
    {
        ostringstream out;
        for (int i = 0; i < c; i++)
        {
            out << "Czworokat nr " << i << ": " << czworokaty[i].toString() << endl;
        }
        return out.str();
    }
    string toString()
    {
        ostringstream out;
        out << sListTrojkaty() << sListCzworokaty();
        return out.str();
    }
    void Move(int dx, int dy)
    {
        for (int i = 0; i < t; i++)
        {
            trojkaty[i].przesun(dx, dy);
        }
        for (int i = 0; i < c; i++)
        {
            czworokaty[i].przesun(dx, dy);
        }
        cout << endl << "Przesunieto obraz"<< " o dx = " << dx << " i dy = " << dy << endl;
    }
};
int main()
{   
    Obraz image;
    int tx1, ty1, tx2, ty2, tx3, ty3, tx4, ty4, nr;
    char ch;
    while (true)
    {
        cout << "1. Wypisac figury" << endl << "2. Dodac trojkat" << endl << "3. Przesunac trojkat"; 
        cout << endl << "4. Dodac czworokat" << endl << "5. Przesunac czworokat" << endl << "6. Przesunac obraz" << endl;
        ch = _getch();
        switch(ch)
        {
            system("cls");
        case '1':
        {
            cout << image.toString();
            break;
        }
        case '2':
        {
            cout << "Punkt P1 x=";
            cin >> tx1;
            cout << "Punkt P1 y=";
            cin >> ty1;
            cout << endl;
            cout << "Punkt P2 x=";
            cin >> tx2;
            cout << "Punkt P2 y=";
            cin >> ty2;
            cout << endl;
            cout << "Punkt P3 x=";
            cin >> tx3;
            cout << "Punkt P3 y=";
            cin >> ty3;
            cout << endl;
            image.dodajTrojkat(Trojkat(Punkt(tx1,ty1),Punkt(tx2,ty2),Punkt(tx3,ty3)));
            break;
        }
        case '3':
        {
            cout << image.sListTrojkaty() << endl;
            cout << endl << "Wpisz nr trojkata do przesuniecia: ";
            cin >> nr;
            cout << endl << "dx = ";
            cin >> tx1;
            cout << endl << "dy = ";
            cin >> ty1;
            image.przesunTrojkat(tx1, ty1, nr);
            break;
        }
        case '4':
        {
            cout << "Punkt P1 x=";
            cin >> tx1;
            cout << "Punkt P1 y=";
            cin >> ty1;
            cout << endl;
            cout << "Punkt P2 x=";
            cin >> tx2;
            cout << "Punkt P2 y=";
            cin >> ty2;
            cout << endl;
            cout << "Punkt P3 x=";
            cin >> tx3;
            cout << "Punkt P3 y=";
            cin >> ty3;
            cout << endl;
            cout << "Punkt P4 x=";
            cin >> tx4;
            cout << "Punkt P4 y=";
            cin >> ty4;
            cout << endl;
            image.dodajCzworokat(Czworokat(Punkt(tx1, ty1), Punkt(tx2, ty2), Punkt(tx3, ty3), Punkt(tx4, ty4)));
            break;
        }
        case '5':
        {
            cout << image.sListCzworokaty() << endl;
            cout << endl << "Wpisz nr czworokata do przesuniecia: ";
            cin >> nr;
            cout << endl << "dx = ";
            cin >> tx1;
            cout << endl << "dy = ";
            cin >> ty1;
            image.przesunCzworokat(tx1, ty1, nr);
            break;
        }
        case '6':
        {            
            cout << endl << "dx = ";
            cin >> tx1;
            cout << endl << "dy = ";
            cin >> ty1;
            image.Move(tx1, ty1);
            break;
        }
        default:
        {   
            cout << endl << "Cos poszlo nie tak :(" << endl << "(Prawdopodobnie zly wybor)";
            break;
        }
        }
        cout << endl << "Nacisnij dowolny przycisk by kontynuowac." << endl;
        _getch();
        system("cls");
    }
}

