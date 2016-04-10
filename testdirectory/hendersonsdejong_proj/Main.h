/****************************************************************
 * Header file for main function
 * 
 * Used by Stephen Henderson and Dion de Jong, modified from 
 * Dr. Buell's boilerplate main header file. 
 *
 * Date: 29 November 2015
**/

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cmath>
using namespace std;

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "ReadData.h"
#include "KNearest.h"

class Main
{
public:
  int main();
  virtual ~Main();

private:

};

#endif // MAIN_H
