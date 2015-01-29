

#include "FLAG3D.h"
#include "BPToolkit.h"


UBPToolkit::UBPToolkit(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


UObject* UBPToolkit::NewObjectFromBlueprint(UObject* WorldContextObject, TSubclassOf<UObject> UC)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	UObject* tempObject = StaticConstructObject(UC);
    
	return tempObject;
}