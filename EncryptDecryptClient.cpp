#include<windows.h>
#include<iostream>
using namespace std;

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
//#include "pch.h"

/***************************************************************************
 * Function Name: main
 * Date: 14/09/2025
 * Author: Shreya Siddharth Sasane
 * Description: Loads the EncryptDecrypt DLL dynamically, obtains function
 *              pointers for encryption and decryption functions using
 *              GetProcAddress, and calls the encryption function.
 * Parameters: None
 * Return Value: int - exit status of the program (0 = success, -1 = failure)
 ***************************************************************************/
int main()
{
    // Load the DLL named EncryptDecrypt.dll
    HINSTANCE hdll = LoadLibrary(L"EncryptDecrypt.dll");

    if (hdll == NULL)
    {
        std::cout << "Unable to load library\n";
        return -1;
    }

    // Function pointer for Encrypt/Decrypt XOR cipher with char key
    FPTR1 fp = (FPTR1)GetProcAddress(hdll, "Encrypt_Ceaser_Cipher");

    if (fp == NULL)
    {
        std::cout << "Unable to get address of function \n";
        return -1;
    }

    // Overwriting fp with address of Decrypt_Ceaser_Cipher function
    fp = (FPTR1)GetProcAddress(hdll, "Decrypt_Ceaser_Cipher");

    if (fp == NULL)
    {
        std::cout << "Unable to get address of function \n";
        return -1;
    }

    // Function pointer for Encrypt/Decrypt Caesar cipher with int key
    FPTR fp = (FPTR)GetProcAddress(hdll, "Encrypt_XOR_Cipher");

    if (fp == NULL)
    {
        std::cout << "Unable to get address of function \n";
        return -1;
    }

    // Overwriting fp with address of Decrypt_XOR_Cipher function
    fp = (FPTR)GetProcAddress(hdll, "Decrypt_XOR_Cipher");

    if (fp == NULL)
    {
        std::cout << "Unable to get address of function \n";
        return -1;
    }

    // Call the function pointer to encrypt file input.txt to output.txt with key 21
    fp("input.txt","output.txt", 21);

    // Free the loaded DLL
    FreeLibrary(hdll);

    return 0;
}
