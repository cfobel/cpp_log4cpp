#include <stdio.h>
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/SimpleLayout.hh>

using namespace std;

int main()
{
    /*Setting up Appender, layout and Category*/
    log4cpp::Appender *appender = new log4cpp::OstreamAppender("OstreamAppender", &cout);
    log4cpp::Layout *layout = new log4cpp::SimpleLayout();
    log4cpp::Category& category = log4cpp::Category::getInstance("Category");

    appender->setLayout(layout);
    category.setAppender(appender);
    category.setPriority(log4cpp::Priority::WARN);

    /*The actual logging*/
    category.info("This is for tracing the flow");
    category.notice("This is to notify certain events");
    category.warn("This is to generate certain warnings");
}
