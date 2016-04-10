#include "Main.h"

/******************************************************************************
 * Project main function
 * 
 * Copyright Stephen Henderson and Dion de Jong.
 * Date: 1 December 2015
 * 
 * Certain boilerplate parts of this function, such as the instantiation
 * of Scanners, ofstreams, and timecalls, were adapted from Dr. Buell's
 * main function boilerplate for reading data in from files.
**/

static const string TAG = "Main: ";

int main(int argc, char *argv[])
{
  string timeCallOutput = "";
  string logStreamName = "";

  Scanner queryScan;
  Scanner templateScan;
  ofstream logStream;

  ReadData readData;
  KNearest k;

  Utils::CheckArgs(1, argc, argv, "logfilename");
  logStreamName = static_cast<string>(argv[1]);

  // Open logStream
  Utils::FileOpen(logStream, logStreamName);

  logStream << TAG << "Beginning execution" << endl;
  timeCallOutput = Utils::timecall("beginning");
  logStream << timeCallOutput;

  /*
  string templateFile = "../../aadata/009_template.dat";
  string queryFile = "../../aadata/009_AU01_query.dat";

  k.setQuery(queryFile);
  k.setTemplate(templateFile);

  k.doKNearest();
  
  k.setQuery("../../aadata/009_AU12_query.dat");
  k.doKNearest();
  */
  
  string query_file_01;
  string query_file_12;
  string query_file_17;
  string template_file;
  for(int i = 1; i <= 47; i++)
  {
    // Build file names
    string number = "0" + Utils::Format(i);
    if(i < 10)
    {
      number = "0" + number;
    }
    query_file_01 = "../../aadata/" + number  + "_AU01_query.dat";
    query_file_12 = "../../aadata/" + number  + "_AU12_query.dat";
    query_file_17 = "../../aadata/" + number  + "_AU17_query.dat";
    template_file = "../../aadata/" + number + "_template.dat";
  
    // Set template file 
    k.setTemplate(template_file);

    // Set query file for each query and find K-nearest from template
    k.setQuery(query_file_01);
    logStream << query_file_01 << endl;
    k.doKNearest(logStream);

    k.setQuery(query_file_12);
    logStream << query_file_12 << endl;
    k.doKNearest(logStream);

    k.setQuery(query_file_17);
    logStream << query_file_17 << endl;
    k.doKNearest(logStream);
  }
  
  // Close log stream, end program
  logStream << TAG << "Ending execution" << endl;
  timeCallOutput = Utils::timecall("ending");
  logStream << timeCallOutput;
}
