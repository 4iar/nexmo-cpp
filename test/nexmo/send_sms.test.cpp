#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/json.hpp"

#include "../mock_client.hpp"
#include "../../src/nexmo.hpp"

using ::testing::AtLeast;
using ::testing::_;
using json = nlohmann::json;


TEST(sendSmsTest, calls) {
    std::string key = "API_KEY";
    std::string secret = "API_SECRET";

    MockClient client;
    Nexmo nexmo(key, secret, &client);

    std::string sender = "441632960960";
    std::string recipient = "441632960960";
    std::string message = "Hello from Nexmo";

    const std::string expected_url = "https://rest.nexmo.com/sms/json";
    json expected_body;
    expected_body["api_key"] = key;
    expected_body["api_secret"] = secret;
    expected_body["to"] = recipient;
    expected_body["from"] = sender;
    expected_body["text"] = message;

    EXPECT_CALL(client, post(expected_url, expected_body.dump()))
        .Times(AtLeast(1));

    nexmo.sendSms(sender, recipient, message);
}