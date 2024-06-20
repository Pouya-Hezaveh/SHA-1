#include <iostream>  // cin, cout
#include <algorithm> //swap
using namespace std;

// ========== UTILITY FUNCTIONS ==========
char switchToHexadecimal(int x)
{
    switch (x)
    {
    case 0:
        return '0';
        break;
    case 1:
        return '1';
        break;
    case 2:
        return '2';
        break;
    case 3:
        return '3';
        break;
    case 4:
        return '4';
        break;
    case 5:
        return '5';
        break;
    case 6:
        return '6';
        break;
    case 7:
        return '7';
        break;
    case 8:
        return '8';
        break;
    case 9:
        return '9';
        break;
    case 10:
        return 'a';
        break;
    case 11:
        return 'b';
        break;
    case 12:
        return 'c';
        break;
    case 13:
        return 'd';
        break;
    case 14:
        return 'e';
        break;
    case 15:
        return 'f';
        break;
    }
    return 'x';
}

string convertTo32bit(unsigned int x)
{
    string result = "";

    for (int i = 0; i < 32; i++)
    {
        if (x % 2)
            result += '1';
        else
            result += '0';
        x /= 2;
    }

    for (int i = 0; i < result.length() / 2; i++)
        swap(result[i], result[result.length() - i - 1]);

    return result;
}

string convertToHexadecimal(unsigned int x)
{

    char temp[8];
    for (int i = 0; i < 8; i++)
    {
        temp[i] = switchToHexadecimal(x % 16);
        x /= 16;
    }

    string result = "";
    for (int i = 7; i >= 0; i--)
        result += temp[i];

    return result;
}
// This function shiftes x, i bits to the left, rotational.
unsigned int rotateToLeft(int i, unsigned int x)
{
    return (x << i) | (x >> (32 - i));
}

// ========== Program ==========
unsigned int h[5] = {0,
                     0,
                     0,
                     0,
                     0};
unsigned int k[4]; // Encryption Key
unsigned int w[80];
string input_data;

void getInputKeys()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Input " << i << "-th key: ";
        cin >> k[i];
    }
}
void getInputData()
{
    cout << "Input Data:\n";

    getline(cin, input_data);
    // I wrote this twice because the inputted endline of the previous outputs will be read by the first getline().
    getline(cin, input_data);
}
void getInputs()
{
    getInputKeys();
    getInputData();
}

unsigned int fPlusK(int i, unsigned int B, unsigned int C, unsigned int D)
{
    if (0 <= i && i <= 19)
        return ((B & C) | (~B & D)) + k[0];
    if (20 <= i && i <= 39)
        return (B ^ C ^ D) + k[1];
    if (40 <= i && i <= 59)
        return ((B & C) | (B & D) | (C & D)) + k[2];
    if (60 <= i && i <= 79)
        return (B ^ C ^ D) + k[3];
    return -1;
}

void processWords(unsigned int block[16])
{
    for (int i = 0; i < 16; i++)
        w[i] = block[i];
    for (int i = 16; i < 80; i++)
        w[i] = rotateToLeft(1, (w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16]));
}

void processBlock(unsigned int block[16])
{
    processWords(block);
    unsigned int a = h[0];
    unsigned int b = h[1];
    unsigned int c = h[2];
    unsigned int d = h[3];
    unsigned int e = h[4];

    for (int i = 0; i < 80; i++)
    {
        unsigned int temp = rotateToLeft(5, a) + fPlusK(i, b, c, d) + e + w[i];
        e = d, d = c, c = rotateToLeft(30, b), b = a, a = temp;
    }

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
}

unsigned int createPadding()
{
    // This function determines the data that would be added to complete the data-block.
    // 0 is my default value.
    return 0;
}

void runHashProcess()
{
    for (int i = 0; i < input_data.length(); i += 64)
    {
        // This part picks the current block to be hashed.
        unsigned int current_block[16];
        for (int j = 0; j < 64; j++)
        {
            if (i + j < input_data.length())
            {
                current_block[(i + j) / 4] *= 256;
                current_block[(i + j) / 4] += input_data[i];
            }
            else
            {
                current_block[(i + j) / 4] *= 256;
                current_block[(i + j) / 4] += createPadding();
            }
        }

        processBlock(current_block);
    }
}

void printResults()
{
    cout << "\nDecimal representation of the hash:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << h[i] << ' ';
    }

    cout << "\n\nBinary representation of the hash:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << convertTo32bit(h[i]) << ' ';
    }

    cout << "\n\nHexadecimal representation of the hash:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << convertToHexadecimal(h[i]) << ' ';
    }
    cout << "\n\n";
}

int main()
{
    getInputs();
    runHashProcess();
    printResults();
    return 0;
}
