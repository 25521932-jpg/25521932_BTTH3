#ifndef CDATHUC_H
#define CDATHUC_H

#include <vector>
using namespace std;

class cDaThuc {
private:
    int bac;
    vector<double> a;

public:
    cDaThuc(int bac = 0);

    void Nhap();
    void Xuat();
    double GiaTri(double x);

    cDaThuc Cong(const cDaThuc& dt);
    cDaThuc Tru(const cDaThuc& dt);
};

#endif
