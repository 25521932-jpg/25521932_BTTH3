#ifndef CARRAY_H
#define CARRAY_H

#include <vector>
using namespace std;

class cArray {
private:
    int n;
    vector<int> a;

public:
    void TaoNgauNhien(int n);
    void Xuat();
    int DemX(int x);
    bool TangDan();
    int LeNhoNhat();
    int SNTLonNhat();
    void SapXepTang();
    void SapXepGiam();
};

#endif
