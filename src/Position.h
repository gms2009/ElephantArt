/*
    This file is part of Saya.
    Copyright (C) 2020 Hung-Zhe, Lin

    Saya is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Saya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Saya.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef POSITION_H_INCLUDE
#define POSITION_H_INCLUDE

#include "Board.h"

#include <vector>
#include <memory>


class Position {
public:
    void init_game();

    Board board;

    void display() const;

    std::vector<Move> get_movelist() const;

    Types::Color get_to_move() const;

    bool fen2board(std::string &fen);
    
    bool is_legal(Move move) const;

private:
    std::vector<std::shared_ptr<const Board>> m_history;


};

#endif
