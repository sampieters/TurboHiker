if(APPLE)
    set(SFML_INCLUDE_DIR "./SFML-2.5.1/APPLE/SFML-2.5.1-MAC/include")
    set(SFML_LIBRARY_DIR "./SFML-2.5.1/APPLE/SFML-2.5.1-MAC/build/lib")

elseif (UNIX)
    set(SFML_INCLUDE_DIR "./SFML-2.5.1/UNIX/SFML-2.5.1/include/")
    set(SFML_LIBRARY_DIR "./SFML-2.5.1/UNIX/SFML-2.5.1/lib/")
    set(SFML_DIR "./SFML-2.5.1/UNIX/SFML-2.5.1/lib/cmake/SFML/")

elseif(WIN32)
    set(SFML_INCLUDE_DIR "./SFML-2.5.1/WIN32/SFML-2.5.1/include/")
    set(SFML_LIBRARY_DIR "./SFML-2.5.1/WIN32/SFML-2.5.1/lib/")
    set(SFML_DIR "./SFML-2.5.1/WIN32/SFML-2.5.1/lib/cmake/SFML")
    file(GLOB SFML_DLL "./SFML-2.5.1/WIN32/SFML-2.5.1/bin/*.dll")
    file(COPY ${SFML_DLL} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()

include_directories(SFML_INCLUDE_DIR)
link_directories(SFML_LIBRARY_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)