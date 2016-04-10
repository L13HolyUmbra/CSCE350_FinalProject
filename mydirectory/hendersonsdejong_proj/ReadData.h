/**************************************************************
 * Header file for ReadData class.
 * 
 * Copyright: Stephen Henderson and Dion de Jong.
 * Date: 29 November 2015
**/

#ifndef READDATA_H
#define READDATA_H

#include <iostream>
using namespace std;

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class ReadData
{
public:
  ReadData();
  virtual ~ReadData();

  vector<double> readQuery(Scanner &inFile);
  vector< vector<double> > readTemplate(Scanner &inFile);

private:
};

#endif
