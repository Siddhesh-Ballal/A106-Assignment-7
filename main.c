// A106 Siddhesh Ballal
/*
Assignment 7: Implement Circular Queue using Array. Perform following operations on it. a) Insertion (Enqueue) b) Deletion (Dequeue) Display
*/

#include <stdio.h>

#define size 5

int items[size];
int front = -1, rear = -1;

 
int Is_Full() 
{
  if ((front == rear + 1) || (front == 0 && rear == size - 1)) 
  return 1;
  
  else
  return 0;
}

 
int Is_Empty() 
{
  if (front == -1) 
  return 1;
  
  else
  return 0;
}

 
void Enqueue(int item) 
{
  if (Is_Full())
  printf("\n Queue is full!! \n");
  
  else 
  {
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    items[rear] = item;
    printf("\n Inserted -> %d", item);
  }
}

 
int Dequeue() 
{
  int item;
  if (Is_Empty()) 
  {
    printf("\n Queue is empty !! \n");
    return (-1);
  } 
  else 
  {
    item = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
  } 
   
    else 
    {
      front = (front + 1) % size;
    }
    printf("\n Deleted item -> %d \n", item);
    return (item);
  }
}

 
void Display() 
{
  int i;
  
  if (Is_Empty())
    printf(" \n Empty Queue\n");
  
  else 
  {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    
    for (i = front; i != rear; i = (i + 1) % size) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

int main() 
{
   
  int choice, value;
  do
  {
    printf("\n\nChoose: \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case(1):
      printf("\nEnter value to be Enqueueed: ");
      scanf("%d", &value);
      Enqueue(value);
      break;

      case(2):
      Dequeue();
      break;

      case(3):
      Display();
      break;

      case(4):
      printf("\nProgram exited Successfully");

    }
  }
  while(choice != 4);

  return 0;
}