////////////////////////////////////////////////////////////////////////
//                                                                    //
//                       HUFFMAN ENCODING                             //
//                                                                    //
////////////////////////////////////////////////////////////////////////

Clara Esther Stassen
STSCLA001

I. File Structure
------------------
huffencode.cpp    Driver for huffman encoding containing interface for user-interaction

HuffenTree.cpp    Builds huffman tree and encodes data

HuffenTree.h      HuffenTree header

HuffenNode.cpp    Node for huffman tree

HuffenNode.h      HuffenNode header

Test.cpp          Unit tests for huffencode

testing.txt       Input test file for unit tests

catch.hpp         Header for unit test framework

Makefile          Makefile to build huffencode and unit tests

README            This file

II. How To Compile
-------------------
- To compile huffencode:
    $ make

- To compile unit tests:
    $ make test

- To clean folder:
    $ make clean

III. How To Run
----------------
- To run huffman encoding:
    $ ./huffencode [input_file] [output_file] 

- To run unit tests:
    $ ./test

IV. Arguments
--------------
<input_file> is required as the name of a text file containing ASCII characters

V. Outputs
------------
<output_file>.hdr  Code Table

<output_file>.out  Encoded Data
             
<output_file>.bin  Encoded Data Bitstream
