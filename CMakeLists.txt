cmake_minimum_required(VERSION 3.15)

project(XLog)


# 使用C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ========================
# 创建XLog静态库
# ========================

set(XLOG_HEADERS
    include/logger.h
    include/log_fac.h
    include/log_console_output.h
    include/log_fileoutput.h
    include/log_format.h
    include/log_output.h
    include/xconfig.h
    include/xlog_format.h
    include/xml_format.h
)


set(XLOG_SOURCES
    src/logger.cpp
    src/log_fac.cpp
    src/log_console_output.cpp
    src/log_fileoutput.cpp
    src/xlog_format.cpp
    src/xml_format.cpp
)


add_library(
    XLog
    ${XLOG_SOURCES}
    ${XLOG_HEADERS}
)


# ========================
# 添加头文件搜索路径
# ========================

target_include_directories(
    XLog

    PUBLIC

    ${PROJECT_SOURCE_DIR}/include
)


# ========================
# example测试程序
# ========================

add_executable(
    example

    example/main.cpp
)


# 链接XLog库

target_link_libraries(
    example

    PRIVATE

    XLog
)

if(MSVC)
    target_compile_options(XLog PRIVATE /EHsc)
    target_compile_options(example PRIVATE /EHsc)
endif()
