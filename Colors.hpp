#ifndef Colors_h
#define Colors_h
#include <string>
struct Colors{
   const std::string none = "\033[0m",
        black  = "\033[30m",
        red = "\033[31m",
        green = "\033[32m",
        yellow = "\033[33m",
        blue = "\033[34m",
        pink = "\033[35m",
        cyan = "\033[36m";
};

#endif
