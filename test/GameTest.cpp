#include "GameTest.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( GameTest );

void GameTest::setUp()
{

}

void GameTest::tearDown()
{

}

void GameTest::testGetInstance()
{
  CPPUNIT_ASSERT_EQUAL(&Game::getInstance(), &Game::getInstance());
}
