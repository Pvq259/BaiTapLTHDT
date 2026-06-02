#include "QuanLy.h"
#include <iostream>
#include <fstream>

using namespace std;

//Tìm sản phẩm
int QuanLy::timSanPham(string ma)
{
    for(int i = 0; i < dsSanPham.size(); i++)
    {
        if(dsSanPham[i].getMaSP() == ma)
            return i;
    }

    return -1;
}

//Thêm Sản Phẩm
void QuanLy::themSanPham()
{
    SanPham sp;

    sp.nhap();

    if(timSanPham(sp.getMaSP()) != -1)
    {
        cout << "Ma san pham da ton tai!\n";
        return;
    }

    dsSanPham.push_back(sp);

    cout << "Them thanh cong!\n";
}

//Hiển thị sản phẩm
void QuanLy::hienThiSanPham()
{
    cout << "\n===== DANH SACH SAN PHAM =====\n";

    for(auto sp : dsSanPham)
    {
        sp.xuat();
    }
}

//Sửa sản phẩm
void QuanLy::suaSanPham()
{
    string ma;

    cout << "Nhap ma can sua: ";
    getline(cin, ma);

    int vt = timSanPham(ma);

    if(vt == -1)
    {
        cout << "Khong tim thay!\n";
        return;
    }

    string tenMoi;
    double giaMoi;

    cout << "Ten moi: ";
    getline(cin, tenMoi);

    cout << "Gia moi: ";
    cin >> giaMoi;
    cin.ignore();

    dsSanPham[vt].setTenSP(tenMoi);
    dsSanPham[vt].setGia(giaMoi);

    cout << "Da cap nhat!\n";
}

//Kiểm tra sản phẩm trong đơn hàng
bool QuanLy::sanPhamDangDuocSuDung(string maSP)
{
    for(auto dh : dsDonHang)
    {
        for(auto ct : dh.getDSChiTiet())
        {
            if(ct.maSP == maSP)
                return true;
        }
    }

    return false;
}

//Xóa sản phẩm
void QuanLy::xoaSanPham()
{
    string ma;

    cout << "Nhap ma can xoa: ";
    getline(cin, ma);

    int vt = timSanPham(ma);

    if(vt == -1)
    {
        cout << "Khong tim thay!\n";
        return;
    }

    if(sanPhamDangDuocSuDung(ma))
    {
        cout << "San pham dang nam trong don hang!\n";
        return;
    }

    dsSanPham.erase(dsSanPham.begin() + vt);

    cout << "Da xoa!\n";
}