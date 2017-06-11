#include <gmock/gmock.h>
#include <string>

#include "../src/client.hpp"


class MockClient : public Client {
public:
    MOCK_METHOD2(post, void(std::string const url, std::string const body));
};
