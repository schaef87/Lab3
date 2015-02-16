//--------------------------------------------------------------------
//
//  Laboratory 3                                           test3.cpp
//
//  Test program for the operations in the List ADT
//
//--------------------------------------------------------------------

#include <iostream>

using namespace std;

// Because of C++ template implementations, must include source for templated class
// That is ugly, but it is required.
#include "ListArray.cpp"
#include "config.h"

void print_help();
void showTwoLists(List<char> list1, List<char> list2); 	// Displays two lists that are supposedly equivalent.

int main()
{
// hack: put a "try/catch" with list creation code?
// we need to demonstrate use of the try/catch syntax.

#if	LAB3_TEST1
    List<int> testList(8);    // Test list to test with ints
    List<int> copyList(testList);  // Used to test copy constructor
    List<int> assignList;     // Used to test assignment operator
    int testData;             // List data item 
#else
    List<char> testList(8);   // Test list to test with chars
    List<char> copyList(testList);  // Used to test copy constructor
    List<char> assignList;     // Used to test assignment operator
    char testData;            // List data item 
#endif
    int n;                    // Position within list
    char cmd;                 // Input command

    print_help();

    do
    {
        testList.showStructure();                     // Output list

        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '='  ||  cmd == '?' )
           cin >> testData;
        else if ( cmd == 'M'  ||  cmd == 'm' )
           cin >> n;

        switch ( cmd )
        {
          case 'H' : case 'h':
               print_help();
               break;

          case '+' :                                  // insert
               cout << "Insert " << testData << endl;
               try
               {
                  testList.insert(testData);
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the insert function.";
               }
               break;

          case '-' :                                  // remove
               cout << "Remove the data item marked by the cursor"
                    << endl;
               try
               {
                  testList.remove();
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the remove function.";
               }
               break;

          case '=' :                                  // replace
               cout << "Replace the data item marked by the cursor "
                    << "with " << testData << endl;
               try
               {
                  testList.replace(testData);
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the replace function.";
               }
               break;

          case '@' :                                  // getCursor
               try
               {
                  cout << "Data item marked by the cursor is "
                       << testList.getCursor() << endl;
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the getCursor function.";
               }
               break;

          case '<' :                                  // gotoBeginning
               cout << "Go to the beginning of the list" << endl;
               try
               {
                  testList.gotoBeginning();
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the gotoBeginning function.";
               }
               break;

          case '>' :                                  // gotoEnd
               cout << "Go to the end of the list" << endl;
               try
               {
                  testList.gotoEnd();
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the gotoEnd function.";
               }
               break;

          case 'N' : case 'n' :                       // gotoNext
               try
               {
                  if ( testList.gotoNext() )
                     cout << "Go to the next data item" << endl;
                  else
                     cout << "Failed -- either at the end of the list "
                          << "or the list is empty" << endl;
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the gotoNext function.";
               }
               break;

          case 'P' : case 'p' :                       // gotoPrior
               try
               {
                  if ( testList.gotoPrior() )
                     cout << "Go to the prior data item" << endl;
                  else
                     cout << "Failed -- either at the beginning of the "
                          << "list or the list is empty" << endl;
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the gotoPrior function.";
               }
               break;

          case 'C' : case 'c' :                       // clear
               cout << "Clear the list" << endl;
               testList.clear();
               break;

          case 'E' : case 'e' :                       // isEmpty
               if ( testList.isEmpty() )
                  cout << "List is empty" << endl;
               else
                  cout << "List is NOT empty" << endl;
               break;

          case 'F' : case 'f' :                       // isFull
               if ( testList.isFull() )
                  cout << "List is full" << endl;
               else
                  cout << "List is NOT full" << endl;
               break;

          case '!' :
		showTwoLists(copyList, testList);
		break;
          case '#' :
		assignList.insert('x');
		assignList = testList;
		showTwoLists(assignList, testList);
		break;

#if	LAB3_TEST2
          case 'M' : case 'm' :                   // In-lab Exercise 2
               cout << "Move the data item marked by the cursor to "
                    << "posititon " << n << endl;
               try
               {
                  testList.moveToNth(n);
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the moveToNth function.";
               }
               break;
#endif // LAB3_TEST1

#if	LAB3_TEST3
          case '?' :                              // In-lab Exercise 3
               try
               {
               if ( testList.find(testData) )
                  cout << "Found" << endl;
               else
                  cout << "NOT found" << endl;
               }
               catch (logic_error &e)
               {
                  cerr << "EXCEPTION: A logic error occurred in the find function.";
               }
               break;
#endif // LAB3_TEST3

          case 'Q' : case 'q' :                   // Quit test program
               break;

          default :                               // Invalid command
               cout << "Inactive or invalid command" << endl;
        }
    }
    while ( cin && cmd != 'Q'  &&  cmd != 'q' );

    if( !cin ) {
	cout << "Input error" << endl;
    }

    return 0;
}

void showTwoLists(List<char> list1, List<char> list2) {
    // Variables should match, but dynamic memory buffer must be different
    cout << "Look at the two lists below and decide whether they are equivalent" << endl;
    cout << "List 1: ";
    list1.showStructure();
    cout << "List 2: ";
    list2.showStructure();
    cout << endl;
}

void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  H   : Help (displays this message)" << endl;
    cout << "  +x  : Insert x after the cursor" << endl;
    cout << "  -   : Remove the data item marked by the cursor" << endl;
    cout << "  =x  : Replace the data item marked by the cursor with x"
         << endl;
    cout << "  @   : Display the data item marked by the cursor" << endl;
    cout << "  <   : Go to the beginning of the list" << endl;
    cout << "  >   : Go to the end of the list" << endl;
    cout << "  N   : Go to the next data item" << endl;
    cout << "  P   : Go to the prior data item" << endl;
    cout << "  C   : Clear the list" << endl;
    cout << "  E   : Empty list?" << endl;
    cout << "  F   : Full list?" << endl;
    cout << "  !   : Test copy constructor" << endl;
    cout << "  #   : Test assignment operator" << endl;
    cout << "  M n : Move data item marked by cursor to pos. n  ("
#if LAB3_TEST2
         << "Active   "
#else
         << "Inactive "
#endif	// LAB3_TEST2
         << ": In-lab Ex. 2)" << endl;
    cout << "  ?x  : Search rest of list for x                  ("
#if LAB3_TEST3
         << "Active   "
#else
         << "Inactive "
#endif	// LAB3_TEST3
         << ": In-lab Ex. 3)" << endl;
    cout << "  Q   : Quit the test program" << endl;
    cout << endl;
}

