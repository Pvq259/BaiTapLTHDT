#include "DonHang.h"
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

    dsChiTiet.push_back(ct);  // thêm vào cuối danh sách
}

// Nhập đơn hàng
void DonHang::nhap()
{
    cin.ignore();         // xóa kí tự thừa
    cout << "Nhap ma don hang: ";
    getline(cin, maDH);       
    int n;
    cout << "Nhap so luong san pham trong don hang: ";
    cin >> n;

    dsChiTiet.clear();
    for (int i = 0; i < n; i++)
    {
        ChiTietDonHang ct;

        cout << "\nNhap san pham thu " << i + 1 << endl;
        cin.ignore();
        cout << "Nhap ma san pham: ";
        getline(cin, ct.maSP);
        cout << "Nhap so luong: ";
        cin >> ct.soLuong;

        dsChiTiet.push_back(ct);       // thêm vào cuối danh sách
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
    cout << "Tong so tien: " << fixed << setprecision(2) << tongTien << endl;
}