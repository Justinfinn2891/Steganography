/**
 * @file main.cpp
 * @author Gabriel Speer and Justin Finn
 * @date 2023-09-25
 * @brief file that contains a main
 * 
 * main.cpp file that operates the graphy class in the form of stegano and encodes and decodes a message into a ppm image
 */


#include <iostream>
#include <vector>
#include "Steganography.h"

using namespace std;

int main() {
  // VARIABLES
  string PPM;
  string textfile;
  string code;
  Graphy Stegano;

  
  cout<<"What type of operation are you running?(E or D/)"<<endl;
  char operation;
  cin>>operation;
  operation=tolower(operation);
  //ENCODING
  if(operation=='e'){
    cout<<"What is the PPM filename?"<<endl;
    cin>>PPM;
    Stegano.readImage(PPM);
    cout<<"What is the name of the input text file?"<<endl;
    cin>>textfile;
    Stegano.readCipherText(textfile);
    Stegano.encipher();
    cout<<"What should be the name of the Encoded PPM file?"<<endl;
    cin>>code;
    Stegano.printImage(code);
    
    //DECODING
  }else if(operation=='d'){
    cout << "What is the encoded PPM filename? ";
    cin >> code;
    Stegano.readImage(code);
    Stegano.decipher();
    cout << "What should be the name for the output text file?";
    cin >> textfile;
    Stegano.printCipherText(textfile);
    
    
   }
  else{
    cout<<"Error"<<endl;
  }
  return 0;
}
