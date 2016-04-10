/***************************************************************
 * ReadData class, for reading data from query and template files.
 * 
 * Copyright: Stephen Henderson and Dion de Jong.
 * Date: 29 November 2015
**/

#include "ReadData.h"

/******************************************************
 * Default un-parameterized constructor for ReadData.
**/
ReadData::ReadData()
{
}

/******************************************************
 * Destructor
**/
ReadData::~ReadData()
{
}

/******************************************************
 * Function to read the data from a query file.
 * 
 * Parameter:
 *   inFile - reference to a Scanner of the query file
 * Return:
 *   vector<double> containing the query data
**/
vector<double> ReadData::readQuery(Scanner &inFile)
{
//  cout << "Enter ReadData::readQuery()" << endl;
  vector<double> theQuery;

  while(inFile.hasNext())
  {
    double tok = inFile.nextDouble();
    theQuery.push_back(tok);
  }

//  cout << "Leave ReadData::readQuery()" << endl;
  return theQuery;
} // vector<double> readQuery(Scanner &inFile)

/******************************************************
 * Function to read the data from a template file.
 * 
 * Parameter:
 *   inFile - reference to a Scanner of the template file
 * Return:
 *   A 2D vector containing the template data
 **/
vector< vector<double> > ReadData::readTemplate(Scanner &inFile)
{
//  cout << "Enter ReadData::readTemplate()" << endl;
  vector<vector<double> > theTemplate;

  while(inFile.hasNext())
  {
    vector<double> temp;
    for(int i = 0; i < 5632; i++)
    {
      string tok = inFile.next();
      temp.push_back(atof(tok.c_str()));
    }
    theTemplate.push_back(temp);
  }

//  cout << "Leave ReadData::readTemplate()" << endl;
  return theTemplate;
} // vector< vector<double> > readTemplate(Scanner &inFile)
