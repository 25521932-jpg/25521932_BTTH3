#ifndef CDAGIAC_H
#define CDAGIAC_H

#include <vector>
using namespace std;

class cDiem {
public:
    double x, y;
    void Nhap();
    void Xuat();
    bool TrungNhau(cDiem other);
};

class cDaGiac {
private:
    int n;
    vector<cDiem> ds;

public:
    void Nhap();
    void Xuat();
    bool HopLe();
    bool CoDiemTrung();
    bool ThangHang();
    double ChuVi();
    double DienTich();
};

#endif
