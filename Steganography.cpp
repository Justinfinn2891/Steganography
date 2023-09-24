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
     cout<< ' '<< *it;
   }
   cout<<endl;
}
void Graphy::encipher()
{
  
}
void Graphy::decipher()
{
  
}

int Graphy::getNthBit(char cipherChar, int n)
{
  
}
