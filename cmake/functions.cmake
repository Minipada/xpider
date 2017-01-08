# To be updated
set(GCF_CLANGFORMAT_PATH "/usr/bin/clang-format-" CACHE STRING "Sets clang-format version")
set(GCF_CLANGFORMAT_STYLE "file" CACHE STRING "Chooses to use personnal .clang-format")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../git-cmake-format ${CMAKE_CURRENT_BINARY_DIR}/git-cmake-format)
