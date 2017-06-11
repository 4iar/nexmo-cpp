#include <string>
#include <iostream>

#include "nexmo.hpp"


int main () {
    std::string key = "API_KEY";
    std::string secret = "API_SECRET";

    Nexmo nexmo(key, secret);

    std::string sender = "4412345678";
    std::string recipient = "441234759";
    std::string message = "this is a message";

    std::cout << nexmo.sendSms(sender, recipient, message);
};
