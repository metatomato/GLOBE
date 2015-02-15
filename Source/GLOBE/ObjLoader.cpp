//
//  ObjLoader.cpp
//  Spline
//
//  Created by Jonathan Boucher on 11/02/15.
//  Copyright (c) 2015 EpicGames. All rights reserved.
//

#include "GLOBE.h"
#include "ObjLoader.h"
#include "StaticMeshResources.h"

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


TArray<FVector> UObjLoader::ExtractFbxVertices(FString ObjData)
{
    TArray<FVector> Vectors = TArray<FVector>();
    TArray<float> Positions = TArray<float>();
    TArray<FString>* Lines = new TArray<FString>();
    TArray<FString>* Sublines = new TArray<FString>();
    TArray<FString> Datalines = TArray<FString>();
    bool EnterVertexSection = false;
    int Count = 0;
    
    ObjData.ParseIntoArrayLines(Lines);
    
    for(FString Line : *Lines)
    {
        FString TrimedLine = Line.Trim();
        
        if(TrimedLine.StartsWith("Vertices"))
        {
            EnterVertexSection = true;
            TrimedLine.RemoveFromStart("Vertices: ");
        }
        
        if(TrimedLine.StartsWith("PolygonVertexIndex"))
        {
            EnterVertexSection = false;
        }
        
        if(EnterVertexSection) {
            TrimedLine.ParseIntoArray(Sublines, TEXT(","), true);
            for(FString Word : *Sublines)
            {
                Positions.Add(FCString::Atof(*Word));
            }
        }
    
    }
    
    FVector Vector = FVector();
    
    for(float Pos : Positions)
    {
        int32 idx = Count%3;
        Vector[idx] = Positions[Count];
        Count++;
        if(2 == idx)
        {
            Vectors.Add(Vector);
        }
    }
    
    delete Sublines;
    delete Lines;
    
    return Vectors;

}



TArray<FVector> UObjLoader::GetVertices(const UStaticMeshComponent* StaticMeshComponent)
{
    TArray<FVector> vertices = TArray<FVector>();
    
    //if (!IsValidLowLevel()) return vertices;
    if (!StaticMeshComponent) return vertices;
    if (!StaticMeshComponent->StaticMesh) return vertices;
    if (!StaticMeshComponent->StaticMesh->RenderData) return vertices;
    
    if (StaticMeshComponent->StaticMesh->RenderData->LODResources.Num() > 0)
    {
        FPositionVertexBuffer* VertexBuffer = &StaticMeshComponent->StaticMesh->RenderData->LODResources[0].PositionVertexBuffer;
        if (VertexBuffer)
        {
            FIndexArrayView ArrayView = StaticMeshComponent->StaticMesh->RenderData->LODResources[0].IndexBuffer.GetArrayView();
            
            for(int32 i = 0 ; i < ArrayView.Num() ; i++) {
                UE_LOG(LogTemp, Warning, TEXT("index %d"),ArrayView[i]);
            }
            
            const int32 VertexCount = VertexBuffer->GetNumVertices();
            for (int32 Index = 0; Index < VertexCount; Index++)
            {
                //This is in the Static Mesh Actor Class, so it is location and tranform of the SMActor
                //const FVector WorldSpaceVertexLocation = GetActorLocation() + GetTransform().TransformVector(VertexBuffer->VertexPosition(Index));
                
                const FVector WorldSpaceVertexLocation = VertexBuffer->VertexPosition(Index);
                
                //add to output FVector array
                vertices.Add(WorldSpaceVertexLocation);
            }
        }
    }
    
    return vertices;
}




























