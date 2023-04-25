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

#include "GTP.h"

#include <functional>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

GTP::GTP() {
    init();
    loop();
}

void GTP::init() {
    if (m_gtp_engine == nullptr) {
        m_gtp_engine = std::make_unique<Engine>();
    }
    m_gtp_engine->initialize();
}

void GTP::loop() {
    while (true) {
        //m_gtp_engine->display();

        auto input = std::string{};
        if (std::getline(std::cin, input)) {

            auto parser = Utils::CommandParser(input);
            WRITING << ">>" << ' ' << input << std::endl;

            if (!parser.valid()) {
                LOGGING << "No input command." << std::endl;
                continue;
            }

            if (parser.get_count() == 1 && parser.find("quit")) {
                break;
            }
            auto out = execute(parser);
            LOGGING << out << std::endl;
        }
    }
}

std::string GTP::execute(Utils::CommandParser &parser) {
    auto out = std::ostringstream{};
    const auto lambda_syntax_not_understood =
        [&](Utils::CommandParser &p, size_t ignore) -> void {

        if (p.get_count() <= ignore) return;
        out << "Syntax not understood: ";
        out << p.get_commands(ignore)->str << std::endl;
    };

    if (const auto res = parser.find("list_commands", 0)) {
      printf("= protocol_version\n");
      printf("name\n");
      printf("version\n");
      printf("known_command\n");
      printf("list_commands\n");
      printf("clear_board\n");
      printf("play\n");
      printf("genmove\n");
      printf("boardsize\n");
      printf("list_games\n");
      printf("set_game\n\n");
    } else if (const auto res = parser.find("protocol_version", 0)) {
      printf("= 2\n");
    } else if (const auto res = parser.find("name", 0)) {
      printf("= ElephantArt\n");
    } else if (const auto res = parser.find("version", 0)) {
      printf("= 1.0.0\n");
    } else if (const auto res = parser.find("list_games", 0)) {
      printf("= chinese chess\n");
    } else if (const auto res = parser.find("boardsize", 0)) {
      printf("= \n");
    } else if (const auto res = parser.find("clear_board", 0)) {
      printf("= \n");
    } else if (const auto res = parser.find("set_game", 0)) {
      printf("= \n");
    } else if (const auto res = parser.find("play", 0)) {
        lambda_syntax_not_understood(parser, 3);
        const auto move = parser.get_command(2)->str;
        const auto gtp_out = m_gtp_engine->do_gtpmove(move);
      printf("= \n");
    } else if (const auto res = parser.find("genmove", 0)) {
      lambda_syntax_not_understood(parser, 2);
      const auto cnt = parser.get_count();
      if (cnt == 1) {
        out << m_gtp_engine->gtp_move();
      //printf("= \n");
      }
    } else  {
      printf("? unknown command\n");
    }

    return out.str();
}

