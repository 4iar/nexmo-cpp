#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/json.hpp"

#include "../mock_client.hpp"
#include "../../src/nexmo.hpp"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;
using json = nlohmann::json;


// Test fixtures
class SendSmsTest : public ::testing::Test {
public:
    MockClient client;
    Nexmo nexmo;

    // API credentials
    std::string key = "API_KEY";
    std::string secret = "API_SECRET";

    // Message details
    std::string sender = "441632960960";
    std::string recipient = "441632960960";
    std::string message = "Hello from Nexmo";

    std::string expected_url = "https://rest.nexmo.com/sms/json";
    json expected_body;

    void SetUp() {
        nexmo = Nexmo(key, secret, &client);

        expected_body["api_key"] = key;
        expected_body["api_secret"] = secret;
        expected_body["to"] = recipient;
        expected_body["from"] = sender;
        expected_body["text"] = message;
    };
};

TEST_F(SendSmsTest, callsClientAppropriately) {
    EXPECT_CALL(client, post(expected_url, expected_body.dump()))
        .Times(AtLeast(1));

    nexmo.sendSms(sender, recipient, message);
}

TEST_F(SendSmsTest, handlesResponseData) {
    std::string fake_response = "{messages: [{fakeresponsedata}]}";

    EXPECT_CALL(client, post(expected_url, expected_body.dump()))
        .WillOnce(Return(fake_response));

    const std::string response = nexmo.sendSms(sender, recipient, message);

    EXPECT_EQ(fake_response, response);
}
