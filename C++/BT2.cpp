#include <iostream>
#include <fstream>
using namespace std;
class Matrix{
    public: int N, M, K; int matrix[100][100];
    void getInp(ifstream& fin)
    {
        fin>>N>>M>>K;
        for (int i = 0; i < N;i++)
        {
            for (int j = 0;j<M;j++)
            {
                fin>>matrix[i][j];
            }
        }
        // for (int i = 0;i<N;i++)
        // {
        //     for (int j = 0;j<M;j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    void maxRow_K(ofstream& fout)
    {
        int max = matrix[K-1][0];
        for (int i = 0 ; i < M ; i++)
        {
            if (matrix[K-1][i] > max)
            {
                max = matrix[K-1][i];
            }
        }
        fout<<max<<" ";
    }
    void minCol_K(ofstream& fout)
    {
        int min = matrix[0][K-1];
        for (int i = 0 ; i < N ; i++)
        {
            if (matrix[i][K-1] < min)
            {
                min = matrix[i][K-1];
            }
        }
        fout<<min<<" ";
    }
};
int main()
{
    ifstream fin("InpMinMax.txt");
    ofstream fout("OutMinMax.txt");
    Matrix matrix;
    matrix.getInp(fin);
    matrix.maxRow_K(fout);
    matrix.minCol_K(fout);
}