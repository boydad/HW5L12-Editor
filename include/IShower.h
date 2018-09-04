#pragma once

struct IShower{
  virtual void show(const Board& board) = 0;
  virtual ~IShower() = default;
};