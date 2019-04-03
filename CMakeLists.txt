cmake_minimum_required(VERSION 3.13)
project(SimpleHTTPServer)

set(CMAKE_CXX_STANDARD 14)
option(DEBUG "debug" ON)
message("debug build type is ${DEBUG}")
if(${DEBUG})
	message("make some debug configuration")
	add_compile_options(-D __DEBUG__)
	add_compile_options(-Og)
	add_compile_options(-rdynamic)
	add_compile_options(-g)
endif()
add_compile_options(-D__ETC_CONFIG_PATH__="${CMAKE_INSTALL_PREFIX}/etc/httpServer.d/Config.yaml")

include_directories(SimpleHTTPServer/base)
include_directories(SimpleHTTPServer/tool)
include_directories(SimpleHTTPServer/tool/HTTP)

aux_source_directory(SimpleHTTPServer/base/ BASE_SRCS)
aux_source_directory(SimpleHTTPServer/tool/ TOOL_SRCS)
aux_source_directory(SimpleHTTPServer/tool/HTTP/ HTTP_SRCS)


link_libraries(pthread)
link_libraries(libyaml-cpp.a)

add_executable(httpServer ${BASE_SRCS} ${TOOL_SRCS} ${HTTP_SRCS})

message("install prefix is ${CMAKE_INSTALL_PREFIX}")
message("etc config file path = ${CMAKE_INSTALL_PREFIX}/etc/httpServer.d/Config.yaml")
install(TARGETS httpServer DESTINATION bin)
install(FILES Config.yaml DESTINATION etc/httpServer.d/)

