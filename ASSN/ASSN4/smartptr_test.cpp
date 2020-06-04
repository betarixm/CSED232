#include <iostream>
#define DeallocMessage
#include "SmartClass.h"

using namespace std;

void constructortests()
{
    cout << "[+] constructor test" << endl;
    SmartMatrix<int> none;
    {
        SmartMatrix<int> mat(none);
        auto mat2 = mat;
        mat = mat2; //mat is freed before assignment

        SmartMatrix<int> mat3(2, 2);
        cout << mat3; //0 0 0 0
    }
    //scope exit : mat3 is firstly freed
    //scope exit : mat2 is secondly freed
    //scope exit : mat is lastly freed
    int arr[] = {1, 2, 3, 4};
    SmartMatrix<int> mat4(2, 2, arr);
    cout << mat4;//1 2 3 4
}
//scope exit : mat4 is firstly freed
//scope exit : none is lastly freed

void calctests()
{
    cout << "[+] calculation test" << endl;
    int arr[] = {1, 2, 3, 4};
    SmartMatrix<int> mat(2, 2, arr);
    int arr2[] = {1, 1, 2, 2};
    SmartMatrix<int> mat2(2, 2, arr2);
    cout << mat << mat2; // 1 2 3 4 1 1 2 2
    cout << "Addition\n" << mat + mat2; //2 3 5 6 //mat+mat2 is freed
    cout << "Subtraction\n" << mat - mat2; // 0 1 1 2 //mat-mat2 is freed
    cout << "Multiplication\n" << mat * 2; // 2 4 6 8 //mat*2 is freed
    cout << 3 * mat; //3 6 9 12 //3*mat is freed
    cout << "Matrix Multiplication\n" << mat * mat2; // 5 5 11 11 // mat*mat2 is freed
    cout << "Inverse\n" << mat.Inverse(); //mat.Inverse() is freed
}
//scope exit : mat2 is freed
//scope exit : mat is freed

void othertests()
{
    cout << "[+] Other Tests" << endl;
    int arr[] = {1, 2, 3, 4};
    SmartMatrix<int> mat(2, 2, arr);
    int newrow[] = {5,6};
    int newcol[] = {10, 11, 12};
    auto newmat = mat;
    cout << mat; // 1 2 3 4
    cout << "AddRow" << endl;
    mat.AddRow(newrow); //I use SmartArray to copy the old values, thus Deallocation message is here. It's not nessary.
    cout << mat; // 1 2 3 4 5 6
    cout << newmat; // 1 2 3 4
    cout << "AddCol" << endl;
    mat.AddCol(newcol); //I use SmartArray to copy the old values, thus Deallocation message is here. It's not nessary.
    cout << mat; //1 2 10 3 4 11 5 6 12
    cout << newmat; // 1 2 3 4
}
//scope exit : newmat is freed
//scope exit : mat is freed
int main()
{
    cout.setf(ios_base::unitbuf);
    constructortests();
    calctests();
    othertests();
    return 0;
}