#include "GameObject.h"
#include "Game.h"
#include "TextureManager.h"

GameObject::GameObject(const LoaderParams* pParams) :
													IGameObject(pParams),
													position(pParams->getX(),
															pParams->getY()),
													width(pParams->getWidth()),
													height(pParams->getHeight()),
													velocity(0, 0),
													acceleration(0, 0)
{
	textureID = pParams->getTextureID();
	currentRow = 1;
	currentFrame = 1;
}

void GameObject::draw()
{
	TextureManager::Instance()->drawFrame(textureID,
											static_cast<int>(position.getX()),
											static_cast<int>(position.getY()),
											width,
											height,
											currentRow,
											currentFrame,
											Game::Instance()->getRenderer(),
											velocity.getX() > 0 ?
												SDL_RendererFlip::SDL_FLIP_HORIZONTAL :
												SDL_RendererFlip::SDL_FLIP_NONE);

}

void GameObject::update()
{
	velocity += acceleration;
	position += velocity;
}