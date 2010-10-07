#include <time.h>
#include "Logging.hpp"

int main() {
    Logger logger;
    logger.info("This is for tracing the flow");
    logger.notice("This is to notify certain events");
    logger.warn("This is to generate certain warnings");
    logger.set_priority("DEBUG");
    logger.info("This is for tracing the flow");
    logger.notice("This is to notify certain events");
    logger.warn("This is to generate certain warnings");

    return 0;
}
