#include "vtkFrameRateWidget.h"
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
#include "vtkCallbackCommand.h"
#include "vtkTimerLog.h"
#include "vtkSmartPointer.h"

#include <sstream>

void vtkFrameRateWidget::Init()
{
  vtkSmartPointer<vtkCallbackCommand> callbackCommand =
    vtkSmartPointer<vtkCallbackCommand>::New();
  callbackCommand->SetCallback(this->RenderCallback);
  this->Interactor->GetRenderWindow()->AddObserver(vtkCommand::RenderEvent, callbackCommand);
  
}

void vtkFrameRateWidget::RenderCallback(vtkObject* caller, long unsigned int vtkNotUsed(eventId),
			    void* vtkNotUsed(clientData), void* vtkNotUsed(callData) )
{
  std::cout << "RenderCallback!" << std::endl;
  
  vtkRenderWindow* window = static_cast<vtkRenderWindow*>(caller);
  vtkSmartPointer<vtkTimerLog> timer = 
    vtkSmartPointer<vtkTimerLog>::New();
  timer->StartTimer();
  vtkRenderer* renderer = window->GetRenderers()->GetFirstRenderer();
  renderer->Render();
//  renderer->WaitForCompletion();
  timer->StopTimer();

  double timeInSeconds=timer->GetElapsedTime();
  double fps=1.0/timeInSeconds;
  std::cout << "FPS: " << fps << std::endl;
  std::stringstream ss;
  ss << fps;
//  this->GetTextActor()->SetInput(ss.str().c_str()); //the callback function has to be static, but we need to be in an instance in order to do this!

}

vtkStandardNewMacro(vtkFrameRateWidget);

//----------------------------------------------------------------------------
vtkFrameRateWidget::vtkFrameRateWidget()
{
}

//----------------------------------------------------------------------------
vtkFrameRateWidget::~vtkFrameRateWidget()
{  
}

//----------------------------------------------------------------------------
void vtkFrameRateWidget::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}