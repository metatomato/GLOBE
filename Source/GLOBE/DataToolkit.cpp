

#include "GLOBE.h"
#include "DataToolkit.h"
#include "Json.h"

UDataToolkit::UDataToolkit(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


TSharedPtr<FJsonObject> UDataToolkit::GetJsonObjectFromString(FString JsonString)
{
    TSharedRef<FJsonStringReader> JsonReader = FJsonStringReader::Create(JsonString);
    
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
    
    const bool Deserialized = FJsonSerializer::Deserialize((TSharedRef<TJsonReader<TCHAR>>)JsonReader, JsonObject);
    if(!Deserialized)
    {
        UE_LOG(LogTemp,Error,TEXT("[UDataToolkit][GetJsonObjectFromString] Deserialization Failed!") );
        return nullptr;
    }
    
    if (JsonObject.IsValid())
    {
        UE_LOG(LogTemp,Error,TEXT("Got a nice Json Object!") );
    }
    else
        UE_LOG(LogTemp,Error,TEXT("JsonString loading failed!!") );
    
    return JsonObject;
}
