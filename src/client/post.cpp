#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#include "../nexmo.hpp"


void Nexmo::Client::post (std::string const url, std::string const body) {

    curlpp::Easy request;

    request.setOpt(new curlpp::options::Url(url));

    // Set the headers for sending json data
    std::list<std::string> header;
    header.push_back("Content-Type: application/json");
    request.setOpt(new curlpp::options::HttpHeader(header));

    // Configure the payload to send
    request.setOpt(new curlpp::options::PostFields(body));
    request.setOpt(new curlpp::options::PostFieldSize(body.length()));

    request.perform();
}
