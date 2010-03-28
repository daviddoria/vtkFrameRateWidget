/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkBoxWidget2.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkFrameRateWidget - A widget for displaying the frame rate of
//  the render window
// .SECTION Description
// 
#ifndef __vtkFrameRateWidget_h
#define __vtkFrameRateWidget_h

#include "vtkAbstractWidget.h"

class vtkFrameRateRepresentation;

class VTK_WIDGETS_EXPORT vtkFrameRateWidget : public vtkAbstractWidget
{
public:
  // Description:
  // Instantiate the object.
  static vtkFrameRateWidget *New();

  // Description:
  // Standard class methods for type information and printing.
  vtkTypeRevisionMacro(vtkFrameRateWidget,vtkAbstractWidget);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Specify an instance of vtkWidgetRepresentation used to represent this
  // widget in the scene. Note that the representation is a subclass of vtkProp
  // so it can be added to the renderer independent of the widget.
  void SetRepresentation(vtkFrameRateRepresentation *r)
    {this->Superclass::SetWidgetRepresentation(reinterpret_cast<vtkWidgetRepresentation*>(r));}
  
  // Description:
  // Create the default widget representation if one is not set. By default,
  // this is an instance of the vtkFrameRateRepresentation class.
  void CreateDefaultRepresentation();

protected:
  vtkFrameRateWidget();
  ~vtkFrameRateWidget();

  static void UpdateAction(vtkAbstractWidget*);
    
//BTX - manage the state of the widget
  int WidgetState;
  enum _WidgetState {Start=0,Active};
//ETX
  
private:
  vtkFrameRateWidget(const vtkFrameRateWidget&);  //Not implemented
  void operator=(const vtkFrameRateWidget&);  //Not implemented
};
 
#endif
