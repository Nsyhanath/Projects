list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")
include (clang_tidy)

add_executable(take-away
  main.cpp
  # If not using tests list all source files here

) 

target_link_libraries(take-away
  INTERFACE 
    project_options
    project_warnings
)
