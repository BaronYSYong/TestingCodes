set(program pthread)

add_executable(pthread1 pthread1.cpp)
target_link_libraries (pthread1 -lpthread)

add_executable(pthread2 pthread2.cpp)
target_link_libraries (pthread2 -lpthread)

add_executable(pthread3 pthread3.cpp)
target_link_libraries (pthread3 -lpthread)
