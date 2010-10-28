/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkFrameRateWidget.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkFrameRateWidget - widget for displaying the framerate
// .SECTION Description
// This class displays text of the framerate in the corner of a render window.


#ifndef __vtkFrameRateWidget_h
#define __vtkFrameRateWidget_h

class vtkRenderer;

#include "vtkTextWidget.h"
#include "vtkTimerLog.h"

class VTK_WIDGETS_EXPORT vtkFrameRateWidget : public vtkTextWidget
{
public:
  static vtkFrameRateWidget *New();
  vtkTypeMacro(vtkFrameRateWidget,vtkBorderWidget);
  vtkFrameRateWidget(){}

  void SetRenderer(vtkRenderer* renderer){this->Renderer = renderer;}

  void Init();

protected:
  void RenderCallback(vtkObject* caller, long unsigned int vtkNotUsed(eventId),
                      void* vtkNotUsed(callData) );

  vtkRenderer* Renderer;
  vtkTimerLog *tlog;

private:
  vtkFrameRateWidget(const vtkFrameRateWidget&);  //Not implemented
  void operator=(const vtkFrameRateWidget&);  //Not implemented
};

#endif