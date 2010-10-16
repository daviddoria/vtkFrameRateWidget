#include "vtkFrameRateWidget.h"
#include "vtkCommand.h"
#include "vtkObjectFactory.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkTextActor.h"
#include "vtkTextRepresentation.h"
#include "vtkTextProperty.h"

#include <sstream>

vtkStandardNewMacro(vtkFrameRateWidget);

void vtkFrameRateWidget::Init()
{
  this->Renderer->AddObserver(vtkCommand::EndEvent, this, &vtkFrameRateWidget::RenderCallback);

  this->CreateDefaultRepresentation();
  static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPositionCoordinate()->SetCoordinateSystemToNormalizedViewport();
  static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPosition2Coordinate()->SetCoordinateSystemToNormalizedViewport();
  static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPositionCoordinate()->SetValue(.05, .05);
  static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPosition2Coordinate()->SetValue(.3, .2);
  static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetTextActor()->GetTextProperty()->SetColor( 0.0, 1.0, 0.0 );
}

void vtkFrameRateWidget::RenderCallback(vtkObject* caller, long unsigned int vtkNotUsed(eventId),
                                        void* vtkNotUsed(callData) )
{
  std::cout << "RenderCallback!" << std::endl;

  double timeInSeconds = this->Renderer->GetLastRenderTimeInSeconds();
  double fps = 1.0/timeInSeconds;

  std::stringstream ss;
  ss << "Frame rate: " << fps << " (fps)";
  this->GetTextActor()->SetInput(ss.str().c_str());

}
