#include<windows.h>
#include<io.h>
#include "pch.h"
#include<fstream>
#include<iostream>
using namespace std;

//#include<unistd.h>

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

#define MAX_SIZE 1024

/***************************************************************************
 * Function Name: Encrypt_Caesar_Cipher
 * Date: 14/09/2025
 * Author: Shreya Siddharth Sasane
 * Description: Encrypts the contents of a source file using Caesar Cipher
 *              and writes the encrypted data to a destination file.
 * Parameters:
 *    Src  - char*: path to the source file to be encrypted
 *    Dest - char*: path to the destination file to save encrypted data
 *    key  - int: the integer key used to shift each byte in the cipher
 ***************************************************************************/
extern "C" __declspec(dllexport) void Encrypt_Caesar_Cipher(char*, char*, int);

void Encrypt_Caesar_Cipher(char* Src, char* Dest, int key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    // Open source file in read-only mode
    fdSrc = _open(Src, _O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    // Open destination file with write permissions, create or truncate it
    fdDest = open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if (fdDest == -1)
    {
        printf("Unable to create destination file\n");
        return;
    }

    // Read source file in chunks, encrypt each byte, and write to destination
    while ((iRet = read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        printf("%d", iRet);

        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] + key) % 256;  // Caesar cipher encryption
        }

        write(fdDest, Buffer, iRet);
    }

    // Close the file descriptors
    close(fdSrc);
    close(fdDest);
}

/***************************************************************************
 * Function Name: Decrypt_Caesar_Cipher
 * Date: 14/09/2025
 * Author: Shreya Siddharth Sasane
 * Description: Decrypts the contents of a source file encrypted with Caesar
 *              Cipher and writes the decrypted data to a destination file.
 * Parameters:
 *    Src  - char*: path to the encrypted source file
 *    Dest - char*: path to the destination file to save decrypted data
 *    key  - int: the integer key used to shift each byte back in the cipher
 ***************************************************************************/
extern "C" __declspec(dllexport) void Decrypt_Caesar_Cipher(char*, char*, int);

void Decrypt_Caesar_Cipher(char* Src, char* Dest, int key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    // Open encrypted source file in read-only mode
    fdSrc = open(Src, _O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    // Open destination file with write permissions, create or truncate it
    fdDest = open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if (fdDest == -1)
    {
        printf("Unable to create destination file\n");
        return;
    }

    // Read encrypted file, decrypt each byte, and write to destination
    while ((iRet = read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        printf("%d", iRet);

        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] - key) % 256;  // Caesar cipher decryption
        }

        write(fdDest, Buffer, iRet);
    }

    // Close the file descriptors
    close(fdSrc);
    close(fdDest);
}

/***************************************************************************
 * Function Name: Encrypt_XOR_Cipher
 * Date: 14/09/2025
 * Author: Shreya Siddharth Sasane
 * Description: Encrypts the contents of a source file using XOR Cipher
 *              with a single character key and writes to a destination file.
 * Parameters:
 *    Src  - char*: path to the source file to be encrypted
 *    Dest - char*: path to the destination file to save encrypted data
 *    key  - char: single character key used for XOR operation
 ***************************************************************************/
extern "C" __declspec(dllexport) void Encrypt_XOR_Cipher(char*, char*, char);

void Encrypt_XOR_Cipher(char* Src, char* Dest, char key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    // Open source file in read-only mode
    fdSrc = open(Src, _O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    // Open destination file with write permissions, create or truncate it
    fdDest = open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if (fdDest == -1)
    {
        printf("Unable to create destination file\n");
        return;
    }

    // Read source file, XOR each byte with key, and write to destination
    while ((iRet = read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        printf("%d", iRet);

        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ key;  // XOR encryption
        }

        write(fdDest, Buffer, iRet);
    }

    // Close the file descriptors
    close(fdSrc);
    close(fdDest);
}

/***************************************************************************
 * Function Name: Decrypt_XOR_Cipher
 * Date: 14/09/2025
 * Author: Shreya Siddharth Sasane
 * Description: Decrypts the contents of a source file encrypted with XOR Cipher
 *              using the same key and writes decrypted data to destination file.
 * Parameters:
 *    Src  - char*: path to the encrypted source file
 *    Dest - char*: path to the destination file to save decrypted data
 *    key  - char: single character key used for XOR operation
 ***************************************************************************/
extern "C" __declspec(dllexport) void Decrypt_XOR_Cipher(char*, char*, char);

void Decrypt_XOR_Cipher(char* Src, char* Dest, char key)
{
    int fdSrc = 0, fdDest = 0;
    int iRet = 0, i = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    // Open encrypted source file in read-only mode
    fdSrc = open(Src, _O_RDONLY);
    if (fdSrc == -1)
    {
        printf("Unable to open source file \n");
        return;
    }

    // Open destination file with write permissions, create or truncate it
    fdDest = open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    if (fdDest == -1)
    {
        printf("Unable to create destination file\n");
        return;
    }

    // Read encrypted file, XOR each byte with key to decrypt, write to dest
    while ((iRet = read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        printf("%d", iRet);

        for (i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ key;  // XOR decryption (same as encryption)
        }

        write(fdDest, Buffer, iRet);
    }

    // Close the file descriptors
    close(fdSrc);
    close(fdDest);
}
