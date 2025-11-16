#pragma once

#include <vector>

namespace nni
{
	class leaf
	{
	public:
		virtual ~leaf() {}
	};

	class node : public leaf
	{
	public:
		std::vector<leaf*> children;

	public:
		virtual ~node()
		{
			for (auto child : children)
			{
				delete child;
			}
		}
	};
}
