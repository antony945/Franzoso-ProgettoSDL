#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <quadmath.h>
#include <iomanip>
#define ERR_MAX 1E-18

using namespace std;

typedef long double Reale;

bool uguali(Reale x, Reale y){
    bool uguali = false;

    if(fabs(x-y) < ERR_MAX)
        uguali = true;

    return uguali;
}

Reale proceduraMisteriosa(Reale x, Reale y){
    if(uguali(x,y))
        return x;
    else
        return proceduraMisteriosa(2.0*x*y/(x+y), (x+y)/2.0);
}

Reale radq(Reale radicando){
    return proceduraMisteriosa(1.0, radicando);

}


//-----------------------------------------------

typedef struct Poligono{
    int n;
    Reale lato;
    Reale apotema;
    Reale differenza;
    Reale perimetro;
    Reale pigreco_vecchio;
    Reale pigreco_nuovo;
    Reale errore;
}Poligono;

Reale metodoArchimede(Poligono i, int n_lati){
    i.n = n_lati;

    i.apotema = radq((1.0*1.0)-((i.lato/2.0)*(i.lato/2.0)));

    i.perimetro = i.lato*i.n;
    i.pigreco_vecchio = i.pigreco_nuovo;
    i.pigreco_nuovo = i.perimetro/2.0;

    i.differenza = 1.0-i.apotema;
    i.lato = radq(((i.lato/2.0)*(i.lato/2.0))+(i.differenza*i.differenza));

    i.errore = fabs(i.pigreco_vecchio-i.pigreco_nuovo);

    cout << setprecision(25) << fixed;
    cout << "Il pigreco e': " << i.pigreco_nuovo << endl;
    cout << "L'errore e':   " << i.errore << endl << endl;

    if(i.errore < ERR_MAX)
        return i.pigreco_nuovo;
    else
        return metodoArchimede(i, 2*i.n);
}

int main(){
    /*
    for( int n = 0; n<=10; n++){
      cout << setprecision(25);
      cout << fixed;
      cout << "n = " << n
           << "   rq("<<n<<") = "
           << radq(n)
           << endl;
    }*/

    Poligono inscritto = {6,1.0,0.0,0.0,0.0,0.0,0.0,0.0};

    Reale pigreco = metodoArchimede(inscritto, inscritto.n);



    return 0;
}