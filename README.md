# SHA-1

This is a C++ scratch file that hashes data using SHA-1 function.

## How It Works

This code is designed to get 4 encryption keys and the data (in form of a string with the space character) from the terminal and then generates the hash based on the keys and prints it in binary, decimal and hexadecimal representations.

### Example

#### Input

```c
0
0
0
0
Hello World!
```

```c
// Because of the interactive input requests, in terminal result looks like this:
Input 0-th key: 0
Input 1-th key: 0
Input 2-th key: 0
Input 3-th key: 0
Input Data:
Hello World!
```

#### Output

```text
Decimal representation of the hash:
2129681083 1998489949 2135663957 2363037805 2616391758

Binary representation of the hash:
01111110111100000101101010111011 01110111000111101000100101011101 01111111010010111010010101010101 10001100110110010001100001101101 10011011111100101111100001001110

Hexadecimal representation of the hash:
7ef05abb 771e895d 7f4ba555 8cd9186d 9bf2f84
```

## Note

### ⚠️ SHA-1 is outdated for security purposes

NIST has set the date of Dec. 31, 2030 to remove SHA-1 support from all software and hardware devices. The once-widely used algorithm is now easy to crack, making it unsafe to use in security contexts.
[Read more.](https://www.darkreading.com/cyber-risk/nist-finally-retires-sha-1)
