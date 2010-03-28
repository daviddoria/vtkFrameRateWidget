/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkFrameRateRepresentation.cxx,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkFrameRateRepresentation.h"
#include "vtkActor.h"
#include "vtkTextActor.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolyData.h"
#include "vtkCallbackCommand.h"
#include "vtkPolyData.h"
#include "vtkProperty.h"
#include "vtkTextProperty.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkInteractorObserver.h"
#include "vtkMath.h"
#include "vtkAssemblyPath.h"
#include "vtkWindow.h"
#include "vtkObjectFactory.h"


vtkCxxRevisionMacro(vtkFrameRateRepresentation, "$Revision: 1.9 $");
vtkStandardNewMacro(vtkFrameRateRepresentation);

//----------------------------------------------------------------------------
vtkFrameRateRepresentation::vtkFrameRateRepresentation()
{
  this->TextActor = vtkSmartPointer<vtkTextActor>::New();
  this->TextActor->GetTextProperty()->SetFontSize ( 24 );
  this->TextActor->SetPosition2 ( 10, 40 );
  this->TextActor->SetInput ( "Frame Rate" );
  this->TextActor->GetTextProperty()->SetColor ( 1.0,0.0,0.0 );
  
  if(!this->Renderer)
    {
    cout << "Render is NULL" << endl;
    }
 
}

//----------------------------------------------------------------------------
vtkFrameRateRepresentation::~vtkFrameRateRepresentation()
{  
 
}


//----------------------------------------------------------------------------
void vtkFrameRateRepresentation::BuildRepresentation()
{
  //frameRateWidget->SetRenderer(renderer);
  //this->SetRenderer(renderer);
  
  /*
  // Rebuild only if necessary
  if ( this->GetMTime() > this->BuildTime ||
       (this->Renderer && this->Renderer->GetVTKWindow() &&
        (this->Renderer->GetVTKWindow()->GetMTime() > this->BuildTime ||
        this->Renderer->GetActiveCamera()->GetMTime() > this->BuildTime)) )
    {
    this->BuildTime.Modified();
    }
  */
}

//----------------------------------------------------------------------------
void vtkFrameRateRepresentation::ReleaseGraphicsResources(vtkWindow *w)
{

}

//----------------------------------------------------------------------------
int vtkFrameRateRepresentation::RenderOpaqueGeometry(vtkViewport *v)
{
  int count=0;
  this->BuildRepresentation();
 
  return count;
}

//----------------------------------------------------------------------------
int vtkFrameRateRepresentation::RenderTranslucentPolygonalGeometry(vtkViewport *v)
{
  int count=0;
  this->BuildRepresentation();
  
  return count;
}

//----------------------------------------------------------------------------
int vtkFrameRateRepresentation::HasTranslucentPolygonalGeometry()
{
  int result=0;
  this->BuildRepresentation();

  return result;
}

//----------------------------------------------------------------------------
void vtkFrameRateRepresentation::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);

}
