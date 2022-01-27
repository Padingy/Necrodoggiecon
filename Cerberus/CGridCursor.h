#pragma once
#include "CEntity.h"
class CGridCursor :
    public CEntity
{
public:
    CGridCursor();

    class CSpriteComponent* ActiveCellSprite = nullptr;

    virtual void Update(float deltaTime) override;

    void UpdateSize(int X, int Y);

    Vector3 Offset;
    Vector3 Offset_Start;
    Vector3 Offset_End;


    bool screenMoved;



   



    bool cellSelected;

    Vector3 selectedCell_1;
   



  



    bool wasMouseReleased;

};

