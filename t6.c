#include <bits/stdc++.h>
// Driver program
int main()
{
// Declare an array
ICSI 333 | Lab 2. Page 5
int v[3] = {10, 100, 200};
// Declare pointer variable
int *ptr;
// Assign the address of v[0] to ptr
ptr = v;
printf("Value of *ptr = %d\n", ptr[0]);
printf("Value of *ptr = %d\n", ptr[1]);
printf("Value of *ptr = %d\n", ptr[2]);
for (int i = 0; i < 3; i++)
{
printf("Value of *ptr = %d\n", *ptr);
printf("Value of ptr = %p\n\n", ptr);
// Increment pointer ptr by 1
ptr++;
}
}