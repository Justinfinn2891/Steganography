#include <iostream>
#include <vector>
#include "Steganography.h"
#include <fstream>

using namespace std;


void Graphy::readImage(string fileName){
  ifstream file;

  file.open(fileName);

  file >> magicNumber >> width >> height >> maxColor;

  int i = 0;
  colorData.push_back(i);
  
  while(file)
    {
      i++;
      colorData.push_back(i);
      
    }
}
void Graphy::printImage(string fileName)
{
  
}
void Graphy::readCipherText(string fileName)
{
  
}
void Graphy::printCipherText(string filename)
{
  
}
void Graphy::cleanImage()
{
  
}
void Graphy::encipher()
{
  
}
void Graphy::decipher()
{
  
}
