//
// Copyright (c) 2012-2015 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#include "boost/di/concepts/configurable.hpp"
#include "boost/di/providers/heap.hpp"

namespace boost { namespace di { inline namespace v1 { namespace concepts {

test none = [] {
    class config { };
    static_expect(!configurable<config>());
};

test just_policies = [] {
    class config {
    public:
        auto policies() const noexcept { return 0; }
    };
    static_expect(!configurable<config>());
};

test just_provider = [] {
    class config {
    public:
        auto provider() const noexcept { return 0; }
    };
    static_expect(!configurable<config>());
};

test private_access = [] {
    class config {
    private:
        auto policies() const noexcept { return 0; }
        auto provider() const noexcept { return 0; }
    };
    static_expect(!configurable<config>());
};

test inheritance = [] {
    class config_ {
    public:
        auto policies() const noexcept { return 0; }
        auto provider() const noexcept { return providers::heap{}; }
    };
    class config : public config_ { };
    static_expect(configurable<config>());
};

test all = [] {
    class config {
    public:
        auto policies() const noexcept { return 0; }
        auto provider() const noexcept { return providers::heap{}; }
    };

    static_expect(configurable<config>());
};

}}}} // boost::di::v1::concepts

