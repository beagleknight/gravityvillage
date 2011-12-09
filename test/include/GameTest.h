#ifndef CLASS_GAME_TEST_H
#define CLASS_GAME_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Game.h"

class GameTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( GameTest );
  CPPUNIT_TEST( testGetInstance );
  CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

    void testGetInstance();
};

#endif 
