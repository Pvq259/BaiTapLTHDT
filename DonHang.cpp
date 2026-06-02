#include "DonHang.h"
#include <iostream>


using namespace std;

DonHang::DonHang()
{
    maDH = "";
}

string DonHang::getMaDH() const
{
    return maDH;
}

void DonHang::setMaDH(string ma)
{
    maDH = ma;
}
vector<ChiTietDonHang>& DonHang::getDSChiTiet()
{
    return dsChiTiet;
}
void DonHang::nhap()
{
    cout << "Ma don hang: ";
    getline(cin, maDH);

    int n;

    cout << "So luong san pham: ";
    cin >> n;

    cin.ignore();

    dsChiTiet.clear();

    for (int i = 0; i < n; i++)
    {
        ChiTietDonHang ct;

        cout << "\nMa san pham: ";
        getline(cin, ct.maSP);

        cout << "So luong: ";
        cin >> ct.soLuong;

        cin.ignore();

        dsChiTiet.push_back(ct);
    }
}

void DonHang::xuat() const
{
    cout << "\nMa don hang: " << maDH << endl;

    for (auto ct : dsChiTiet)
    {
        cout << "Ma SP: "
             << ct.maSP
             << " - SL: "
             << ct.soLuong
             << endl;
    }
}