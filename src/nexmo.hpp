#pragma once

#include <string>
#include "client.hpp"


class Nexmo {
private:
    // API credentials
    std::string key;
    std::string secret;

    Client* client;
public:
    Nexmo () {};
    Nexmo (std::string key, std::string secret) {
        this->key = key;
        this->secret = secret;
        this->client = new Client;
    };
    Nexmo (std::string key, std::string secret, Client* new_client) {
        this->key = key;
        this->secret = secret;
        this->client = new_client;
    };
    std::string sendSms(std::string sender, std::string recipient, std::string message);
};
