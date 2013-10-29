//
// Copyright (c) 2012-2013 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/policies/scopes_permission.hpp"

#include <boost/test/unit_test.hpp>
#include "boost/di.hpp"

#include "data.hpp"

namespace boost {
namespace di {
namespace policies {

BOOST_AUTO_TEST_CASE(scopes_permission_fail) {
    injector<
        scopes_permission<allow_scope<scopes::unique<>>> // allow_scope<scopes::shared<>>
    >().create<c24>();
}

} // namespace policies
} // namespace di
} // namespace boost
