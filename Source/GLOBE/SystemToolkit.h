

#pragma once

#include "Object.h"
#include "SystemToolkit.generated.h"

/**
 * 
 */
UCLASS()
class USystemToolkit : public UObject
{
	GENERATED_UCLASS_BODY()

	
    UFUNCTION(BlueprintCallable , meta = (FriendlyName = "MakeDir", CompactNodeTitle = "MkDIR", Keywords = "make directory"), Category = iGLou_System)
    static void MakeDir(FString DirectoryName);
    
    UFUNCTION(BlueprintCallable , meta = (FriendlyName = "MakeiGLouDir", CompactNodeTitle = "MkDIR", Keywords = "make iGLou directory"), Category = iGLou_System)
    static void MakeiGLouDir();
    
    UFUNCTION(BlueprintCallable , meta = (FriendlyName = "SaveString", CompactNodeTitle = "SAVE", Keywords = "save string"), Category = iGLou_System)
    static void SaveStringToFile(FString string, FString file);
    
    UFUNCTION(BlueprintCallable , meta = (FriendlyName = "LoadString", CompactNodeTitle = "LOAD", Keywords = "save string"), Category = iGLou_System)
    static FString GetStringFromFile(FString file);
   
};
