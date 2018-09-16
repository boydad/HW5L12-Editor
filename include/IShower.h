#pragma once

#include "board.h"

struct IShowing{
  virtual void show(const Board& board) = 0;
  virtual ~IShowing() = default;
};
