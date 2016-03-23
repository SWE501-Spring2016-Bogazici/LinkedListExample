cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(DListExample)
set(DLIST_SOURCE DListExample.cpp DList/DList.cpp DList/DList.h DList/DListItem.cpp DList/DListItem.h)
add_executable(DListExample ${DLIST_SOURCE})

project(FrameWriter)
set(FW_SOURCE FrameWriter.cpp DList/DList.cpp DList/DList.h DList/DListItem.cpp DList/DListItem.h)
add_executable(FrameWriter ${FW_SOURCE})


project(TemplateDListExample)
set(TD_SOURCE TemplateDListExample.cpp)
add_executable(TemplateDListExample ${TD_SOURCE})