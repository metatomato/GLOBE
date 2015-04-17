//
//  MobileToolkit.h
//  GLOBE
//
//  Created by Jonathan Boucher on 16/04/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//

#pragma once
#include "MobileToolkit.generated.h"

UCLASS()
class UMobileToolkit : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure,
              meta = (FriendlyName = "ScaleToRatio",
                      Keywords = "scale ratio"),
              Category = iGLou)
    static float ScaleValueToScreenRatio(float XScreen, float YScreen, float LowerValue, float UpperValue, bool isPortrait);
    
    UFUNCTION(BlueprintPure,
              meta = (FriendlyName = "ScaleToMultipleRatio",
                      Keywords = "scale ratio"),
              Category = iGLou)
    static float ScaleValueToMultipleScreenRatio(float XScreen, float YScreen, float Value_3_4, float Value_10_16, float Value_9_16, bool isPortrait);
    
    UFUNCTION(BlueprintPure,
              meta = (FriendlyName = "ScaleForAllRatio",
                      Keywords = "scale ratio"),
              Category = iGLou)
    static float ScaleValueForAllScreenRatio(float XScreen,
                                                 float YScreen,
                                                 float Value_3_4_android,
                                                 float Value_3_4,
                                                 float Value_10_16_android,
                                                 float Value_10_16,
                                                 float Value_9_16_android,
                                                 float Value_9_16,
                                                 bool isPortrait);
    
    static FVector2D Linearize(float X0, float X1, float Y0, float Y1);
    
    static const float RATIO_9_16;
    static const float RATIO_9_16_ANDROID;
    static const float RATIO_10_16;
    static const float RATIO_10_16_ANDROID;
    static const float RATIO_3_4;
    static const float RATIO_3_4_ANDROID;
    
};


