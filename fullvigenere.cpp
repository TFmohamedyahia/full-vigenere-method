/*############################################################
The code Created by : Mohamed Yahia
This program to Encrypt and Decrypt using Full Vigenere method 
##############################################################
*/
#include <iostream>
using namespace std;

// following class for full vigenere method that contain Encrypt and Decrypt function 
class vigenere {
public:
  string k;                   // Key for Vigenere cipher
  vigenere(string key);       // prametrized Constructor to initialize the key (handles uppercase/lowercase)
  string toLowerCase(string str);  // function to convert uppercase to lowercase
  string encryption(string text);        // Encryption function
  string decryption(string text);        // Encryption function
};



// Implemntation for class constractor
vigenere::vigenere(string key){
  for (int i = 0; i < key.length(); i++) {
      k += toupper(key[i]);   // Convert all key characters to uppercase
  }
}

// Implemntation for  toLowerCase  func
string vigenere::toLowerCase( string str){
  string result;

      for (int i = 0; i < str.length(); i++) {
          result += tolower(str[i]);
      }
      return result;
}

// Implemntation for  encryption  func
string vigenere::encryption(string text){
  string output;

  for (int i = 0, j = 0; i < text.length(); i++) {
    char c = text[i];
    if (isalpha(c)) { // Check if character is a letter
      // Convert to uppercase and perform Vigenere encryption
      output += ((toupper(c) + k[j] - 26) % 26) + 'A';
    }
    else if (isdigit(c)) { // Check if character is a digit
      output += ((c - '0' + k[j] - 'A') % 10) + '0';
    }
    else {
      output += c; // Keep non alphabetic characters (if char not alphabetic)
    }
    ++j %= k.length(); // Move to the next key character
  }
  return toLowerCase(output);
}

// Implemntation for  decryption  func
string vigenere::decryption(string text){
  string output;
  for (int i = 0, j = 0; i < text.length(); i++) {
    char c = text[i];
    if (isalpha(c)) { // Check if character is a letter
      output += ((toupper(c) - k[j] + 26) % 26) + 'A';    // Convert to uppercase and perform Vigenere decryption
    } 
    else if (isdigit(c)) { // Check if character is a digit
      output += ((c - '0' - k[j] + 'A' + 10) % 10) + '0'; // Decrypt digits within 0-9 range
    }
    else {
      output += c; // Keep non alphabetic characters (if char not alphabetic)
    }
    ++j %= k.length(); // Move to the next key character
  }
  return toLowerCase(output);
}


int main() {
  string key, plain, cipher;
  int choose;

  cout << "Welcome in plogram.\n";

  cout << "Enter The privet key: ";
  getline(cin, key);

  vigenere vig(key);

  cout << "[1] Encryption \n";
  cout << "[2] Decryption \n";
  cout << "Choose what do you want: "; 
  cin >> choose;
  cin.ignore(); // Ignore the newline character left in the buffer

  if (choose == 1) {
    cout << "Enter The message: ";
    getline(cin, plain);
    string ciphertext = vig.encryption(plain);
    cout << "Encrypted Text: " << ciphertext << endl;
  } 
  else if (choose == 2) {
    cout << "Enter The Chipher: ";
    getline(cin, cipher);
    string decryptedText = vig.decryption(cipher); 
    cout << "Decrypted Text: " << decryptedText << endl;
  } 
  else {
    cout << "Invalid input \n";
  }

  return 0;
}