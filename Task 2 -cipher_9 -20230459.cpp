#include <iostream>
#include <string>
using namespace std;
string cipher_9();
string decipher_9();

string decipher_9() {
int key;
    string encrypted, message;

    cout << "Enter the encrypted message: ";
    cin >> encrypted;

    cout << "Enter the key: ";
    cin >> key;

    int lenmess = encrypted.length();  // Determine the length of the encrypted message

    char array[key][lenmess];

    // Initialize the array with spaces
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < lenmess; j++) {
            array[i][j] = ' ';
        }
    }

    // Fill the array with characters from the encrypted message in a zigzag pattern
    int row = 0;
    bool down = true;
    int index = 0;
    for (int i = 0; i < lenmess; i++) {
        array[row][i] = '*'; // mark the positions to be filled with characters

        if (row == key - 1) { // when the character's place at the last row
            down = false;
        } else if (row == 0) { // when the character's place at the first row
            down = true;
        }

        if (down) {
            row++; // starts to go down
        } else {
            row--; // starts to go up
        }
    }

    // Read the characters from the encrypted message into the array
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < lenmess; j++) {
            if (array[i][j] == '*' && index < encrypted.length()) {
                array[i][j] = encrypted[index++];
            }
        }
    }

    // Read the deciphered message from the array
    string deciphered;
    row = 0;
    down = true;
    for (int i = 0; i < lenmess; i++) {
        deciphered += array[row][i];

        if (row == key - 1) { // when the character's place at the last row
            down = false;
        } else if (row == 0) { // when the character's place at the first row
            down = true;
        }

        if (down) {
            row++; // starts to go down
        } else {
            row--; // starts to go up
        }
    }

    cout << "The encrypted message: " << encrypted << endl;
    cout << "The original message: " << deciphered << endl;

    return 0;
}

int main() {
    string text, message, encrypt, decrypted;
    int key, lenmess;

    // Your existing code for encryption...

    // Call the decipher function

    decipher_9();

    // Display the decrypted message


    return 0;
}

string cipher_9(){
    string text, message, encrypt;
    int key;
    // get the original text from the user
    cout << "Please enter the message you want to encrypt: \n";
    getline(cin, text);
    // take the key from the user
    cout << "Enter the Key please: " << endl;
    cin >> key;
    // take the length of the text and declare the empty array
    int lenmess = 0; // the text's length without the spaces
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') { // remove the spaces
            message += text[i];
            lenmess++;
        }
    }
    char array[key][lenmess];
    // Initialize the array with spaces
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < lenmess; j++) {
            array[i][j] = ' ';
        }
    }
    // Fill the array with characters from the message in a zigzag pattern
    int row = 0;
    bool down = true;
    for (int i = 0; i < lenmess; i++) {
        array[row][i] = message[i];
        if (row == key - 1) { // when the character's place at the last row
            down = false;
        } else if (row == 0) { // when the character's place at the first row
            down = true;
        }

        if (down) {
            row++; // starts to go down
        } else {
            row--; // starts to go up
        }
    }
    // Read the encrypted message from the array
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < lenmess; j++) {
            if (array[i][j] != ' ') {
                encrypt += array[i][j];
            } else {
                continue;
            }
        }
    }
    cout << "the plain Message: " << text << endl;
    cout << "Encrypted Message: " << encrypt << endl;
    return 0;
}
