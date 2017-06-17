// #include <stdio.h>
//
// // C recursive function to solve tower of hanoi puzzle
// void towerOfHanoi(int n, char fromrod, char torod, char auxrod)
// {
// 	if (n == 1)
// 	{
// 		printf("\n Move disk 1 from rod %c to rod %c", fromrod, torod);
// 		return;
// 	}
// 	towerOfHanoi(n-1, fromrod, auxrod, torod);
// 	printf("\n Move disk %d from rod %c to rod %c", n, fromrod, torod);
// 	towerOfHanoi(n-1, auxrod, torod, fromrod);
// }
//
// int main()
// {
// 	int n = 3; // Number of disks
// 	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
// 	return 0;
// }



#include <iostream>

using namespace std;

struct disc {
  int tower;
  int level;
  int size;
  disc* next;
};

disc* initTower(disc* t_hanoi, int level, int size) {
  if(t_hanoi == NULL) {
    disc* n_disc = new disc;
    n_disc->tower = 1;
    n_disc->level = level;
    n_disc->size = size;

    n_disc->next = t_hanoi;
    t_hanoi = n_disc;
  } else {
      t_hanoi->next = initTower(t_hanoi->next, level, size);
  }
  return t_hanoi;
}

void printTower(disc* t_hanoi){
  if(t_hanoi != NULL) {


    cout << t_hanoi->tower << " " << t_hanoi->level << " " << t_hanoi->size << endl;



    printTower(t_hanoi->next);
  }
}

int main() {
  disc* t_hanoi = NULL;
   for (int i = 0; i < 3; i++)
    t_hanoi = initTower(t_hanoi, i+1,i+1);

  printTower(t_hanoi);

}
