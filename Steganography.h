#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H
#include <vector>
#include <string>

class Graphy
{
 private:

  // image number 
  std::string magicNumber;
  // width of image
  int width;
  // height of image
  int height;
  // max color of image
  int maxColor;
  // holds pixel data
  std::vector<int> colorData;
  // holds encrypted text 
  std::string cipherText;


  /**
   *
   * Gets bit and converts it
   * @param cipherChar is used for the character of the char and the int n is used for an int counter
   * @pre 
   * returns int
   * @ post converted cipherChar
   */
  int getNthBit(char cipherChar, int n);
  
    
 public:
  
  /**
   *
   * Reads in PPM image and extracts information from it
   * @param std::string fileName (name of file used to open file)
   * @pre
   * @return 
   * @post fills vector with integers
   *  
   */
  void readImage(std::string fileName);

  /** 
   *
   * stores converted ppm data into new file 
   * @param std::string fileName (used as new name for file)
   * @pre
   * @return
   * @post fills data into file
   */
  void printImage(std::string fileName);

  /**
   *
   * reads text from a file and stores it
   * @param std::string filename (name of file used to extract information from)
   * @pre
   * @return
   * @post grabs sentence from file
   */
  void readCipherText(std::string fileName);

  /** 
   * stores newly converted cipher text into file
   * @param std::string filename
   * @pre 
   * @return 
   * @post information stored into file
   */
  void printCipherText(std::string fileName);

  /** 
   * Evens out the least significant bight of each color value 
   * @pre
   * return
   * @post bight with evened out numbers
   */
  void cleanImage();

  /**
   * Puts secret text into image
   * @pre regular immage
   * @return
   * @post image with enciphered text
   */ 
  void encipher();

  /**
   *
   * Finds secret message in enciphered image
   * @pre enciphered image
   * @return
   * @post message from image
   */
  void decipher();
  
  
};

#endif // STEGANOGRAPHY_H
