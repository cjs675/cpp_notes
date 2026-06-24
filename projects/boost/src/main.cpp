#include "../include/blacklist.hpp"
#include <fmt/core.h> 
#include <fmt/color.h> 
#include <vector>


int main() {
    fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "--- Security Blacklist System ---\n");

    PasswordBlacklist securitySystem;
    securitySystem.loadFromJson("passwords.json");

    // test of passwords 
    std::vector<std::string> test_attempts = {
        "admin",
        "MySecurePass99",
        "qwerty",
        "hello_world"
    }; 

    for (const auto& attempt : test_attempts) {
        if (securitySystem.isBanned(attempt)) {
            fmt::print(fg(fmt::color::red), "[BLOCKED] '{}' is on the blacklist\n", attempt);
        } else {
            fmt::print(fg(fmt::color::green), "[ALLOWED] '{}' looks safe \n", attempt);
        }
    } 

    return 0;

}
