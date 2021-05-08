#include "raylib-cpp.hpp"
#include "Grid.hpp"
#include <vector>

class Automaton {
private:
  void update();
  void render();
  void processEvents();
  void setup(int seed);
  int gen_count = 0;
  // std::vector<int> countNeighbors(int, int);
public:
  Automaton(int height, int width, int pixel_size,
            std::string window_name = "Cellular Automaton") {
    this->HEIGHT = height / pixel_size;
    this->WIDTH = width / pixel_size;
    this->pixel_size = pixel_size;
    this->WINDOW_NAME = window_name;
    this->window = new raylib::Window(height, width, this->WINDOW_NAME);
  }
  void run(int seed = time(0));

private:
  int HEIGHT;
  int WIDTH;
  int pixel_size;
  Grid *grid;
  raylib::Window *window;
  std::string WINDOW_NAME;
};