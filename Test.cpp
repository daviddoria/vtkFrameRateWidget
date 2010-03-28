#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>

#include "vtkFrameRateWidget.h"

int main (int argc, char *argv[])
{
  vtkSmartPointer<vtkSphereSource> sphere = 
      vtkSmartPointer<vtkSphereSource>::New();
  double center[3] = {0,0,0};
  //sphere->SetCenter(0.0, 0.0, 0.0);
  sphere->SetCenter(center);
  sphere->SetRadius(2.0);
  sphere->Update();
  
  vtkPolyData* polydata = sphere->GetOutput();
  
  // map the contours to graphical primitives
  vtkSmartPointer<vtkPolyDataMapper> mapper = 
      vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInput(polydata);
  
  // create an actor for the contours
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  
  // a renderer and render window
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
      vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  
  // an interactor
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
  
  //the widget
  vtkSmartPointer<vtkFrameRateWidget> frameRateWidget = 
      vtkSmartPointer<vtkFrameRateWidget>::New();
  frameRateWidget->SetInteractor(renderWindowInteractor);
    
  // add the actors to the scene
  renderer->AddActor(actor);
  renderer->SetBackground(1,1,1); // Background color white
  
  renderWindow->Render();
  frameRateWidget->On();
  renderWindowInteractor->Start();
  
  return EXIT_SUCCESS;
}
