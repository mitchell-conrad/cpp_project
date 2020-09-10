file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${sample_project_SOURCE_DIR}/include/sample_project/*.h")
add_library(project_library)

target_compile_features(project_library PUBLIC cxx_std_17)
target_include_directories(project_library PUBLIC ../include)
target_sources(project_library
        PUBLIC
        ${HEADER_LIST}
        PRIVATE
        ipv4.cpp
        )
target_link_libraries(project_library PRIVATE fmt::fmt)

source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})

add_executable(project_executable)
target_compile_features(project_executable PUBLIC cxx_std_17)
target_sources(project_executable
        PRIVATE
        main.cpp
        )
target_link_libraries(project_executable
        PRIVATE
        project_library
        )