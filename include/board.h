#pragma once
#include <array>


namespace{
  const size_t boardSize = 1000;
}

using Board = std::array< std::array<int, boardSize> , boardSize>;
