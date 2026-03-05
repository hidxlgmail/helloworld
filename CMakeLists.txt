cmake_minimum_required(VERSION 3.10)

project(QtHelloWorld VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11) # CentOS 7 默认 GCC 4.8 只支持到 11，若需 C++17 需额外配置
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动处理 Qt 的元对象编译器 (MOC)、UI 编译器 (UIC) 和资源编译器 (RCC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找 Qt5 组件
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

# 源文件
add_executable(QtHelloWorld
    main.cpp
)

# 链接 Qt 库
target_link_libraries(QtHelloWorld PRIVATE Qt5::Widgets Qt5::Core)

# 针对 Windows 的特殊处理：隐藏控制台窗口
if(WIN32)
    set_target_properties(QtHelloWorld PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

# 针对 WASM 的特殊处理：生成 .html 文件
if(EMSCRIPTEN)
    set_target_properties(QtHelloWorld PROPERTIES SUFFIX ".html")
endif()