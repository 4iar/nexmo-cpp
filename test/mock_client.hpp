#include <gmock/gmock.h>
#include <string>

#include "../src/client.hpp"


class MockClient : public Client {
public:
    MOCK_METHOD2(post, std::string(std::string const url, std::string const body));
};