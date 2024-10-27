file(GLOB SOURCES "*.cpp")
add_executable(cc_model ${SOURCES})

target_include_directories(cc_model PUBLIC ${CMAKE_SOURCE_DIR}/include)