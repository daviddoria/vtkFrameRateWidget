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
// .NAME vtkTextWidget - widget for placing text on overlay plane
// .SECTION Description
// This class provides support for interactively placing text on the 2D
// overlay plane. The text is defined by an instance of vtkTextActor. It uses
// the event bindings of its superclass (vtkBorderWidget). In addition, when
// the text is selected, the widget emits a WidgetActivateEvent that
// observers can watch for. This is useful for opening GUI dialogues to
// adjust font characteristics, etc. (Please see the superclass for a
// description of event bindings.)

// .SECTION See Also
// vtkBorderWidget vtkCaptionWidget


#ifndef __vtkFrameRateWidget_h
#define __vtkFrameRateWidget_h

class vtkTextRepresentation;
class vtkTextActor;

#include "vtkTextWidget.h"

class VTK_WIDGETS_EXPORT vtkFrameRateWidget : public vtkTextWidget
{
public:
  // Description:
  // Instantiate class.
  static vtkFrameRateWidget *New();

  // Description:
  // Standard VTK methods.
  vtkTypeMacro(vtkFrameRateWidget,vtkBorderWidget);
  void PrintSelf(ostream& os, vtkIndent indent);

  void Init();
  
protected:
  static void RenderCallback(vtkObject* caller, long unsigned int vtkNotUsed(eventId),
			    void* vtkNotUsed(clientData), void* vtkNotUsed(callData) );
			    
  vtkFrameRateWidget();
  ~vtkFrameRateWidget();

private:
  vtkFrameRateWidget(const vtkFrameRateWidget&);  //Not implemented
  void operator=(const vtkFrameRateWidget&);  //Not implemented
};

#endif