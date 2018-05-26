#pragma once

template<typename TContainer>
inline int Count(const TContainer& container)
{
	const size_t n = container.size();
	return static_cast<int>(n);
}

using uint = unsigned int;
