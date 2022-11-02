#include "GameScore.h"


GameScore::GameScore(const LoaderParams* pParams) : GameObject(pParams)
{

}

void GameScore::IncreaseScore()
{
	score++;
}