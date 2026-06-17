#ifndef DONHANG_H
#define DONHANG_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Chi tiết từng sản phẩm trong đơn hàng
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
    double tongTien;

public:
    // Constructor
    DonHang();

    // Getter
    string getMaDH() const;
    const vector<ChiTietDonHang>& getDSChiTiet() const;
    double getTongTien() const;

    // Setter
    void setMaDH(string ma);
    void setTongTien(double tongTien);

    // Thêm chi tiết đơn hàng
    void themChiTiet(string maSP, int soLuong);

    // Nhập xuất
    void nhap();
    void xuat() const;
};

#endif