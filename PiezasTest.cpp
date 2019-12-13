/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
//reset tests
TEST(PiezasTest, resetFull)
{
  Piezas piezas;
  bool check = true;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  piezas.dropPiece(2);
  piezas.dropPiece(2);
  piezas.dropPiece(2);
  piezas.dropPiece(3);
  piezas.dropPiece(3);
  piezas.dropPiece(3);
  piezas.reset();
  for(int i = 0; i < BOARD_COLS; i++)
  {
	  for(int j = 0; j < BOARD_ROWS; j++)
	  {
		  if(piezas.pieceAt(i, j) != Blank)
		  {
		    check = false;
		  } 
	  }
  }
	ASSERT_EQ(check, true);
}

TEST(PiezasTest, resetPartialFull)
{
  Piezas piezas;
  bool check = true;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  piezas.reset();
  for(int i = 0; i < BOARD_COLS; i++)
  {
	  for(int j = 0; j < BOARD_ROWS; j++)
	  {
		  if(piezas.pieceAt(i, j) != Blank)
		  {
		    check = false;
		  } 
	  }
  }
	ASSERT_EQ(check, true);
}

TEST(PiezasTest, resetOnEmpty)
{
  Piezas piezas;
  bool check = true;
  piezas.reset();
  for(int i = 0; i < BOARD_COLS; i++)
  {
	  for(int j = 0; j < BOARD_ROWS; j++)
	  {
		  if(piezas.pieceAt(i, j) != Blank)
		  {
		    check = false;
		  } 
	  }
  }
	ASSERT_EQ(check, true);
}

// drop piece tests
TEST(PiezasTest, dropPieceInvalid)
{
  
}

TEST(PiezasTest, dropPieceBlank)
{
  
}

TEST(PiezasTest, dropPieceXcol0)
{
  
}

TEST(PiezasTest, dropPieceYcol0)
{
  
}
//piece at tests
TEST(PiezasTest, pieceAtBlank)
{

}

TEST(PiezasTest, pieceAtInvalid)
{

}

TEST(PiezasTest, pieceAt11X)
{

}

TEST(PiezasTest, pieceAt11Y)
{

}

//game state tests
TEST(PiezasTest, gameStateNotFull)
{

}

TEST(PiezasTest, gameStateXWinner)
{

}

TEST(PiezasTest, gameStateYWinner)
{

}

TEST(PiezasTest, gameStateTie)
{

}

