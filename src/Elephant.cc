/*
    This file is part of ElephantArt.
    Copyright (C) 2021 Hung-Zhe Lin

    ElephantArt is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ElephantArt is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ElephantArt.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ASCII.h"
#include "GTP.h"
#include "UCCI.h"
#include "Selfplay.h"
#include "config.h"
#include "Utils.h"

#include <iostream>
#include <string>
#include <sstream>
#include <memory>

const static std::string get_license() {
    auto out = std::ostringstream{};
    if (!option<bool>("quit_license")) {
        out << "    ";
        out << PROGRAM << " " << VERSION << " Copyright (C) 2021  Hung-Zhe Lin"    << std::endl;
        out << "    This program comes with ABSOLUTELY NO WARRANTY."               << std::endl;
        out << "    This is free software, and you are welcome to redistribute it" << std::endl;
        out << "    under certain conditions; see the COPYING file for details."   << std::endl;
    }
    return out.str();
}

static void ascii_loop() {
    auto ascii = std::make_unique<ASCII>();
}

static void gtp_loop() {
    auto gtp = std::make_unique<GTP>();
}

static void ucci_loop() {
    auto ucci = std::make_unique<UCCI>();
}

static void selfplay_loop() {
    auto selfplay = std::make_unique<Selfplay>();
}

int main(int argc, char **argv) {
    const auto args = ArgsParser(argc, argv);
    args.dump();

    LOGGING << get_license();

    init_basic_parameters();
        gtp_loop();
/*
    if (option<std::string>("mode") == "ascii") {
        ascii_loop();
    } else if (option<std::string>("mode") == "gtp") {
        gtp_loop();
    } else if (option<std::string>("mode") == "ucci") {
        ucci_loop();
    } else if (option<std::string>("mode") == "selfplay") {
        selfplay_loop();
    }
*/
    return 0;
}
