//
// Created by kevin on 01/03/19.
//

#include "foo.hpp"

void foo::dump(std::ostream &is) const
{
    is << _x << std::endl;
}