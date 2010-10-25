#include <vtkSmartPointer.h>
#include <vtkMath.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSphereSource.h>
#include <vtkGlyph3D.h>
#include <vtkPoints.h>
#include <iostream>
#include <sstream>

#include "vtkFrameRateWidget.h"

using namespace std;



int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc !=2)
    {
        cerr << "ERROR: Number of arguments should be 1" << endl << endl;
        cerr << "Usage: " << argv[0] << " <number_of_points>" << endl;
        return EXIT_FAILURE;
    }

    unsigned nPoints = 0;
    istringstream(argv[1]) >> nPoints;


    // Create the renderer
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();


    // Create some random points
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    for (unsigned i=0; i<nPoints; ++i)
    {
        points->InsertNextPoint(vtkMath::Random(0,nPoints), 
                                vtkMath::Random(0,nPoints),
                                vtkMath::Random(0,nPoints));
    }
    
    vtkSmartPointer<vtkPolyData> data =
       vtkSmartPointer<vtkPolyData>::New();
   data->SetPoints(points); 


    //
    // Add some spheres representing the atoms
    // 
    vtkSmartPointer<vtkSphereSource> source =
        vtkSmartPointer<vtkSphereSource>::New();
    source->SetRadius(nPoints*0.01);
    vtkSmartPointer<vtkGlyph3D> glyph =
        vtkSmartPointer<vtkGlyph3D>::New();
    glyph->SetInput(data);
    glyph->SetSourceConnection(source->GetOutputPort());
    glyph->SetVectorModeToUseNormal();
    glyph->SetScaleModeToScaleByVector();
    glyph->SetColorModeToColorByScalar();

    vtkSmartPointer<vtkPolyDataMapper> mapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkSmartPointer<vtkActor> actor =
        vtkSmartPointer<vtkActor>::New();
    mapper->SetInputConnection(glyph->GetOutputPort());
    actor->SetMapper(mapper);
    renderer->AddActor(actor);



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
//    // Read a PDB file
//    vtkSmartPointer<vtkPDBReader> reader =
//        vtkSmartPointer<vtkPDBReader>::New();
//    reader->SetFileName(argv[1]);
//    reader->Update();
//    
//    cout << "Number of points:" <<
//        reader->GetOutput()->GetNumberOfPoints() << endl;
