#ifndef DONHANG_H
#define DONHANG_H

#include <vector>
#include <string>

using namespace std;

struct ChiTietDonHang
{
    string maSP;
    int soLuong;
};

class DonHang
{
private:
    string maDH;
    vector<ChiTietDonHang> dsChiTiet;

public:
    DonHang();

    string getMaDH() const;

    void setMaDH(string ma);

    void nhap();
    void xuat() const;

    vector<ChiTietDonHang>& getDSChiTiet() const;
};


#endif