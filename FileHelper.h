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
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct File {
	string FileName;
	File() {
		FileName = "";
	}

	void Write(string Text) {
		ofstream FileObject(FileName);
		FileObject << Text;
		FileObject.close();
	};

	int Rename(string NewName) {
		int result = 0;
		result = rename(FileName.c_str(), NewName.c_str());
		if (result == 0) {
			FileName = NewName;
		}
		return result;
	};

	string Read() {
		ifstream FileObject(FileName);
		bool FirstLine = true;
		string result = "";
		string line =  "";
		while (getline(FileObject, line)) {
			if (FirstLine) {
				FirstLine = false;
			}
			else {
				result.append("\n");
			}
			result.append(line);
		};
		return result;
	};
};
