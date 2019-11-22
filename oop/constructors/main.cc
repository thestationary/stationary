/* File : day09.cc */
#include <iostream>
#include "student.h"
#include <stdio.h>

int main()
{ Student fanis("Fanis");
  
  Student manos = fanis;  /* Constructor-Copy is now called */
  // Student s2(s1);   is exactly the same with above line */
/*
 * if instead of Student manos = fanis, we had:
 * Student manos;
 * manos = fanis;
 * then Constructor-Copy is not called.
 *  In this case, '=' function-symbol overload will be called:
 * Student& Student::operator=(const Student& s);
 *  If the above function is not defined, then the operation which
 * will be executed is : bitwise copy.
 */
  std::cout << "bitwise copy:" << std::endl;
  printf("\nAddress of fanis.name: \t%p\n", fanis.get_name());
  printf("Address of manos.name: \t%p\n", manos.get_name());
  std::cout << "They are the same!!!" << std::endl;
  Student sitaras;
  sitaras = fanis;
  printf("Address of sitaras.name: \t%p\n", sitaras.get_name());
}