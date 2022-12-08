#include <iostream>

using namespace std;

class Vector
{
    double *v;
    int num;
    int state;
public:
    Vector() : v(NULL), num(0), state(0) {}
    Vector(int n);
    Vector(int n, double&);
    Vector(int n, double*);
    Vector(const Vector& s);
    Vector& operator=(const Vector& s);
    ~Vector() {
        cout << " del vec";
        if (v) delete[] v;
    }
    void Output();
    void Input();
    Vector Add(Vector& b);
};
Vector::Vector(int n) {
    if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    num = n;
    v = new double[n] ;
    for (int i = 0; i < n; i++) {
        v[i] = 0.0;

    }
}
Vector::Vector(int n, double& b) {
    if (n <= 0) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    num = n;
    v = new double[n];
    for (int i = 0; i < n; i++) {
        v[i] = b;

    }
}
Vector::Vector(int n, double* p) {
    if (n <= 0 || p == NULL) { v = NULL; num = 0; state = -1; cout << " Vec --> 0 "; }
    num = n;
    v = new double[n];
    for (int i = 0; i < n; i++) {
        v[i] = p[i];
    }
}
Vector::Vector(const Vector& s) {
    if (this != &s) {
        num = s.num;
        v = new double[num];
        state = 0;
        for (int i = 0; i < num; i++) v[i] = s.v[i];
    }
}
Vector& Vector::operator=(const Vector& s) {
    if (num != s.num)
    {
        if (v) delete[] v;
        num = s.num;
        v = new double[num];
        state = 0;
    }
    for (int i = 0; i < num; i++) v[i] = s.v[i];
    return *this;
}
void Vector::Input() {
    if (num == 0) {
        if (v) delete[] v;
        do {
            cout << "Input size Vec\n";
            cin >> num;
        } while (num <= 0);
        v = new double[num];
    }
    for (int i = 0; i < num; i++) {
        cout << " v [ " << i << " ] "; cin >> v[i] ;
    }
}
void Vector::Output() {
    if (num != 0) {
        for (int i = 0; i < num; i++) {
            cout << " v [ " << i << " ] " << v[i] << '\t';
            cout << endl;
        }
    }
}
Vector Vector::Add(Vector& b) {
    int tnum;
    tnum = num < b.num ? num : b.num;
    if (tnum >= 0) {
        Vector tmp(tnum);
        for (int i = 0; i < tnum; i++) tmp.v[i] = v[i] + b.v[i];
        return tmp;
    }
    return Vector(0);
}

int main()
{
    double a(1.0);
    double b(0), c;
    cout << a << endl;  
    cout << b << endl;
    c = a + b;
    cout << c << endl;
    cout << " Test " << endl;
    Vector VecObj, VecObj1(10);
    cout << "VecObj \n";
    VecObj.Output();
    cout << "VecObj1 \n";
    VecObj1.Output();
    cout << " Input a " << endl;
    cin >> a ;
    cout << a << endl;
    Vector VecObj2(10, a);
    VecObj2.Output();
    VecObj.Input();
    cout << endl;
    VecObj.Output();
    VecObj1 = VecObj.Add(VecObj2);
    VecObj1.Output();
    system("PAUSE");
    return 0; 
}
