#include "SanPham.h"

SanPham::SanPham(){
    maSP = "";
    tenSP = "";
    gia = 0;
}

SanPham::SanPham(string ma, string ten, double gia){
    this->maSP = ma;
    this->tenSP = ten;
    this->gia = gia;
}

string SanPham::getMaSP() const{
    return maSP;
}

string SanPham::getTenSP() const{
    return tenSP;
}

double SanPham::getGia() const{
    return gia;
}

void SanPham::setMaSP(string ma){
    maSP = ma;
}

void SanPham::setTenSP(string ten){
    tenSP = ten;
}

void SanPham::setGia(double gia){
    this->gia = gia;
}

void SanPham::nhap(){
    cout << "Ma san pham: ";
    getline(cin, maSP);

    cout << "Ten san pham: ";
    getline(cin, tenSP);

    cout << "Gia: ";
    cin >> gia;
    cin.ignore();
}

void SanPham::xuat() const {
    cout << "Ma San Pham : "<< maSP <<endl;
    cout << "Ten San Pham : " << tenSP << endl;
    cout << "Gia San Pham : "<< gia << endl;
}

