//
// Copyright (c) 2012-2013 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/policies/scopes_permission.hpp"
#include "boost/di/scopes/deduce.hpp"
#include "boost/di/scopes/singleton.hpp"
#include "boost/di/scopes/unique.hpp"

#include <boost/test/unit_test.hpp>
#include <boost/mpl/vector.hpp>

#include "contains_all.hpp"
#include "data.hpp"

namespace boost {
namespace di {
namespace policies {

BOOST_AUTO_TEST_CASE(value) {
    BOOST_CHECK((
        contains_all<
            mpl::vector<
                mpl::pair<int, scopes::unique<>>
            >
          , scopes_permission<>::verify<
                mpl::vector0<>
              , int
              , mpl::false_
            >::type
         >::value
    ));
}

BOOST_AUTO_TEST_CASE(none) {
    BOOST_CHECK((
        contains_all<
            mpl::vector<
                mpl::pair<int, scopes::unique<>>
              , mpl::pair<double, scopes::unique<>>
              , mpl::pair<char, scopes::unique<>>
            >
          , scopes_permission<>::verify<
                mpl::vector0<>
              , c2
              , mpl::false_
            >::type
         >::value
    ));
}

BOOST_AUTO_TEST_CASE(allow_requires) {
    BOOST_CHECK((
        contains_all<
            mpl::vector<>
          , scopes_permission<
                allow_scope<scopes::unique<>>
            >::verify<
                mpl::vector0<>
              , c2
              , mpl::false_
            >::type
         >::value
    ));
}

BOOST_AUTO_TEST_CASE(allow_some_of_requirements_order) {
    BOOST_CHECK((
        contains_all<
            mpl::vector<
                mpl::pair<aux::shared_ptr<int>, scopes::shared<>>
            >
          , scopes_permission<
                allow_scope<scopes::unique<>>
            >::verify<
                mpl::vector0<>
              , c24
              , mpl::false_
            >::type
         >::value
    ));
}

BOOST_AUTO_TEST_CASE(allow_all_of_requirements) {
    BOOST_CHECK((
        contains_all<
            mpl::vector0<>
          , scopes_permission<
                allow_scope<scopes::unique<>>, allow_scope<scopes::shared<>>
            >::verify<
                mpl::vector0<>
              , c24
              , mpl::false_
            >::type
         >::value
    ));
}

} // namespace policies
} // namespace di
} // namespace boost
