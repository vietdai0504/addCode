#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class PersonalProfile {
private:
    int MaSV, CaiThien;
    double DTB;
    string Ten, GT, NgaySinh, Lop, Khoa, HoanThanh;

public:
    int getID()
    {
        return MaSV;
    }
    double getDTB()
    {
        return DTB;
    }
    void getInfo(ifstream& fin) {
        string str, info;
        getline(fin, str);
        stringstream ss(str);
        getline(ss, info, ',');
        MaSV = stoi(info);
        getline(ss, Ten, ',');
        getline(ss, GT, ',');
        getline(ss, NgaySinh, ',');
        getline(ss, Lop, ',');
        getline(ss, Khoa, ',');
        getline(ss, info, ',');
        DTB = stod(info);
        getline(ss, HoanThanh, ',');
        getline(ss, info, ',');
        CaiThien = stoi(info);
    }

    void write(ofstream& fout)
    {
        fout<<MaSV<<","<<Ten<<","<<GT<<","<<NgaySinh<<","<<Lop<<","<<Khoa<<","<<DTB<<","<<HoanThanh<<","<<CaiThien<<endl;
    }
    void display() {
        cout << left << setw(20) << "Ma sinh vien " << "| " << MaSV << endl;
        cout << left << setw(20) << "Ten " << "| " << Ten << endl;
        cout << left << setw(20) << "Gioi tinh " << "| " << GT << endl;
        cout << left << setw(20) << "Ngay Sinh " << "| " << NgaySinh << endl;
        cout << left << setw(20) << "Lop " << "| " << Lop << endl;
        cout << left << setw(20) << "Khoa " << "| " << Khoa << endl;
        cout << left << setw(20) << "Diem trung binh " << "| " << DTB << endl;
        cout << left << setw(20) << "Hoan thanh " << "| " << HoanThanh << endl;
        cout << left << setw(20) << "Cai thien " << "| " << CaiThien << endl;
    }
};

class DSSV {
public:
    static const int MAX = 100;
    int n = 0;
    PersonalProfile ds[MAX];

    void getfullInfo(ifstream& fin1,ifstream& fin2, ofstream& fout) {
        string str;
        getline(fin1, str);
        fout << str << endl;
        while (!fin1.eof()) {
            ds[n++].getInfo(fin1);
        }
        while (!fin2.eof()) {
            PersonalProfile check;
            check.getInfo(fin2);
            int id = check.getID();
            bool test = true;
            for (int i = 0; i < n; i++) {
                if (id == ds[i].getID()) {
                    test = false;
                    break;
                }
            }
            if (test) {
                ds[n++] = check;
            }
        }

    }

    void writeFile(ofstream& fout)
    {
        for (int i = 0;i<n;i++)
        {
            ds[i].write(fout);
        }
    }
    void displayFull() {
        for (int i = 0; i < n; ++i) {
            std::cout<<left<<setw(20)<<"STT "<<"| "<<i+1<<endl;
            ds[i].display();
            cout<<endl;
        }
    }

    void filterDTB(double point)
    {
        cout<<"Cac sinh vien co diem thap hon "<<point<<" :"
        for (int i = 0; i<n;i++)
        {
            if (ds[i].getDTB()>point)
            {
                ds[i].display();
                cout<<endl;
            }
        }
    }
};

int main() {
    ifstream fin1("InitialInfo.csv");
    ifstream fin2("MoreInfo.csv");
    ofstream fout("UpdateInfo.csv");
    DSSV ds;
    ds.getfullInfo(fin1,fin2,fout);
    ds.displayFull();
    ds.writeFile(fout);
    double point; 
    cout<<"Nhap diem muon loc: "; cin>>point;
    ds.filterDTB(point);

    fin1.close(); fin2.close(); fout.close();
}