#include <string>


class Nexmo {
public:
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
};
