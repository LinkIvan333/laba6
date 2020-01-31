//
// Created by zamot on 30.01.2020.
//
#include <boost/log/trivial.hpp>
#ifndef SOURCE_LOGS_H
#define SOURCE_LOGS_H


#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace logs{
    void info(std::string s, std::string hash){
        auto id = std::this_thread::get_id();
        BOOST_LOG_TRIVIAL(info) << " THREAD " << id
                                 << ": [INPUT DATA - " << s
                                 << ", HASH - " << hash << "]\n";

    }



}

#endif //SOURCE_LOGS_H
