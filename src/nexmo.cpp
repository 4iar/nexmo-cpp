#include <iostream>
#include <string>

#include "nexmo.hpp"


Nexmo::Nexmo () {
}

Nexmo::Nexmo (std::string api_key, std::string api_secret) {
    key = api_key;
    secret = api_secret;
}
