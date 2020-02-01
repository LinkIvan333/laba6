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
namespace logs{

        void init() {
            auto logFileT = boost::log::add_file_log(
                    boost::log::keywords::file_name = "logs/log_trace.log",
                    boost::log::keywords::rotation_size = 128 * 1024 * 1024,
                    boost::log::keywords::format =
                            (boost::log::expressions::stream << boost::log::expressions::format_date_time<boost::posix_time::ptime>(
                                    "TimeStamp", "%Y-%m-%d %H:%M:%S")
                                          << ": <" << boost::log::trivial::severity << "> "
                                          << boost::log::expressions::smessage));
            logFileT->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
            auto logFileI = boost::log::add_file_log(
                    boost::log::keywords::file_name = "logs/log_info.log",
                    boost::log::keywords::rotation_size = 128 * 1024 * 1024,
                    boost::log::keywords::format =
                            (boost::log::expressions::stream << boost::log::expressions::format_date_time<boost::posix_time::ptime>(
                                    "TimeStamp", "%Y-%m-%d %H:%M:%S")
                                                             << ": <" << boost::log::trivial::severity << "> "
                                                             << boost::log::expressions::smessage));
            logFileI->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
        }

        void logTrace(const std::string &data, const std::string &hash) {
            auto id = boost::this_thread::get_id();
            BOOST_LOG_TRIVIAL(trace) << " THREAD #" << id
                                     << ": [INPUT DATA - " << data
                                     << ", HASH - " << hash << "]\n";
        }

        void logInfo(const std::string &data, const std::string &hash) {
            auto id = boost::this_thread::get_id();
            BOOST_LOG_TRIVIAL(info) << "THREAD #" << id
                                    << ": [INPUT DATA - " << data
                                    << ", HASH - " << hash << "]\n";
        }
}

#endif //SOURCE_LOGS_H
