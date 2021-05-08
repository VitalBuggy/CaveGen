#include "./Automaton.h"
#include "./../include/raylib-cpp.hpp"
#include <vector>

void Automaton::setup(int seed) {
  SetTargetFPS(30);

  this->grid = new Grid(this->HEIGHT + 1, this->WIDTH + 1, seed);
  this->grid->FillGrid();
}

void Automaton::render() {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  for (int i = 0; i < this->HEIGHT; i++)
    for (int j = 0; j < this->WIDTH; j++)
      if (this->grid->GetCell(i, j).GetType() == Cell::Types::EMPTY)
        DrawRectangle(i * this->pixel_size, j * this->pixel_size,
                      this->pixel_size, this->pixel_size,
                      CLITERAL(Color){191, 189, 176, 255});
      else if (this->grid->GetCell(i, j).GetType() == Cell::Types::WALL)
        DrawRectangle(i * this->pixel_size, j * this->pixel_size,
                      this->pixel_size, this->pixel_size,
                      CLITERAL(Color){66, 70, 99, 255});

  std::string s = "N: ";
  s += std::to_string(this->gen_count);
  DrawText(s.c_str(), 5, 5, 30, CLITERAL(Color){255, 0, 0, 255});

  EndDrawing();
}

void Automaton::processEvents() {
  if (IsKeyPressed(KEY_SPACE)) {
    this->grid->simulate();
    gen_count++;
  }
}

void Automaton::run(int seed) {
  this->setup(seed);
  while (!this->window->ShouldClose()) {
    this->processEvents();
    this->update();
    this->render();
  }
}

void Automaton::update() {}