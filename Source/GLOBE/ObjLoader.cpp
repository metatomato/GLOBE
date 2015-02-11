//
//  ObjLoader.cpp
//  Spline
//
//  Created by Jonathan Boucher on 11/02/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//

#include "Spline.h"
#include "ObjLoader.h"

TArray<FVector> UObjLoader::ExtractObjVertices(FString ObjData)
{
    TArray<FVector> Vertices = TArray<FVector>();
    TArray<FString>* Lines = new TArray<FString>();
    TArray<FString>* Sublines = new TArray<FString>();
    
    ObjData.ParseIntoArrayLines(Lines);
    
    for(FString Line : *Lines)
    {
        if(Line.StartsWith("v"))
        {
            Line.ParseIntoArrayWS(Sublines);
            
            FVector Vertex = FVector(   FCString::Atof(*(*Sublines)[1]),
                                        FCString::Atof(*(*Sublines)[2]),
                                        FCString::Atof(*(*Sublines)[3])
                                       );
                                                       
            //UE_LOG(LogTemp, Warning, TEXT("%s"),*(Vertex.ToString()));
            
            Vertices.Add(Vertex);
        }
    }
    
    delete Sublines;
    delete Lines;
    
    return Vertices;
}