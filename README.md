Implementation of the ElGamal asymmetric key encryption algorithm, making use of the GNU multiple precision arithmetic library.
The program gives you the option to choose the bit size of the encrypt number ranging from 64bit to 2048bit.
Then you pass the string you want to encrypt and the program encrypts the message. 
At your screen, it prints all the stages of the encryption. Finally it decrypts the message and print it on the screen.

How to run:
I made this project using CodeBlocks so I suggest you to use the same IDE to run the project.
The important step you have to do is to connect the Library.I include the library files in the repistory.
To include the library follow this steps:

- Go to Project->Build Options and at Linker settings and Add "gmp" (Without quostionmarks)

- Go to Project->Build Options and at Search direcoties\Compiler add the Path to \include
folder of the library(I include it in the repository ElGamal/gmp-static-mingw-4.1 (1)/gmp/include

- Go to Project->Build Options and at Search direcoties\Linker add the Path to \lib
folder of the library(I include it in the repository ElGamal/gmp-static-mingw-4.1 (1)/gmp/lib)

And you are ready to run it.
