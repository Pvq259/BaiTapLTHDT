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
    int soLuong;

public:
    SanPham();
    SanPham(string ma, string ten, double gia, int soLuong);

    // Getter
    string getMaSP() const;
    string getTenSP() const;
    double getGia() const;
    int getSoLuong() const;

    // Setter
    void setMaSP(string ma);
    void setTenSP(string ten);
    void setGia(double gia);
    void setSoLuong(int soLuong);

    // Nhập xuất
    void nhap();
    void xuat() const;
};

#endif