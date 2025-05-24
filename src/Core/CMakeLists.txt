
add_subdirectory(sglLogger)

set(NAME ${PROJECT_NAME})

file(GLOB CURRENT_DIR
      Logger/*.cpp
      Logger/*.hpp
    )

file(GLOB LOGGER_INTERFACE
			${PROJECT_NAME}/*.cpp
			${PROJECT_NAME}/*.hpp
     )

set(LOGGER_INTERFACE ${LOGGER_INTERFACE})

# add_library(${NAME} STATIC
# 						${CURRENT_DIR} ${LOGGER}
#            )
#
# target_link_libraries(${NAME} PRIVATE ProjectWarnings)

# if(BUILD_ENGINE_WITH_PRECOMPILED_HEADERS)
# target_precompile_headers(${NAME} PUBLIC EllipsePCH.hpp)
# set(CMAKE_PCH_INSTANIATE_TEMPLATES ON)
# endif()
  
target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

