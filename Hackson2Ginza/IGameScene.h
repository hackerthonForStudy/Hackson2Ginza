#pragma once

class IGameScene
{
public:
	virtual ~IGameScene() = default;
	virtual void Init	() = 0;
	virtual void Update	() = 0;
	virtual void Draw	()const = 0;
};