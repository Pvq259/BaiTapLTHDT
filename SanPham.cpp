#include "SanPham.h"
#include <iomanip>

using namespace std;

// Hàm mặc định
SanPham::SanPham()
{
    maSP = "";
    tenSP = "";
    gia = 0;
    soLuong = 0;
}

// Hàm mặc định có tham số
SanPham::SanPham(string ma, string ten, double gia, int soLuong)
{
    this->maSP = ma;
    this->tenSP = ten;
    this->gia = gia;
    this->soLuong = soLuong;
}

// Getter
string SanPham::getMaSP() const
{
    return maSP;
}
string SanPham::getTenSP() const
{
    return tenSP;
}
double SanPham::getGia() const
{
    return gia;
}
int SanPham::getSoLuong() const
{
    return soLuong;
}

// Setter
void SanPham::setMaSP(string ma)
{
    maSP = ma;
}
void SanPham::setTenSP(string ten)
{
    tenSP = ten;
}
void SanPham::setGia(double gia)
{
    this->gia = gia;
}
void SanPham::setSoLuong(int soLuong)
{
    this->soLuong = soLuong;
}

// Nhập thông tin sản phẩm
void SanPham::nhap()
{
    cin.ignore();
    cout << "Nhap ma san pham: ";
    getline(cin, maSP);
    cout << "Nhap ten san pham: ";
    getline(cin, tenSP);
    cout << "Nhap gia: ";
    cin >> gia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

// Xuất thông tin sản phẩm
void SanPham::xuat() const
{
    cout << left
         << setw(15) << maSP
         << setw(30) << tenSP
         << setw(15) << fixed << setprecision(2) << gia      //Làm tròn giá sp dến 2 số thập phân 
         << setw(10) << soLuong
         << endl;
}

