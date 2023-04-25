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

#ifndef GTP_H_INCLUDE
#define GTP_H_INCLUDE

#include "Engine.h"
#include "Utils.h"
#include "CLInterface.h"

#include <memory>
#include <string>

class GTP : public CLInterface {
public:
    GTP();
    GTP(const GTP&) = delete;
    GTP& operator=(const GTP&) = delete;

private:
    virtual void init();

    virtual void loop();

    virtual std::string execute(Utils::CommandParser &parser);

    std::unique_ptr<Engine> m_gtp_engine{nullptr};
};

#endif
