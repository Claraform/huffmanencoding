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

 // Create HuffmanTree
 STSCLA001::HuffmanTree tree;
 // Build Tree
 tree.buildTree(infile);

 // Encode Data
 tree.encode(outfile);

 // Exit
 return 0;
}