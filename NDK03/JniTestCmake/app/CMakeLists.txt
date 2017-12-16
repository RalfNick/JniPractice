# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.
#设置构建本地库文件所需要的CMake最低版本

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
set(distribution_DIR ${CMAKE_SOURCE_DIR}/../distribution)
#指定so库存存放的位置
set(CPP_DIR src/main/cpp)
#指定源文件的位置

add_library( # Sets the name of the library.
             #设置library的名字，也是加载时的库的名字，生成的so是libnative-lib.so
             native-lib

             # Sets the library as a shared library.
             #设置library是一个共享库
             SHARED

             # Provides a relative path to your source file(s).
             #指定需要编译的源代码的相对路径
             ${CPP_DIR}/native-lib.cpp ${CPP_DIR}/MyMath.cpp)

set_target_properties(native-lib PROPERTIES
                      LIBRARY_OUTPUT_DIRECTORY ${distribution_DIR}/libs/${ANDROID_ABI})

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#搜索指定预编译库，并将路径存储到一个变量中。
#CMake默认情况下包含搜索路径下的系统库文件，仅需要指定NDK的库文件的名字即可。
#CMake在编译时会确认该库文件是否存在。

find_library( # Sets the name of the path variable.
              #指定库文件路径的变量
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              #指定CMake需要加载的NDK库文件名字
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#指定需要链接到自己生成库文件上的库。
#你可以链接多个库文件，如在这个脚本中自己定义的库，预编译的三方库，或者是系统的库文件

target_link_libraries( # Specifies the target library.
                       #指定链接到的目标库文件
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       #链接目标库文件到包含在NDK中的Log库上
                       ${log-lib} )