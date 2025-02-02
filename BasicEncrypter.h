/*
This program will allow the user to encrypt a file of their choosing using a key and a basic encryption algorithm. The default working directory of this app is the same as the location
of the executable file itself. Please note that, while you technically could use this program for legitamate security purposes, it is ill-advised to do so, as it makes use of an
encryption algorithm that can be cracked very easily. I am able to use more advanced encryption algorithms, but I decided not to for this program,
since this one is just meant to be a demo anyways.

This is just beginning to tap into my full potential as a software developer. While this may look somewhat basic,
it is important to note that this is just scratching the surface of what I am capable of. More advanced and adaptable versions of this and many other kinds of programs
can be created using the skills I have.

DISCLAIMER: This program is a DEMO PROGRAM, one I created for the express purpose of giving others a taste of what I am capable of with my computer programming skills.
I do not intend for it to be useful for any real world purpose, and I advise that you don't expect that from it either.

README: For more info about what this program does, and to learn about it's licencing restrictions, please refer to the README.txt file that is packaged with this one

To run this program on your own device, you will need to download the EXE to your Windows PC, or build it's code using a C++ compiler. This program was created for Windows 10.
While it may work on other operating systems, I have not tested for that and therefore cannot guarentee as such.
*/

#pragma once
#include "FileHelper.h"
#define ENCRYPT true
#define DECRYPT false

string EncryptionFilter(string text, string key, bool encrypt_mode) { // Probably the most important function of this program, this handles all encryption and decryption processes for this app.
	string Result = "";
	int Buffer = 0;
	string CurrentChar;
	const char * RawText = text.c_str();
	if (encrypt_mode) {
		while (Buffer < text.size()) {
			CurrentChar = RawText[Buffer] + key.c_str()[Buffer % key.size()];
			Result.append(CurrentChar);
			Buffer++;
		}
	}
	else {
		while (Buffer < text.size()) {
			CurrentChar = RawText[Buffer] - key.c_str()[Buffer % key.size()];
			Result.append(CurrentChar);
			Buffer++;
		}
	}
	return Result;
}

void Encrypt(string filename, string key) { // This function does not actually encrypt anything itself, but it does take in the information needed to do so, then obtains the encrypted file content from the EncryptionFilter() function and saves it to a separate file.
	if (key.size() <= 95) {
		File PlainFile;
		File CipherFile;
		PlainFile.FileName = filename;
		string CipherText = EncryptionFilter(PlainFile.Read(), key, ENCRYPT);
		if (CipherText.compare("") != 0) {
			string EncryptedFileName = "Encrypt-" + filename;
			CipherFile.FileName = EncryptedFileName;
			CipherFile.Write(CipherText);
			cout << "Your encrypted file has been saved as " << EncryptedFileName + "\n";
			cout << "Remember this key! This file cannot be decrypted without it!\n";
		}
		else {
			cout << "Your file failed to load. Make sure you entered the name correctly and also did not select a completely blank file\n";
		}
	}
	else {
		cout << "Your key is too large! Due to the way this demo handles encryption,\n your key must be equal to or less than 95.\n";
	}

}

void Decrypt(string filename, string key) { // Does the exact opposite of the Encrypt() function. Takes in a filename and key, then attempts to decrypt it, once again using the EncryptionFilter() function.
	if (key.size() <= 95) {
		File CipherFile;
		File PlainFile;
		CipherFile.FileName = filename;
		string PlainText = EncryptionFilter(CipherFile.Read(), key, DECRYPT);
		if (PlainText.compare("") != 0) {
			string DecryptedFileName = "Decrypt-" + filename;
			PlainFile.FileName = DecryptedFileName;
			PlainFile.Write(PlainText);
			cout << "Your decrypted file has been saved as " << DecryptedFileName + "\n";
			cout << "Please be mindful that if you entered an incorrect key, this may still look like it worked,\n";
			cout << "but the resulting file will not be usable. Ensure you can still read it before you get rid of the encrpted version.\n";
		}
		else {
			cout << "Your file failed to load. Make sure you entered the name correctly and also did not select a completely blank file\n";
		}
	}
	else {
		cout << "Your key is too large! Due to the way this demo handles encryption,\n your key must be equal to or less than 95.\n";
	}

}

void ListCommands() { // This function will list all the commands that can be used in this console app. This is helpful to ensure that any user will be able to interact with this program, even if they didn't already know how before.
	cout << "List of commands you can use in this program:\n";
	cout << "- Encrypt: Choose a text file within this program's directory and an encryption key, to encrypt it using that key.\n";
	cout << "- Decrypt: Choose a file that is currently encrypted with this program and in it's own directory,\n then enter the correct key to decrypt it.\n";
	cout << "- Help: Displays this info\n";
	cout << "- Exit: Close this program.\n";
}

bool UserInput() { // This function takes user input, and then triggers the correct function or response for what they entered.
	string Command = "";
	string Key = "";
	string FileName = "";
	bool Continue = true;
	cout << "Enter a command, or type \"help\" for a list of commands: ";
	cin >> Command;
	if (Command.compare("Encrypt") == 0 or Command.compare("encrypt") == 0) {
		cout << "Enter name of file to encrpyt: ";
		cin >> FileName;
		cout << "Enter encryption key for this file: ";
		cin >> Key;
		Encrypt(FileName, Key);
	}
	else if (Command.compare("Decrypt") == 0 or Command.compare("decrypt") == 0) {
		cout << "Enter name of file to decrpyt: ";
		cin >> FileName;
		cout << "Enter encryption key for this file: ";
		cin >> Key;
		Decrypt(FileName, Key);
	}
	else if (Command.compare("Help") == 0 or Command.compare("help") == 0) {
		ListCommands();
	}
	else if (Command.compare("Exit") == 0 or Command.compare("exit") == 0) {
		Continue = false;
	}
	else {
		cout << "Invalid command input. Please try again!\n";
	}
	return Continue;
}