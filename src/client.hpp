#pragma once

#include <string>


class Client {
public:
    // Define these as virtual methods for easy compatibility with gmock
    virtual ~Client () {};
    virtual std::string post (std::string const url, std::string const body);
};