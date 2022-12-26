cmake_minimum_required(VERSION 3.5)

project(common_compass LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets DBus Core REQUIRED)

if(ANDROID)
  add_library(client_compass SHARED
    main.cpp
    client_compass.cpp
    client_compass.h
    client_compass.ui
  )
add_library(server_compass SHARED
  main.cpp
  Compass.cpp
  Compass.h
  Compass_adapter.h
  Compass_adapter.cpp
)

else()
    add_executable(server_compass
     server_compass/main.cpp
     server_compass/Compass.cpp
     server_compass/Compass.h
     server_compass/Compass_adapter.h
     server_compass/Compass_adapter.cpp
    )
  add_executable(client_compass
    client_compass/main.cpp
     client_compass/client_compass.cpp
     client_compass/client_compass.h
     client_compass/client_compass.ui
  )

endif()

target_link_libraries(client_compass PRIVATE Qt5::Widgets)
target_link_libraries(client_compass PRIVATE Qt5::DBus)
target_link_libraries(server_compass Qt5::DBus)
target_link_libraries(server_compass Qt5::Core)


