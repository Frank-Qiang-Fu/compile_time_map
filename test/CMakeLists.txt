add_executable(my_test test.cpp)
target_link_libraries(my_test PRIVATE 
Catch2    
compile_time_map
)

enable_testing()

add_test(NAME catch_test
    COMMAND $<TARGET_FILE:my_test> --success
    )