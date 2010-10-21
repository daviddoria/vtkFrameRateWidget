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


/* VTK version stuff */
#define OLD_VTK_VERSION (VTK_MAJOR_VERSION<5 || (VTK_MAJOR_VERSION==5 && VTK_MINOR_VERSION<7))
#if OLD_VTK_VERSION

#include "vtkCallbackCommand.h"

static void RenderCallbackOLD(vtkObject *caller, unsigned long, void *clientData, void *)
{
	vtkRenderer *renderer = vtkRenderer::SafeDownCast(caller);
	vtkFrameRateWidget *frw = (vtkFrameRateWidget*) clientData;
	
	double timeInSeconds = renderer->GetLastRenderTimeInSeconds();
	double fps = 1.0/timeInSeconds;
	
	std::stringstream ss;
	ss << "Frame rate: " << fps << " (fps)";
	frw->GetTextActor()->SetInput(ss.str().c_str());	
}
#endif


vtkStandardNewMacro(vtkFrameRateWidget);

void vtkFrameRateWidget::Init()
{
#if OLD_VTK_VERSION
	vtkCallbackCommand *callback = vtkCallbackCommand::New();
	callback->SetCallback(RenderCallbackOLD);
	callback->SetClientData(this);
	this->Renderer->AddObserver(vtkCommand::EndEvent, callback);
	callback->Delete();
#else
	this->Renderer->AddObserver(vtkCommand::EndEvent, this, &vtkFrameRateWidget::RenderCallback);
#endif
	
	this->CreateDefaultRepresentation();
	static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPositionCoordinate()->SetCoordinateSystemToNormalizedViewport();
	static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPosition2Coordinate()->SetCoordinateSystemToNormalizedViewport();
	static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPositionCoordinate()->SetValue(.05, .05);
	static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetPosition2Coordinate()->SetValue(.3, .2);
	//static_cast<vtkTextRepresentation*>(this->WidgetRep)->GetTextActor()->GetTextProperty()->SetColor( 0.0, 1.0, 0.0 );
	this->GetTextActor()->GetTextProperty()->SetColor( 0.0, 1.0, 0.0 );
	this->GetTextActor()->SetInput("Frame rate: ");
	this->GetTextActor()->GetTextProperty()->SetJustificationToLeft();
}

void vtkFrameRateWidget::RenderCallback(vtkObject* caller, long unsigned int vtkNotUsed(eventId),
                                        void* vtkNotUsed(callData) )
{
	double timeInSeconds = this->Renderer->GetLastRenderTimeInSeconds();
	double fps = 1.0/timeInSeconds;
	
	std::string ss;
	char a[20];
	ss.append("Frame Rate:");
	sprintf(a,"%5.2f",fps);
	ss.append(a);
	ss.append(" (fps)\t");

	this->GetTextActor()->SetInput(ss.c_str());

}


#undef OLD_VTK_VERSION