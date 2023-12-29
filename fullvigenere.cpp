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
  string key, plainText;
  cout << "Enter The Text: "; getline(cin, plainText);
  cout << "Enter The Key: "; getline(cin, key);

  // Define vigenere object and give it key 
  vigenere vig(key);
  string ciphertext = vig.encryption(plainText);
  string decryptedText = vig.decryption(ciphertext);

  cout << "=====================================\n";
  cout << "Encrypted Text: " << ciphertext << endl;
  cout << "Decrypted Text: " << decryptedText << endl;

  return 0;
}
