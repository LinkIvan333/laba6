// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <picosha2.h>
#include <logs.h>
#include <regex>
#include <string>
#include <iostream>
#include <thread>
using namespace std;

namespace header {

    void tryregex(string s) {
        std::string hash_hex_str;
        picosha2::hash256_hex_string(s.begin(),s.end(), hash_hex_str);
        if (std::regex_match(hash_hex_str, regex {R"(\w{60}+[0]{4})"})) {
            logs::info(s,hash_hex_str);
        }
    }

    void runner(int random){
        while(true){
            srand(time(nullptr)+random);
            unsigned int a = rand()%10000;
            tryregex(to_string(a));
        }
    }

    void startTreads(){
        std::vector<std::thread> threads;
        for(unsigned int i = 0; i < std::thread::hardware_concurrency(); i++)
            threads.emplace_back(thread(runner,i));
        for(auto& th : threads)
            th.join();
    }
}
#endif // INCLUDE_HEADER_HPP_
