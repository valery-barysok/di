//
// Copyright (c) 2014 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/policies/binding_correctness.hpp"

#include <boost/test/unit_test.hpp>
#include "boost/di.hpp"

#include "common/data.hpp"

namespace boost {
namespace di {
namespace policies {

BOOST_AUTO_TEST_CASE(undefined_behaviors_fail) {
    injector<
        binding_correctness
      , bind_int<42>::when<call_stack<ub1>>
    > injector_;

    injector_.create<ub3>();
}

} // namespace policies
} // namespace di
} // namespace boost
