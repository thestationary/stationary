# OOP - NOTES

## Contents
[1. Namespaces](#Namespaces)




## Namespaces


```
/* File : main.cc */
#include <iostream>

#include "namespace.h"

using namespace std;

int myInt = 100000000;


int   main() {
    
     cout << myInt << endl;

     cout << Example::E << endl;

     cout << "The namespace myInt: " << Example::myInt << endl ;

     Example::printValues();

   
     using namespace Example;

     cout << "The namespace E from main:  " << E << endl ;
     cout << ::myInt << endl;

   }

```

```
/* File : namespace.cc */
#include <iostream>

#include "namespace.h"

using namespace std;

int Example::myInt = 8;

   void Example::printValues()
        {
           cout << "Printing from printValues" << endl;

           cout << myInt << endl;

           cout << E << endl;

        }
```


```
/* File : namespace.h */
   namespace Example{
              const double PI = 3.14159;
              const double E = 2.71828;
//              int myInt = 8;    // The problem with this becomes obvious now!
              extern int myInt;   // Declaration only.
                                  // Example::myInt will be defined in a source file
              void printValues();
            }
```

Είναι γνωστό ότι:
- Τα namespaces μπορούν να έχουν δηλώσεις και ορισμούς μέσα στην δήλωση ενός namespace
- Τα header files δεν περιέχουν ορισμούς μεταβλητών, παραμόνο δήλωση. Με εξέρεση τον
τύπο const.

Για να προσαρμοστεί η myInt του namespace Example μέσα στο αρχείο "namespace.h", θα πρέπει
να γίνει ο ορισμός κάπου αλλού. Άρα με το extern δηλώνουμε οτι κάπου αλλού θα
ορίσουμε την μεταβλητή myInt.



