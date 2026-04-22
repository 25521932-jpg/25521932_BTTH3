#ifndef CNVSX_H
#define CNVSX_H

#include <string>
using namespace std;

class cNhanVienSX {
private:
    string maNV, hoTen;
    int namSinh;
    int soSP;
    double donGia;

public:
    void Nhap();
    void Xuat();
    double TinhLuong();
    int Tuoi();
};

#endif
