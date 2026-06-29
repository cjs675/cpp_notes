#include "../include/blacklist.hpp"
#include <nlohmann/json.hpp>
#include <fmt/core.h>
#include <fmt/color.h> 
#include <fstream> 
#include <iostream> 

using json = nlohmann::json;

// init bloom filter with capacity of 10,000 bits 
PasswordBlacklist::PasswordBlacklist() : filter(10000) {}

void PasswordBlacklist::loadFromJson(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        fmt::print(fg(fmt::color::red), "Error: could not open {}\n", filepath);
        return;
    }


    json data = json::parse(file);
    int count = 0;

    // insert each password from json into our bloom filter 
    for (const auto& pw : data["banned_passwords"]) { 
        filter.insert(pw.get<std::string>());
        count++;
    }
 
    fmt::print(fg(fmt::color::green), "Loaded {} banned passwords into the filter.\n", count); 
}
 
bool PasswordBlacklist::isBanned(const std::string& password) const {
    return filter.may_contain(password);
} 

