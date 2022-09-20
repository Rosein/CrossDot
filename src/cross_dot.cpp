#include "cross_dot.h"
#include <iostream>

void Display::setCharAt(char character, int position)
{
  board_[position - 1] = character;
}

void Display::setXat(int position) {
  setCharAt('X', position);
}

void Display::setOat(int position) {
  setCharAt('O', position);
}

std::string Display::getBoard() { return board_; }

std::string Display::draw()
{
  std::string output{
    board_.substr(0, 3) + "\n" +
    board_.substr(3, 3) + "\n" +
    board_.substr(6, 3) + "\n"};

  std::cout << output;

  return output;
}

Status Controller::play()
{
  for(int i = 0; i < 5; i++)
  {
    input_->enterInput();
  }
  
  return Status::XWon;
}