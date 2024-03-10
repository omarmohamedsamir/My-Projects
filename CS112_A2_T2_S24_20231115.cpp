//File:CS112_A2_T2_S24_20231115
//Purpose:// Simple C++ program for a substitution cipher, allowing users to encrypt or decrypt messages with a key of five unique letters.
//Authir: Omar Mohamed Samir Soliman (Sgroup: S24)
//Cipher:Simple Substitution cipher(5)
//Email:omarmohamedsmir111@gmail.com
//ID:20231115

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Function to check the uniqueness of characters in a string
bool isUnique(const string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        for (size_t j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j]) {
                return false; // Characters are not unique
            }
        }
    }
    return true; // All characters are unique
}

// Function to build the substitution key based on the user input
string buildSubstitutionKey(const string& userKey) {
    string substitutionKey = userKey;

    // Add the remaining 21 letters in order after the key letters
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (substitutionKey.find(ch) == string::npos) {
            substitutionKey += ch;
        }
    }

    return substitutionKey;
}

// Function to encrypt a message using the provided key
string encrypt(const string& plaintext, const string& key) {
    string ciphertext = plaintext;

    for (char& ch : ciphertext) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            ch = key[ch - base];
        }
    }

    return ciphertext;
}

// Function to decrypt a message using the provided key
string decrypt(const string& ciphertext, const string& key) {
    string decryptedMessage = ciphertext;

    for (char& ch : decryptedMessage) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            // Reverse the substitution by finding the index in the key
            ch = static_cast<char>(key.find(ch) + base);
        }
    }

    return decryptedMessage;
}

// Function to validate if a string contains only letters and spaces
bool isAllLettersAndSpaces(const string& str) {
    for (char ch : str) {
        if (!isalpha(ch) && !isspace(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    // Get user input for the key
    string userKey;
    do {
        cout << "Enter a key of five unique letters: ";
        getline(cin, userKey);

        // Validate the key length and uniqueness
        if (userKey.length() != 5 || !isUnique(userKey)) {
            cout << "Invalid key. Please enter five unique letters." << endl;
            continue;
        }

        // Validate if the key contains only letters
        if (!isalpha(userKey[0]) || !isalpha(userKey[1]) || !isalpha(userKey[2]) || !isalpha(userKey[3]) || !isalpha(userKey[4])) {
            cout << "Invalid key. Please enter letters only." << endl;
            continue;
        }

        // If all conditions are met, break out of the loop
        break;
    } while (true);

    // Build the substitution key
    string substitutionKey = buildSubstitutionKey(userKey);

    // Get user input for the operation (encrypt or decrypt)
    string operation;
    do {
        cout << "Enter 'encrypt' to encrypt a message or 'decrypt' to decrypt a message: ";
        getline(cin, operation);

        // Convert the operation to lowercase for case-insensitive comparison
        for (char& ch : operation) {
            ch = tolower(ch);
        }
    } while (operation != "encrypt" && operation != "decrypt");

    // Get user input for the message
    string input;
    do {
        cout << "Enter a message: ";
        getline(cin, input);

        // Validate if the input contains only letters and spaces
        if (!isAllLettersAndSpaces(input)) {
            cout << "Invalid input. Please enter a message containing only letters and spaces." << endl;
        }
    } while (!isAllLettersAndSpaces(input));

    // Process the input based on the selected operation
    if (operation == "encrypt") {
        // Encrypt the message, excluding spaces
        string encryptedMessage = encrypt(input, substitutionKey);
        // Display the encrypted message
        cout << "Encrypted message: " << encryptedMessage << endl;
    } else if (operation == "decrypt") {
        // Decrypt the message
        string decryptedMessage = decrypt(input, substitutionKey);
        // Display the decrypted message
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid operation. Please enter 'encrypt' or 'decrypt'." << endl;
        return 1; // Exit with an error code
    }

    return 0;
}
