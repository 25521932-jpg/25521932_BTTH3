#include "cDaThuc.h"
#include <iostream>
#include <cmath>
using namespace std;

cDaThuc::cDaThuc(int bac) {
    this->bac = bac;
    a.resize(bac + 1, 0);
}

// Nhập đa thức
void cDaThuc::Nhap() {
    cin >> bac;
    a.resize(bac + 1);

    for (int i = bac; i >= 0; i--) {
        cin >> a[i]; // nhập hệ số từ cao xuống
    }
}

// Xuất đa thức
void cDaThuc::Xuat() {
    for (int i = bac; i >= 0; i--) {
        if (a[i] == 0) continue;

        if (i != bac && a[i] > 0) cout << "+";

        if (i == 0) cout << a[i];
        else if (i == 1) cout << a[i] << "x";
        else cout << a[i] << "x^" << i;
    }
    cout << endl;
}

// Tính giá trị đa thức
double cDaThuc::GiaTri(double x) {
    double res = 0;
    for (int i = 0; i <= bac; i++) {
        res += a[i] * pow(x, i);
    }
    return res;
}

// Cộng
cDaThuc cDaThuc::Cong(const cDaThuc& dt) {
    int maxBac = max(bac, dt.bac);
    cDaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double h1 = (i <= bac) ? a[i] : 0;
        double h2 = (i <= dt.bac) ? dt.a[i] : 0;
        kq.a[i] = h1 + h2;
    }
    return kq;
}

// Trừ
cDaThuc cDaThuc::Tru(const cDaThuc& dt) {
    int maxBac = max(bac, dt.bac);
    cDaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double h1 = (i <= bac) ? a[i] : 0;
        double h2 = (i <= dt.bac) ? dt.a[i] : 0;
        kq.a[i] = h1 - h2;
    }
    return kq;
}
    
