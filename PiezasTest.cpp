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
  
}

TEST(PiezasTest, resetPartialFull)
{

}

TEST(PiezasTest, resetOnEmpty)
{

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

