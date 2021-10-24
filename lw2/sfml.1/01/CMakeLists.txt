add_executable(01 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Soft/CppDistro/cmake/share/cmake-3.9/Modules/")
find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_compile_features(01 PUBLIC cxx_std_17)
target_compile_definitions(01 PRIVATE SFML_STATIC)

target_link_libraries(01 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})