

#include "GLOBE.h"
#include "SystemToolkit.h"
#include "Paths.h"
#include "FileManager.h"


USystemToolkit::USystemToolkit(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


void USystemToolkit::MakeDir(FString DirectoryName)
{
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    
    FString FullPath = FPaths::GameContentDir();
    //FullPath += "/";
    FullPath += DirectoryName;
    
    if(!PlatformFile.DirectoryExists( *FullPath))
    {
        PlatformFile.CreateDirectory( *FullPath);
        UE_LOG(LogTemp,Error,TEXT("Directory %s has been created!"), *FullPath );
    }
    else
        UE_LOG(LogTemp,Error,TEXT("Directory %s already exist!"), *FullPath );
}



void USystemToolkit::MakeiGLouDir()
{
    MakeDir(FString(TEXT("iGLou")));
}



void USystemToolkit::SaveStringToFile(FString String, FString File)
{
    FString FullPath = FPaths::GameContentDir();
    FullPath += "iGLou/";
    FullPath += File;
    FFileHelper::SaveStringToFile(String, * FullPath);
}



FString USystemToolkit::GetStringFromFile(FString File)
{
    FString FullPath = FPaths::GameContentDir();
    FullPath += "iGLou/";
    FullPath += File;
    
    if ( ! FPlatformFileManager::Get().GetPlatformFile().FileExists( *FullPath))
    {
        UE_LOG(LogTemp,Error,TEXT("Could Not Find File"));
GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("File NOT FOUND!") );
        return FString(TEXT(""));
    }
    else
    {
        UE_LOG(LogTemp,Error,TEXT("%s FOUND!") , *File);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("File FOUND!") );
    }
    
    
    FString Result;
    FFileHelper::LoadFileToString(Result, *FullPath);
    return Result;
}


















































