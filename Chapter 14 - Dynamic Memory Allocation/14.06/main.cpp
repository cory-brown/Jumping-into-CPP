/*

Jumping into C++

Chapter 14
Practice Problem

6. Write a program that takes a width and a height and dynamically generates a maze with the
given width and height. The maze must always have a valid path through it (how can you ensure
this?) Print the maze to the screen once it’s been generated.

*/


#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void initMaze(int **mazeGrid, int h, int w);
void createMaze(int **mazeGrid, int h, int w);
void direction(int h, int w);
void printMaze(int **mazeGrid, int h, int w);
void deallocateMaze(int **mazeGrid, int h);

int main() {
  int h, w;
  cout << "Welcome to the maze" << endl;
  cout << "First you must choose the size of your maze" << endl;
  cout << "Please the enter the height of the maze" << endl;
  cin >> h;
  cout << "Please the enter the width of the maze" << endl;
  cin >> w;

  int **mazeGrid = new int *[h];
  for (int i = 0; i < h; ++i) {
    mazeGrid[i] = new int[w];
  }
  initMaze(mazeGrid, h, w);
  createMaze(mazeGrid, h, w);
  printMaze(mazeGrid, h, w);
  deallocateMaze(mazeGrid, h);
}

void initMaze(int **mazeGrid, int h, int w) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      mazeGrid[i][j] = 0;
    }
  }
}

void createMaze(int **mazeGrid, int h, int w) {
  srand(time(NULL));
  bool running = true;
  while (running) {
    int hNum = rand() % h;
    int wNum = rand() % w;

    if ((hNum == 0 || hNum == h - 1) || (wNum == 0 || wNum == h - 1)) {
      mazeGrid[hNum][wNum] = 1;
      running = !running;
    }
  }
}

void printMaze(int **mazeGrid, int h, int w) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << " " << mazeGrid[i][j] << " ";
    }
    cout << endl;
  }
}

void deallocateMaze(int **mazeGrid, int h) {
  for (int i = 0; i < h; ++i) {
    delete[] mazeGrid[i];
  }
  delete[] mazeGrid;
}
