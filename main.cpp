#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "QuanLi.h"

int main()
{
    QuanLy ql;

    ql.docSanPham();
    ql.docDonHang();

    ql.menu();

    return 0;
}