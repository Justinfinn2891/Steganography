#include <iostream>
#include <vector>
#include "Steganography.h"
#include <fstream>

using namespace std;


void Graphy::readImage(string fileName){
  ifstream file;

  file.open(fileName);

  file >> magicNumber >> width >> height >> maxColor;
  //loop to show that it inputs properly
  int i = 0;
  int save=0;
  while(file>>save)
    {
      i++;
      colorData.push_back(save);
    }
  file.close();
  for (auto it = colorData.begin(); it != colorData.end(); ++it){
        cout << ' ' << *it;
  }
  cout<<endl;
}
void Graphy::printImage(string fileName)
{
                                                                                                                                                                                      
}
void Graphy::readCipherText(string fileName)
{
  ifstream file;

  file.open(fileName);
  
  getline(file, cipherText);

  file.close();
}
void Graphy::printCipherText(string filename)
{
  
}
void Graphy::cleanImage()
{
   for (auto it = colorData.begin(); it != colorData.end(); ++it){
     int f=*it%2;
     *it=*it - f;
   }
}
void Graphy::encipher(){
  cleanImage();
  int count=0;
  int i=0;
  int length=cipherText.length();
  
  while(i<length){
  int ch=cipherText[i];
  int cycle=0;
  
  while(cycle<7){
    int bit= getNthBit(ch,cycle);
    
    for (auto it = colorData.begin(); it != colorData.end(); ++it){
      *it = *it+bit;
    }

  }
  count++;
}
}
  
void Graphy::decipher()
{
  
}

int Graphy::getNthBit(char cipherChar, int n)
{
  int store[8];
  int letter=(int(cipherChar)+0);
  int count=0;
  int tic=0;
  
  while(letter!=0){
    store[count]=letter%2;
    letter=(letter-store[count])/2;
    count++;
  }
  while(count<7){
    count++;
    store[count]=0;
  }
  while(tic<4){
    int a=store[tic];
    int b=store[7-tic];
    store[tic]=b;
    store[7-tic]=a;
    tic++;
    }

  return store[n];
}
