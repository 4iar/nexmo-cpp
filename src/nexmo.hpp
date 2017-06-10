#pragma once

#include <string>


class Nexmo {
private:
    // API credentials
    std::string key;
    std::string secret;

    struct Client {
        void post (std::string const url, std::string const body);
    };

    Client client;

public:
    Nexmo () {};
    Nexmo (std::string key, std::string secret) {
        this->key = key;
        this->secret = secret;
    };

    void sendSms(std::string sender, std::string recipient, std::string message);
};
