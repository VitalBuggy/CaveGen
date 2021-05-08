#pragma once
class Cell {
public:
  enum Types {
    EMPTY = 0,
    WALL = 1,
  };

  Cell::Types type;

  Cell() { this->type = Cell::Types::EMPTY; }

  void SetType(Cell::Types t) { this->type = t; }
  Cell::Types GetType() { return this->type; }
};