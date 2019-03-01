add_library(MyFoo foo.cpp)
add_executable(demo main.cpp)
target_link_libraries(demo MyFoo)