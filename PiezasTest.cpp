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
  
	ASSERT_EQ(piezas.pieceAt(0, 3), Blank);
}

TEST(PiezasTest, resetPartialFull)
{
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  piezas.reset();
  ASSERT_EQ(piezas.pieceAt(1, 1), Blank);
}

TEST(PiezasTest, resetOnEmpty)
{
  Piezas piezas;
  piezas.reset();
  ASSERT_EQ(piezas.pieceAt(0, 0), Blank);
}

// drop piece tests
TEST(PiezasTest, dropPieceInvalid)
{
  Piezas piezas;
  ASSERT_EQ(piezas.dropPiece(8), Invalid);
}

TEST(PiezasTest, dropPieceInvalidNegative)
{
  Piezas piezas;
  ASSERT_EQ(piezas.dropPiece(-8), Invalid);
}

TEST(PiezasTest, dropPieceBlank)
{
  Piezas piezas;
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), Blank);
}

TEST(PiezasTest, dropPieceXcol0)
{
  Piezas piezas;
  ASSERT_EQ(piezas.dropPiece(0), X);
}

TEST(PiezasTest, dropPieceYcol0)
{
  Piezas piezas;
  piezas.dropPiece(0);
  ASSERT_EQ(piezas.dropPiece(0), O);
}
//piece at tests
TEST(PiezasTest, pieceAtBlank)
{
  Piezas piezas;
  ASSERT_EQ(piezas.pieceAt(0, 0), Blank);
}

TEST(PiezasTest, pieceAtInvalidRow)
{
  Piezas piezas;
  ASSERT_EQ(piezas.pieceAt(-9, 0), Invalid);
}

TEST(PiezasTest, pieceAtInvalidCol)
{
  Piezas piezas;
  ASSERT_EQ(piezas.pieceAt(0, -9), Invalid);
}

TEST(PiezasTest, pieceAt11X)
{
  Piezas piezas;
  piezas.dropPiece(1);
  piezas.dropPiece(0);
  piezas.dropPiece(1);
  ASSERT_EQ(piezas.pieceAt(1, 1), X);
}

TEST(PiezasTest, pieceAt11O)
{
  Piezas piezas;
  piezas.dropPiece(1);
  piezas.dropPiece(1);
  ASSERT_EQ(piezas.pieceAt(1, 1), O);
}

//game state tests
TEST(PiezasTest, gameStateNotFull)
{
  Piezas piezas;
  piezas.dropPiece(1); // X
  piezas.dropPiece(1); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(1); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(0); // X
  ASSERT_EQ(piezas.gameState(), Invalid);
}

TEST(PiezasTest, gameStateX4Across)
{
  Piezas piezas;
  piezas.dropPiece(1); // X
  piezas.dropPiece(-1); // O
  piezas.dropPiece(1); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(1); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(0); // X
  piezas.dropPiece(2); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(-8); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(2); // O
  piezas.dropPiece(3); // X
  piezas.dropPiece(3); // O
  piezas.dropPiece(3); // X
  ASSERT_EQ(piezas.gameState(), X);

}

TEST(PiezasTest, gameStateYWinner)
{
  Piezas piezas;
  piezas.dropPiece(-1); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(3); // X
  piezas.dropPiece(0); // O
  piezas.dropPiece(0); // X
  piezas.dropPiece(1); // O
  piezas.dropPiece(1); // X
  piezas.dropPiece(1); // O
  piezas.dropPiece(-2); // X
  piezas.dropPiece(2); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(3); // O
  piezas.dropPiece(3); // X
  ASSERT_EQ(piezas.gameState(), O);
}

TEST(PiezasTest, gameStateTie)
{
  Piezas piezas;
  piezas.dropPiece(0); // X
  piezas.dropPiece(1); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(3); // O
  piezas.dropPiece(0); // X
  piezas.dropPiece(1); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(3); // O
  piezas.dropPiece(0); // X
  piezas.dropPiece(1); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(3); // O
  piezas.dropPiece(0); // X
  piezas.dropPiece(1); // O
  piezas.dropPiece(2); // X
  piezas.dropPiece(3); // O
  ASSERT_EQ(piezas.gameState(), Blank);
}

