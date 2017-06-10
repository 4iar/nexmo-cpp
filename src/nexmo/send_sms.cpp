#include "json.hpp"

#include "../nexmo.hpp"


using json = nlohmann::json;

void Nexmo::sendSms(std::string sender, std::string recipient, std::string message) {

    json body;
    body["api_key"] = this->key;
    body["api_secret"] = this->secret;
    body["to"] = sender;
    body["from"] = recipient;
    body["text"] = message;

    std::string url = "https://rest.nexmo.com/sms/json";


    this->client.post(url, body.dump());
};
