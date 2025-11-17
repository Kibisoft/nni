#pragma once

#include <vector>
#include <memory>

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
		std::vector<std::unique_ptr<leaf>> children;
	public:
		virtual ~node() {}
	};
}
