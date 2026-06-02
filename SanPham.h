#ifndef SANPHAM_H
#define SANPHAM_H

#include <iostream>
#include <string>

using namespace std;

class SanPham
{
private:
    string maSP;
    string tenSP;
    double gia;
public:
    SanPham();
    SanPham(string ma, string ten, double gia);

    string getMaSP() const;
    string getTenSP() const;
    double getGia() const;

    void setMaSP(string ma);
    void setTenSP(string ten);
    void setGia(double gia);

    void nhap();
    void xuat() const;
};

#endif