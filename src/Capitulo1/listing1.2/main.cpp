/**
 Codigo del linsting 1.2 de "Advanced Linux Programming"
 Integrantes:
 @Miryam Godoy
 @Alex Gomez
**/


#include <iostream>
#include <cassert>
#include "main.hpp"

double reciprocal(int i){
  //I should be non-zero
  assert (i!=0);
  return 1.0/i;

}
