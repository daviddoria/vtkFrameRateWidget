#include <vtkSmartPointer.h>
#include <vtkMath.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>

#include "vtkFrameRateWidget.h"

int main(int, char *[])
{
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();

  for(unsigned int i = 0; i < 10; i++)
    {
    // Create a sphere
    vtkSmartPointer<vtkSphereSource> sphereSource =
      vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->SetCenter(vtkMath::Random(0,5), vtkMath::Random(0,5), vtkMath::Random(0,5));

    // Create a mapper and actor
    vtkSmartPointer<vtkPolyDataMapper> mapper =
      vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(sphereSource->GetOutputPort());

    vtkSmartPointer<vtkActor> actor =
      vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    //actors.push_back(actor);
    renderer->AddActor(actor);
    }

  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);

  vtkSmartPointer<vtkRenderWindowInteractor> interactor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  interactor->SetRenderWindow(renderWindow);

  /*
  vtkSmartPointer<vtkTextActor> textActor =
    vtkSmartPointer<vtkTextActor>::New();
  textActor->SetInput("This is a test");
  textActor->GetTextProperty()->SetColor( 0.0, 1.0, 0.0 );
  */
  vtkSmartPointer<vtkFrameRateWidget> frameRateWidget =
    vtkSmartPointer<vtkFrameRateWidget>::New();

  /*
  vtkSmartPointer<vtkTextRepresentation> textRepresentation =
    vtkSmartPointer<vtkTextRepresentation>::New();

  */
//  frameRateWidget->SetRepresentation(textRepresentation);
  frameRateWidget->SetInteractor(interactor);
  //frameRateWidget->SetTextActor(textActor);
  frameRateWidget->SetRenderer(renderer);
  frameRateWidget->SelectableOff();
  frameRateWidget->Init();

  renderer->SetBackground(1,1,1); // Background color white

  renderWindow->Render();
  frameRateWidget->On();
  interactor->Start();

  return EXIT_SUCCESS;
}
