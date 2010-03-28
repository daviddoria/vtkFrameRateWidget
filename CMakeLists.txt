cmake_minimum_required(VERSION 2.6)

PROJECT(FrameRateWidget)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(FrameRateWidget Test.cpp vtkFrameRateWidget.cxx vtkFrameRateRepresentation.cxx)
TARGET_LINK_LIBRARIES(FrameRateWidget vtkHybrid vtkWidgets)
