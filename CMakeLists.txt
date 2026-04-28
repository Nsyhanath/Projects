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

# Uncomment the rest of these cmake blocks IF
# you plan to use my tests in your project

# You will also need to make a test directory and put tests in it.
# The test directory will need a CMakeLists.txt
# Feel free to copy one of the lab test files as a start.

# add_library(project1
#  If  writing unit tests, then put the source code to be
#  unit tested here.
# )

# No need to edit these, just uncomment them

# target_link_libraries(project1
#   INTERFACE 
#     project_options
#     project_warnings
# )

# target_link_libraries(take-away
#   PRIVATE 
#     project1
# )

# target_include_directories(project1
#   PUBLIC
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
# )


