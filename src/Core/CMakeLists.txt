
add_subdirectory(sglLogger)

set(NAME ${PROJECT_NAME})

file(GLOB LOGGER_INTERFACE
      Logger/*.cpp
      Logger/*.hpp
    )

# set(LOGGER_INTERFACE ${LOGGER_INTERFACE_DIR})

# add_library("${NAME}Interface" INTERFACE
# 						${LOGGER}
#            )

# target_link_libraries(${NAME} PRIVATE ProjectWarnings)

# if(BUILD_ENGINE_WITH_PRECOMPILED_HEADERS)
# target_precompile_headers(${NAME} PUBLIC EllipsePCH.hpp)
# set(CMAKE_PCH_INSTANIATE_TEMPLATES ON)
# endif()
  
target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

