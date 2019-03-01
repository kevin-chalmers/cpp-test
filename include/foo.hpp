//
// Created by kevin on 01/03/19.
//

#ifndef CPP_TEST_FOO_H
#define CPP_TEST_FOO_H

#include <iostream>

class foo
{
private:
    int _x = 0;

public:
    foo() : _x{42} { }

    foo(const int x) : _x{x} { }

    int x() const { return _x; }

    void dump(std::ostream &is = std::cout) const;
};

#endif //CPP_TEST_FOO_H
