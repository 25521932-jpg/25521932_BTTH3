#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// tạo mảng random
void cArray::TaoNgauNhien(int n) {
    this->n = n;
    a.resize(n);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 - 50; // [-50, 49]
    }
}

// xuất mảng
void cArray::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// đếm x
int cArray::DemX(int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == x) cnt++;
    return cnt;
}

// kiểm tra tăng dần
bool cArray::TangDan() {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

// số lẻ nhỏ nhất
int cArray::LeNhoNhat() {
    int minLe = 1e9;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            minLe = min(minLe, a[i]);
            found = true;
        }
    }
    return found ? minLe : -1;
}

// kiểm tra số nguyên tố
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

// số nguyên tố lớn nhất
int cArray::SNTLonNhat() {
    int maxSNT = -1;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            maxSNT = max(maxSNT, a[i]);
        }
    }
    return maxSNT;
}

// selection sort tăng
void cArray::SapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min_idx]) min_idx = j;
        swap(a[i], a[min_idx]);
    }
}

// giảm dần
void cArray::SapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[max_idx]) max_idx = j;
        swap(a[i], a[max_idx]);
    }
}
