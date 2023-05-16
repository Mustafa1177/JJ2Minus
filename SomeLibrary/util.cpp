#include "pch.h"
#include "util.h"

#include <direct.h>

#include <string>

std::string getCCWD() {
    char cwd[1024];
    if (_getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::string cwdString(cwd);
        return cwdString + "/minus.ini";
    }
    return "";
}
