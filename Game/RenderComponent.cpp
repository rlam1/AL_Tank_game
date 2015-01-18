#include "RenderComponent.h"


RenderComponent::RenderComponent()
{
	renderObject = Sprite();
	renderSize = renderObject.GetSize();
}


RenderComponent::~RenderComponent()
{
}


void RenderComponent::Update()
{
    al_draw_bitmap(renderObject.GetSprite(), position.x, position.y, NULL);
}


void RenderComponent::Init()
{
}


void RenderComponent::GetPosition()
{
}
