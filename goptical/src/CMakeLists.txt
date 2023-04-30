set(SOURCES "")

add_subdirectory(core)
add_subdirectory(design)

add_library(${PROJECT_NAME}_static STATIC ${SOURCES})
add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(${PROJECT_NAME}_static ${LIBS})
target_link_libraries(${PROJECT_NAME} ${LIBS})