#ifndef CTAMGIAC_H
#define CTAMGIAC_H

class cTamGiac {
private:
    double Ax, Ay, Bx, By, Cx, Cy;

    double DoDai(double x1, double y1, double x2, double y2);

public:
    cTamGiac();
    ~cTamGiac();

    void Nhap();
    void Xuat();

    bool HopLe();

    void KiemTraLoai();

    double ChuVi();
    double DienTich();

    void TinhTien(double dx, double dy);
    void PhongTo(double k);
    void ThuNho(double k);
    void Quay(double goc);
};

#endif
