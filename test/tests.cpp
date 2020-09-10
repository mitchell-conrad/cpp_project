#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "sample_project/ipv4.h"
#include <sstream>

namespace sample_project::test {
TEST_CASE("initialization", "[ipv4]")
{
    constexpr auto test = ipv4(0, 0, 0, 0);
    REQUIRE(test.octets() == std::array<uint8_t, 4>{0, 0, 0, 0});
}

TEST_CASE("equality", "[ipv4]")
{
    constexpr auto a = ipv4(123, 123, 123, 123);
    constexpr auto b = ipv4(123, 123, 123, 123);
    constexpr auto c = ipv4(123, 123, 123, 12);
    REQUIRE(a == b);
    REQUIRE(a != c);
}

TEST_CASE("from string", "[ipv4]")
{
    auto test = ipv4("192.168.111.230");
    REQUIRE(test == ipv4(192, 168, 111, 230));

    auto short_test = ipv4("1.1.1.1");
    REQUIRE(short_test == ipv4(1, 1, 1, 1));

    REQUIRE_THROWS_AS(ipv4("invalid_ipv4str"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("192.168.111.230.123"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("300.168.111.230"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("200.168.111"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("192.168.111.2a1"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("   192.16.11.2"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("192..168.1"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("...."), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4(".168.111.230"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("aaa.aaa.aaa.aaa"), std::invalid_argument);
    REQUIRE_THROWS_AS(ipv4("1 2.168.1 1.230"), std::invalid_argument);
}

TEST_CASE("constants", "[ipv4]")
{
    constexpr auto localhost = ipv4::localhost();
    REQUIRE(localhost == ipv4(127, 0, 0, 1));

    constexpr auto broadcast = ipv4::broadcast();
    REQUIRE(broadcast == ipv4(255, 255, 255, 255));

    constexpr auto unspecified = ipv4::unspecified();
    REQUIRE(unspecified == ipv4(0, 0, 0, 0));
}

TEST_CASE("ostream", "[ipv4]")
{
    constexpr auto unspecified = ipv4::unspecified();
    std::ostringstream stream;
    stream << unspecified;
    REQUIRE(stream.str() == "0.0.0.0");
}

TEST_CASE("to string", "[ipv4]")
{
    constexpr auto unspecified = ipv4::unspecified();
    REQUIRE(unspecified.to_string() == "0.0.0.0");

    std::string test_string{"192.168.111.230"};
    REQUIRE(ipv4(test_string).to_string() == test_string);
}

TEST_CASE("copy construct", "[ipv4]")
{
    auto unspecified = ipv4::unspecified();
    auto copy_assign = unspecified;
    REQUIRE(unspecified == copy_assign);

    auto copy_construct{unspecified};
    REQUIRE(unspecified == copy_construct);
}

TEST_CASE("compare", "[ipv4]")
{
    auto unspecified = ipv4::unspecified();
    auto broadcast = ipv4::broadcast();
    auto mid = ipv4{100, 100, 100, 100};

    REQUIRE(unspecified < mid);
    REQUIRE(mid > unspecified);
    REQUIRE(unspecified < broadcast);
    REQUIRE(mid < broadcast);

    REQUIRE(unspecified >= unspecified);
    REQUIRE(mid >= unspecified);
    REQUIRE(mid >= mid);
    REQUIRE(broadcast >= mid);
    REQUIRE(broadcast >= broadcast);
}
} // namespace sample_project::ipv4::test