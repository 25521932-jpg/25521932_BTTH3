#include "cDaGiac.h"
#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

// ===== cDiem =====
void cDiem::Nhap() {
    cin >> x >> y;
}

void cDiem::Xuat() {
    cout << "(" << x << ", " << y << ")";
}

bool cDiem::TrungNhau(cDiem other) {
    return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
}

// ===== cDaGiac =====
void cDaGiac::Nhap() {
    cin >> n;
    ds.resize(n);
    for (int i = 0; i < n; i++) ds[i].Nhap();
}

void cDaGiac::Xuat() {
    cout << "Da giac co " << n << " dinh:\n";
    for (int i = 0; i < n; i++) {
        ds[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

bool cDaGiac::HopLe() {
    return n >= 3;
}

bool cDaGiac::CoDiemTrung() {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].TrungNhau(ds[j])) return true;
    return false;
}

//  kiểm tra tất cả điểm thẳng hàng
bool cDaGiac::ThangHang() {
    for (int i = 2; i < n; i++) {
        double area = ds[0].x * (ds[1].y - ds[i].y)
                    + ds[1].x * (ds[i].y - ds[0].y)
                    + ds[i].x * (ds[0].y - ds[1].y);
        if (fabs(area) > EPS) return false;
    }
    return true;
}

double KhoangCach(cDiem a, cDiem b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double cDaGiac::ChuVi() {
    double cv = 0;
    for (int i = 0; i < n; i++)
        cv += KhoangCach(ds[i], ds[(i + 1) % n]);
    return cv;
}

double cDaGiac::DienTich() {
    double dt = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        dt += ds[i].x * ds[j].y - ds[j].x * ds[i].y;
    }
    return fabs(dt) / 2.0;
}
