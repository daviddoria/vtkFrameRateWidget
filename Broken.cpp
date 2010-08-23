#include <vtkSmartPointer.h>
#include <vtkTextRepresentation.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkTextWidget.h>

#include "vtkFrameRateWidget.h"

int main (int argc, char *argv[])
{
 
  // a renderer and render window
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
      vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  
  // an interactor
  vtkSmartPointer<vtkRenderWindowInteractor> interactor = 
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
  interactor->SetRenderWindow(renderWindow);
  
    vtkSmartPointer<vtkTextActor> textActor =
    vtkSmartPointer<vtkTextActor>::New();
  textActor->SetInput("This is a test");
  textActor->GetTextProperty()->SetColor( 0.0, 1.0, 0.0 );
  
  //the widget
  //vtkSmartPointer<vtkFrameRateWidget> frameRateWidget = 
    //  vtkSmartPointer<vtkFrameRateWidget>::New();
    vtkSmartPointer<vtkTextWidget> frameRateWidget = 
      vtkSmartPointer<vtkTextWidget>::New();
      
  vtkSmartPointer<vtkTextRepresentation> textRepresentation =
    vtkSmartPointer<vtkTextRepresentation>::New();
  textRepresentation->GetPositionCoordinate()->SetValue( .15, .15 );
  textRepresentation->GetPosition2Coordinate()->SetValue( .7, .2 );
  frameRateWidget ->SetRepresentation( textRepresentation );
  frameRateWidget->SetInteractor(interactor);
  frameRateWidget->SetTextActor(textActor);
  frameRateWidget->SelectableOff();
  
  renderer->SetBackground(1,1,1); // Background color white
  
  renderWindow->Render();
  frameRateWidget->On();
  interactor->Start();
  
  return EXIT_SUCCESS;
}
