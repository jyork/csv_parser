Simple CSV parser in C++. Should compile with any C++14 compliant compiler (tested with MSVC2019 and Clang/MacOS).
Known issues: doesn't handle newlines inside a quoted string.
To use, just drop header and cpp files in your project and use:
    CSVParser parser;
    std::vector<std::string> fields = parser.ReadRow(<string data>);
You can specify a different delimeter (pipes or tabs are used in many sources).
You can specify that an exception be thrown if the line ends without closing a quote.
  
Enjoy!
