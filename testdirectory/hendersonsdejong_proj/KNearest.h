/***************************************************************
 * Header file for KNearest neighbor computation class. 
 * 
 * Copyright: Stephen Henderson and Dion de Jong.
 * Date: 29 November 2015
**/

#ifndef KNEAREST_H
#define KNEAREST_H  

#include <iostream>
using namespace std;

#include "ReadData.h"

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

class KNearest
{
public:
  KNearest();
  virtual ~KNearest();

  void doKNearest(ostream &outStream);
  void doKNearest();

  void setQuery(string fileName);
  void setTemplate(string fileName);
  vector<double> getQuery() const;
  vector< vector<double> > getTemplate() const;

private:
  vector<double> theQuery;
  vector< vector<double> > theTemplate;

};

#endif
