#include <iostream>
using namespace std;
enum LOAI{LOAI1,LOAI2,LOAI3};
struct NGAY{
    int ngay, thang, nam;
};
struct TRAICAY{
    char ten[50];
    float dongia, trongluong, thanhtien;
    NGAY ngaynhap;
    LOAI loai;
};
void nhap(TRAICAY& a)
{
    cout<<"Nhap ten trai cay: "; cin>>a.ten;
    cout<<"Nhap don gia: "; cin>>a.dongia;
    cout<<"Nhap trong luong: "; cin>>a.trongluong;
    cout<<"Nhap ngay nhap: "; cin>>a.ngaynhap.ngay;
    cout<<"Nhap thang nhap: "; cin>>a.ngaynhap.thang;
    cout<<"Nhap nam nhap: "; cin>>a.ngaynhap.nam;
    int x;
    cout<<"Nhap loai trai cay(0:LOAI1, 1:LOAI2, 2:LOAI3): "; cin>>x;
    switch(x)
    {
        case 0:
            a.loai = LOAI1; break;
        case 1:
            a.loai = LOAI2; break;
        case 2: 
            a.loai = LOAI3; break;
    }
}
void phaiTra(TRAICAY& a)
{
    float heso;
    switch(a.loai)
    {
        case LOAI1:
            heso = 1;
            break;
        case LOAI2:
            heso = 0.75;
            break;
        case LOAI3:
            heso = 0.5;
            break;
    }
    a.thanhtien = a.dongia*a.trongluong*heso;
}
void print(TRAICAY& a)
{
    cout<<"Ten trai cay: "<<a.ten<<endl;
    cout<<"Trong luong: "<<a.trongluong<<endl;
    cout<<"Ngay thang nam nhap: "<<a.ngaynhap.ngay<<" "<<a.ngaynhap.thang<<" "<<a.ngaynhap.nam<<endl;
    cout<<"Loai trai cay: ";
    switch(a.loai)
    {
        case LOAI1:
            cout<<"LOAI 1"<<endl;
            break;
        case LOAI2:
            cout<<"LOAI 2"<<endl;
            break;
        case LOAI3:
            cout<<"LOAI 3"<<endl;
            break;
    }
    cout<<"Thanh tien: "<<a.thanhtien<<endl;
}
int main()
{
    TRAICAY cam;
    nhap(cam);
    phaiTra(cam);
    print(cam);
}