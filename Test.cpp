#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <memory>

namespace STSCLA001
{
 using namespace std;

 // HuffmanNode.h Tests
 TEST_CASE("HuffmanNode Tests")
 {
  SECTION("Node Creation, get and set values")
  {
   shared_ptr<HuffmanNode> node(new HuffmanNode('T', 7));
   REQUIRE((*node).getFreq() == 7);
   REQUIRE((*node).getLetter() == 'T');
   (*node).setFreq(20);
   REQUIRE((*node).getFreq() == 20);
   REQUIRE((*node).getLetter() == 'T');
   REQUIRE((*node).getLeft() == nullptr);
   REQUIRE((*node).getRight() == nullptr);
  }
  SECTION("Creating Left and Right Node Links")
  {
    shared_ptr<HuffmanNode> node(new HuffmanNode('N', 0));
    shared_ptr<HuffmanNode> left(new HuffmanNode('L', 1));
    shared_ptr<HuffmanNode> right(new HuffmanNode('R', 2));

    (*node).setLeft(left);
    (*node).setRight(right);

    REQUIRE((*node).getLeft() == left);
    REQUIRE((*(*node).getLeft()).getFreq() == 1);
    REQUIRE((*(*node).getLeft()).getLetter() == 'L');
    REQUIRE((*node).getRight() == right);
    REQUIRE((*(*node).getRight()).getFreq() == 2);
    REQUIRE((*(*node).getRight()).getLetter() == 'R');
  }
  SECTION("Node Comparison Operator Test")
  {
   shared_ptr<HuffmanNode> left(new HuffmanNode('L', 1));
   shared_ptr<HuffmanNode> right(new HuffmanNode('R', 2));
   REQUIRE(((*left) > (*right)) == false);
  }
 }
 TEST_CASE("HuffmanTree Tests")
 {
  SECTION("Tree Building")
  {
   HuffmanTree h;
   h.buildTree("testing.txt");
   unordered_map<char, int> m = h.getMap();
   for (auto &node : m)
   {
    if (node.first == 'a')
    {
     REQUIRE(node.second == 1);
    }
    if (node.first == 'b')
    {
     REQUIRE(node.second == 2);
    }
    if (node.first == 'c')
    {
     REQUIRE(node.second == 4);
    } 
   }
  }
  SECTION("Code Table Test")
  {
   HuffmanTree h;
   h.buildTree("testing.txt");
   for (auto letter: h.code)
   {
    if(letter.first == 'a')
    {
     REQUIRE(letter.second == "00");
    }
    if(letter.first == 'b')
    {
     REQUIRE(letter.second == "01");
    }
    if(letter.first == 'c')
    {
     REQUIRE(letter.second == "1");
    }
   }
  }
  SECTION("File Output Test")
  {
   HuffmanTree h;
   h.buildTree("testing.txt");
   h.encode("testout");

   ifstream ifs("testout.hdr");
   REQUIRE(bool(ifs) == true);
   ifs.close();
   
   ifstream is("testout.bin");
   REQUIRE(bool(is) == true);
   is.close();

   ifstream ifss("testout.out");
   REQUIRE(bool(ifss) == true);
   string temp;
   getline(ifss, temp);
   REQUIRE(temp == "0001011111");
  }
 }
}