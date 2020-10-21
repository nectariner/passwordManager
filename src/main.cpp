#include <iostream>
#include "logging.h"

int main() {
    logging::log(logging::INFO, __func__, "Program just started");
    logging::log(logging::INFO, __func__);
    return 0;
}