#include <iostream>
#include <math.h>

using namespace std;
class ClassMatrix {
    double** a;
    int line, col;
public:
    ClassMatrix() {
        line = 4;
        col = 3;
        a = new double* [line];
        for (int i = 0; i < line; i++) {
            a[i] = new double[col];
            for (int j = 0; j < col; j++) {
                a[i][j] = 0;
            }
        }
    }
    ClassMatrix(int n);
    ClassMatrix(int n, int m, int value);
    ClassMatrix(const ClassMatrix&);
    ~ClassMatrix() { cout << "Matrix deleted" << endl; }
    void def();
    void FindElem();
    void input();
    void output();
    void mul();
    ClassMatrix add(ClassMatrix& s);
    ClassMatrix dif(ClassMatrix& s);
};

ClassMatrix::ClassMatrix(int n, int m, int value) {
    line = n;
    col = m;
    a = new double* [line];
    for (int i = 0; i < line; i++) {
        a[i] = new double[col];
        for (int j = 0; j < col; j++) {
            a[i][j] = value;
        }
    }
}

ClassMatrix::ClassMatrix(int n) {
    line = n;
    col = n;
    a = new double* [line];
    for (int i = 0; i < line; i++) {
        a[i] = new double[col];
        for (int j = 0; j < col; j++) {
            a[i][j] = 0;
        }
    }
}

ClassMatrix::ClassMatrix(const ClassMatrix& s) {
    line = s.line;
    col = s.col;
    a = new double* [line];
    for (int i = 0; i < line; i++) {
        a[i] = new double[col];
        for (int j = 0; j < col; j++) {
            a[i][j] = s.a[i][j];
        }
    }
}

void ClassMatrix::def() {
    cout << "|DEFAULT VALUE|";
    cout << "Input number: ";
    double value;
    cin >> value;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            a[i][j] = value;
        }
    }
}

void ClassMatrix::FindElem() {
    cout << "|FIND ELEMENT|";
    cout << "Input line and column: " << endl;
    int i, j;
    cin >> i;
    cin >> j;
    cout << "Your element: " << a[i - 1][j - 1] << endl;
}

void ClassMatrix::input() {
    cout << "|INPUT|" << endl;
    cout << "Input count line: ";
    cin >> line;
    cout << "Input count column: ";
    cin >> col;
    cout << "Input MATRIX: " << endl;
    a = new double* [line];
    for (int i = 0; i < line; i++) {
        a[i] = new double[col];
    }
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            cout << "a[" << i << "][" << j << "]=";
            cin >> a[i][j];
        }
    }
}

void ClassMatrix::output() {
    cout << "|MATRIX|" << endl;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void ClassMatrix::mul() {
    cout << "|MUL|" << endl;
    cout << "Input number for mul: ";
    float mul;
    cin >> mul;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            a[i][j] = a[i][j] * mul;
        }
    }
}


ClassMatrix ClassMatrix::add(ClassMatrix& s) {
    ClassMatrix tmp;
    tmp.line = line;
    tmp.col = col;
    for (int i = 0; i < tmp.line; i++) {
        for (int j = 0; j < tmp.col; j++) {
            tmp.a[i][j] = a[i][j] + s.a[i][j];
        }
    }
    return tmp;
}

ClassMatrix ClassMatrix::dif(ClassMatrix& s) {
    ClassMatrix tmp;
    tmp.line = line;
    tmp.col = col;
    for (int i = 0; i < tmp.line; i++) {
        for (int j = 0; j < tmp.col; j++) {
            tmp.a[i][j] = a[i][j] - s.a[i][j];
        }
    }
    return tmp;
}
int main()
{
    ClassMatrix a, b(5), c(2, 3, 4), d(c), c1(2, 3, 5);
    cout << "Obj a" << endl;
    a.output();
    cout << "Obj b" << endl;
    b.output();
    cout << "Obj c" << endl;
    c.output();
    cout << "Obj d" << endl;
    d.output();
    a.input();
    cout << "Obj a" << endl;
    a.output();
    b.def();
    cout << "Obj b" << endl;
    b.output();
    a.FindElem();
    a.mul();
    cout << "Obj a" << endl;
    a.output();
    c = c.add(d);
    cout << "Obj c" << endl;
    c.output();
    c = c.dif(c1);
    cout << "Obj c" << endl;
    c.output();
    return 0;

}
