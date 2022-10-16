#include <iostream> 
#include <fstream> 
#include <iostream> 
using namespace std;

int main()
{
    int n,m;
    cout << "Nhap so dinh cua do thi 1: \n";
    cin >> n;
    cout << "Nhap so dinh cua do thi 2: ";
    cin >> m;
    ofstream input1 ("input1.txt");
    input1 << n << "\n";
    input1 << "0 1 0 1 1 0\n1 0 1 0 1 1\n0 1 0 1 0 1\n1 0 1 0 1 0\n1 1 0 1 0 1\n0 1 1 0 1 0";
    input1.close();
    ofstream input2 ("input2.txt");
    input2 << m << "\n";
    input2 << "0 1 1 0 1\n0 0 0 1 0\n0 1 0 0 0\n0 0 1 0 1\n1 0 0 1 0";
    input2.close();
    return 0;
}