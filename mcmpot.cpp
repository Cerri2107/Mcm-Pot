#include<iostream>

using namespace std;

int mcm(const int &a, const int &b) {
    static int tmpa = 0;
    static int tmpb = 0;
    tmpa = (tmpa == 0) ? a : tmpa;
    tmpb = (tmpb == 0) ? b : tmpb;
    if (a == b) {
        tmpa = 0;
        tmpb = 0;
        return a;
    }
    else if (a < b)
        return mcm(a + tmpa, b);
    else
        return mcm(a, b + tmpb);
}

// int pot(const int &base, const int &e) {
//     if (e != 0) {
//         static int b = 0;
//         b = (b == 0) ? base : b;
//         if (e > 1)
//             return pot(base * b, e - 1);
//         else {
//             b = 0;
//             return base;
//         }
//     }
//     else
//         return 1;
// }

float pot(const float &base, const int &e) {
    if (e > 0)
        return base * pot(base, e - 1);
    else if (e < 0)
        return -(base * pot(base, e + 1));
    else
        return 1;
}

int main() {
    int n1, n2, n3, n4, _mcm, e;
    float b, _pot;

    cout << "Inserire 4 numeri da cui verra ricavato il minimo comune multiplo: ";
    cin >> n1;
    cin >> n2;
    cin >> n3;
    cin >> n4;
    _mcm = mcm(n1, n2);
    _mcm = mcm(_mcm, n3);
    _mcm = mcm(_mcm, n4);
    cout << "MCM: " << _mcm << endl;

    cout << endl << "inserire base e esponente per potenza: ";
    cin >> b;
    cin >> e;
    _pot = pot(b, e);
    cout << "POT: " << _pot << endl;
    
    cin.get();
    cin.get();
}
