/* TODO:
 * Enhanced polybius cipher
 * Deciphers
 * 7~9 ciphers
 */


/*
 * Author: Mostafa Omar Mahmoud El-Sayed
 * ID: 20170292
 * Date: 23/2/2018
 * Program that ciphers/deciphers text using different methods
 */

#include <iostream>
#include <string.h>
using namespace std;
void affineCipher(string msg);
void caeserCipher(string msg, int shifts);
void atbashCipher(string msg);
void ROT13(string msg);
void baconianCipher(string msg);
void simplesubCipher(string msg);
void polybiusCipher(string msg);
void xorCipher(string msg);
void affineDecipher(string msg);
int main() {
	cout << "Ahlan ya user ya habibi\nWhat would you like to do today?\n";
	int choice;
	cout << "1- Cipher a message\n2- Decipher a message\n3- End\n";
	while (cin >> choice)
	{
		if (choice == 1) // cipher
		{
			int cipherChoice;
			cout << "Which ciphering technique would you like to use?\n";
			cout << "1- Affine     2- Caesar     3- Atbash     4- ROT13     5- Baconian\n";
			cout << "6- Simpe Substitution     7- Polybius Square     8- Morse Code     9- XOR      10- Rail fence\n";
			cin >> cipherChoice;
			string msg, ans;
			cin.ignore(36767, '\n');
			cout << "Enter ciphered text: ";
			getline(cin, msg);
			if (cipherChoice == 1)
				affineCipher(msg);
			else if (cipherChoice == 2) {
				int shifts;
				cout << "Please enter shift amount: ";
				cin >> shifts;
				caeserCipher(msg, shifts);
			}
			else if (cipherChoice == 3)
				atbashCipher(msg);
			else if (cipherChoice == 4)
				ROT13(msg);
			else if (cipherChoice == 5)
				baconianCipher(msg);
			else if (cipherChoice == 6)
				simplesubCipher(msg);
			else if (cipherChoice == 7)
				polybiusCipher(msg);
			else if (cipherChoice == 9)
				xorCipher(msg);

		}
		else if (choice == 2)
		{
			int decipherChoice;
			cout << "Which deciphering technique would you like to use?\n";
			cout << "1- Affine     2- Caesar     3- Atbash     4- ROT13     5- Baconian\n";
			cout << "6- Simpe Substitution     7- Polybius Square     8- Morse Code     9- XOR      10- Rail fence\n";
			cin >> decipherChoice;
			string msg, ans;
			cin.ignore(36767, '\n');
			cout << "Enter your message: ";
			getline(cin, msg);
			if (decipherChoice == 1)
				affineDecipher(msg);

		}
		if (choice == 3)
			break;
		cout << "\nWhat would you like to do now?\n";
		cout << "1- Cipher a message\n2- Decipher a message\n3- End\n";
	}
	return 0;
}
void affineCipher(string msg)
{
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i])) {
			char c = ((tolower(msg[i]) - 'a')*5+8)%26;
			if (isupper(msg[i]))
				ans += (char)(c + 'A');
			else
				ans += (char)(c + 'a');
		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;
}
void caeserCipher(string msg, int shifts)
{
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i])) {
			char c = ((tolower(msg[i]) - 'a') + shifts)%26;
			if (isupper(msg[i]))
				ans += (char)(c + 'A');
			else
				ans += (char)(c + 'a');
		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;
}
void atbashCipher(string msg)
{
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			char c = (25 - (tolower(msg[i]) - 'a'));
			if (isupper(msg[i]))
				ans += (char)(c + 'A');
			else
				ans += (char)(c + 'a');
		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;
}
void ROT13(string msg)
{
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			char c = ((tolower(msg[i]) - 'a') + 13)%26;
			if (isupper(msg[i]))
				ans += (char)(c + 'A');
			else
				ans += (char)(c + 'a');
		}
		else
			ans += msg[i];
		}
	cout << "Encrypted message is: " << ans << endl;
}
void baconianCipher(string msg)
{
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			string binaryEncryption;
			int c = tolower(msg[i]) - 'a';
			while (c > 0)
			{
				if (c%2 == 0)
					binaryEncryption += 'a';
				else
					binaryEncryption += 'b';
				c /= 2;
			}
			for (int i = 0; i < 5 - (int)binaryEncryption.size(); ++i)
				ans += 'a';
			for (int i = (int)binaryEncryption.size() - 1; i >= 0; --i)
			{
				ans += binaryEncryption[i];
			}

		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;
}
void simplesubCipher(string msg)
{
	string cipherTxt;
	string ans;
	do {
		cout <<"Please enter cipher text (26 chars): ";
		cin >> cipherTxt;
	}
	while (cipherTxt.size() != 26);
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			int c = tolower(msg[i]) - 'a';
			if (isupper(msg[i]))
				ans += toupper(cipherTxt[c]);
			else
				ans += tolower(cipherTxt[c]);
		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;
}
void polybiusCipher(string msg)
{
	cout << "Please enter the omitted character: ";
	char ommited;
	cin >> ommited;
	cout << "Please enter your key: ";
	char key[5] = {""};
	for (int i = 0; i < 5; ++i)
		cin >> key[i];
	string cipherMap[26] = {""};
	int index = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (index != tolower(ommited) - 'a')
			{
				cipherMap[index] = key[i];
				cipherMap[index] += key[j];
			}
			else
			{
				cipherMap[index] = ommited;
				--j;
			}
			++index;
		}
	}
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			int c = tolower(msg[i]) - 'a';
			ans += cipherMap[c];
		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;

}
void xorCipher(string msg)
{
	cout << "Please enter secret character: ";
	char key;
	cin >> key;
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		char c = msg[i]^key;
		ans += c;
	}
	cout << "Encrypted message is: " << ans << endl;
}
void affineDecipher(string msg)
{
	string ans;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			char c = (tolower(msg[i]) - 'a');
			c = (21*(c-8))%26;
			if (isupper(msg[i]))
				c += 'A';
			else
				c += 'a';
			ans += c;
		}
		else
			ans += msg[i];
	}
	cout << "The original message is: " << ans << endl;
}
