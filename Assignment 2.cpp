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
void railfenceCipher (string in);
int find2(string str, char f);
void ceaserDecipher(string msg, int shifts);
void atbashDecipher(string msg);
void baconianDecipher (string msg);
void simplesubDecipher(string msg);
void polybiusDecipher(string msg);
void xorDecipher(string msg);
void morseCipher(string msg);
void morseDecipher(string msg);
void fenceCipher(string msg);
void fenceDecipher(string msg);
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
			cout << "Plain Text: ";
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
			else if (cipherChoice == 8)
				morseCipher(msg);
			else if (cipherChoice == 9)
				xorCipher(msg);
			else if (cipherChoice == 10)
				fenceCipher(msg);

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
			cout << "Ciphered Text: ";
			getline(cin, msg);
			if (decipherChoice == 1)
				affineDecipher(msg);
            else if (decipherChoice == 2){
                int shifts;
                cout << "Please enter shift amount: ";
                cin >> shifts;
                ceaserDecipher(msg, shifts);
            }
            else if (decipherChoice == 3)
                atbashDecipher(msg);
            else if (decipherChoice == 4)
                ROT13(msg);
            else if (decipherChoice == 5)
                baconianDecipher (msg);
            else if (decipherChoice == 6)
                simplesubDecipher(msg);
            else if (decipherChoice == 7)
                polybiusDecipher(msg);
            else if (decipherChoice == 8)
            	morseDecipher(msg);
            else if (decipherChoice == 9)
                xorDecipher(msg);
            else if (decipherChoice == 10)
            	fenceDecipher(msg);

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
	int key;
	cout << "a: ";
    cin >> key;
    cout << "b: ";
    int b;
    cin >> b;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i])) {
			char c = ((tolower(msg[i]) - 'a')*key+8)%26;
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
	cout << "ROT13 Message is: " << ans << endl;
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
	string cipherWord;
	string ans;
	bool unique = true;
	do {
		cout <<"cipher Word (unique 5 chars): ";
		cin >> cipherWord;
        for (int i = 0; i < cipherWord.size(); ++i) {
            cipherWord[i] = tolower(cipherWord[i]);
        }
		unique = true;
		for (int i = 0; i < 5; ++i)
		{
			if (find2(cipherWord, cipherWord[i]) > 1)
			{
				unique = false;
				break;
			}
		}
	}
	while(!unique);
	string cipherMap;
	for (int i = 0; i < 5; ++i) {
		cipherMap += cipherWord[i];
	}
	for (int i = 0; i < 26; ++i) {
		if (find2(cipherMap, (char) (i + 'a'))==0){
			cipherMap += (char) (i + 'a');
		}
	}
	for (int i = 0; i < msg.size(); ++i) {
		if (isalpha(msg[i]))
		{
			int c = tolower(msg[i]) - 'a';
			if (isupper(msg[i]))
				ans += toupper(cipherMap[c]);
			else
				ans += cipherMap[c];
		}
		else
			ans += msg[i];
	}
	cout << "Encrypted message is: " << ans << endl;
}
int find2(string str, char f){
	int occ = 0;
	for(int i = 0; i <  str.length(); ++i){
		if(f == str[i]){
			++occ;
		}
	}
	return occ;
}
void polybiusCipher(string msg)
{
	cout << "Please enter the omitted character: ";
	char ommited;
	cin >> ommited;
	cout << "Please enter your key: ";
	char key[5];
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
			char c = msg[i] ^key;
			ans += c;
	}
	cout << "Encrypted message is: " << ans << endl;
    cout << "Encrypted message in Hexa: ";
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout << hex << (int)ans[i];
    }
}
void affineDecipher(string msg)
{
	string ans;
	int key;
	cout << "c: ";
	cin >> key;
    cout << "b: ";
    int b;
    cin >> b;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			int c = (tolower(msg[i])) - 'a';
			c = key*(c-b);
				while (c < 0) {
					c += 26;
				}
				c %= 26;

//			c = (c < 8) ? ((key*(c-8))*-1)%26
			if (isupper(msg[i]))
				c += 'A';
			else
				c += 'a';
			ans += c;
		}
		else
			ans += msg[i];
	}
	cout << "Plain Text: " << ans << endl;
}
void railfenceCipher (string in) {

	cout << "Key: ";
	int rfkey;
	cin >> rfkey;
	int cr = 0;
	string rows[rfkey];
		for(int i = 0; i < in.length(); ++i) {
			if (in[i] != ' ') {
				rows[(cr >= rfkey ? rfkey - 1 - (cr % rfkey) : cr)] += in[i];
				++cr;
				if (cr == rfkey * 2) {
					cr = 0;
				}
				if (cr == rfkey || cr == 0) {
					++cr;
				}
			}
		}
	cout << "Encrypted message is: ";
	for (int i = 0; i < rfkey; ++i)
		cout << rows[i];
	cout << endl;

}
void ceaserDecipher(string msg, int shifts)
{
    string ans;
    for (int i = 0; i < (int)msg.size(); ++i)
    {
        if (isalpha(msg[i])) {
            char c = ((tolower(msg[i]) - 'a') - shifts);
            while (c < 0)
                c += 26;
            c %= 26;
            if (isupper(msg[i]))
                ans += (char)(c + 'A');
            else
                ans += (char)(c + 'a');
        }
        else
            ans += msg[i];
    }
    cout << "Plain Text: " << ans << endl;
}
void atbashDecipher(string msg)
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
    cout << "Plain Text: " << ans << endl;
}
void baconianDecipher (string msg)
{
    string ans;
    for (int i = 0; i < msg.size(); i += 5)
    {
        int letter = 0;
        if (isalpha(msg[i])) {
            for (int j = i + 4; j >= i; --j) {
                if (msg[j] == 'b') {
                    int product = 1;
                    for (int k = 0; k < (i + 4) - j; ++k) {
                        product *= 2;
                    }
                    letter += product;
                }
            }
            ans += (char) (letter + 'a');
        }
        else {
            ans += msg[i];
            i -= 4;
        }
    }
    cout << "Plain Text: " << ans << endl;
}
void simplesubDecipher(string msg)
{
    string cipherWord;
    string ans;
    bool unique = true;
    do {
        cout <<"cipher Word (unique 5 chars): ";
        cin >> cipherWord;
        unique = true;
        for (int i = 0; i < 5; ++i)
            cipherWord[i] = tolower(cipherWord[i]);
        for (int i = 0; i < 5; ++i)
        {
            if (find2(cipherWord, cipherWord[i]) > 1)
            {
                unique = false;
                break;
            }
        }
    }
    while(!unique);
    string cipherMap;
    for (int i = 0; i < 5; ++i) {
        cipherMap += cipherWord[i];
    }
    for (int i = 0; i < 26; ++i) {
        if (find2(cipherMap, (char) (i + 'a'))==0){
            cipherMap += (char) (i + 'a');
        }
    }
    for (int i = 0; i < msg.size(); ++i) {
        if (isalpha(msg[i]))
        {
            int c;
            for (int j = 0; j < 26; ++j)
            {
                if (msg[i] == cipherMap[j])
                    c = j;
            }
            if (isupper(msg[i]))
                ans += (char)(c + 'A');
            else
                ans += (char)(c + 'a');
        }
        else
            ans += msg[i];
    }
    cout << "Plain Text: " << ans << endl;
}
void polybiusDecipher(string msg) {
    cout << "Please enter the omitted character: ";
    char ommited;
    cin >> ommited;
    cout << "Please enter your key: ";
    char key[5];
    for (int i = 0; i < 5; ++i)
        cin >> key[i];
    string cipherMap[26] = {""};
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (index != tolower(ommited) - 'a') {
                cipherMap[index] = key[i];
                cipherMap[index] += key[j];
            } else {
                cipherMap[index] = ommited;
                --j;
            }
            ++index;
        }
    }
    string ans;
    for (int i = 0; i < msg.size(); i++)
    {
        string letter;
        letter   = msg[i];
        letter += msg[i+1];
        if (isdigit(msg[i]))
        {
            int c;
            for (int j = 0; j < 26; ++j)
            {
                if (cipherMap[j] == letter)
                {
                    c = j;
                    break;
                }
            }
            ans += (char)(c+'a');
            ++i;
        }
        else
            ans += msg[i];

    }
    cout << "Plain Text: " << ans << endl;
}
void xorDecipher(string msg)
{
    cout << "Please enter secret character: ";
    char key;
    cin >> key;
    string ans;
    cout << "Hexa or Regular text? (h/r): ";
    char choice;
    cin >> choice;
    if (choice == 'r')
    {
		for (int i = 0; i < (int)msg.size(); ++i)
		{
			char c = msg[i] ^key;
			ans += c;
		}
    }
    else
    {
		string temp;
    	for (int i = 0; i < msg.size(); ++i)
    	{
    		if (msg[i] != ' ')
    		{
    			temp += msg[i];
    		}
    		else
    		{
    			int letter = 0;
    			for (int j = 0; j < temp.size(); ++j)
    			{
    				if (isdigit(temp[j]))
    				{
    					int product = 1;
    					for (int k = 0; k < (int)temp.size()-j - 1; ++k)
    					{
    						product = product * 16;
    					}
    					letter = letter + (temp[j] - '0')*product;
    				}
    				else
    				{
    					int product = 1;
    					for (int k = 0; k < (int)temp.size() - j - 1; ++k)
    					{
    						product = product * 16;
    					}
    					letter = letter + (tolower(temp[j]) - 'a' + 10)*product;
    				}
    			}
				temp = "";
				letter ^= key;
				ans += (char)letter;
    		}
    	}
    }
    cout << "Plain Text: " << ans << endl;
    cout << "Plain Text in Hexa: ";
    for (int i = 0; i < ans.size(); ++i)
    {
    	cout << hex << (int)ans[i];
    }
}
void morseCipher(string msg)
{
	string cipherMap[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
	    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
	    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
	    "-.--", "--.."};
	string ans;
	for (int i = 0; i < msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			int c = tolower(msg[i]) - 'a';
			ans += cipherMap[c];
			ans += " ";
		}
		else
		{
			ans += "  ";
		}
	}
	cout << "Ciphered Text: " << ans << endl;
}
void morseDecipher(string msg)
{
	string cipherMap[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
	    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
	    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
	    "-.--", "--.."};
	string ans;
	string temp;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (msg[i] != ' ' && i != (int)msg.size() - 1)
		{
			temp += msg[i];
		}
		else
		{
			if (i == (int)msg.size() -1)
				temp += msg[i];
			int letter = -1;
			for (int j = 0; j < 26; ++j)
			{
				if (temp == cipherMap[j]) {
					letter = j;
					break;
				}
			}
			if (letter == -1){
				if (i+1 < msg.size() && msg[i+1] != ' ')
					ans += " ";
			}
			else
			{
				ans += (char)(letter + 'a');
			}
			temp = "";
		}
	}
	cout << "Plain Text: " << ans << endl;

}
void fenceCipher(string msg)
{
	int key;
	cout << "Key: ";
	cin >> key;
	string cipher[key];
	bool ascend = true;
	int cr = 0;
	for (int i = 0; i < (int)msg.size(); ++i)
	{
		if (isalpha(msg[i]))
		{
			if (ascend)
			{
				cipher[cr%key] += msg[i];
				cr++;
			}
			else
			{
				cipher[cr%key] += msg[i];
				cr--;
			}
			if (cr == key){
				ascend = !ascend;
				cr -= 2;
			}
			else if (cr == -1)
			{
				ascend = !ascend;
				cr += 2;
			}
		}
	}
	cout << "Cipher Text: ";
	for (int i = 0; i < key; ++i)
		cout << cipher[i];
	cout << endl;
}
void fenceDecipher(string msg)
{
	int key;
	cout << "Key: ";
	cin >> key;
	string cipher[key];
	int state = 1;
	int dots1 = 1 + (key-2)*2;
	int dots2 = -1;
	int cr = 0;
	for (int i = 0; i < key; ++i)
	{
		for (int k = 0; k < msg.size(); ++k)
		{
			cipher[i] += ".";
		}
	}
	int index = 0;
	for (int i = 0; i < msg.size(); ++i)
	{
		if (state == 1 || cr == 0 || cr == key-1)
		{
			cipher[cr][index] = msg[i];
			if (index + dots1+1 < msg.size())
				index += dots1+1;
			else
			{
				cr++;
				index = cr;
				if (cr == key - 1)
					dots1 = 1 + (key-2)*2;
				else
					dots1 -= 2;
				dots2 += 2;
				state = -1;
			}
		}
		else
		{
			cipher[cr][index] = msg[i];
			if (index + dots2+1 < msg.size())
				index += dots2+1;
			else
			{
				cr++;
				index = cr;
				if (cr == key - 1)
					dots1 = 1 + (key-2)*2;
				else
					dots1 -= 2;
				dots2+=2;
				state = -1;
			}
		}
		state *= -1;

	}
	cr = 0;
	string ans;
	bool ascend = true;
	for (int i = 0; i < key; ++i)
		cout << cipher[i] << endl;
	for (int i = 0; i < msg.size(); ++i)
	{
		ans += cipher[cr][i];
		if (ascend)
		{
			cr++;
		}
		else
		{
			cr--;
		}
		if (cr == key){
			ascend = !ascend;
			cr -= 2;
		}
		else if (cr == -1)
		{
			ascend = !ascend;
			cr += 2;
		}
	}
	cout << "Plain Text: " << ans << endl;

}
