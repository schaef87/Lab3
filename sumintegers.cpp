#include <iostream>
#include "ListArray.cpp"   // Note that we are including the file                                    
			   // containing the code -- NOT the header file

using namespace std;

int main ()
{
      List<int> samples(100);   // Set of samples
      int newSample,            // Input sample
          sum = 0;              // Sum of the input samples
        
      // Read in a set of samples from the keyboard.

      cout << "Enter list of samples (end with EOF) : ";
      while ( cin >> newSample ) {
          samples.insert(newSample);
      }

      // Sum the samples and output the result.
        
      if ( ! samples.isEmpty() )           // If have data
      {
         samples.gotoBeginning();          // First set cursor to beginning of list
         do {
           sum += samples.getCursor();     // Add data item to running sum
         } while ( samples.gotoNext() );   // Go to next data item (if any)
      }

      cout << "Sum is " << sum << endl;

      return 0;
} 

