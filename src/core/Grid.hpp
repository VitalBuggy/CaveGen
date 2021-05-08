#pragma once
#include "./Cell.hpp"
#include <vector>

class Grid {
private:
  std::vector<std::vector<Cell>> grid;
  std::vector<std::vector<Cell>> grid_tmp;

  std::pair<int, int> CountNeighbors(int x, int y) {
    std::pair<int, int> out = {0, 0};

    for (int dx = -1; dx <= 1; dx++)
      for (int dy = -1; dy <= 1; dy++)
        if (!(dx == 0 && dy == 0)) {
          Cell cell = this->grid[(x + dx + this->width) % this->width]
                                [(y + dy + this->height) % this->height];
          if (cell.GetType() == Cell::Types::EMPTY)
            out.first++;
          else if (cell.GetType() == Cell::Types::WALL)
            out.second++;
        }

    return out;
  }

  int height, width, seed;

public:
  Grid(int height, int width, int seed) {
    this->height = height;
    this->width = width;
    this->seed = seed;

    this->grid.resize(this->height);
    ;
    this->grid_tmp.resize(this->height);
    ;
    for (int i = 0; i < this->height; i++) {
      this->grid[i].resize(this->width);
      this->grid_tmp[i].resize(this->width);
    }
  }

  void FillGrid() {
    srand(this->seed);

    for (int i = 0; i < height; i++)
      for (int j = 0; j < width; j++)
        grid[i][j].SetType(rand() % 100 < 53 ? Cell::Types::WALL : Cell::Types::EMPTY);
  }

  Cell GetCell(int x, int y) { return grid[x][y]; }

  void simulate() {
    for (int i = 0; i < this->height; i++)
      for (int j = 0; j < this->width; j++)
        this->grid_tmp[i][j] = this->grid[i][j];

    for (int i = 0; i < this->height; i++)
      for (int j = 0; j < this->width; j++)
        switch (this->grid[i][j].GetType()) {
        case Cell::Types::EMPTY:
          if (CountNeighbors(i, j).second > 4)
            this->grid_tmp[i][j].SetType(Cell::Types::WALL);
          continue;
        case Cell::Types::WALL:
          if (CountNeighbors(i, j).first > 4)
            this->grid_tmp[i][j].SetType(Cell::Types::EMPTY);
          continue;
        }

    for (int i = 0; i < this->height; i++)
      for (int j = 0; j < this->width; j++)
        grid[i][j] = grid_tmp[i][j];
  }
};
