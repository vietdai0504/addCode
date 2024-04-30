#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
float bp(int a)
{
    return a*a;
}
class Pointer{
    public: int a,b,c;
    void getIn(ifstream& fin)
    {
        fin>>a>>b>>c;
    }
    // void printL()
    // {
    //     cout<<a<<" "<<b<<" "<<c<<endl;
    // }
};
class ListPointer : public Pointer{
    public: vector<Pointer> points; int n = 0;
    void getFullPoint(ifstream& fin)
    {
        while(!fin.eof())
        {
            Pointer point;
            point.getIn(fin);
            points.push_back(point);
            n++;
        }
    }
    float kc(int i, int j)
    {
        return (float)sqrt(bp(points[i].a-points[j].a)+bp(points[i].b-points[j].b)+bp(points[i].c-points[j].c));
    }
    void result(ofstream& fout)
    {
        vector<Pointer> kq;
        float max = kc(0,1);
        kq.push_back(points[0]);
        kq.push_back(points[1]);
        for (int i = 0;i<n-1;i++)
        {
            for (int j = i;j<n;j++)
            {
                float kcP = kc(i,j);
                if (kcP > max)
                {
                    kq.clear();
                    kq.push_back(points[i]);
                    kq.push_back(points[j]);
                    max = kcP;
                }   
            }
        }
        for (int i = 0;i<2;i++)
        {
            fout<<"("<<kq[i].a<<","<<kq[i].b<<","<<kq[i].c<<") ";
        }
    }
};
int main()
{
    ifstream fin("InpDis.txt");
    ofstream fout("OutDis.txt");
    ListPointer ListP;
    ListP.getFullPoint(fin);
    // for (int i = 0;i<ListP.n;i++)
    // {
    //     ListP.points[i].printL();
    // }
    ListP.result(fout);
}