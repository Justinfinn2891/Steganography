#include <iostream>
#include <vector>
#include "Steganography.h"
#include <fstream>
#include <string>

using namespace std;


void Graphy::readImage(string fileName){
  ifstream file;

  file.open(fileName+".ppm");

  file >> magicNumber >> width >> height >> maxColor;

  int i = 0;
  int save=0;
  while(file>>save)
    {
      i++;
      colorData.push_back(save);
    }
  file.close();
}
void Graphy::printImage(string fileName)
{
  fileName=fileName+".ppm";
  ofstream outFile(fileName);
  outFile<<magicNumber<<" ";
  outFile<<width<<" "<<height<<" ";
  outFile<<maxColor;
  
   for (auto it = colorData.begin(); it != colorData.end(); ++it){
     int store= *it;
     outFile<<store<<" ";
    }
   
   outFile.close();
}
void Graphy::readCipherText(string fileName)
{
  ifstream file;

  file.open(fileName+".txt");
  
  getline(file, cipherText);

  file.close();
}
void Graphy::printCipherText(string fileName)
{
 fileName=fileName+".txt";
 
  ofstream outFile(fileName);
  outFile<<cipherText<<endl;                                                                                    
   outFile.close();
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
  int length=cipherText.length();
  auto it = colorData.begin();
  while(count<length){
  int ch=cipherText[count];
  int cycle=0;
  
  while(cycle<8){
    cycle++;
    int bit= getNthBit(ch,cycle);
      *it = *it+bit;
      ++it;
     }
  count++;
}
}
  
void Graphy::decipher()
{
  string d = " "; 
  for(auto it = colorData.begin(); it != colorData.end();++it)
    {
      int f=*it%2;     
      d +=to_string(f);
      }

  int size = d.length()/8; 
  int dec[size];
  int z = 0;

  for(int i = 0; i < d.length(); i+=8)
     {
       string c = d.substr(i, 8);
       cout<<c<<endl;
       int len = c.length();
       int base = 1;
       int dec_value = 0;

       for(int j = len -1; j>= 0; j--)
	 {
	   if(c[j] == '1')
	     {
	       dec_value += base;
	     }
	      base = base * 2; 
		}
	  dec[z] = dec_value;
	  
	  cout << dec[z] << endl;
	  z++;
	    }
       
   
for(int g = 0; g < size; g++)
  {
    int store = dec[g];
   char one = store + '0';
    one = one - '0';
    if(one == 00000000)
      {
	// IGNORE
      }
    else
      {
    cipherText += one;
      }
    
  }
 
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

  return store[n-1];
}
