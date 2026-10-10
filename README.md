# Lib98
## C++98 Backport Library
- Beta Library
- Experimental
## Feature
### lib98::string_view
- lib98::string_view: This is std::string_view(C++17) Porting.(Simplified version）
- Constructors: Default constructor, C-Type String(char*/const char*), std::string
#### Functions
- c_str(): Return pointer(const char*)
- length(): Return String Length
- begin(): Return Pointer(const char*)
- end(): Return Pointer + length
#### operators
- ==: Check for a match.(Returns true if they match, false otherwise.)
- !=: Check for a mismatch.
- []: Access like an array.(Index Access)

### lib98::array
- lib98::array: This is std::array(C++11) Porting.(Simplified version)
- Constructors: Copyconstructor, Default Constructor
#### Functions
- data(): Return Array Pointer
- size(): Return Array Size
- begin(): Return ArrayPointer
- end(): Return ArrayPointer + size
- at(): With Range Check Array Access

#### Operators
- =: Assignment
- []: array access(Index)

### lib98::bytesarr
- BETA
- NOT USED
- YOUR CODE VIEW
