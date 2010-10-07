#ifndef ___LOGGING_HPP___
#define ___LOGGING_HPP___

#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/SimpleLayout.hh>

using namespace std;


class Logger {
    log4cpp::Appender *appender;
    log4cpp::Layout *layout;

    void initialize(const string &level) {
        appender = new log4cpp::OstreamAppender("OstreamAppender", &cout);
        layout = new log4cpp::SimpleLayout();

        appender->setLayout(layout);
        category.setAppender(appender);
        set_priority(level);
    }

public:
    log4cpp::Category& category;
    Logger() : category(log4cpp::Category::getInstance("Category")) {
        initialize("WARN");
    }
    Logger(const string &level) : category(log4cpp::Category::getInstance("Category")) {
        initialize(level);
    }
    ~Logger() {
        category.removeAllAppenders();
    }

    void emerg(const string &msg) { category.emerg(msg); }
    void fatal(const string &msg) { category.fatal(msg); }
    void alert(const string &msg) { category.alert(msg); }
    void crit(const string &msg) { category.crit(msg); }
    void error(const string &msg) { category.error(msg); }
    void warn(const string &msg) { category.warn(msg); }
    void notice(const string &msg) { category.notice(msg); }
    void info(const string &msg) { category.info(msg); }
    void debug(const string &msg) { category.debug(msg); }

    void set_priority(const string &level) { 
        category.setPriority(log4cpp::Priority::getPriorityValue(level));
    }
};

#endif
