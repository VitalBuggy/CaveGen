# Generating Caves using Cellular Automaton

This is the second project I have fully completed that has something to do with Cellular Automaton. This time around, I decided to do something slightly harder than [RPSCellularAutomaton](https://github.com/VitalBuggy/RPSCellularAutomaton). Though a lot of the infrastructure and core logic is the same, in order to make things a bit more interesting for myself, I decided to add more abstraction to my code. This can be seen from the file structure of the project. Though mostly the same, there are more files, meaning that the process of decomposing the problem can be seen slightly more clearly in this iteration of one of my projects to do with CellularAutomaton.

## Build Instructions

### Linux

- Start off by cloning the repository in a folder of your choice

 ```sh
 git clone https://github.com/VitalBuggy/CaveGen
 ```

- In order to build, just go into the directory and run `make`

 ```sh
 cd CaveGen && make
 ```

- A binary is going to be created in the folder `bin/`, in order to run it just do

 ```sh
 ./bin/app
 ```

 in the project root

### Windows

TODO

### OSX

TODO

## Results

These are the different results after 20 itertions of the algorithm

![image](https://raw.githubusercontent.com/VitalBuggy/CaveGen/master/images/cellular_automaton.png "0-20 iterations of algorithm")

## Usage

A "quality of life" feature in this program is seeding. You can pass a seed in as an argument and you will generate the same cave as such

```sh
./bin/app <seed>
```

In the future I plan to add some more bells and whistles such as: dynamically adjustable wall density (the initial ratio of wall cells and empty cells) and saving generated caves as images

## Documentation

TODO

## Contribution

In order to contribute, please feel free to submit a pull request, I review pull requests within 48 hours of submission
