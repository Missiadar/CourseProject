#include "CaesarCipher.h"
#include <string>

string CaesarCipher::Encrypt(string message, int key) {
	string encrypted_message;
	key = (key >= 0) ? key : 26 - (-key % 26);
	for (int i = 0; i < message.size(); i++) {
		if (isalpha(message[i])) {
			if (isupper(message[i])) {
				encrypted_message += (message[i] - 65 + key) % 26 + 65;
			}
			else {
				encrypted_message += (message[i] - 97 + key) % 26 + 97;
			}
		}
		else {
			encrypted_message += message[i];
		}
	}
	return encrypted_message;
}

string CaesarCipher::Decrypt(string ciphertext, int key) {
	string decrypted_message;
	for (int i = 0; i < ciphertext.size(); i++) {
		if (isalpha(ciphertext[i])) {
			if (isupper(ciphertext[i])) {
				decrypted_message += (ciphertext[i] - 65 - key + 26) % 26 + 65;
			}
			else {
				decrypted_message += (ciphertext[i] - 97 - key + 26) % 26 + 97;
			}
		}
		else {
			decrypted_message += ciphertext[i];
		}
	}
	return decrypted_message;
}