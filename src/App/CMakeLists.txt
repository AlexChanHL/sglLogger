
string(CONCAT testApplicationName ${PROJECT_NAME} "TestApplication")

add_executable(testApplicationName)

    set(SOURCES
        Core/main.cpp
       )

    set(HEADERS

       )

target_sources(testApplicationName PUBLIC
               ${SOURCES} ${HEADERS}
              )

target_link_libraries(testApplicationName PUBLIC
 											sglLogger ProjectWarnings
                      )

target_include_directories(testApplicationName PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

