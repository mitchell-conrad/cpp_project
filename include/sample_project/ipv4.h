#ifndef SAMPLE_PROJECT_IPV4_H
#define SAMPLE_PROJECT_IPV4_H
#include <array>
#include <ostream>
#include <string>

namespace sample_project {

class ipv4 {
public:
    [[deprecated("Use ipv4 constructor instead.")]] [[nodiscard]] static auto
    from_string(const std::string& addr_string) -> ipv4
    {
        return ipv4(addr_string);
    }

    [[deprecated("Use ipv4 constructor instead.")]] [[nodiscard]] constexpr static auto
    from_ints(const uint8_t a, const uint8_t b, const uint8_t c, const uint8_t d) -> ipv4
    {
        return ipv4(a, b, c, d);
    };

    [[deprecated("Use ipv4 constructor instead.")]] [[nodiscard]] constexpr static auto
    from_array(const std::array<uint8_t, 4>& array) -> ipv4
    {
        return ipv4(array);
    }

    [[nodiscard]] constexpr static auto unspecified() -> ipv4 { return ipv4(0, 0, 0, 0); }

    [[nodiscard]] constexpr static auto broadcast() -> ipv4 { return ipv4(255, 255, 255, 255); }

    [[nodiscard]] constexpr static auto localhost() -> ipv4 { return ipv4(127, 0, 0, 1); }

    [[nodiscard]] constexpr auto octets() const -> std::array<uint8_t, 4> { return addr_; }

    [[nodiscard]] auto to_string() const -> std::string;

    constexpr explicit ipv4(const std::array<uint8_t, 4>& array) :
        ipv4(array[0], array[1], array[2], array[3])
    {
    }

    constexpr ipv4(const uint8_t a, const uint8_t b, const uint8_t c, const uint8_t d) :
        addr_{a, b, c, d}
    {
    }

    /// Construct ipv4 addr from a string.
    /// Expected format 123.123.123.123 or as a regex (^\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}$)
    explicit ipv4(const std::string& addr_string);

    /// Copy/move constructor
    constexpr ipv4(const ipv4&) = default;
    constexpr ipv4(ipv4&&) = default;

    /// Copy/move assignment operator
    constexpr auto operator=(const ipv4&) -> ipv4& = default;
    constexpr auto operator=(ipv4&&) -> ipv4& = default;

private:
    std::array<uint8_t, 4> addr_;
};

inline auto operator<<(std::ostream& out, const ipv4& addr) -> std::ostream&
{
    return out << addr.to_string();
}


// A three way comparison operator would be great here
inline auto operator==(const ipv4& a, const ipv4& b)
{
    return a.octets() == b.octets();
}
inline auto operator!=(const ipv4& a, const ipv4& b)
{
    return !(a == b);
}
inline auto operator<(const ipv4& a, const ipv4& b)
{
    return std::lexicographical_compare(a.octets().begin(), a.octets().end(), b.octets().begin(),
                                        b.octets().end());
}
inline auto operator>=(const ipv4& a, const ipv4& b) {
    return !(a < b);
}
inline auto operator>(const ipv4& a, const ipv4& b) {
    return b < a;
}
inline auto operator<=(const ipv4& a, const ipv4& b) {
    return !(b < a);
}
} // namespace sample_project

#endif // CPP_UTIL_IPV4_HPP