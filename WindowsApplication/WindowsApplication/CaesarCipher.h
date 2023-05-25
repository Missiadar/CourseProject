#pragma once
#include <string>
using namespace std;
ref class CaesarCipher{
public:
	static string Encrypt(string message, int key);
	static string Decrypt(string ciphertext, int key);
};

