//A simple thrift hello and adder interface

/*
 * The first thing to know about are types. The available types in Thrift are:
 *
 *  bool        Boolean, one byte
 *  i8 (byte)   Signed 8-bit integer
 *  i16         Signed 16-bit integer
 *  i32         Signed 32-bit integer
 *  i64         Signed 64-bit integer
 *  double      64-bit floating point value
 *  string      String
 *  binary      Blob (byte array)
 *  map<t1,t2>  Map from one type to another
 *  list<t1>    Ordered list of one type
 *  set<t1>     Set of unique elements of one type
 */


/*
 * Structs are the basic complex data structures. They are comprised of fields
 * which each have an integer identifier, a type, a symbolic name, and an
 * optional default value.
 */

//Simple structure definition
//Think these define input/outputs from my clientserver functions - act as a common definition between?
struct helloStruct {
    1: i32 num1,
    2: i32 num2,
    3: string string1,
}

/*
 * Ahh, now onto the cool part, defining a service. Services just need a name
 * and can optionally inherit from another service using the extends keyword.
 */

//Simple service
//Services are for defining methods to be used in C style.
//Full methods are implemented in client/server, similar to a header file
//It has a return type, arguments and optionally a list of exceptions that it may throw.
//Argument lists and exception lists are specified using the exact same syntax as field lists in struct or exception definitions.

service helloService {

    string hello_func(),

    i32 add(1:i32 num1, 2:i32 num2)
}

