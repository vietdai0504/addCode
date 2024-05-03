#include <iostream>
using namespace std;
void nhap(int** A, int m, int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<"A["<<i<<"]["<<j<<"]= "; cin>>*(*(A+i)+j);
        }
    }
}
void print(int** A, int m, int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<*(*(A+i)+j)<<" ";
        }
        cout<<endl;
    }
}
int tongAm(int** A, int m, int n)
{
    int sum=0;
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(A[i][j]<0)
                sum+=A[i][j];
        }
    }
    return sum;
}
void chiaBa(int** A, int m, int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (A[i][j]%3==0)
                cout<<"A["<<i<<"]["<<j<<"]= "<<A[i][j]<<" ";
        }
    }
}
int main()
{
    int** A, m, n;
    cout<<"Nhap m, n: "; cin>>m>>n;
    A = new int*[m];
    for (int i = 0;i<m;i++)
    {
        *(A+i) = new int[n];
    }
    nhap(A,m,n);
    print(A,m,n);
    cout<< "tong cac phan tu am trong mang: "<<tongAm(A,m,n)<<endl;
    chiaBa(A,m,n);
}