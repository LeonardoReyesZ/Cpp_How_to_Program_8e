(Print Array Range) Overload function template printArray of Fig. 14.1 so that it takes two 
additional integer arguments, namely int lowSubscript and int highSubscript. A call to this
function will print only the designated portion of the array. Validate lowSubscript and 
highSubscript; if either is out of range or if highSubscript is less than or equal to 
lowSubscript, the overloaded printArray function should return 0; otherwise, printArray 
should return the number of elements printed. Then modify main to exercise both versions of 
printArray on arrays a, b and c (lines 22–24 of Fig. 14.1). Be sure to test all capabilities 
of both versions of printArray.
