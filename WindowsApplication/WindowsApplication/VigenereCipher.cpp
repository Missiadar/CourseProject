#include "VigenereCipher.h"
#include <string>

string VigenereCipher::Encrypt(string message, string key) {
    string ciphertext;

    int keyLength = key.length();
    int messageLength = message.length();

    for (int i = 0; i < messageLength; ++i) {
        char currentChar = message[i];
        char keyChar = key[i % keyLength];

        if (isalpha(currentChar)) {
            // Сдвигаем текущий символ на основе символа ключа
            char baseChar = isupper(currentChar) ? 'A' : 'a';
            char encryptedChar = (currentChar - baseChar + (toupper(keyChar) - 'A')) % 26 + baseChar;
            ciphertext += encryptedChar;
        }
        else {
            // Символ не является буквой, оставляем его без изменений
            ciphertext += currentChar;
        }
    }
    return ciphertext;
}

string VigenereCipher::Decrypt(string ciphertext, string key) {
    string decryptedText;

    int keyLength = key.length();
    int ciphertextLength = ciphertext.length();

    for (int i = 0; i < ciphertextLength; ++i) {
        char currentChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(currentChar)) {
            // Сдвигаем текущий символ на основе символа ключа
            char baseChar = isupper(currentChar) ? 'A' : 'a';
            char decryptedChar = (currentChar - baseChar - (toupper(keyChar) - 'A') + 26) % 26 + baseChar;
            decryptedText += decryptedChar;
        }
        else {
            // Символ не является буквой, оставляем его без изменений
            decryptedText += currentChar;
        }
    }

    return decryptedText;
}







