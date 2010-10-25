cmake_minimum_required(VERSION 2.6)

PROJECT(FrameRateWidget)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(${PROJECT_NAME}1 Test1.cpp vtkFrameRateWidget.cxx)
ADD_EXECUTABLE(${PROJECT_NAME}2 Test2.cpp vtkFrameRateWidget.cxx)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}1 vtkHybrid vtkWidgets)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}2 vtkHybrid vtkWidgets)
