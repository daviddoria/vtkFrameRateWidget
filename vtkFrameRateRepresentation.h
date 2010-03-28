/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkFrameRateRepresentation.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkFrameRateRepresentation - a class defining the representation for the vtkFrameRateWidget
// .SECTION Description
// This class is a concrete representation for the vtkFrameRateWidget. It
// represents a TextActor.
//

#ifndef __vtkFrameRateRepresentation_h
#define __vtkFrameRateRepresentation_h

#include "vtkWidgetRepresentation.h"
#include "vtkSmartPointer.h"

class vtkActor;
class vtkPolyDataMapper;
class vtkProperty;
class vtkTextActor;
class vtkTextProperty;

class VTK_WIDGETS_EXPORT vtkFrameRateRepresentation : public vtkWidgetRepresentation
{
public:
  // Description:
  // Instantiate the class.
  static vtkFrameRateRepresentation *New();

  // Description:
  // Standard methods for the class.
  vtkTypeRevisionMacro(vtkFrameRateRepresentation,vtkWidgetRepresentation);
  void PrintSelf(ostream& os, vtkIndent indent);
  
// Description:
  // These are methods that satisfy vtkWidgetRepresentation's API.
  //virtual void PlaceWidget(double bounds[6]);
  virtual void BuildRepresentation();
  //virtual int ComputeInteractionState(int X, int Y, int modify=0);
  //virtual void StartWidgetInteraction(double e[2]);
  //virtual void WidgetInteraction(double e[2]);
  //virtual double *GetBounds();
  
  // Description:
  // Methods supporting, and required by, the rendering process.
  virtual void ReleaseGraphicsResources(vtkWindow*);
  virtual int RenderOpaqueGeometry(vtkViewport*);
  virtual int RenderTranslucentPolygonalGeometry(vtkViewport*);
  virtual int HasTranslucentPolygonalGeometry();


  // Description:
  // The interaction state may be set from a widget (e.g., vtkBoxWidget2) or
  // other object. This controls how the interaction with the widget
  // proceeds. Normally this method is used as part of a handshaking
  // process with the widget: First ComputeInteractionState() is invoked that
  // returns a state based on geometric considerations (i.e., cursor near a
  // widget feature), then based on events, the widget may modify this
  // further.
  void SetInteractionState(int state);

protected:
  vtkFrameRateRepresentation();
  ~vtkFrameRateRepresentation();

private:
  vtkFrameRateRepresentation(const vtkFrameRateRepresentation&);  //Not implemented
  void operator=(const vtkFrameRateRepresentation&);  //Not implemented
  
  vtkSmartPointer<vtkTextActor> TextActor;
};

#endif
