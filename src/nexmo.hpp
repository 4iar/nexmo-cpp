#pragma once

#include <string>


class Nexmo {
private:
    // API credentials
    std::string key;
    std::string secret;

    Nexmo ();
    Nexmo (std::string api_key, std::string api_secret);

    class message {
    };

    class call {
    };

    class verify {
    };

    void sendSms(std::string sender, std::string recipient, std::string message);
};
