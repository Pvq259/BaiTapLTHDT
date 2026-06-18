#include "DonHang.h"
#include "SanPham.h"
#include <iomanip>

using namespace std;

// Hàm mặc định
DonHang::DonHang()
{
    maDH = "";
    tongTien = 0;
}

// Getter
string DonHang::getMaDH() const
{
    return maDH;
}

const vector<ChiTietDonHang>& DonHang::getDSChiTiet() const
{
    return dsChiTiet;
}

double DonHang::getTongTien() const
{
    return tongTien;
}

// Setter
void DonHang::setMaDH(string ma)
{
    maDH = ma;
}

void DonHang::setTongTien(double tongTien)
{
    this->tongTien = tongTien;
}

// Thêm chi tiết đơn hàng
void DonHang::themChiTiet(string maSP, int soLuong)
{
    ChiTietDonHang ct;

    ct.maSP = maSP;
    ct.soLuong = soLuong;

    dsChiTiet.push_back(ct);
}

// Sửa số lượng sản phẩm
bool DonHang::suaSoLuong(string maSP, int soLuongMoi)
{
    for (int i = 0; i < dsChiTiet.size(); i++)
    {
        if (dsChiTiet[i].maSP == maSP)
        {
            dsChiTiet[i].soLuong = soLuongMoi;
            return true;
        }
    }

    return false;
}

// Xóa sản phẩm khỏi đơn hàng
bool DonHang::xoaChiTiet(string maSP)
{
    for (int i = 0; i < dsChiTiet.size(); i++)
    {
        if (dsChiTiet[i].maSP == maSP)
        {
            dsChiTiet.erase(dsChiTiet.begin() + i);
            return true;
        }
    }

    return false;
};

// Nhập đơn hàng
void DonHang::nhap()
{
    cout << "Nhap ma don hang: ";
    getline(cin, maDH);

    int n;

    cout << "Nhap so luong san pham trong don hang: ";
    cin >> n;

    dsChiTiet.clear();

    for (int i = 0; i < n; i++)
    {
        ChiTietDonHang ct;

        cin.ignore();

        cout << "\nNhap san pham thu " << i + 1 << endl;

        cout << "Nhap ma san pham: ";
        getline(cin, ct.maSP);

        cout << "Nhap so luong: ";
        cin >> ct.soLuong;

        dsChiTiet.push_back(ct);
    }
}

// Xuất đơn hàng
void DonHang::xuat() const
{
    cout << "\nMa don hang: " << maDH << endl;

    cout << left
         << setw(15) << "Ma SP"
         << setw(10) << "So luong"
         << endl;

    for (int i = 0; i < dsChiTiet.size(); i++)
    {
        cout << left
             << setw(15) << dsChiTiet[i].maSP
             << setw(10) << dsChiTiet[i].soLuong
             << endl;
    }
}
