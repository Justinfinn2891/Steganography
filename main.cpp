
#include <iostream>
#include <vector>
#include "Steganography.h"

using namespace std;

int main() {
  string PPM;
  string input;
  string code;
  Graphy Stegano;

  
  cout<<"What type of operation are you running?(E or D/)"<<endl;
  char operation;
  cin>>operation;
  operation=tolower(operation);
  
  if(operation=='e'){
    cout<<"What is the PPM filename?"<<endl;
    cin>>PPM;
    Stegano.readImage(PPM);
    Stegano.encipher();
    cout<<"What is the name of the input text file?"<<endl;
    cin>>input;
    Stegano.readCipherText(input);
    cout<<"What should be the name of the Encoded PPM file?"<<endl;
    cin>>code;
    Stegano.printImage(code);
    
    
  }

  string encode, textfile; 
   if(operation=='d'){
    cout << "What is the encoded PPM filename? ";
    cin >> encode;

    if(encode == code)
      {
	cout << "What should be the name for the output text file?";
	cin >> textfile;
      }
  }
  else{
    cout<<"Error"<<endl;
  }
  return 0;
}
