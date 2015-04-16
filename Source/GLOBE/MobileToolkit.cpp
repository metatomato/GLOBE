//
//  MobileToolkit.cpp
//  GLOBE
//
//  Created by Jonathan Boucher on 16/04/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//

#include "GLOBE.h"
#include "MobileToolkit.h"

const float UMobileToolkit::RATIO_9_16  = 9.f / 16.f;
const float UMobileToolkit::RATIO_10_16  = 10.f / 16.f;
const float UMobileToolkit::RATIO_3_4   = 3.f / 4.f;
const float UMobileToolkit::RATIO_9_16_ANDROID   = 45.f / 74.f;

FVector2D UMobileToolkit::Linearize(float X0, float X1, float Y0, float Y1)
{
    float CoeffDir = (Y1 - Y0) / (X1 - X0);
    float InitVal  = Y1 - (CoeffDir * X1);
    
    return FVector2D(CoeffDir,InitVal);
}


float UMobileToolkit::ScaleValueToScreenRatio(float XScreen, float YScreen, float LowerValue, float UpperValue, bool isPortrait)
{
//    float CoeffDir = (UpperValue - LowerValue) / (RATIO_3_4 - RATIO_9_16);
//    float InitVal  = UpperValue - (CoeffDir * RATIO_3_4);
    
    FVector2D LinearCoeff = Linearize(RATIO_9_16, RATIO_3_4, LowerValue, UpperValue);
    
    if(!isPortrait)
    {
 //       CoeffDir = (UpperValue - LowerValue) / ( 1/RATIO_9_16 - 1/RATIO_3_4);
 //       InitVal  = UpperValue - (CoeffDir  / RATIO_9_16);

        LinearCoeff = Linearize(1/RATIO_3_4, 1/RATIO_9_16, LowerValue, UpperValue);
    }
    
    
    
    float Ratio = XScreen / YScreen;
    
    return Ratio * LinearCoeff.X + LinearCoeff.Y;
}


float UMobileToolkit::ScaleValueToMultipleScreenRatio(float XScreen, float YScreen, float Value_3_4, float Value_9_16_android, float Value_9_16, bool isPortrait)
{
    float Ratio = XScreen / YScreen;
    
    FVector2D LinearCoeff;
    
    if (Ratio <= RATIO_10_16) {
        LinearCoeff = Linearize(RATIO_9_16,RATIO_9_16_ANDROID, Value_9_16, Value_9_16_android);
    } else {
        LinearCoeff = Linearize(RATIO_9_16_ANDROID, RATIO_3_4, Value_9_16_android, Value_3_4);
    }
    
    return Ratio * LinearCoeff.X + LinearCoeff.Y;
    
}