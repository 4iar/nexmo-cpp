#include "json.hpp"

#include "../client.hpp"
#include "../nexmo.hpp"


using json = nlohmann::json;

std::string Nexmo::sendSms(std::string sender, std::string recipient, std::string message) {
    // Construct the request
    json body;
    body["api_key"] = this->key;
    body["api_secret"] = this->secret;
    body["to"] = recipient;
    body["from"] = sender;
    body["text"] = message;
    std::string url = "https://rest.nexmo.com/sms/json";

    return this->client->post(url,body.dump());
};
