/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkBoxWidget2.cxx,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkFrameRateWidget.h"
#include "vtkFrameRateRepresentation.h"
#include "vtkCommand.h"
#include "vtkCallbackCommand.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkObjectFactory.h"
#include "vtkWidgetEventTranslator.h"
#include "vtkWidgetCallbackMapper.h" 
#include "vtkEvent.h"
#include "vtkWidgetEvent.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkRendererCollection.h"


vtkCxxRevisionMacro(vtkFrameRateWidget, "$Revision: 1.3 $");
vtkStandardNewMacro(vtkFrameRateWidget);

//----------------------------------------------------------------------------
vtkFrameRateWidget::vtkFrameRateWidget()
{
  this->WidgetState = vtkFrameRateWidget::Start;
  
  // Define widget events
  /*
  this->CallbackMapper->SetCallbackMethod(vtkCommand::UpdateEvent,
                                          vtkEvent::NoModifier,
                                          0, 0, NULL,
                                          vtkWidgetEvent::Update,
                                          this, vtkFrameRateWidget::UpdateAction);
  */
  
}

//----------------------------------------------------------------------------
vtkFrameRateWidget::~vtkFrameRateWidget()
{  
}

//----------------------------------------------------------------------
void vtkFrameRateWidget::UpdateAction(vtkAbstractWidget *w)
{
  // We are in a static method, cast to ourself
  vtkFrameRateWidget *self = reinterpret_cast<vtkFrameRateWidget*>(w);

  self->Render();
}

//----------------------------------------------------------------------
void vtkFrameRateWidget::CreateDefaultRepresentation()
{
  if ( ! this->WidgetRep )
    {
    this->WidgetRep = vtkFrameRateRepresentation::New();
    this->WidgetRep->SetRenderer(this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer());
    //this->Renderer->AddActor2D ( this->TextActor );
  
    }
}

//----------------------------------------------------------------------------
void vtkFrameRateWidget::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);

}


