# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("userlib")


add_library(userlib

        SHARED

        main.cpp
        core/include/KittyMemory/MemoryBackup.cpp
        core/include/KittyMemory/KittyUtils.cpp
        core/include/KittyMemory/MemoryPatch.cpp
        core/include/KittyMemory/KittyMemory.cpp
        #core/include/monostring/MonoString.cpp

        )

set(LINKED_LIBS EGL GLESV2 log)
set(CMAKE_C_FLAGS "-w -s -Wno-error=format-security  -fpermissive -fvisibility=hidden -fexceptions")
set(CMAKE_CXX_FLAGS "-w -s -Wno-error=format-security -fvisibility=hidden -Werror -std=c++17 -Wno-error=c++11-narrowing -fpermissive -Wall -fexceptions")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--gc-sections,--strip-all,-llog")

target_link_libraries( # Specifies the target library.
        userlib
        ${LINKED_LIBS}
)