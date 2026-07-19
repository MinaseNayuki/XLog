# XLog

A lightweight and extensible C++ logging framework.

XLog is a simple logging library implemented with C++17.
The project focuses on modern C++ engineering practices, including
object-oriented design, abstraction, polymorphism and modular architecture.

## Features

- [x] Logger core
- [x] Multiple log levels
- [x] Console output
- [x] File output
- [x] Custom log format
- [x] XML log format
- [x] Configurable initialization
- [x] CMake build support

Future improvements:

- [ ] JSON log format
- [ ] Thread-safe logging
- [ ] Asynchronous logging
- [ ] Log rotation
- [ ] Configuration file support

## Project Structure
XLog
|
├── include
│ ├── logger.h
│ ├── log_fac.h
│ ├── log_format.h
│ ├── log_output.h
│ ├── xlog_format.h
│ ├── xml_format.h
│ └── xconfig.h
|
├── src
│ ├── logger.cpp
│ ├── log_fac.cpp
│ ├── log_console_output.cpp
│ ├── log_fileoutput.cpp
│ ├── xlog_format.cpp
│ └── xml_format.cpp
|
├── example
│ └── main.cpp
|
└── CMakeLists.txt

## Design

XLog uses several object-oriented design ideas:

- Abstract interface
- Runtime polymorphism
- Factory pattern
- Singleton pattern


Architecture:
            User

             |
             |

          Log Macro

             |
             |

          LogFac

             |
             |

          Logger

      /              \

LogFormat          LogOutput

   |                  |
XLogFormat      ConsoleOutput

XmlFormat         FileOutput


## Usage

Example:

```cpp
#include "log_fac.h"

int main()
{
    xconfig cfg;

    cfg.output = xconfig::console;
    cfg.type = xconfig::normal;


    log_fac::instance().init(cfg);


    LOGINFO("server started");

    return 0;
}

Output:

2026-07-19 12:00:00 info server started:main.cpp 15

XML format example:

<log>
    <level>info</level>
    <message>server started</message>
    <file>main.cpp</file>
    <line>15</line>
</log>

Build

Requirements
C++17 compiler
CMake 3.15+
Build
mkdir build
cd build

cmake ..

cmake --build .

Design Goals

The main purpose of this project is to practice:

C++ class design
Interface abstraction
Resource management
Library organization
CMake project management
