
wasmedge_add_executable(main 
    ${CMAKE_SOURCE_DIR}/lazy/main.cpp
)

target_link_libraries(main
    PUBLIC
    wasmedgeCommon
    wasmedgeLoader
    wasmedgeValidator
    wasmedgeVM
    wasmedge
)

if(EXISTS "${CMAKE_SOURCE_DIR}/lazy/test.wasm")
    file(COPY ${CMAKE_SOURCE_DIR}/lazy/test.wasm DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()