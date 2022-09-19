#include "cross_dot.h"
#include <iostream>

void Display::setXat(int position) {
  board_[position - 1] = 'X';
  return;
}

void Display::setOat(int position) {
  board_[position - 1] = 'O';
  return;
}

std::string Display::getBoard() { return board_; }

std::string Display::draw()
{

    std::string output {board_.substr(0, 3) + "\n" +
           board_.substr(3, 3) + "\n" +
           board_.substr(6, 3) + "\n"};

    std::cout<<output;

    return output;
}