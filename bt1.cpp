#include "cTamGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

// so sánh số thực an toàn
static bool eq(double a, double b) {
    return fabs(a - b) <= 1e-6 * max(fabs(a), fabs(b));
}

// khoảng cách
double cTamGiac::DoDai(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

cTamGiac::cTamGiac() {
    Ax = Ay = Bx = By = Cx = Cy = 0;
}

cTamGiac::~cTamGiac() {}

void cTamGiac::Nhap() {
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;
}

void cTamGiac::Xuat() {
    cout << "A(" << Ax << "," << Ay << ") ";
    cout << "B(" << Bx << "," << By << ") ";
    cout << "C(" << Cx << "," << Cy << ")\n";
}

bool cTamGiac::HopLe() {
    double AB = DoDai(Ax, Ay, Bx, By);
    double BC = DoDai(Bx, By, Cx, Cy);
    double CA = DoDai(Cx, Cy, Ax, Ay);

    return (AB + BC > CA && AB + CA > BC && BC + CA > AB);
}

void cTamGiac::KiemTraLoai() {
    if (!HopLe()) {
        cout << "Khong phai tam giac\n";
        return;
    }

    double AB = DoDai(Ax, Ay, Bx, By);
    double BC = DoDai(Bx, By, Cx, Cy);
    double CA = DoDai(Cx, Cy, Ax, Ay);

    double AB2 = AB * AB;
    double BC2 = BC * BC;
    double CA2 = CA * CA;

    // đều
    if (eq(AB, BC) && eq(BC, CA)) {
        cout << "Tam giac deu\n";
        return;
    }

    // vuông
    if (eq(AB2 + BC2, CA2) ||
        eq(AB2 + CA2, BC2) ||
        eq(BC2 + CA2, AB2)) {
        cout << "Tam giac vuong\n";
        return;
    }

    // cân
    if (eq(AB, BC) || eq(BC, CA) || eq(CA, AB)) {
        cout << "Tam giac can\n";
        return;
    }

    cout << "Tam giac thuong\n";
}

double cTamGiac::ChuVi() {
    double AB = DoDai(Ax, Ay, Bx, By);
    double BC = DoDai(Bx, By, Cx, Cy);
    double CA = DoDai(Cx, Cy, Ax, Ay);
    return AB + BC + CA;
}

double cTamGiac::DienTich() {
    double AB = DoDai(Ax, Ay, Bx, By);
    double BC = DoDai(Bx, By, Cx, Cy);
    double CA = DoDai(Cx, Cy, Ax, Ay);

    double p = (AB + BC + CA) / 2;
    return sqrt(p * (p - AB) * (p - BC) * (p - CA));
}
