#pragma once
#include <string>
using namespace std;
ref class VigenereCipher{
public:
	static string Encrypt(string message, string key);
	static string Decrypt(string ciphertext, string key);
};

