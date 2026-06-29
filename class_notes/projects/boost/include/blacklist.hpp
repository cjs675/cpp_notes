#pragma once 
#include <boost/bloom/filter.hpp> 
#include <string> 

class PasswordBlacklist {
    private: 
        boost::bloom::filter<std::string, 5> filter;

    public:
        PasswordBlacklist();
        void loadFromJson(const std::string& filepath);
        bool isBanned(const std::string& password) const;
};
