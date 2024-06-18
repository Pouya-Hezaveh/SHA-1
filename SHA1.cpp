#include <string>
#include <iostream>
using namespace std;

unsigned int h[4];
string input_data;

void getInputHashParameters()
{
    for (int i = 0; i <= 4; i++)
    {
        cout << "Input the H[" << i << "]: ";
        cin >> h[i];
    }
}
void getInputData()
{
    cout << "Input Data:\n";
    getline(cin,input_data);
    // I wrote this twice because the inputted endline of the previous outputs will be read by the first getline().
    getline(cin,input_data);
}
void getInputs()
{
    getInputHashParameters();
    getInputData();
}

void printOutputs()
{
    cout << "\nDecimal representation of the hash:\n";
    for (int i = 0; i <= 4; i++)
    {
        cout << h[i] << ' ';
    }
    cout<<'\n';
}

int main()
{
    getInputs();
    printOutputs();
    return 0;
}
