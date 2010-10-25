#include <vtkSmartPointer.h>
#include <vtkMath.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <iostream>
#include <sstream>

#include "vtkFrameRateWidget.h"


using namespace std;



int main(int argc, char *argv[])
{
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();

    // Check command line arguments
    if (argc !=2)
    {
        cerr << "ERROR: Number of arguments should be 1" << endl << endl;
        cerr << "Usage: " << argv[0] << " <number_of_points>" << endl;
        return EXIT_FAILURE;
    }

    unsigned nPoints = 0;
    istringstream(argv[1]) >> nPoints;



    for(unsigned int i = 0; i < nPoints; i++)
    {
        // Create a sphere
        vtkSmartPointer<vtkSphereSource> sphereSource =
            vtkSmartPointer<vtkSphereSource>::New();
        sphereSource->SetRadius(nPoints*0.01);
        sphereSource->SetCenter(vtkMath::Random(0,nPoints), 
                                vtkMath::Random(0,nPoints), 
                                vtkMath::Random(0,nPoints));

        // Create a mapper and actor
        vtkSmartPointer<vtkPolyDataMapper> mapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
        mapper->SetInputConnection(sphereSource->GetOutputPort());

        vtkSmartPointer<vtkActor> actor =
            vtkSmartPointer<vtkActor>::New();
        actor->SetMapper(mapper);
        renderer->AddActor(actor);
    }

    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(renderWindow);

    vtkSmartPointer<vtkFrameRateWidget> frameRateWidget =
        vtkSmartPointer<vtkFrameRateWidget>::New();
    frameRateWidget->SetInteractor(interactor);
    frameRateWidget->SetRenderer(renderer);
    frameRateWidget->SelectableOff();
    frameRateWidget->Init();

    renderer->SetBackground(1,1,1); // Background color white
    renderWindow->Render();
    frameRateWidget->On();
    interactor->Start();

    return EXIT_SUCCESS;
}
