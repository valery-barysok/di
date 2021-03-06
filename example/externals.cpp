//
// Copyright (c) 2012-2015 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

//[externals
//<-
#include <cassert>
#include <memory>
//->
#include <boost/di.hpp>

namespace di = boost::di;

//<-
struct interface { virtual ~interface() noexcept = default; };
struct implementation1 : interface { };
struct implementation2 : interface { };
//->

struct example {
    example(std::shared_ptr<interface> p, int i) {
        assert(dynamic_cast<implementation2*>(p.get()));
        assert(i == 42);
    }
};

int main() {
    /*<<create injector with `interface` binding to `implementation1`>>*/
    auto config = di::make_injector(
        di::bind<interface, implementation1>
    );

    /*<<create injector with external `interface` binding to `implementation2`>>*/
    auto injector = di::make_injector(
        config
      , di::bind<int>.to(42)
      , di::bind<interface>.to(std::make_shared<implementation2>()) [di::override]
    );

    /*<<create `example`>>*/
    injector.create<example>();
}

//]

