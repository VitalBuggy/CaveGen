#include "./core/Automaton.h"

int main(int argc, char *argv[]) {
  Automaton a(800, 600, 4, "Cave Gen");
  (argc < 2 ? a.run() : a.run(atoi(argv[1])));

  return 0;
}
