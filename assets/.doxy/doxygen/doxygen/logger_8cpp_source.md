

# File logger.cpp

[**File List**](files.md) **>** [**device**](dir_7dcf813d97a5be213fa89559baaee677.md) **>** [**logger.cpp**](logger_8cpp.md)

[Go to the documentation of this file](logger_8cpp.md)


```C++
#include "logger.h"


namespace jac {


std::unique_ptr<OutputStreamCommunicator> Logger::_errorStream;
std::unique_ptr<OutputStreamCommunicator> Logger::_logStream;
std::unique_ptr<OutputStreamCommunicator> Logger::_debugStream;


} // namespace jac
```


