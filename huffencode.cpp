#include "HuffmanTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
 // Check for correct argument usage
 if (argc != 3)
 {
  cout << "Incorrect Arguments. Please run file with:" << endl;
  cout << "huffencode [inputfile] [outputfile_prefix]" << endl;
  cout << "Exiting..." << endl;
  return 0;
 }

 // Capture arguments
 string infile(argv[1]);
 string outfile(argv[2]);

 // Read Input File and Store in String
 ifstream ifs(infile);
 if (!ifs)
 {
  cout << "Error opening " << infile << " ASCII file." << endl;
  cout << "Does the file exist in the working directory?" << endl;
  return 0;
 }
 string data;
 string temp;
 stringstream ss;
 ss << ifs.rdbuf();
 data = ss.str();
 ifs.close();

 // Create HuffmanTree
 STSCLA001::HuffmanTree tree;
 // Build Tree
 tree.buildTree(data);
 
 // Encode Data
 string encoded = tree.encode(data);

 // Write Out Encoded Data to File
 ofstream ofs(outfile);
 ofs << encoded;
 ofs.close();

 // Exit
 return 0;
}