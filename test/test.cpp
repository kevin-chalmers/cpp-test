//
// Created by kevin on 01/03/19.
//

#define BOOST_TEST_MODULE MyCMakeTest
#include <boost/test/unit_test.hpp>

#include "foo.hpp"

BOOST_AUTO_TEST_CASE(constructor_test)
{
    foo f;
    BOOST_CHECK_EQUAL(f.x(), 42);

    foo f2{24};
    BOOST_REQUIRE_EQUAL(f2.x(), 24);
}