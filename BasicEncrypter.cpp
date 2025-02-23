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

#include "BasicEncrypter.h"

int main() // Main function of this app. While most of the code for this program is in the header file, the program always starts and ends here.
{
    cout << "This program will allow you to choose a file within it's own directory to encrypt or decrypt with a password.\n This is intended as a demo program and should not be expected to\n have any real world value. Please refer to the README.txt file that is packaged with\n this program to learn more about it's purpose and licensing restrictions\n\n";
    bool Running = true;
    while (Running) {
        Running = UserInput();
    }
    return 0;
}

