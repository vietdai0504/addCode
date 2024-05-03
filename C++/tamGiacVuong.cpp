#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
float luyThua(int a)
{
    return a*a;
}
class Point{
    public: int a,b;
    void nhap(ifstream& inp)

    {
        inp >> a >> b;
    }

};
class pointList : public Point {
    public: Point points[100]; int count = 0, n = 0;
    void nhapFull(ifstream& inp)
    {
        while(!inp.eof())
        {
            points[n].nhap(inp);
            n++;
        }
    }
    float doDaiB(int i, int j)
    {
        return (float)((luyThua(points[i].a-points[j].a)+luyThua(points[i].b-points[j].b)));
    }
    void tamGiacVuong(ofstream& out)
    {
        for (int i = 0;i<n-2;i++)
        {
            for (int j = i + 1 ; j < n - 1; j++)
            {
                for (int k = j + 1;k < n;k++)
                {
                    float AB = doDaiB(i,j), AC = doDaiB(i,k), BC = doDaiB(j,k);
                    if (((AB+AC) == BC) || ((AB+BC) == AC) || ((BC+AC) == AB))
                    {
                        count++;
                    }
                }
            }
        }
        out<<count<<" ";
    }
};
int main()
{
    ifstream inp("InpPoint.txt");
    ofstream out("OutPoint.txt");
    pointList point;
    point.nhapFull(inp);
    point.tamGiacVuong(out);
    inp.close();
    out.close();
}