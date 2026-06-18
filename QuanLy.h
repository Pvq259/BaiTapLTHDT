#ifndef QUANLY_H
#define QUANLY_H

#include "SanPham.h"
#include "DonHang.h"
#include <vector>

class QuanLy
{
private:
    vector<SanPham> dsSanPham;
    vector<DonHang> dsDonHang;

public:
    void menu();

    // SAN PHAM
    void themSanPham();
    void hienThiSanPham() const;
    void suaSanPham();
    void xoaSanPham();
    int timSanPham(string ma);

    // DON HANG
    void themDonHang();
    void hienThiDonHang();
    void suaDonHang();
    void xoaDonHang();
    int timDonHang(string ma);

    bool sanPhamDangDuocSuDung(string maSP);

    // FILE
    void luuSanPham();
    void docSanPham();

    void luuDonHang();
    void docDonHang();
};

#endif