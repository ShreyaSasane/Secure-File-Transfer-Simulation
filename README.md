===========================================================================
EncryptDecrypt DLL Project
===========================================================================

Author       : Shreya Siddharth Sasane
Date         : 14/09/2025
Description  :
    This project consists of a DLL that implements encryption and decryption
    functions using two classical ciphers: Caesar Cipher and XOR Cipher.
    The DLL exports functions to encrypt and decrypt files with given keys.
    A separate client application dynamically loads this DLL and calls
    these functions using function pointers obtained via GetProcAddress.

===========================================================================

Project Structure:
------------------
1. EncryptDecrypt DLL source code (EncryptDecrypt.cpp):
    - Encrypt_Caesar_Cipher
    - Decrypt_Caesar_Cipher
    - Encrypt_XOR_Cipher
    - Decrypt_XOR_Cipher

2. Client Application source code (main.cpp):
    - Dynamically loads EncryptDecrypt.dll
    - Retrieves function pointers for encryption/decryption functions
    - Invokes the encryption function to encrypt a file

===========================================================================

DLL Functionality:
------------------

1. Encrypt_Caesar_Cipher(char* Src, char* Dest, int key)
   - Reads the source file byte-by-byte
   - Shifts each byte by 'key' using modulo 256 (Caesar cipher)
   - Writes the encrypted content to the destination file

2. Decrypt_Caesar_Cipher(char* Src, char* Dest, int key)
   - Reads the encrypted source file
   - Reverses the Caesar cipher shift by subtracting 'key'
   - Writes decrypted content to the destination file

3. Encrypt_XOR_Cipher(char* Src, char* Dest, char key)
   - Reads the source file
   - XORs each byte with the single-byte key
   - Writes encrypted data to destination

4. Decrypt_XOR_Cipher(char* Src, char* Dest, char key)
   - Reads the encrypted source file
   - XORs each byte with the same key to decrypt
   - Writes decrypted data to destination

===========================================================================

Client Application:
-------------------
- Loads the DLL using LoadLibrary
- Obtains addresses of encryption and decryption functions using GetProcAddress
- Uses function pointers to call these functions
- Example: Encrypts "input.txt" into "output.txt" with key 21

===========================================================================

Compilation Instructions:
-------------------------
- Compile DLL:
  Use your compiler to build EncryptDecrypt.cpp as a DLL named EncryptDecrypt.dll

- Compile Client:
  Compile main.cpp linking with appropriate Windows libraries (Kernel32.lib, etc.)

===========================================================================

Usage Example:
--------------
1. Place EncryptDecrypt.dll and client executable in the same directory.
2. Ensure input.txt file exists with content to encrypt.
3. Run client executable to encrypt input.txt into output.txt using Caesar cipher or XOR cipher.

===========================================================================

Notes:
------
- This project uses Windows-specific APIs (_open, open, _close, close) and functions like LoadLibrary and GetProcAddress.
- Error handling prints messages on failure to open files or load functions.
- Caesar cipher shifts bytes modulo 256.
- XOR cipher uses a single character key for encryption/decryption.
- Make sure file paths are correct when passing to functions.

===========================================================================

Contact:
--------
For any questions or feedback, contact Shreya Siddharth Sasane.

===========================================================================
