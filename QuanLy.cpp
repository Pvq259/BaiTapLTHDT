#include "QuanLy.h"
#include <iostream>
#include <fstream>
#include <iomanip>                  //dùng setw
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


void QuanLy::themSanPham()
{
    SanPham sp;
    sp.nhap();

    if (timSanPham(sp.getMaSP()) != -1)
    {
        cout << "Ma san pham da ton tai!\n";
        return;
    }

    dsSanPham.push_back(sp);

    cout << "\nThem san pham thanh cong!\n";

    luuSanPham();

    char ch;
    cout << "\nBan co muon them san pham nay vao don hang khong? (Y/N): ";
    cin >> ch;

    if (ch == 'Y' || ch == 'y')
    {
        string maDH;
        int soLuong;
        double sotien;

        cin.ignore();

        cout << "Nhap ma don hang: ";
        getline(cin, maDH);

        cout << "Nhap so luong mua: ";
        cin >> soLuong;

        int vtDH = timDonHang(maDH);

        if (vtDH == -1)
        {
            DonHang dh;

            dh.setMaDH(maDH);
            dh.themChiTiet(sp.getMaSP(), soLuong );

            dsDonHang.push_back(dh);

            cout << "Da tao don hang moi va them san pham thanh cong!\n";
        }
        else
        {
            dsDonHang[vtDH].themChiTiet(sp.getMaSP(), soLuong );

            cout << "Them vao don hang thanh cong!\n";
        }
        luuDonHang();
    }
}


//Hiển thị sản phẩm
void QuanLy::hienThiSanPham() const
{
    if (dsSanPham.empty())
    {
        cout << "\nDanh sach rong!\n";
        return;
    }

    cout << "\n=======================================================================\n";

    cout << left
         << setw(15) << "Ma SP"
         << setw(30) << "Ten SP"
         << setw(15) << "Gia"
         << setw(10) << "SL";

    cout << endl;

    cout << "=======================================================================\n";

    for (const SanPham& sp : dsSanPham)
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

// Tìm đơn hàng
int QuanLy::timDonHang(string ma)
{
    for(int i = 0; i < dsDonHang.size(); i++)
    {
        if(dsDonHang[i].getMaDH() == ma)
            return i;
    }

    return -1;
}

//Thêm đơn hàng
void QuanLy::themDonHang()
{
    DonHang dh;

    dh.nhap();

    if(timDonHang(dh.getMaDH()) != -1)
    {
        cout << "Ma don hang da ton tai!\n";
        return;
    }

    dsDonHang.push_back(dh);

    cout << "Them thanh cong! " << endl;
}
double QuanLy::tinhTongTienDonHang(const DonHang& dh)
{
    double tong = 0;

    for (auto ct : dh.getDSChiTiet())
    {
        int vt = timSanPham(ct.maSP);

        if (vt != -1)
        {
            tong += dsSanPham[vt].getGia() * ct.soLuong;
        }
    }

    return tong;
}

//Hiển thị đơn hàng
void QuanLy::hienThiDonHang()
{
    cout << "\n===== DANH SACH DON HANG =====\n";

    for(auto dh : dsDonHang) 
    {
        dh.xuat();
        cout << "Tong tien: "<< fixed << setprecision(2) << tinhTongTienDonHang(dh) << endl;
    }
}

//Xóa đơn hàng
void QuanLy::xoaDonHang()
{
    string ma;

    cout << "Nhap ma don hang: ";
    getline(cin, ma);

    int vt = timDonHang(ma);

    if(vt == -1)
    {
        cout << "Khong tim thay!\n";
        return;
    }

    dsDonHang.erase(dsDonHang.begin() + vt);

    cout << "Da xoa!\n";
}


// Các hàm lưu

//Sản Phẩm
void QuanLy::luuSanPham()
{
    ofstream fout("SanPham.txt");

    if (!fout)
    {
        cout << "Khong mo duoc file!\n";
        return;
    }

    fout << dsSanPham.size() << endl;

    for (auto sp : dsSanPham)
    {
        fout << sp.getMaSP() << endl;
        fout << sp.getTenSP() << endl;
        fout << sp.getGia() << endl;
        fout << sp.getSoLuong() << endl;
    }

    fout.close();
}

//Đơn hàng
void QuanLy::luuDonHang()
{
    ofstream fout("DonHang.dat");

    if (!fout)
        return;

    fout << dsDonHang.size() << endl;

    for (auto dh : dsDonHang)
    {
        fout << dh.getMaDH() << endl;

        vector<ChiTietDonHang> ds = dh.getDSChiTiet();

        fout << ds.size() << endl;

        for (auto ct : ds)
        {
            fout << ct.maSP << endl;
            fout << ct.soLuong << endl;
        }
    }
    fout.close();
}


// Các hàm đọc 
//Sản Phẩm
void QuanLy::docSanPham()
{
    ifstream fin("SanPham.txt");
    if (!fin)
        return;
    dsSanPham.clear();
    int n;
    fin >> n;
    fin.ignore();
    for (int i = 0; i < n; i++)
    {
        string ma;
        string ten;
        double gia;
        int sl;
        getline(fin, ma);
        getline(fin, ten);   
        fin >> gia;
        fin >> sl;
        fin.ignore();
        SanPham sp(ma, ten, gia,sl);
        dsSanPham.push_back(sp);
    }
    fin.close();
}


//Đơn hàng
void QuanLy::docDonHang()
{
    ifstream fin("DonHang.dat");

    if (!fin)
        return;

    dsDonHang.clear();

    int soDH;

    fin >> soDH;
    fin.ignore();

    for (int i = 0; i < soDH; i++)
    {
        DonHang dh;

        string maDH;

        getline(fin, maDH);

        dh.setMaDH(maDH);

        int n;

        fin >> n;
        fin.ignore();

        for (int j = 0; j < n; j++)
        {
            string maSP;
            int soLuong;
            double sotien;
            getline(fin, maSP);

            fin >> soLuong;
            fin >>sotien;
            fin.ignore();

            dh.themChiTiet(maSP, soLuong );
        }

        dsDonHang.push_back(dh);
    }

    fin.close();
}
// Hàm sửa dơn hàng
void QuanLy::suaDonHang()
{
    string maDH;
    cout << "Nhap ma don hang can sua: ";
    getline(cin, maDH);

    int vtDH = timDonHang(maDH);

    if (vtDH == -1)
    {
        cout << "Khong tim thay don hang!\n";
        return;
    }

    char chon;

    do
    {
        cout << "\n===== SUA DON HANG =====\n";
        cout << "a. Them mot san pham vao don hang\n";
        cout << "b. Sua so luong san pham\n";
        cout << "c. Xoa san pham khoi don hang\n";
        cout << "d. Thoat\n";

        cout << "Nhap lua chon: ";
        cin >> chon;
        cin.ignore();

        switch (chon)
        {
        case 'a':
        case 'A':
        {
            string maSP;
            int soLuong;

            cout << "Nhap ma san pham: ";
            getline(cin, maSP);

            if (timSanPham(maSP) == -1)
            {
                cout << "San pham khong ton tai!\n";
                break;
            }

            cout << "Nhap so luong: ";
            cin >> soLuong;
            cin.ignore();

            dsDonHang[vtDH].themChiTiet(maSP, soLuong);

            cout << "Them san pham thanh cong!\n";
            luuDonHang();

            break;
        }

        case 'b':
        case 'B':
        {
            string maSP;
            int soLuongMoi;

            cout << "Nhap ma san pham can sua: ";
            getline(cin, maSP);

            cout << "Nhap so luong moi: ";
            cin >> soLuongMoi;
            cin.ignore();

            if (dsDonHang[vtDH].suaSoLuong(maSP, soLuongMoi))
            {
                cout << "Cap nhat thanh cong!\n";
                luuDonHang();
            }
            else
            {
                cout << "Khong tim thay san pham trong don hang!\n";
            }

            break;
        }

        case 'c':
        case 'C':
        {
            string maSP;

            cout << "Nhap ma san pham can xoa: ";
            getline(cin, maSP);

            if (dsDonHang[vtDH].xoaChiTiet(maSP))
            {
                cout << "Xoa thanh cong!\n";
                luuDonHang();
            }
            else
            {
                cout << "Khong tim thay san pham trong don hang!\n";
            }

            break;
        }

        case 'd':
        case 'D':
            cout << "Thoat sua don hang!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (chon != 'd' && chon != 'D');
}



//Menu

void QuanLy::menu()
{
    int chon;

    do
    {
        try
        {
            cout << "\n========== MENU ==========\n";
            cout << "1. Them san pham\n";
            cout << "2. Sua san pham\n";
            cout << "3. Xoa 1 san pham\n";
            cout << "4. Nhap thong tin don hang\n";
            cout << "5. Sua thong tin don hang\n";
            cout << "6. Xoa don hang\n";
            cout << "7. Liet ke san pham \n";
            cout << "8. Liet ke don hang\n";
            cout << "0. Thoat\n";

            cout << "Nhap lua chon : ";
            cin >> chon;

            if (cin.fail())
            {
                throw "Lua chon phai la so!";
            }
            cin.ignore();

            switch (chon)
            {
            case 1:
                themSanPham();
                break;
            case 7:
                hienThiSanPham();
                break;
            case 2:
                suaSanPham();
                break;
            case 3:
                xoaSanPham();
                break;
            case 4:
                themDonHang();
                break;
            case 8:
                hienThiDonHang();
                break;
            case 5:
                suaDonHang();
                break;
            case 6:
                xoaDonHang();
                break;
            case 0:
                luuSanPham();
                luuDonHang();
                cout << "Tam biet !\n";
                break;
            default:
                throw "Lua chon khong hop le!";
            }
        }
        catch (const char* loi)
        {
            cout << "\nLoi: " << loi << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (chon != 0);
}
