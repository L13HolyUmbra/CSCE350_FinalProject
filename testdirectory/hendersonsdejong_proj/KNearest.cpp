/*************************************************************
 * KNearest class for computing the K-nearest neighbors of
 * a query file, given template files. 
 * 
 * Copyright: Stephen Henderson and Dion de Jong.
 * Date: 29 November 2015
**/

#include "KNearest.h"

/******************************************************
 * Default un-parameterized constructor for KNearest
**/
KNearest::KNearest()
{
}

/******************************************************
 * Destructor
**/
KNearest::~KNearest()
{
}


/**********************************************************************
 * Function to find the K-nearest neighbors, given a query
 * and template.
 * 
 * The query data is defined as a vector of 5632 elements, denoted by X.
 * The template data is defined as Y = {Y(1), Y(2), ..., Y(j), ..., Y(n)}, 
 * (containing n=138 images). To compute the similarity S between X and Y(j), 
 * we use the K-nearest neighbors relation (see write-up).
 *
 * As each S value is calculated it is stored in a heap. It is also stored
 * as the key in multimap of <value, index>. Because a heap is used, the 10 
 * first (largest) S values are removed: the closer the S value is to 1, the 
 * closer that template value is to the query. These 10 values are then used
 * as accessors to the map, where they are stored as keys. When their values
 * are accessed from the map, we are given the index of the template with
 * which the query is a closest neighbor. 
 *
 *
 * ** A NOTE ON PRINTING AND REPEATED ELEMENTS **
 * It may be noted that a multimap is used to store the S values with
 * their corresponding j indices rather than a map. This is because
 * maps do not allow repeated keys, and thus if two neighbors are found
 * with the same S value, only one would be stored; the multimap allows
 * multiple elements to havce the same key. However, when accessing 
 * elements based on keys, the multimap only accesses the first element
 * with the given key. Therefore, each time we print an element we 
 * delete the elements, so as to prevent printing duplicates. 
 *
 *
 * ******** PSEUDO CODE *********
 * for each template image (138):
 *   calculate S
 *   push S onto heap
 *   push S,j onto multimap
 * for 10 largest S values
 *   print j corresponding to S
 *   remove S from heap
 * *******************************
 * 
 * Parameter:
 *   outStream - output stream to which the function will print results
**/
void KNearest::doKNearest(ostream &outStream)
{
//  cout << "Enter doKNearest()" << endl;
  multimap<double, int> nearestNeighbors;
  priority_queue<double> valHeap;

  double value = 0.0;
  double sumXY, sumXX, sumYY = 0.0;
  double q, t = 0.0;
  for(int j = 0; j < theTemplate.size(); j++)
  {
    value = 0.0;
    sumXY = 0.0;
    sumXX = 0.0;
    sumYY = 0.0;

    // Calculate sums
    for(int k = 0; k < 5632; k++)
    {
      q = theQuery[k];
      t = theTemplate[j][k];

      sumXY += q * t;
      sumXX += q * q;
      sumYY += t * t;
    } // for k(0:5632) 

    // Calculate final s value
    value = sumXY / (sqrt(sumXX) * sqrt(sumYY));

    // Push value and index onto multimap, and push value onto heap
    nearestNeighbors.emplace(value, j + 1);
    valHeap.push(value);
  } // for j in template

  // Print 10 nearest
  double thisValue = 0.0;
  for(int counter = 1; counter <= 10; counter++)
  {
    outStream << Utils::Format(counter, 2);

    // Access and remove top heap element
    thisValue = valHeap.top();
    valHeap.pop();

    // Print j based on S value, then delete element from multimap
    map<double, int>::iterator theElement = nearestNeighbors.find(thisValue);
    outStream << right << Utils::Format(theElement->second, 5) << ": ";
    outStream << Utils::Format(thisValue, 5) << endl;
    nearestNeighbors.erase(theElement);

    counter++;
  }
  outStream << endl;
//  cout << "Leave doKNearest()" << endl;
} // void doKNearest(ostream &outStream)

/**********************************************************************
 * Function to do K nearest neighbors without specified output stream.
 * This function is simply a default function for the doKNearest that 
 * sends output to cout.
**/
void KNearest::doKNearest()
{
  doKNearest(cout);
} // void doKNearest()

/******************************************************
 * Mutator function for member variable theQuery.
 * 
 * Parameter:
 *   theQuery - a vector<double> to set as theQuery
**/
void KNearest::setQuery(string fileName)
{
  Scanner scan;
  ReadData readData;

  scan.openFile(fileName);
  this->theQuery = readData.readQuery(scan);

  scan.close();
} // void setQuery(vector<double> theQuery)

/******************************************************
 * Mutator function for member variable theTemplate.
 * 
 * Parameter: 
 *   theTemplate - 2D vector of doubles to set as theTemplate
**/
void KNearest::setTemplate(string fileName)
{
  Scanner scan;
  ReadData readData;

  scan.openFile(fileName);
  this->theTemplate = readData.readTemplate(scan);

  scan.close();
} // void setTemplate(vector< vector<double> > theTemplate)

/******************************************************
 * Accessor function for member variable theQuery.
 * 
 * Return:
 *   theQuery member variable
**/
vector<double> KNearest::getQuery() const
{
  return this->theQuery;
} // vector<double> getQuery() const

/******************************************************
 * Accessor function for member variable theTemplate.
 * 
 * Return:
 *   theTemplate member variable
**/
vector< vector<double> > KNearest::getTemplate() const
{
  return this->theTemplate;
} // vector< vector<double> > getTemplate() const

