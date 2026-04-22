#include "cNhanVienSX.h"
#include <iostream>
using namespace std;

void cNhanVienSX::Nhap() {
    cin >> maNV;
    cin.ignore();
    getline(cin, hoTen);
    cin >> namSinh >> soSP >> donGia;
}

void cNhanVienSX::Xuat() {
    cout << maNV << " | " << hoTen << " | "
         << namSinh << " | " << soSP << " | "
         << donGia << " | Luong: " << TinhLuong() << endl;
}

double cNhanVienSX::TinhLuong() {
    return soSP * donGia;
}

int cNhanVienSX::Tuoi() {
    return 2026 - namSinh;
}
