
set(NAME ${PROJECT_NAME})

file(GLOB CURRENT_DIR
      *.cpp
      *.hpp
    )

file(GLOB_RECURSE CORE
     Core/*.cpp
     Core/*.hpp
    )

file(GLOB_RECURSE CORE_ROUTE
		 Core/Route/*.cpp
     Core/Route/*.hpp
    )

file(GLOB_RECURSE LOGGER
 		${PROJECT_NAME}/*.cpp
 		${PROJECT_NAME}/*.hpp
    )


add_library(${NAME} STATIC
						${CURRENT_DIR} ${LOGGER} ${CORE} ${ROUTE}
           )

target_link_libraries(${NAME} PRIVATE
                      ProjectWarnings vendor
                     )

# if(BUILD_ENGINE_WITH_PRECOMPILED_HEADERS)
# target_precompile_headers(${NAME} PUBLIC EllipsePCH.hpp)
# set(CMAKE_PCH_INSTANIATE_TEMPLATES ON)
# endif()
  
target_include_directories(${NAME} PUBLIC
													 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:/>
                          )


