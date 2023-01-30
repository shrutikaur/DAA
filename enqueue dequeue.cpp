/*Begin
   function Enqueue() to insert elements in queue:
      If queue is completely filled up then print “Overflow”.
      Otherwise insert element at rear.
      Update the value of rear
End
Begin
   function Dequeue() to delete elements from queue:
      If queue is completely empty then print “Underflow”.
      Otherwise insert element from the front.
      Update the value of rear.
End*/
#include <bits/stdc++.h>
using namespace std;
struct Q {
   int f, r, capacity;
   int* q;
   Q(int c) {
      f = r= 0;
      capacity = c;
      q = new int;
   }
   ~Q() { delete[] q; }
   void Enqueue(int d) {
      if (capacity == r) { //check if queue is empty or not
         printf("\nQueue is full\n");
         return;
      } else {
         q[r] = d; //insert data
         r++; //update rear
      }
      return;
   }
   void Dequeue() {
      if (f == r) {
         printf("\nQueue is empty\n");
         return;
      } else {
         for (int i = 0; i < r - 1; i++) {
            q[i] = q[i + 1];
         }
         r--; //update rear
      }
      return;
   }
   void Display() //display the queue {
      int i;
      if (f == r) {
         printf("\nQueue is Empty\n");
         return;
      }
      for (i = f; i < r; i++) {
         printf(" %d <-- ", q[i]);
      }
      return;
   }
   void Front() {
      if (f == r) {
         printf("\nQueue is Empty\n");
         return;
      }
      printf("\nFront Element is: %d", q[f]); //print front element of queue
      return;
   }
};
int main(void) {
   Q qu(3);
   qu.Display();
   cout<<"after inserting elements"<<endl;
   qu.Enqueue(10);
   qu.Enqueue(20);
   qu.Enqueue(30);
   qu.Display();
   qu.Dequeue();
   qu.Dequeue();
   printf("\n\nafter two node deletion\n\n");
   qu.Display();
   qu.Front();
   return 0;
}