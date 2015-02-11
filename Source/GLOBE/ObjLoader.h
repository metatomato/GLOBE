//
//  ObjLoader.h
//  Spline
//
//  Created by Jonathan Boucher on 11/02/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//

#pragma once
#include "ObjLoader.generated.h"

UCLASS()
class UObjLoader : public UObject
{
    GENERATED_BODY()
    
public:
    UFUNCTION(BlueprintCallable,
              meta = (  FriendlyName = "Extract Obj Vertices",
                        Keyword = "System Loader extract obj"),
              Category = "iGLou")
    static TArray<FVector> ExtractObjVertices(FString ObjData);
};