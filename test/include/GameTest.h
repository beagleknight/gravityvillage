#ifndef CLASS_GAME_TEST_H
#define CLASS_GAME_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class GameTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( GameTest );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
};

#endif 
